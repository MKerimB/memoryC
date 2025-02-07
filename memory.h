#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class basicMem {

private:
	DWORD procID;
	HANDLE handler;

public:
	basicMem(const char* pName);
	~basicMem();

	DWORD GetProcessId();
	HANDLE GetProcessHandle();

	uintptr_t GetModuleAddress(const char* moduleName);
	uintptr_t GetPointerAddress(uintptr_t baseAddress, uintptr_t pointer, std::vector<DWORD> offsets);

	template <typename T>
	T Read(uintptr_t address) {
		
		T value;
		ReadProcessMemory(this->handler, (LPCVOID)address, &value, sizeof(L), NULL);
		return value;
	}

	template <typename T>
	bool Write(LPVOID address, T value) {

		return WriteProcessMemory(this->handler, (LPVOID) address, &value, sizeof(L), NULL);

	}

};

