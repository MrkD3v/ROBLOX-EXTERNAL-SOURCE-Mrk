#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <iostream>
#include <string>

inline HANDLE g_process = nullptr;
inline DWORD g_pid = 0;
inline uintptr_t Base = 0;

template<typename T>
T read(uintptr_t address) {
    T buffer{};
    if (!g_process || !address) return buffer;
    ReadProcessMemory(g_process, reinterpret_cast<LPCVOID>(address), &buffer, sizeof(T), nullptr);
    return buffer;
}

inline bool read_array(uintptr_t address, void* buffer, size_t size) {
    if (!g_process || !address || !buffer || size == 0)
        return false;

    SIZE_T bytesRead = 0;
    bool success = ReadProcessMemory(g_process, reinterpret_cast<LPCVOID>(address), buffer, size, &bytesRead);
    return success && bytesRead == size;
}

template<typename T>
void write(uintptr_t address, const T& value) {
    if (!g_process || !address) return;
    WriteProcessMemory(g_process, reinterpret_cast<LPVOID>(address), &value, sizeof(T), nullptr);
}

inline bool is_valid_address(uintptr_t address) {
    return address != 0 && address >= 0x10000 && address < 0x7FFFFFFFFFFF;
}

inline DWORD get_process_id(const std::wstring& process_name) {
    PROCESSENTRY32W entry{};
    entry.dwSize = sizeof(entry);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return 0;

    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (_wcsicmp(entry.szExeFile, process_name.c_str()) == 0) {
                CloseHandle(snapshot);
                return entry.th32ProcessID;
            }
        } while (Process32NextW(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return 0;
}

inline uintptr_t get_module_base(DWORD pid, const std::wstring& module_name) {
    MODULEENTRY32W mod{};
    mod.dwSize = sizeof(mod);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (snapshot == INVALID_HANDLE_VALUE) return 0;

    if (Module32FirstW(snapshot, &mod)) {
        do {
            if (_wcsicmp(mod.szModule, module_name.c_str()) == 0) {
                CloseHandle(snapshot);
                return reinterpret_cast<uintptr_t>(mod.modBaseAddr);
            }
        } while (Module32NextW(snapshot, &mod));
    }

    CloseHandle(snapshot);
    return 0;
}

inline bool DriverInitialize() {
    g_pid = get_process_id(L"RobloxPlayerBeta.exe");
    if (!g_pid) return false;

    g_process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, g_pid);
    if (!g_process) return false;

    Base = get_module_base(g_pid, L"RobloxPlayerBeta.exe");
    return Base != 0;
}
