
#include "pch.h"
#include "src/spawn/masterninja.h"
#include <Windows.h>
#include "src/spawn/coordinates.h"
#include "src/spawn/globals.h"
#include <vector>


//CHAPTER 1
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
extern "C" BattleTracker masterninjabtlCH1Tracker[] = {
    
        {0x0000, 0x2DF0057}, // START BATTLE 01 - RIGHT AFTER RED GATE DOOR
        {0x0000, 0x2DF0057}, // START BATTLE 02 - AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
        {0x0000, 0x2DF0057}, // START BATTLE 03 - AFTER 1st SAVE - AFTER CHEST JUMP DOWN
        {0x0000, 0x2DF0057}, // START BATTLE 04 - AFTER 1st SAVE - 2nd CHEST
        {0x0000, 0x2E00E0F}, // START BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
        {0x0000, 0x2E0785F}, // START BATTLE 06 - After Bridge Before Buddah Cutscene
        {0x0000, 0x2E0785F}, // START BATTLE 07 - FIRST LEDGE RUN AFTER BUDDAH CUTSCENE
        {0x0000, 0x2E51D80}  // START BATTLE 08 - GLASS BREAK IS NINJA BY SAVE
};
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
extern "C" SpawnCoords masterninjabtlCH1SpawnCoords[] = {
        // CH1 Start
        // START - AFTER MURAMASA CUTSCENE (RED GATE) NG2 ARCHER PLACEMENT
        { -11.19219685f, 4.00f, 11.25521278f, 0.0f },
        { 13.00108051f, 4.00f, -17.73134232f, 0.00f },
        { 16.07675171f, -1.0f, -29.52827263f, 0.00f },
        { 19.12763214f, -1.5f, -37.46701431f, 0.00f },

        // START - AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
        { -56.49800873f, -1.699999809f, 31.9538784f, 0.0f },

        // START - AFTER 1st SAVE - 2nd CHEST
        { 42.06149673f, -10.60000134f, -72.02714539f, 0.0f },
        { 42.44620132f, -10.60000038f, -53.21555328f, 0.0f },
        { 32.36677933f, -10.59999943f, -71.96556091f, 0.0f },

        // START - BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
        { 72.96051025f, -4.500015736f, -116.6359253f, 0.0f },

        // START - BATTLE 06 - After Bridge Before Buddah Cutscene (Grey Ninja)
        { 125.3550034f, 18.00f, -109.2900772f, 0.0f },
        { 122.9854355f, 18.00f, -111.8772812f, 0.0f },

        // START - BATTLE 06 - After Bridge Before Buddah Cutscene (IS Ninja)
        { 155.3605957f, 10.0f, -112.2211304f, 0.0f },

        // BATTLE 07 - FIRST LEDGE RUN ARCHER AFTER CUTSCENE
        { 72.12442017f, 3.00f, -99.09088898f, 0.0f },
        { 68.19638062f, 3.00f, -97.50299835f, 0.0f },
        { 68.28087616f, 3.00f, -100.6895676f, 0.0f },

        // BATTLE 08 - IS NINJA GLASS BREAK
        { -1.88998425f, 200.0f, -8.786634445f, 0.0f },
        { -1.88998425f, 200.0f, -8.786634445f, 0.0f } // Assuming this is a duplicate of the previous entry
};

extern "C" ChapterData masterNinjaCH1CoordData = {
	masterninjabtlCH1BattleCoords,
	masterninjabtlCH1Tracker,
	masterninjabtlCH1DistanceThreshold,
};
size_t battleCoordsSize = sizeof(masterninjabtlCH1BattleCoords);
size_t trackerSize = sizeof(masterninjabtlCH1Tracker);

