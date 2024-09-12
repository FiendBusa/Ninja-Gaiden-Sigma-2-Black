#include "pch.h"
#include <Windows.h>

#include <iostream>
#include <sstream>
#include "src/spawn/coordinates.h"
#include "src/spawn/ultimateninja.h"
#include "src/spawn/masterninja.h"
#include "src/spawn/warrior.h"
#include "src/spawn/mentor.h"
#include "src/spawn/globals.h"
#include "src/spawn/spawn.h"
#include <Windows.h>
#include <mmsystem.h>
#include <iomanip>
#include <random>
#include <chrono>
#include "SimpleIni.h"
#include <string>

#pragma comment(lib, "winmm.lib")



/*Author: Fiend Busa
* Updates: https://studio.youtube.com/channel/UCyskPAuZdVG_rUI3jDfS5vw
*/

struct HookInfo {
    DWORD_PTR offset;
    int length;
    void* hookFunction;
    const char* hookName;
    DWORD_PTR* returnAddress; 
};

std::wstring byteToWString(BYTE byteValue) {
    return std::to_wstring(static_cast<int>(byteValue));
}

DWORD_PTR GetBaseAddress()
{
  
    HMODULE hModule = GetModuleHandle(NULL);
    return (DWORD_PTR)hModule;
}

TCHAR* GetExecutablePath(TCHAR* exePath, DWORD size) {
    GetModuleFileName(NULL, exePath, size);
    TCHAR* lastSlash = wcsrchr(exePath, '\\');
    if (lastSlash) {
        *lastSlash = '\0'; 
    }
    return exePath;
}

