#include "pch.h"
#include <Windows.h>

#include <iostream>
#include <sstream>
#include "src/spawn/coordinates.h"
#include "src/spawn/masterninja.h"
#include "src/spawn/mentor.h"
#include "src/spawn/globals.h"
#include "src/spawn/spawn.h"
#include <Windows.h>
#include <mmsystem.h>
#include <iomanip>

#pragma comment(lib, "winmm.lib")

/*Author: Fiend Busa
* Updates: https://studio.youtube.com/channel/UCyskPAuZdVG_rUI3jDfS5vw
*/



DWORD_PTR GetBaseAddress()
{
    // Get the base address of the module
    HMODULE hModule = GetModuleHandle(NULL);
    return (DWORD_PTR)hModule;
}


//
//extern "C" DWORD_PTR jmpBK = 0;
//extern "C" DWORD_PTR jmpBK2 = 0;



/*__attribute((naked)) void Test()
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
    );
}*/



void WriteFloats(DWORD_PTR baseAddress, intptr_t* offsets, float* values, size_t count) {
    DWORD oldProtect;
    for (size_t i = 0; i < count; ++i) {
        // Calculate the address by adding the offset to the base address
        void* address = reinterpret_cast<void*>(baseAddress + offsets[i]);

        VirtualProtect(address, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect);
        *(float*)address = values[i];
        VirtualProtect(address, sizeof(float), oldProtect, &oldProtect);

        // Display a message box with the result
       /* std::stringstream ss;
        ss << "Wrote " << values[i] << " to address 0x" << std::hex << std::setw(8) << std::setfill('0') << reinterpret_cast<uintptr_t>(address);
        MessageBoxA(nullptr, ss.str().c_str(), "WriteFloats Result", MB_OK);*/
    }
}

void NopMemory(void* address, size_t size) {
    DWORD oldProtect;
    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
    memset(address, 0x90, size);
    VirtualProtect(address, size, oldProtect, &oldProtect);
}


//clear up junk bytes? though not really needed, not sure
bool Hook(void* hookAddress, void* myFunc, int len) {

    if (len < 14) {
        return false;
    }

    DWORD oldProtect;
    VirtualProtect(hookAddress, len, PAGE_EXECUTE_READWRITE, &oldProtect);


    *(BYTE*)hookAddress = 0xFF;
    *((BYTE*)hookAddress + 1) = 0x25;
    *(DWORD*)((BYTE*)hookAddress + 2) = 0;
    *(DWORD_PTR*)((BYTE*)hookAddress + 6) = (DWORD_PTR)myFunc;
   

    VirtualProtect(hookAddress, len, oldProtect, &oldProtect);
    
    
  

    return true;
}

void WriteByte(DWORD_PTR address, BYTE value) {
    DWORD oldProtect;
    // Change memory protection to allow writing of a single byte
    VirtualProtect((void*)address, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &oldProtect);

    // Write the byte value to the address
    *(BYTE*)address = value;

    // Restore the original memory protection
    VirtualProtect((void*)address, sizeof(BYTE), oldProtect, &oldProtect);
}



