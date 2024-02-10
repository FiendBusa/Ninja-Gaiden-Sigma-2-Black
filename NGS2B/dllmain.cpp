#include "pch.h"
#include <Windows.h>

#include <iostream>
#include <sstream>
#include "src/spawn/coordinates.h"
#include "src/spawn/masterninja.h"
#include "src/spawn/globals.h"




DWORD_PTR GetBaseAddress()
{
    // Get the base address of the module
    HMODULE hModule = GetModuleHandle(NULL);
    return (DWORD_PTR)hModule;
}

extern "C" DWORD_PTR jmpBK = 0;
extern "C" DWORD_PTR jmpBK2 = 0;



__attribute((naked)) void Test()
{
    __asm(".intel_syntax noprefix;"
        "movzx edi,byte ptr [rdx];"
        "mov rsi, rcx;"
        "movzx ebp,byte ptr [rdx+01];"
        "xor r12d,r12d;"
        "movzx r14d,word ptr [rdx+04];"
        "cmp r14d,0x9D;"
        "jne 1f;"
        "mov r14d,0xA1;"
        "1:"
        "jmp qword ptr [rip + jmpBK];"
        ".att_syntax;"
    );
}

__attribute__((naked)) void InjectSound() {
    __asm__ volatile (
        ".intel_syntax noprefix;"
        
        "cmp r8, 0x2;"
        "jne 2f;"    
        "cmp r9, 0x3b;" 
        "je 1f;"
        "cmp r9, 0x45;" 
        "je 0f;"
        "jmp 2f;"
        "0:"
        "mov r9,0x3D;"
        "jmp 2f;"
        "1:"
        "mov r9, 0x3E;" 
        "2:"
        "mov [rdx],r8d;"
        "xor ebp,ebp;"
        "mov [rdx+04],r9d;"
        "mov rbx,rdx;"
        "mov rax, [rcx+0x130];"
        "jmp qword ptr [rip + jmpBK2];" // Jump to jmpBK
        "3:"
        ".att_syntax;"
        );
}



bool Hook(void* hookAddress, void* myFunc, int len) {
    
    if (len < 14) { // Minimum size for a JMP instruction in x64 is 14 bytes.
        return false;
    }

    DWORD oldProtect;
    VirtualProtect(hookAddress, len, PAGE_EXECUTE_READWRITE, &oldProtect);


    *(BYTE*)hookAddress = 0xFF; // JMP instruction opcode for x64.
    *((BYTE*)hookAddress + 1) = 0x25; // Indirect JMP opcode.
    *(DWORD*)((BYTE*)hookAddress + 2) = 0; // Placeholder for the address.
    *(DWORD_PTR*)((BYTE*)hookAddress + 6) = (DWORD_PTR)myFunc;


    VirtualProtect(hookAddress, len, oldProtect, &oldProtect);

    return true;
}


DWORD WINAPI MainThread(LPVOID param) {
    
    //INJECT C BATTLE (COORDINATES)
    baseAddress = GetBaseAddress();
    int hookLength = 16;

    DWORD_PTR hookAddress = baseAddress + 0x1607CA4;
    
    returnInjectCBattle = hookAddress + hookLength;
   

    Hook((void*)hookAddress, InjectCBattle, hookLength);
    
    /*int hookLength = 18;

    DWORD_PTR hookAddress = GetBaseAddress() + 0x161A451;
    jmpBK = hookAddress + hookLength;

    if (Hook((void*)hookAddress, Test, hookLength)) {
        MessageBoxA(NULL, "INJECTA LOADED", "NGS2B", 0);
    }

    int hookLength2 = 19;

    DWORD_PTR hookAddress2 = GetBaseAddress() + 0x14C4E34;
    jmpBK2 = hookAddress2 + hookLength2;

    if (Hook((void*)hookAddress2, InjectSound, hookLength2)) {
        MessageBoxA(NULL, "INJECT SOUND LOADED", "NGS2B", 0);
    }*/
    
    
  

    while (true) {
        if (GetAsyncKeyState(VK_F12) & 0x8000) {
            
            break;
        }
        Sleep(100);
    }
    FreeLibraryAndExitThread((HMODULE)param, 0);

    return 0;
}

bool WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
    
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, MainThread, hModule, 0, 0);
        break;

    }
   
    return true;
}