void LoadConfig() {
    TCHAR exePath[MAX_PATH];
    GetExecutablePath(exePath, MAX_PATH);

    
    std::wstring iniPath = std::wstring(exePath) + L"\\plugin\\NGS2B\\System\\config.ini";

    CSimpleIniW ini;  
    ini.SetUnicode();

    SI_Error rc = ini.LoadFile(iniPath.c_str());
    if (rc < 0) {
        MessageBox(NULL, L"Can't load 'config.ini'", L"NGS2B", NULL);
        return;
    }
    //MessageBox(NULL, L"Loaded INI'", L"ERROR", NULL);
    
   
    //DELIMBS
    newVal1 = ini.GetDoubleValue(L"DELIMB", L"globalDelimbMulp", 1.0f);
    highDelimbMulp = ini.GetDoubleValue(L"DELIMB", L"highDelimbMulp", 1.80f);
    guilthrowDmgMulp = ini.GetDoubleValue(L"DELIMB", L"guilthrowDmgMulp", 1.50f);
    scytheDelimbMulp = ini.GetDoubleValue(L"DELIMB", L"scytheDelimbMulp", 4.00f);
    enmaDelimbMulp = ini.GetDoubleValue(L"DELIMB", L"emnaDelimbMulp", 3.00f);
    femaleDelimbMulp = ini.GetDoubleValue(L"DELIMB", L"femaleDelimbMulp", 2.50f);

    //MURAMASA
    weaponUpgradeCost = static_cast<uint16_t>(ini.GetLongValue(L"SHOP", L"weaponUpgradeCost", 30000));

    //ENEMY HP MULP
    reHPTable[0].hpMulp = ini.GetDoubleValue(L"WATERDRAGON", L"waterDragonHPMulp", 0.50f);

    //GRAPHICS
    corpseTimerLycans = ini.GetDoubleValue(L"GRAPHICS", L"corpseTimerLycans", 1800.00f);
    ng2Shine = ini.GetBoolValue(L"Graphics", L"shine", true);
    bloomIntensity = ini.GetDoubleValue(L"Graphics",L"bloomIntensity",0.25f);

    //ENEMY AI
    isNinjaGrabSpeed = ini.GetBoolValue(L"ENEMYAI", L"isNinjaGrabSpeed", false);
    greyNinjaGrabSpeed = ini.GetBoolValue(L"ENEMYAI", L"greyNinjaGrabSpeed", false);
    zedGrabSpeed = ini.GetBoolValue(L"ENEMYAI", L"zedGrabSpeed", false);
    lizGrabSpeedTail = ini.GetBoolValue(L"ENEMYAI", L"lizGrabSpeedTail", true);

    //AUDIO
    mainMenuTrack = static_cast<BYTE>(ini.GetLongValue(L"AUDIO", L"mainMenuTrack", 0x3E));
    ch1HeroTrack = static_cast<BYTE>(ini.GetLongValue(L"AUDIO", L"ch1HeroTrack", 0x3D));
    ch14HeroTrack = static_cast<BYTE>(ini.GetLongValue(L"AUDIO", L"ch14HeroTrack", 0x4D));
    configChime = ini.GetBoolValue(L"AUDIO", L"configChime", true);

    //GAMEPLAY
    animationSmoothing = ini.GetBoolValue(L"GAMEPLAY", L"animationSmoothing", true);
    quickSelectBlur = ini.GetBoolValue(L"GAMEPLAY", L"quickSelectBlur", false);
    microStutter = static_cast<BYTE>(ini.GetLongValue(L"GAMEPLAY", L"microStutter", 0x00));
    whiteFlash = ini.GetBoolValue(L"GAMEPLAY", L"whiteFlash", true);
    disableEssence = ini.GetBoolValue(L"GAMEPLAY", L"disableEssence", false);
    hasFullAirborneIframes = ini.GetBoolValue(L"GAMEPLAY", L"hasFullAirborneIframes", false);
    ultimateNinja = ini.GetBoolValue(L"GAMEPLAY", L"UltimateNinja", false);

    
    //CAMERA
    fovValue = ini.GetDoubleValue(L"CAMERA", L"fov", 1.00f);
    isFreeCamIzunaOnly = ini.GetBoolValue(L"CAMERA", L"isFreeCamIzunaOnly", true);
    isFreeCamAll = ini.GetBoolValue(L"CAMERA", L"isFreeCamAll", false);

    //DANGER ZONE
    instantResume = ini.GetBoolValue(L"DANGERZONE", L"instantResume", false);

    //DEBUG
    noClip = ini.GetBoolValue(L"DEBUG", L"noClip", false);
    freezeEnemies = ini.GetBoolValue(L"DEBUG", L"freezeEnemies", false);
    disableDelimb = ini.GetBoolValue(L"DEBUG", L"disableDelimb", false);
    windowAlwaysReadInputs = ini.GetBoolValue(L"DEBUG", L"windowAlwaysReadInputs", false);

    //SPAWN
    ch1RasetsuDisableMinions = ini.GetBoolValue(L"SPAWN", L"ch1RasetsuDisableMinions", false);
    skipCH1StatueEncOne = ini.GetBoolValue(L"SPAWN", L"skipCH1StatueEncOne", false);
    skipCH4Statue = ini.GetBoolValue(L"SPAWN", L"skipCH4Statue", false);

    //INTERFACE
    vibrantMainMenu = ini.GetBoolValue(L"INTERFACE", L"vibrantMainMenu", true);
    saveLastFrame = ini.GetBoolValue(L"INTERFACE", L"saveLastFrame", false);

    // ATTACK CANCELS
    CSimpleIniW::TNamesDepend keys;
    ini.GetAllKeys(L"ATTACKCANCELS", keys);
    attackCancelList.clear();

    for (const auto& key : keys) {
        std::wstring value = ini.GetValue(L"ATTACKCANCELS", key.pItem, L"");

        if (!value.empty()) {
           
            std::wistringstream iss(value);
            std::wstring attackAnimStr, cancelAnimStr, cancelInputStr;

            std::getline(iss, attackAnimStr, L',');
            std::getline(iss, cancelAnimStr, L',');
            std::getline(iss, cancelInputStr, L',');

      
            attackCancelTable entry;
            entry.attackAnim = static_cast<uint16_t>(std::stoi(attackAnimStr, nullptr, 16)); 
            entry.cancelAnim = static_cast<uint16_t>(std::stoi(cancelAnimStr, nullptr, 16)); 
            entry.cancelInput = static_cast<uint32_t>(std::stoul(cancelInputStr, nullptr, 16)); 

           
            attackCancelList.push_back(entry);
        }
    }
    attackCancelListSize = attackCancelList.size();
    

    std::wstringstream output;

    // Iterate through all sections
    CSimpleIniW::TNamesDepend sections;
    ini.GetAllSections(sections);

    for (auto& section : sections) {
        output << L"[" << section.pItem << L"]\n"; // Section header

        // Iterate through all keys in the section
        CSimpleIniW::TNamesDepend keys;
        ini.GetAllKeys(section.pItem, keys);

        for (auto& key : keys) {
            const wchar_t* value = ini.GetValue(section.pItem, key.pItem, L"");
            output << key.pItem << L" = " << value << L"\n";
        }

        output << L"\n"; 
    }


    std::wstring outputStr = output.str();

    
    //MessageBoxW(NULL, outputStr.c_str(), L"INI File Values", MB_OK);
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

     
    }
}

