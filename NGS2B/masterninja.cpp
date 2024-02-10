
#include "pch.h"
#include "src/spawn/masterninja.h"
#include <Windows.h>
#include "src/spawn/coordinates.h"
#include "src/spawn/globals.h"
#include <vector>


//CUSTOM SPAWN TRIGGER POINTS
//TRIGGERS CUSTOM SPAWNS IF PLAYER IS NEAR THESE COORDINATES (BASED ON DISTANCE THRESHOLD SET)
//AND ALSO HOLDS COORDINATES FOR WHEN TO DISABLE CUSTOM SPAWNS TO PREVENT INFINITE SPAWNS I.E: REACHING
//THE FIRST SAVE STATUE WILL DISABLE ALL PREVIOUS CUSTOM SPAWN UP UNTIL THE SAVE INCLUDING IF YOU SAVE AND DIE SINCE THESE
//ARE ESSENTIALLY TRIGGER ZONES
//RENAME TO masterninjabtlCH1TriggerCoords - not sure why i set it to battle coords lol
BattleCoords masterninjabtlCH1BattleCoords[] = {

       {-4.278018951f, 3.77045989f, 9.020205498f},   // START BATTLE 01
        {-39.91788101f, -1.499999881f, 21.50466156f}, // First Save Point
        {-49.01662445f, -1.499999881f, 33.85672379f}, // START BATTLE 02
        {-51.74726868f, -1.499999881f, 35.24174118f}, // BATTLE 02 DISABLE
        {-62.02156448f, -16.95000076f, 20.7978096f},  // START BATTLE 03
        {-47.44185638f, -13.80000019f, 33.14215469f}, // BATTLE 03 DISABLE
        {-58.54923248f, -10.60000134f, 40.36560059f}, // START BATTLE 04
        {-81.10764313f, -7.499994755f, 24.86401367f}, // BATTLE 04 DISABLE
        {-121.6169052f, -4.500015736f, 61.81223297f}, // BATTLE 05
        {-128.2968445f, -4.500015736f, 85.37071991f}, // BATTLE 05 DISABLE
        {-110.43430339f, 8.976043701f, 122.7386932f}, // BATTLE 06
        {-97.55497742f, 1.849431992f, 141.0948486f},   // BATTLE 06 DISABLE
        {-99.24944305f, -5.399999142f, 96.4569931f},  // BATTLE 07
        {-86.55921173f, -4.129928112f, 39.43626785f}, // BATTLE 07 DISABLE
        {9.224415779f, 200.0f, -4.210312366f},        // BATTLE 08
        {-17.29926109f, 204.0f, -22.24618149f}        // BATTLE 08 DISABLEs
};
//KEEPS TRACK OF CUSTOM SPAWNS NOT ORIGINALLY IN THE GAME
BattleTracker masterninjabtlCH1Tracker[] = {
    
        {0x0000, 0x2DF0057}, // START BATTLE 01 - RIGHT AFTER RED GATE DOOR
        {0x0000, 0x2DF0057}, // START BATTLE 02 - AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
        {0x0000, 0x2DF0057}, // START BATTLE 03 - AFTER 1st SAVE - AFTER CHEST JUMP DOWN
        {0x0000, 0x2DF0057}, // START BATTLE 04 - AFTER 1st SAVE - 2nd CHEST
        {0x0000, 0x2E00E0F}, // START BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
        {0x0000, 0x2E0785F}, // START BATTLE 06 - After Bridge Before Buddah Cutscene
        {0x0000, 0x2E0785F}, // START BATTLE 07 - FIRST LEDGE RUN AFTER BUDDAH CUTSCENE
        {0x0000, 0x2E51D80}  // START BATTLE 08 - GLASS BREAK IS NINJA BY SAVE
};

//DISTANCE BEFORE CUSTOM SPAWN IS TRIGGERED
//TRIGGER THRESHOLD INCREASES THE LOWER THE VALUE
DistanceThreshold masterninjabtlCH1DistanceThreshold[] = {
        
        {20.00f}, // START BATTLE 01 - RIGHT AFTER RED GATE DOOR
        {20.00f}, // First Save Point Middle Of Door - Trigger to turn off the above battle point
        {20.00f}, // START BATTLE 02 - AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
        {20.00f}, // BATTLE 02 DISABLE - 1st CHEST AREA
        {20.00f}, // START BATTLE 03 - AFTER 1st SAVE - AFTER CHEST JUMP DOWN
        {20.00f}, // BATTLE 03 DISABLE - TOP OF FIRST FLIGHT OF STAIRS
        {20.00f}, // START BATTLE 04 - AFTER 1st SAVE - 2nd CHEST
        {20.00f}, // BATTLE 04 DISABLE - AFTER 1st SAVE - 2nd CHEST - FIRST METAL DOOR
        {50.00f}, // BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
        {20.00f}, // BATTLE 05 DISABLE - NEXT TO SECOND SAVE
        {500.00f}, // BATTLE 06 - AFTER BRIDGE BEFORE BUDDAH CUTSCENE
        {20.00f}, // BATTLE 06 DISABLE (RIGHT BEFORE BUDDAH CUTSCENE) - AFTER BRIDGE BEFORE BUDDAH CUTSCENE
        {50.00f}, // BATTLE 7 - AFTER BUDDAH CUTSCENE FOR LEDGE RUN
        {20.00f}, // BATTLE 7 - DISABLE
        {20.00f}, // BATTLE 8 - GLASS BREAK IS NINJA AFTER DOOR
        {20.00f}  // BATTLE 8 - DISABLE
    };


