#include "pch.h"
#include "src\spawn\mentor.h"

//1607CA4 319CBB4
void __attribute__((naked)) InjectCBattleMN() {

    //RAX = R8, RBX = R9
    //DONT ASK WHY I DIDN'T START WITH RAX/RBX - CE PORTING THINGS LoL
    __asm__ volatile(".intel_syntax noprefix;"
        //ORIGINAL CODE   
        "mov edi,eax;"
        "mov [rbx],edi;"
        "mov eax,edi;"
        "mov rdi, [rsp + 0x40];"
        "mov rsi, [rsp + 0x38];"
        "jmp qword ptr [rip + returnInjectCBattle];"


        );
}