void NopMemory(void* address, size_t size) {
    DWORD oldProtect;
    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
    memset(address, 0x90, size);
    VirtualProtect(address, size, oldProtect, &oldProtect);
}

HookInfo hooks[] = {
    {0x1607A89, 15, InjectC, "InjectC", &returnInjectC},
    {0x15D9148, 15, InjectEntDie, "InjectEntDie", &returnInjectEntDie},
    {0x137DF7A, 17, InjectTripleIS, "InjectTripleIS", &returnInjectTripleIS},
    {0xF7365A, 19, InjectDelimb1, "InjectDelimb1", &returnInjectDelimb1},
    {0x1005839, 14, InjectDelimb2, "InjectDelimb2", &returnInjectDelimb2},
    {0x14C4E34, 19, InjectSound, "InjectSound", &returnInjectSound},
    {0xF89F97, 18, InjectAnim, "InjectAnim", &returnInjectAnim},
    {0x1622AAD, 17, InjectStrigger, "InjectStrigger", &returnInjectStrigger},
    {0xB5CF96, 15, InjectLockCam, "InjectLockCam", &returnInjectLockCam},
    {0x136E032, 16, InjectClip, "InjectClip", &returnInjectClip},
    {0xFEACB3, 16, InjectInventory, "InjectInventory", &returnInjectInventory},
    {0x15EF523, 18, InjectInventoryCCNew, "InjectInventoryCCNew", &returnInjectInventoryCCNew},
    {0x145F459, 16, InjectCorpse, "InjectCorpse", &returnInjectCorpse},
    {0xF80C82, 18, InjectHalfCut, "InjectHalfCut", &returnInjectHalfCut},
    {0x1414BF7, 15, InjectDelimbAnim, "InjectDelimbAnim", &returnInjectDelimbAnim},
    {0x14158A9, 15, InjectDelimbFiends, "InjectDelimbFiends", &returnInjectDelimbFiends},
    {0xF48C1D, 16, InjectAIDodge, "InjectAIDodge", &returnInjectAIDodge},
    {0xF34B15, 21, InjectGuilIzunaDmg, "InjectGuilIzunaDmg", &returnInjectGuilIzunaDmg},
    {0x15E93CB, 15, InjectBlackSmith, "InjectBlackSmith", &returnInjectBlackSmith},
    {0x13D2BFE, 16, InjectWeaponUpgrade, "InjectWeaponUpgrade", &returnInjectWeaponUpgrade},
    {0x13D2A60, 20, InjectEssRemoval, "InjectEssRemoval", &returnInjectEssRemoval},
    {0xF72EC9, 17, InjectScytheDelimb, "InjectScytheDelimb", &returnInjectScytheDelimb},
    {0xFD5F21, 14, InjectFreeCam, "InjectFreeCam", &returnInjectFreeCam},
    {0x15D9AE9, 16, InjectREHP, "InjectREHP", &returnInjectREHP},
    {0x1619577, 19, InjectDisableSpawns, "InjectDisableSpawns", &returnInjectDisableSpawns},
    {0x1031CC4, 18, InjectSpecialEffects, "InjectSpecialEffects", &returnInjectSpecialEffects},
    {0x13396ED, 15, InjectBloom, "InjectBloom", &returnInjectBloom},
    {0xFCF194, 15, InjectFOV, "InjectFOV", &returnInjectFOV},
   {0xF2E6CC, 19, InjectSpecialEffectsApply, "InjectSpecialEffectsApply", &returnInjectSpecialEffectsApply},
    {0x1416D9D, 14, InjectIFrames, "InjectIFrames", &returnInjectIFrames},
    {0xB5CC6A, 16, InjectInput, "InjectInput", &returnInjectInput},
    {0xF56372, 14, InjectAttackCancel, "InjectAttackCancel", &returnInjectAttackCancel},
    {0x1622FA4, 19, InjectDiffLoad, "InjectDiffLoad", &returnInjectDiffLoad}
    

};


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