void  __attribute__((naked))InjectCoords() {

    __asm__ volatile(".intel_syntax noprefix;"
        //ORIGINAL CODE
        "mov dword ptr [rbp-0x7D],0x00000000;"
        "movaps xmm0,[rsp+0x20];"
        "movdqu [r10],xmm0;"
        "push rax;"
        "push rbx;"
        "push rcx;"
        "push rdx;"
        "mov rbx, qword ptr [rip+baseAddress];"
        "mov rdx, [rip+scounter];"
        //CHAPTER 1
        "mov rax,[rip + masterninjabtlCH1SpawnCoords];"
        "mov rcx,[rip + masterninjabtlCH1Tracker];"
        "cmp byte ptr [rbx+0x35C421A],0x06;"
        "je coordsCH01;"
        "jmp codecoords;"
    //CHAPTER 1
    "coordsCH01:"
        "cmp bx,0xFE68;"
        "je coordsCH0101;"
        "cmp bx,0x0C20;"
        "je coordsCH0101;"
        "cmp bx,0x7670;"
        "je coordsCH0101;"
        "cmp bx,0x1B90;"
        "je coordsCH0101;"
        "jmp codecoords;"
    "coordsCH0101:"
        //BATTLE 8
        "cmp dword ptr [rcx + 0x0E * 0x4], 0x0101;"
        "je coordsCH0107;"
        //BATTLE 7
        "cmp dword ptr [rcx + 0x0C * 0x4], 0x0101;"
        "je coordsCH0106;"
        //BATTLE 6
        "cmp dword ptr [rcx + 0x0A * 0x4], 0x0101;"
        "je coordsCH0105;"
        //BATTLE 5
        "cmp dword ptr [rcx + 0x08 * 0x4], 0x0101;"
        "je coordsCH0104;"
        //BATTLE 4
        "cmp dword ptr [rcx + 0x06 * 0x4], 0x0101;"
        "je coordsCH0103;"
        //BATTLE 3
        "cmp dword ptr [rcx + 0x04 * 0x4], 0x0101;"
        "je codecoords;"
        //BATTLE 2
        "cmp dword ptr [rcx + 0x02 * 0x4], 0x0101;"
        "je coordsCH0102;"
        //BATTLE 1
        "cmp dword ptr [rcx], 0x0101;"
        "jne codecoords;"
        "movaps xmm10, [rax];"
        "cmp byte ptr[rdx], 0x01;"
        "je setCoords;"
        "movaps xmm10, [rax + 0x04 * 0x4];"
        "cmp byte ptr[rdx], 0x02;"
        "je setCoords;"
        "movaps xmm10, [rax + 0x08 * 0x4];"
        "cmp byte ptr[rdx], 0x03;"
        "je setCoords;"
        "movaps xmm10, [rax + 0x0C * 0x4];"
        "cmp byte ptr[rdx], 0x04;"
        "je setCoords;"
        "jmp codecoords;"
        //AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
   "coordsCH0102:"
        "movaps xmm10,[rax+0x10*0x4];"
        "jmp setCoords;"
        //START - AFTER 1st SAVE - 2nd CHEST
    "coordsCH0103:"
        "movaps xmm10,[rax+0x14*0x4];"
        "cmp byte ptr [rdx],0x01;"
        "jle setCoords;"
        "movaps xmm10,[rax+0x18*0x4];"
        "cmp byte ptr [rdx],0x02;"
        "jle setCoords;"
        "movaps xmm10,[rax+0x1C*0x4];"
        "cmp byte ptr [rdx],0x05;"
        "jle setCoords;"
        "jmp codecoords;"
        //BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
    "coordsCH0104:"
        "movaps xmm10,[rax+0x20*0x4];"
        "jmp setCoords;"
        //BATTLE 06 - BATTLE 06
    "coordsCH0105:"
        "movaps xmm10,[rax+0x24*0x4];"
        "cmp byte ptr [rdx],0x02;"
        "jle setCoords;"
        "movaps xmm10,[rax+0x28*0x4];"
        "cmp byte ptr [rdx],0x04;"
        "jle setCoords;"
        "movaps xmm10,[rax+0x2C*0x4];"
        "cmp byte ptr [rdx],0x06;"
        "jle setCoords;"
        "jmp codecoords;"
        //BATTLE 07
    "coordsCH0106:"
        "movaps xmm10,[rax+0x30*0x4];"
        "cmp byte ptr [rdx],0x01;"
        "jle setCoords;"
        "movaps xmm10,[rax+0x34*0x4];"
        "cmp byte ptr [rdx],0x02;"
        "jle setCoords;"
        "movaps xmm10,[rax+0x38*0x4];"
        "cmp byte ptr [rdx],0x03;"
        "jle setCoords;"
        "jmp codecoords;"
        //BATTLE 08 - GLASS BREAK IS NINJA
        "coordsCH0107:"
        "movaps xmm10,[rax+0x3C*0x4];"
        "jmp setCoords;"
    "setCoords:"
        "movaps [rbx],xmm10;"
    "codecoords:"
        "pop rdx;"
        "pop rcx;"
        "pop rbx;"
        "pop rax;"
        "jmp qword ptr [rip + returnInjectCoords];"

        );
}