ChapterData masterNinjaCH1CoordData = {
	masterninjabtlCH1BattleCoords,
	masterninjabtlCH1Tracker,
	masterninjabtlCH1DistanceThreshold,
};

extern "C" DWORD_PTR returnInjectCBattle = 0;

//CURRENT WORK AS OF 2024-02-10
void __attribute__((naked)) InjectCBattle() {
       

    //DONT ASK WHY I DIDN'T START WITH RAX/RBX - CE PORTING THINGS LoL
    __asm(".intel_syntax noprefix;"
        "push rcx;"
        "push rdx;"
        "push rsi;"
        "push rdi;"
        "push rbp;"
        "push r8;"
        "push r9;"
        "xorps xmm10, xmm10;"
         //CH1
        "lea r8,[rip+masterNinjaCH1CoordData];"
        "add r8,0x8;"
        "mov r9,r8;"
        "add r8,0x8;"
        "mov rdi,r8;"
        "sub r8,0x10;"
        "lea rsi, qword ptr [rip+baseAddress];"
        "cmp byte ptr [rsi+0x35C421A],0x06;"
        "je 1f;"
        "jmp 2f;"
       "1:"
        "cmp rcx,rdx;"
        "ja 2f;"
       
        //DISTANCE THRESHOLD
         "movss xmm10,[rdi+rbp*4];"
        "inc rbp;"
        //X
        "movss xmm5,[r8+rcx*4];"
        "subss xmm5,[rip+baseAddress+0x319BC88];"
        "mulss xmm5, xmm5;"
        //inc rcx;"
        //Y
        "add rcx,0x01;"
        "movss xmm6,[r8+rcx*4];"
        "subss xmm6, [rip+baseAddress+0x319BC84];"
        "mulss xmm6,xmm6;"
        //Z
        //inc rcx
        "add rcx,0x01;"
        "movss xmm7,[r8+rcx*4];"
        "subss xmm7,[rip+baseAddress+0x319BC80];"
        "mulss xmm7,xmm7;"
        "addss xmm5,xmm6;"
        "addss xmm5,xmm7;"
        "sub rcx,0x02;"
        "movss xmm9,xmm10;"
        "comiss xmm5,xmm9;"
        "jbe 3f;"
        "add rcx,0x03;"
        "cmp rcx,rdx;"
        "jl 1b;"
        "jmp 2f;"
       "3:"//cTriggerEvent:
        "xor rsi,rsi;"
        "xor rdx,rdx;"
        "lea rax, qword ptr [rip+baseAddress];"

        //CH2
        //cmp byte ptr [rip+baseAddress+35C421A],0x06
        //je cTriggerEventCH2f

        //CH3
        //cmp byte ptr [rip+baseAddress+35C421A],0x08
        //je cTriggerEventCH3f

        //CH1
      /*  "cmp rcx,0x00;"
        "je cTriggerEvent01f;"*/

        /*"cmp rcx,0x03;"
        "je cTriggerEventsDisablef;"

        "cmp rcx,0x03;"
        "je cTriggerEvent02f;"

        "mov rdx,0x02;"

        "cmp rcx,0x09;"
        "je cTriggerEventsDisablef;"

        "cmp rcx,0x0C;"
        "je cTriggerEvent03f;"

        "mov rdx,0x04;"
        "cmp rcx,0x0F;"
        "je cTriggerEventsDisablef;"

        "cmp rcx,0x12;"
        "je cTriggerEvent04f;"

        "mov rdx,0x06;"
        "cmp rcx,0x15;"
        "je cTriggerEventsDisablef;"


        "cmp rcx,0x18;"
        "je cTriggerEvent05f;"

        "mov rdx,0x08;"
        "cmp rcx,0x1B;"
        "je cTriggerEventsDisablef;"


        "cmp rcx,0x1E;"
        "je cTriggerEvent06f;"

        "mov rdx,0x0A;"
        "cmp rcx,0x21;"
        "je cTriggerEventsDisablef;"


        "cmp rcx,0x24;"
        "je cTriggerEvent07f;"

        "mov rdx,0x0C;"
        "cmp rcx,0x27;"
        "je cTriggerEventsDisablef;"

        "mov rdx,0x18;"
        "cmp rcx,0x2A;"
        "je cTriggerEvent08f;"

        "mov rdx,0x0E;"
        "cmp rcx,0x2C;"
        "je cTriggerEventsDisablef;"*/

        "jmp 2f;"
            
       "2:"//codecbattle
        "pop r9;"
        "pop r8;"
        "pop rbp;"
        "pop rdi;"
        "pop rsi;"
        "pop rdx;"
        "pop rcx;"
                  
       
        //ORIGINAL CODE   
        "mov edi,eax;"
        "mov [rbx],edi;"
        "mov eax,edi;"
        "mov rdi, [rsp + 0x40];"
        "mov rsi, [rsp + 0x38];"
        "jmp qword ptr [rip + returnInjectCBattle];"

                
      );
    }