void ApplyHooks(HookInfo* hooks, int count, DWORD_PTR baseAddress) {
    for (int i = 0; i < count; i++) {
        DWORD_PTR hookAddress = baseAddress + hooks[i].offset;
        if (hooks[i].returnAddress) {
            *(hooks[i].returnAddress) = hookAddress + hooks[i].length;
        }
        if (!Hook((void*)hookAddress, hooks[i].hookFunction, hooks[i].length)) {
            std::stringstream ss;
            ss << "Failed to hook: " << hooks[i].hookName << " at address: 0x" << std::hex << hookAddress;
            MessageBoxA(NULL, ss.str().c_str(), "Hook Error", MB_OK | MB_ICONERROR);
        }
    }
}

bool HookNew(void* hookAddress, void* myFunc, int len) {

    if (len < 14) {
        return false;
    }

    DWORD oldProtect;
    VirtualProtect(hookAddress, len, PAGE_EXECUTE_READWRITE, &oldProtect);

    // Insert jump instruction (FF 25 [4-byte displacement])
    *(BYTE*)hookAddress = 0xFF;
    *((BYTE*)hookAddress + 1) = 0x25;
    *(DWORD*)((BYTE*)hookAddress + 2) = 0x0; // Relative displacement
    *(DWORD_PTR*)((BYTE*)hookAddress + 6) = (DWORD_PTR)myFunc;

    // NOP out remaining bytes to avoid corrupted instructions
    for (int i = 14; i < len; i++) {
        *((BYTE*)hookAddress + i) = 0x90; // NOP
    }

    VirtualProtect(hookAddress, len, oldProtect, &oldProtect);

    return true;
}




void WriteByte(DWORD_PTR address, BYTE value) {
    DWORD oldProtect;
 
    VirtualProtect((void*)address, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &oldProtect);

 
    *(BYTE*)address = value;

 
    VirtualProtect((void*)address, sizeof(BYTE), oldProtect, &oldProtect);
}
void WriteBytes(DWORD_PTR addressess[], BYTE values[], int count) {
    DWORD oldProtect;

    for (size_t i = 0; i < count; i++) {
        VirtualProtect((void*)addressess[i], sizeof(BYTE), PAGE_EXECUTE_READWRITE, &oldProtect);
        *(BYTE*)addressess[i] = values[i];
        VirtualProtect((void*)addressess[i], sizeof(BYTE), oldProtect, &oldProtect);
    }
}

void ApplyGraphics(DWORD_PTR baseAddress) {

    DWORD_PTR hookAddress = baseAddress + 0x169F2CD;

    if (ng2Shine) {
        WriteByte(hookAddress, 0xF8);
        return;
    }
    WriteByte(hookAddress, 0xF9);
}
void ApplyGameplay(DWORD_PTR baseAddress) {
    DWORD_PTR hookAddress = baseAddress + 0xF44E07;

    if (ultimateNinja) {
        WriteByte(hookAddress, 0x77);
        return;
    }
    WriteByte(hookAddress, 0x76);
}
void ApplyHelpers(DWORD_PTR baseAddress)
{
    DWORD_PTR hookAddress = baseAddress + 0x134F53B;

    if (noClip) {
        WriteByte(hookAddress, 0x90);
        WriteByte(hookAddress + 0x01, 0x90);
        WriteByte(hookAddress + 0x02, 0x90);
        WriteByte(hookAddress + 0x03, 0x90);
    }
    else {
        WriteByte(hookAddress, 0x0F);
        WriteByte(hookAddress + 0x01, 0xB6);
        WriteByte(hookAddress + 0x02, 0x04);
        WriteByte(hookAddress + 0x03, 0x01);
    }

    hookAddress = baseAddress + 0xF65476;

    if (freezeEnemies) {
        WriteByte(hookAddress, 0x90);
        WriteByte(hookAddress + 0x01, 0x90);
        WriteByte(hookAddress + 0x02, 0x90);
        WriteByte(hookAddress + 0x03, 0x90);
        WriteByte(hookAddress + 0x04, 0x90);
        WriteByte(hookAddress + 0x05, 0x90);
        WriteByte(hookAddress + 0x06, 0x90);
        WriteByte(hookAddress + 0x07, 0x90);
    }
    else {
        WriteByte(hookAddress, 0x41);
        WriteByte(hookAddress + 0x01, 0xFF);
        WriteByte(hookAddress + 0x02, 0x94);
        WriteByte(hookAddress + 0x03, 0xC4);
        WriteByte(hookAddress + 0x04, 0xE0);
        WriteByte(hookAddress + 0x05, 0x99);
        WriteByte(hookAddress + 0x06, 0x7D);
        WriteByte(hookAddress + 0x07, 0x01);
    }

    hookAddress = baseAddress + 0x1414C62;

    if (disableDelimb) {
        WriteByte(hookAddress, 0xEB);
    }
    else {
        WriteByte(hookAddress, 0x77);
    }

    hookAddress = baseAddress + 0xF29267;

    if (disableEssence) {
        WriteByte(hookAddress, 0x90);
        WriteByte(hookAddress + 0x01, 0x90);
        WriteByte(hookAddress + 0x02, 0x90);
        WriteByte(hookAddress + 0x03, 0x90);
        WriteByte(hookAddress + 0x04, 0x90);
    }
    else {
        WriteByte(hookAddress, 0xE8);
        WriteByte(hookAddress + 0x01, 0x74);
        WriteByte(hookAddress + 0x02, 0xBF);
        WriteByte(hookAddress + 0x03, 0x56);
        WriteByte(hookAddress + 0x04, 0x00);
    }

    hookAddress = baseAddress + 0x13412B9;

    if (windowAlwaysReadInputs) {
        WriteByte(hookAddress, 0x90);
        WriteByte(hookAddress + 0x01, 0x90);
    }
    else {
        WriteByte(hookAddress, 0x8B);
        WriteByte(hookAddress + 0x01, 0xCF);

    }
}