//JUNK HOOKING UNTIL ALL DATA IS PORTED - ADD LOGIC LATER
DWORD WINAPI MainThread(LPVOID param) {
    
    //INJECTCBATTLE (COORDINATES)
    baseAddress = GetBaseAddress();
    int hookLength = 16;

    DWORD_PTR hookAddress = baseAddress + 0x1607CA4;
   
   returnInjectCBattle = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectCBattle, hookLength);


   //INJECTCOORDS
   hookLength = 17;
   hookAddress = baseAddress + 0x161855E;

    returnInjectCoords = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectCoords, hookLength);

   //INJECTC
    hookLength = 15;

    hookAddress = baseAddress + 0x1607A89;

    returnInjectC = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectC, hookLength);

   //INJECTA
    hookLength = 18;

    hookAddress = baseAddress + 0x161A451;

    returnInjectA = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectAMaster, hookLength);

    //DISABLESPAWNSINJECT

    hookLength = 19;

    hookAddress = baseAddress + 0x1619577;

    returnInjectDisableSpawns = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectDisableSpawns, hookLength);

    //INJECTENTDIE
    hookLength = 15;

    hookAddress = baseAddress + 0x15D9148;

    returnInjectEntDie = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectEntDie, hookLength);

    //INJECTDONTDISABLEBATTLE

    hookLength = 15;

    hookAddress = baseAddress + 0x160C54E;

    returnInjectDontDisableBattle = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectDontDisableBattle, hookLength);

    //INJECTTELEPLAYER
    hookLength = 18;

    hookAddress = baseAddress + 0x141BBBD;

    returnInjectTelePlayer = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectTelePlayer, hookLength);

    //INJECT TRIPLE IS
    hookLength = 17;

    hookAddress = baseAddress + 0x137DF7A;

    returnInjectTripleIS = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectTripleIS, hookLength);

   


   // FreeLibraryAndExitThread((HMODULE)param, 0);

    //PlaySound(TEXT("C:\\Users\\g-gil\\Downloads\\James Shimoji - Pepsi Man Theme Song (ORIGINAL).wav"), NULL, SND_FILENAME | SND_ASYNC);

    //DELIMB1
   hookLength = 19;

    hookAddress = baseAddress + 0xF7365A;

   returnInjectDelimb1 = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectDelimb1, hookLength);

    //DELIMB2
  hookLength = 14;

    hookAddress = baseAddress + 0x1005839;

    returnInjectDelimb2 = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectDelimb2, hookLength);


    //INJECT SOUND
    hookLength = 19;

    hookAddress = baseAddress + 0x14C4E34;
    returnInjectSound = hookAddress + hookLength;
    Hook((void*)hookAddress, InjectSound, hookLength);


    DWORD_PTR nopeAddy = baseAddress + 0xF7363A;

    NopMemory((void*)nopeAddy, 2);

    nopeAddy = baseAddress + 0xF7363C;

    NopMemory((void*)nopeAddy, 2);

    hookAddress = baseAddress + 0x1399FA7;
    //IS ACCURACY
    WriteByte(hookAddress, 0xEB);

  

  

   /* nopeAddy = baseAddress + 0xF73607;

    NopMemory((void*)nopeAddy, 6);

    nopeAddy = baseAddress + 0xFD5E2F;

    NopMemory((void*)nopeAddy, 2);*/



    //SET DAMAGE VALUES FOR MASTER NINJA (BASICALLY DIVIDE BY 2)
    intptr_t masterDamageOffsets[] = {
        0x1D9F3A4,
        0x1D9F3A8,
        0x1D9F3E4,
        0x1D9F3E8,
        0x1D9F424,
        0x1D9F428,
        0x1D9F464,
        0x1D9F468,
        0x1D9F4A4,
        0x1D9F4A8,
        0x1D9F544,
        0x1D9F548,
        0x1D9F584,
        0x1D9F588,
        0x1D9F5C4,
        0x1D9F5C8,
    };
    float masterDamageNewVals[] = {
       2.00f,
        2.50f,
        2.00f,
        2.50f,
        2.00f,
        2.50f,
        2.00f,
        2.50f,
        2.00f,
        2.50f,
        2.00f,
        2.50f,
        2.00f,
        2.50f,
        2.00f,
        2.50f,
    };

    

   

    // Call the function
    WriteFloats(baseAddress, masterDamageOffsets, masterDamageNewVals, 16);

    while (true) {
        WORD playerHP = *(WORD*)(baseAddress + 0x319CBB4);
        if (playerHP <= 0) {
            
            //CLEAR VARS
            scounter = 0;
            scounter2 = 0;
            scounter3 = 0;
            scounter4 = 0;
            scounter5 = 0;
            scounter6 = 0;
            cBattleRespawnCount = 0;
            cBattleRespawnCount2 = 0;
            cBattleRespawnCount3 = 0;
            cBattleRespawnCount4 = 0;
            cBattleRespawnCount5 = 0;
            cBattleRespawnCount6 = 0;
            cDeleteEnemy = 0;
            counter = 0;
            entDied = 0;          

            canSpawn = 0;

            minimumspawn = 0;
            maximumspawn = 0;
            chpstage = 0;

            //CLEAR BATTLE TRACKER DATA
            ClearTracking();
        }
        Sleep(100);
        
    }



    /*GAJA
    hookLength = 15;

    hookAddress = baseAddress + 0xF48FB8;

    returnInjectGaja = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectGaja, hookLength);*/

    //FreeLibraryAndExitThread((HMODULE)param, 0);
    
   

   


   
    
    
    //FreeLibraryAndExitThread((HMODULE)param, 0);

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