//1607CA4 319CBB4
void __attribute__((naked)) InjectCBattle() {
   
    //RAX = R8, RBX = R9
    //DONT ASK WHY I DIDN'T START WITH RAX/RBX - CE PORTING THINGS LoL
    __asm__ volatile(".intel_syntax noprefix;"
            "push rcx;"
            "push rdx;"
            "push rsi;"
            "push rdi;"
            "push rbp;"
            "push r8;"
            "push r9;"
            "xorps xmm10, xmm10;"
            "xor rbp,rbp;"
            "xor rsi,rsi;"
            "mov r8,[rip+masterNinjaCH1CoordData];"
            "mov r9, [rip+battleCoordsSize];"
            "add r9,r8;"
            "mov rdi, [rip+trackerSize];"
            "add rdi,r9;"
            "mov rcx,0x00;"
            "mov rdx,0x64;"
            "mov rsi, qword ptr [rip+baseAddress];"
            "cmp byte ptr [rsi+0x35C421A], 0x06; "
            "je cBtlLoopStart;"
            //CH2
            "jmp codecbattle;"
      "cBtlLoopStart:"
            "cmp rcx,rdx;"
            "ja codecbattle;"
       
            //DISTANCE THRESHOLD
            "movss xmm10,[rdi+rbp*4];"
            "inc rbp;"
            //X
            "movss xmm5,[r8+rcx*4];"
            "subss xmm5,[rsi+0x319BC88];"
            "mulss xmm5, xmm5;"
            //inc rcx;"
            //Y
            "add rcx,0x01;"
            "movss xmm6,[r8+rcx*4];"
            "subss xmm6, [rsi+0x319BC84];"
            "mulss xmm6,xmm6;"
            //Z
            //inc rcx
            "add rcx,0x01;"
            "movss xmm7,[r8+rcx*4];"
            "subss xmm7,[rsi+0x319BC80];"
            "mulss xmm7,xmm7;"
            "addss xmm5,xmm6;"
            "addss xmm5,xmm7;"
            "sub rcx,0x02;"
            "movss xmm9,xmm10;"
            "xorps xmm10,xmm10;"
            "comiss xmm5,xmm10;"
            "je codecbattle;"
            "comiss xmm5,xmm9;"
            "jbe cTriggerEvent;"
            "add rcx,0x03;"
            "cmp rcx,rdx;"
            "jl cBtlLoopStart;"
            "jmp codecbattle;"
      "cTriggerEvent:"
            "mov r8,rsi;"
            "xor rsi,rsi;"
            "xor rdx,rdx;"


            //CH2
            //cmp byte ptr [rip+baseAddress+35C421A],0x06
            //je cTriggerEventCH2f

            //CH3
            //cmp byte ptr [rip+baseAddress+35C421A],0x08
            //je cTriggerEventCH3f

            //CH1
            "cmp  rcx,0x00;"
            "je cTriggerEvent01;"

           "cmp rcx,0x03;"
            "je cTriggerEventsDisable;"

            "cmp rcx,0x03;"
            "je cTriggerEvent02;"

            "mov rdx,0x02;"

            "cmp rcx,0x09;"
            "je cTriggerEventsDisable;"

            "cmp rcx,0x0C;"
            "je cTriggerEvent03;"

            "mov rdx,0x04;"
            "cmp rcx,0x0F;"
            "je cTriggerEventsDisable;"

            "cmp rcx,0x12;"
            "je cTriggerEvent04;"

            "mov rdx,0x06;"
            "cmp rcx,0x15;"
            "je cTriggerEventsDisable;"


            "cmp rcx,0x18;"
            "je cTriggerEvent05;"

            "mov rdx,0x08;"
            "cmp rcx,0x1B;"
            "je cTriggerEventsDisable;"


            "cmp rcx,0x1E;"
            "je cTriggerEvent06;"

            "mov rdx,0x0A;"
            "cmp rcx,0x21;"
            "je cTriggerEventsDisable;"


            "cmp rcx,0x24;"
            "je cTriggerEvent07;"

            "mov rdx,0x0C;"
            "cmp rcx,0x27;"
            "je cTriggerEventsDisable;"

            "mov rdx,0x18;"
            "cmp rcx,0x2A;"
            "je cTriggerEvent08;"

            "mov rdx,0x0E;"
            "cmp rcx,0x2C;"
            "je cTriggerEventsDisable;"

            "jmp codecbattle;"

            //CHAPTER 1
     //RIGHT AFTER RED GATE  DOOR
        "cTriggerEvent01:"
            "cmp dword ptr [r9], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9], 0x0101;"
            "mov rcx, [r9 + 0x01 * 0x4];"
            "jmp cStartTriggerEvent;"
            //AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
        "cTriggerEvent02:"
            "cmp dword ptr [r9 + 0x02 * 0x4], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9 + 0x02 * 0x4], 0x0101;"
            "mov rcx, [r9 + 0x03 * 0x4];"
            "jmp cStartTriggerEvent;"
            //AFTER 1st SAVE - AFTER CHEST JUMP DOWN
         "cTriggerEvent03:"
            "cmp dword ptr [r9 + 0x04 * 0x4], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9 + 0x04 * 0x4], 0x0101;"
            "mov rcx, [r9 + 0x05 * 0x4];"
            "jmp cStartTriggerEvent;"
            //AFTER 1st SAVE - 2nd CHEST
         "cTriggerEvent04:"
            "cmp dword ptr [r9 + 0x06 * 0x4], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9 + 0x06 * 0x4], 0x0101;"
            "mov rcx, [r9 + 0x07 * 0x4];"
            "jmp cStartTriggerEvent;"
            //BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
         "cTriggerEvent05:"
            "cmp dword ptr [r9 + 0x08 * 0x4], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9 + 0x08 * 0x4], 0x0101;"
            "mov rcx, [r9 + 0x09 * 0x4];"
            "jmp cStartTriggerEvent;"
            //BATTLE 06 - IS BATTLE - BEFORE 2nd SAVE
         "cTriggerEvent06:"
            "cmp dword ptr [r9 + 0x0A * 0x4], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9 + 0x0A * 0x4], 0x0101;"
            "mov rcx, [r9 + 0x0B * 0x4];"
            "jmp cStartTriggerEvent;"
            //BATTLE 07 - FIRST LEDGE RUN AFTER BUDDAH CUTSCENE
         "cTriggerEvent07:"
            "cmp dword ptr [r9 + 0x0C * 0x4], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9 + 0x0C * 0x4], 0x0101;"
            "mov  rcx, [r9 + 0x0D * 0x4];"
            "jmp cStartTriggerEvent;"
            //BATTLE 08 - GLASS BREAK AFTER DOOR
        "cTriggerEvent08:"
            "cmp dword ptr [r9 + 0x0E * 0x4], 0x0000;"
            "jne codecbattle;"
            "mov dword ptr [r9 + 0x0E * 0x4], 0x0101;"
            "mov rcx, [r9 + 0x0F * 0x4];"
            "mov byte ptr[r8 + 0x2E51D80], 0x01;"
            "mov byte ptr[r8 + 0x2E51D82], 0x01;"
            "jmp codecbattle;"
            //CHAPTER 1 END
        "cTriggerEventsDisable:"
            "cmp rsi, rdx;"
            "ja codecbattle;"
            "mov dword ptr [r9 + rsi * 4], 0x0F0F;"
            "mov byte ptr[rip + scounter], 0x00;"
            "mov byte ptr[rip + cDeleteEnemy], 0x00;"
            "mov byte ptr[rip + cBattleRespawnCount], 0x00;"
            "add rsi, 0x02;"
            "jmp cTriggerEventsDisable;"
        "cStartTriggerEvent:"
            "mov rdi, 0x00000000FFFFFFFF;"
            "and rcx, rdi;"
            "add r8, rcx;"
            "mov dword ptr [r8], 0x01000100;"
            "jmp codecbattle;"
        "cStartTriggerEvent02:;"
            "mov rdi, 0x00000000FFFFFFFF;"
            "and rcx, rdi;"
            "add rax, rcx;"
            "mov byte ptr[rax], 01;"
            "mov byte ptr[rax + 02], 01;"
       "codecbattle:"//codecbattle
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