void ApplyDanger(DWORD_PTR baseAddress) {

    DWORD_PTR hookAddress = baseAddress + 0x160B22A;

    if (instantResume) {
        WriteByte(hookAddress, 0x0E);
        return;
        
    }
    WriteByte(hookAddress, 0x03);
}

void ApplyEffects(DWORD_PTR baseAddress) {

    //FRAME FREEZE/JUDDER
    DWORD_PTR hookAddress = baseAddress + 0x1457F73;

    if (microStutter > 0x03) {
        microStutter = 0x03;
    }
    WriteByte(hookAddress, microStutter);


   
    //BLUR EFFECT WHEN OPENING MENU
    hookAddress = baseAddress + 0x13D0CC2;

    if (quickSelectBlur) {
        WriteByte(hookAddress, 0x89);
        WriteByte(hookAddress + 0x01, 0x9C);
        WriteByte(hookAddress + 0x02, 0x24);
        WriteByte(hookAddress + 0x03, 0xB4);
        WriteByte(hookAddress + 0x04, 0x00);
        WriteByte(hookAddress + 0x05, 0x00);
        WriteByte(hookAddress + 0x06, 0x00);
    }
    else {
        WriteByte(hookAddress, 0x31);
        WriteByte(hookAddress + 0x01, 0xDB);
        WriteByte(hookAddress + 0x03, 0x90);
        WriteByte(hookAddress + 0x04, 0x90);
        WriteByte(hookAddress + 0x05, 0x90);
        WriteByte(hookAddress + 0x06, 0x90);
        WriteByte(hookAddress + 0x07, 0x90);
    }

    //ANIMATION SMOOTHING
    hookAddress = baseAddress + 0xFC32B1;

    if (animationSmoothing) {
        WriteByte(hookAddress, 0xEB);

    }
    else {
        WriteByte(hookAddress, 0x75);
    }
    
}

void ApplyInterFace(DWORD_PTR baseAddress, BYTE currentMenu) {

    if (vibrantMainMenu && currentMenu <= 0x03) {
      
            WriteByte(baseAddress + vibrantMainMenuAddress[0], 0x74);
            WriteByte(baseAddress + vibrantMainMenuAddress[1], 0x9A);
            
        
    }
    else {
        WriteByte(baseAddress + vibrantMainMenuAddress[0], 0x75);
        WriteByte(baseAddress + vibrantMainMenuAddress[1], 0x7F);
    }
    //SAVE LAST FRAME
    DWORD_PTR hookAddress = baseAddress + 0x1E671D0;

    if (saveLastFrame) {
        WriteByte(hookAddress, 0x00);
    }


   
}


//JUNK HOOKING UNTIL ALL DATA IS PORTED - ADD LOGIC LATER
DWORD WINAPI MainThread(LPVOID param) {
    baseAddress = GetBaseAddress();
    int hookLength = 0;
    DWORD_PTR hookAddress = 0;

    int hookCount = sizeof(hooks) / sizeof(HookInfo);
    ApplyHooks(hooks, hookCount, baseAddress);

    LoadConfig();
 

  

   

   

  
    




    DWORD_PTR nopeAddy = baseAddress + 0xF7363A;

    NopMemory((void*)nopeAddy, 2);

    nopeAddy = baseAddress + 0xF7363C;

    NopMemory((void*)nopeAddy, 2);

    hookAddress = baseAddress + 0x1399FA7;
   
    //IS ACCURACY
    WriteByte(hookAddress, 0xEB);

  

   

    //REHP (THIS SEEMS TO CHECK IF PLAYING STORY OR NOT)
    hookAddress = baseAddress + 0x15D1618;
    WriteByte(hookAddress, 0xEB);

   




  

    //INJECT AIDODGE
    hookLength = 16;

    hookAddress = baseAddress + 0xF48C1D;

    returnInjectAIDodge = hookAddress + hookLength;
    returnInjectAIDodgeCMP = baseAddress + 0xF48DD8;
    returnInjectAIDodgePAddress = baseAddress + 0x2F78B10;
    returnInjectAIDodgeCan = baseAddress + 0xF48E59;

    //Hook((void*)hookAddress, InjectAIDodge, hookLength);

    //GUIL/IZUNA DMG
    hookLength = 21;

    hookAddress = baseAddress + 0xF34B15;
    returnInjectGuilIzunaDmgJbe = baseAddress + 0xF34BE8;

    returnInjectGuilIzunaDmg = hookAddress + hookLength;
    //Hook((void*)hookAddress, InjectGuilIzunaDmg, hookLength);

    

    //WEAPON UPGRADE ESS COST CHECK
    hookLength = 16;

    hookAddress = baseAddress + 0x13D2BFE;

    returnInjectWeaponUpgrade = hookAddress + hookLength;
    returnInjectWeaponUpgradeDontAllow = baseAddress + 0x13D2DAD;

    //Hook((void*)hookAddress, InjectWeaponUpgrade, hookLength);

   

    //FIX SCYTHE WALL JUMP Y
    hookLength = 17;

    hookAddress = baseAddress + 0xF72EC9;

    returnInjectScytheDelimb = hookAddress + hookLength;
    returnInjectScytheDelimbAddress = baseAddress + 0xF72F57;

    //Hook((void*)hookAddress, InjectScytheDelimb, hookLength);

    //FREE IZUNA CAM
    hookLength = 14;

    hookAddress = baseAddress + 0xFD5F21;

    returnInjectFreeCam = hookAddress + hookLength;
    returnInjectFreeCamCall = baseAddress + 0xFD5F34;
    

    //Hook((void*)hookAddress, InjectFreeCam, hookLength);

    //REHP
    hookLength = 16;

    hookAddress = baseAddress + 0x15D9AE9;

    returnInjectREHP = hookAddress + hookLength;

    //Hook((void*)hookAddress, InjectREHP, hookLength);

   // AIR IFRAME
   /* hookLength = 17;

    hookAddress = baseAddress + 0xF48AB0;

    returnInjectAirFrame = hookAddress + hookLength;*/



   /* Hook((void*)hookAddress, InjectAirFrame, hookLength);*/

  

    //SPECIAL EFFECTS
   /* hookLength = 17;
    hookAddress = baseAddress + 0x1031CC4;*/
    injectSpecialEffectsJa += baseAddress;
    /*returnInjectSpecialEffects = hookAddress + hookLength;*/
    
    //Hook((void*)hookAddress, InjectSpecialEffects, hookLength);

     //SPECIAL EFFECTS APPLY (I.E WHITE)
 /*   hookLength = 19;
    hookAddress = baseAddress + 0xF2E6CC;*/
    injectSpecialEffectsApplyCMP += baseAddress;
    injectSpecialEffectsJNE += baseAddress;
    /*returnInjectSpecialEffectsApply = hookAddress + hookLength;*/


    //ATTACKCANCEL
    /*attackCancelJNE += baseAddress;
    attackCancelMOV += baseAddress;
    attackCancelMOVRSI += baseAddress;*/
   /* hookLength = 25;
    hookAddress = baseAddress + 0xF567C0;
    attackCancelJNE += baseAddress;
    attackCancelMOV += baseAddress;
    attackCancelMOVRSI += baseAddress;
    returnInjectAttackCancel = hookAddress + hookLength;
    
    HookNew((void*)hookAddress, InjectAttackCancel, hookLength);*/




    ApplyEffects(baseAddress);

   
   


    //////MAIN MENU MORE GREY
    //hookAddress = baseAddress + 0xDCC255;
    //WriteByte(hookAddress, 0x90);
    //hookAddress = baseAddress + 0xDCC269;
    //Hook((void*)hookAddress, InjectAlpha, hookLength);

    //WriteByte(hookAddress + 0x01, 0x90);
    //hookAddress = baseAddress + 0xDCC269;
    //WriteByte(hookAddress, 0x92);
    




    ////INJECT DELIMB1
    //hookLength = 17;

    //hookAddress = baseAddress + 0x148D2FD;

    //returnInjectEntData = hookAddress + hookLength;

    //Hook((void*)hookAddress, InjectEntData, hookLength);

    ////INJECT DELIMB2
    //hookLength = 14;

    //hookAddress = baseAddress + 0xF89FAB;

    //returnInjectEntDataAnim = hookAddress + hookLength;

    //Hook((void*)hookAddress, InjectEntDataAnim, hookLength);

    //INJECT DELIMB3 (SCYTHE FIX)
   /* hookLength = 15;

    hookAddress = baseAddress + 0xF72EC9;

    returnInjectEntDataAnim = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectEntDataAnim, hookLength);*/

  

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
        0x1D9F5C8
    };
    float masterDamageNewVals[] = {
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f,
        1.80f
    };

    

   


    WriteFloats(baseAddress, masterDamageOffsets, masterDamageNewVals, 16);

   /* std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribution(1, 100);*/
   
   ApplyGraphics(baseAddress);
   ApplyDanger(baseAddress);
   ApplyHelpers(baseAddress);
   ApplyInterFace(baseAddress, 0x00);
   ApplyGameplay(baseAddress);
    


    while (true) {
        
        BYTE currentDiff = *(BYTE*)(baseAddress + 0x35C4218);
        WORD playerHP = *(WORD*)(baseAddress + 0x319CBB4);
        BYTE currentMenu = *(BYTE*)(baseAddress + menuIDOffset);
        
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
            cBattleRespawnCount7 = 0;
            cBattleRespawnCount8 = 0;
            cBattleRespawnCount9 = 0;
            cBattleRespawnCount10 = 0;
            //SKIP 11 12
            cBattleRespawnCount13 = 0;
            cBattleRespawnCount14 = 0;
            cBattleRespawnCount15 = 0;
            cBattleRespawnCount16 = 0;

            cDeleteEnemy = 0;
            counter = 0;
            entDied = 0;

            canSpawn = 0;
            canspawn2 = 0;

            minimumspawn = 0;
            maximumspawn = 0;
            chpstage = 0;

            striggerOffset = 0;

            ent = 0;
            enthitadd = 0;
            enthitadd2 = 0;

            //WATER DRAGON CAN PERFORM WATER ATTACKS
            canWaterDragonAttacks = false;
            canWaterDragonOT = false;

            inventoryCCNew = false;

            canHalfCut = false;

            canUpgradeWep = false;

            ApplyInterFace(baseAddress, currentMenu);

            switch (currentDiff) {
            case 4: {
                ClearTracking();
                ClearTrackingUN();
                break;
            }
            case 2: {
                ClearTrackingWarrior();
                break;
            }
            case 3: {
                ClearTrackingMN();
                break;
            }
            default:
                ClearTracking();
                ClearTrackingWarrior();
                ClearTrackingMN();
                ClearTrackingUN();
                break;
            }
        }
    
            
       
        
    

        if (diffInjected != currentDiff) {
            switch (currentDiff) {
            case 4: {
                diffInjected = currentDiff;

                if (ultimateNinja) {
                    hookLength = 16;
                    hookAddress = baseAddress + 0x1607CA4;
                    returnInjectCBattle = hookAddress + hookLength;

                    Hook((void*)hookAddress, InjectCBattleUN, hookLength);

                    // INJECTCOORDS
                    hookLength = 17;
                    hookAddress = baseAddress + 0x161855E;
                    returnInjectCoords = hookAddress + hookLength;
                    Hook((void*)hookAddress, InjectCoordsUN, hookLength);

                    // INJECTA
                    hookLength = 18;
                    hookAddress = baseAddress + 0x161A451;
                    returnInjectA = hookAddress + hookLength;
                    Hook((void*)hookAddress, InjectAUN, hookLength);



                    // INJECTDONTDISABLEBATTLE
                    hookLength = 15;
                    hookAddress = baseAddress + 0x160C54E;
                    returnInjectDontDisableBattle = hookAddress + hookLength;
                    Hook((void*)hookAddress, InjectDontDisableBattle, hookLength);
                    break;
                }

                
                //REGULAR MASTER
                // INJECTCBATTLE
                hookLength = 16;
                hookAddress = baseAddress + 0x1607CA4;
                returnInjectCBattle = hookAddress + hookLength;
             
                Hook((void*)hookAddress, InjectCBattle, hookLength);

                // INJECTCOORDS
                hookLength = 17;
                hookAddress = baseAddress + 0x161855E;
                returnInjectCoords = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectCoords, hookLength);

                // INJECTA
                hookLength = 18;
                hookAddress = baseAddress + 0x161A451;
                returnInjectA = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectAMaster, hookLength);

               

                // INJECTDONTDISABLEBATTLE
                hookLength = 15;
                hookAddress = baseAddress + 0x160C54E;
                returnInjectDontDisableBattle = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectDontDisableBattle, hookLength);

                break;


            }
                  //WARRIROR

            case 2: {
                diffInjected = currentDiff;

              /* std::wstring message2 = L"GAME DIFFICULTY: " + byteToWString(currentDiff);
                std::wstring message = L"INJECTING NEW DIFFICULTY: " + byteToWString(diffInjected);


                MessageBox(NULL, message.c_str(), L"Debug Info", MB_OK);
                MessageBox(NULL, message2.c_str(), L"Debug Info", MB_OK);*/


                // INJECTCBATTLE
                hookLength = 16;
                hookAddress = baseAddress + 0x1607CA4;
                returnInjectCBattle = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectCBattleWarrior, hookLength);


                // INJECTCOORDS
                hookLength = 17;
                hookAddress = baseAddress + 0x161855E;
                returnInjectCoords = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectCoordsWarrior, hookLength);

                // INJECTA
                hookLength = 18;
                hookAddress = baseAddress + 0x161A451;
                returnInjectA = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectAWarrior, hookLength);
                 break;
            }
            case 3: {
                diffInjected = currentDiff;

                /* std::wstring message2 = L"GAME DIFFICULTY: " + byteToWString(currentDiff);
                  std::wstring message = L"INJECTING NEW DIFFICULTY: " + byteToWString(diffInjected);


                  MessageBox(NULL, message.c_str(), L"Debug Info", MB_OK);
                  MessageBox(NULL, message2.c_str(), L"Debug Info", MB_OK);*/


                  // INJECTCBATTLE
                hookLength = 16;
                hookAddress = baseAddress + 0x1607CA4;
                returnInjectCBattle = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectCBattleMN, hookLength);


                // INJECTCOORDS
                hookLength = 17;
                hookAddress = baseAddress + 0x161855E;
                returnInjectCoords = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectCoordsMN, hookLength);

               
                // INJECTA
                hookLength = 18;
                hookAddress = baseAddress + 0x161A451;
                returnInjectA = hookAddress + hookLength;
                Hook((void*)hookAddress, InjectAMN, hookLength);
                break;
            }
            }
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            
           
            //MessageBoxA(NULL,"Reloading CONFIG","NGS2B",NULL);
            LoadConfig();
            ApplyGraphics(baseAddress);
            ApplyEffects(baseAddress);
            ApplyDanger(baseAddress);
            ApplyHelpers(baseAddress);
            ApplyGameplay(baseAddress);
           
           

            
        }
               
        
        Sleep(100);
    

            
            
           
        }
     
        
        return 0;
}





    /*GAJA
    hookLength = 15;

    hookAddress = baseAddress + 0xF48FB8;

    returnInjectGaja = hookAddress + hookLength;

    Hook((void*)hookAddress, InjectGaja, hookLength);*/

    //FreeLibraryAndExitThread((HMODULE)param, 0);
    
   

   


   
    
    
    //FreeLibraryAndExitThread((HMODULE)param, 0);

  

bool WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
    
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, MainThread, hModule, 0, 0);
        break;

    }
   
    return true;
}


