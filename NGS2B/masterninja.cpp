
#include "pch.h"
#include "src/spawn/masterninja.h"
#include <Windows.h>
#include "src/spawn/coordinates.h"
#include "src/spawn/globals.h"
#include <vector>


//CHAPTER 14
BattleCoords masterninjabtlCH14BattleCoords[] = {

       //{-4.278018951f, 3.77045989f, 9.020205498f},   // START BATTLE 01
       // {-39.91788101f, -1.499999881f, 21.50466156f}, // First Save Point
       // {-49.01662445f, -1.499999881f, 33.85672379f}, // START BATTLE 02
       // {-51.74726868f, -1.499999881f, 35.24174118f}, // BATTLE 02 DISABLE
       // {-62.02156448f, -16.95000076f, 20.7978096f},  // START BATTLE 03
       // {-47.44185638f, -13.80000019f, 33.14215469f}, // BATTLE 03 DISABLE
       // {-58.54923248f, -10.60000134f, 40.36560059f}, // START BATTLE 04
       // {-81.10764313f, -7.499994755f, 24.86401367f}, // BATTLE 04 DISABLE
       // {-121.6169052f, -4.500015736f, 61.81223297f}, // BATTLE 05
       // {-128.2968445f, -4.500015736f, 85.37071991f}, // BATTLE 05 DISABLE
       // {-110.43430339f, 8.976043701f, 122.7386932f}, // BATTLE 06
       // {-97.55497742f, 1.849431992f, 141.0948486f},   // BATTLE 06 DISABLE
       // {-99.24944305f, -5.399999142f, 96.4569931f},  // BATTLE 07
       // {-86.55921173f, -4.129928112f, 39.43626785f}, // BATTLE 07 DISABLE
       // {9.224415779f, 200.0f, -4.210312366f},        // BATTLE 08
       // {-17.29926109f, 204.0f, -22.24618149f}        // BATTLE 08 DISABLEs

          // BATTLE 01 - START
        {-387.6779175f, 11.60204792f, 48.64099121f},
        // BATTLE 02 - RIGHT AT BOTTOM OF STAIRS
        {-378.7885132f, 4.685351849f, 18.79888535f},
        // BATTLE 03 - BEFORE ENTERING WOODEN BRIDGE
        {-368.5033264f, -0.2742561996f, 38.44132996f},
        // BATTLE 04 - END OF WOODEN BRIDGE
        {-347.8982849f, -5.462541103f, 40.73313904f},
        // Extra point that seems to be part of BATTLE 04 or another battle
        {-364.8066711f, -1.967795014f, 63.11040115f},
        // BATTLE 05 - BEFORE MURAMASA (RIGHT BEFORE DOOR)
        {-343.7631836f, -9.062458038f, 22.28748512f},
        // SAVE 01 - MIDDLE OF FIRST STEPS
        {-319.6992493f, -17.423769f, 19.59589195f},
        // BATTLE 06 - PAST FIRST ARCHER CANOPY
        {-286.5622253f, -32.89982605f, -24.82680511f},
        // BATTLE 07 - PIT AFTER ARCHER CANOPY
        {-269.9479675f, -37.69255447f, -8.818642616f},
        // FIEND RYU AREA - DON'T CLOSE DOOR UNLESS PLAYER KILLED ALL PREVIOUS ENEMIES
        {-235.6382599f, -49.61859894f, -9.828026772f},
        // BATTLE 08 - CLAW ROOM
        {-205.6638794f, -48.20999527f, -12.35608578f},
        // BATTLE 09 - SAVE AREA
        {-184.1086426f, -49.59182739f, -18.90171051f},
        // RESET BATTLES BEFORE ENTERING BRIDGE
        {-167.0256805f, -52.54894257f, -23.41503525f},
        // BATTLE 10 - BEFORE RASETSU BRIDGE BATTLE
        {-146.8469391f, -52.59009933f, -24.07250595f},
        // CH14 RASETSU BUDDAH HEAD (TELEPORT PLAYER)
        {-51.11900711f, -40.77991104f, -98.70074463f}, // Notice the order of coordinates is corrected to X, Y, Z
        // BATTLE 11 - RASETSU
        {-114.4229736f, -52.93864059f, -15.65097141f}
};
extern "C" BattleTracker masterninjabtlCH14Tracker[] = {
    

        {0x0000, 0x2DD29D0}, // BATTLE 01 - START
        {0x0000, 0x2DD29D0}, // BATTLE 02 - RIGHT AT BOTTOM OF STAIRS
        {0x0000, 0x2DD29D0}, // BATTLE 03 - BEFORE ENTERING WOODEN BRIDGE
        {0x0000, 0x2DD29D0}, // BATTLE 04 - END OF WOODEN BRIDGE
        {0x0000, 0x2DD29D0}, // BATTLE 04 - END OF WOODEN BRIDGE (Duplicate)
        {0x0000, 0x2DD29D0}, // BATTLE 05 - BEFORE MURAMASA (RIGHT BEFORE DOOR)
        {0x0000, 0x2DD5328}, // BATTLE 06 - PAST FIRST ARCHER CANOPY
        {0x0000, 0x2DD5328}, // BATTLE 07 - PIT AFTER ARCHER CANOPY
        {0x0000, 0x2DD5328}, // BATTLE 08 - CLAW ROOM
        {0x0000, 0x2DE3B78}, // BATTLE 09 - SAVE AREA
        {0x0000, 0x2DE1FE8}, // BATTLE 10 - BEFORE RASETSU BRIDGE BATTLE
        {0x0000, 0x2DE5510}  // BATTLE 11 - RASETSU
};
DistanceThreshold masterninjabtlCH14DistanceThreshold[] = {
        
        //{20.00f}, // START BATTLE 01 - RIGHT AFTER RED GATE DOOR
        //{20.00f}, // First Save Point Middle Of Door - Trigger to turn off the above battle point
        //{20.00f}, // START BATTLE 02 - AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
        //{20.00f}, // BATTLE 02 DISABLE - 1st CHEST AREA
        //{20.00f}, // START BATTLE 03 - AFTER 1st SAVE - AFTER CHEST JUMP DOWN
        //{20.00f}, // BATTLE 03 DISABLE - TOP OF FIRST FLIGHT OF STAIRS
        //{20.00f}, // START BATTLE 04 - AFTER 1st SAVE - 2nd CHEST
        //{20.00f}, // BATTLE 04 DISABLE - AFTER 1st SAVE - 2nd CHEST - FIRST METAL DOOR
        //{50.00f}, // BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
        //{20.00f}, // BATTLE 05 DISABLE - NEXT TO SECOND SAVE
        //{500.00f}, // BATTLE 06 - AFTER BRIDGE BEFORE BUDDAH CUTSCENE
        //{20.00f}, // BATTLE 06 DISABLE (RIGHT BEFORE BUDDAH CUTSCENE) - AFTER BRIDGE BEFORE BUDDAH CUTSCENE
        //{50.00f}, // BATTLE 7 - AFTER BUDDAH CUTSCENE FOR LEDGE RUN
        //{20.00f}, // BATTLE 7 - DISABLE
        //{20.00f}, // BATTLE 8 - GLASS BREAK IS NINJA AFTER DOOR
        //{20.00f}  // BATTLE 8 - DISABLE

        {400.00f}, // BATTLE 01 - START
        {200.00f}, // BATTLE 02 - RIGHT AT BOTTOM OF STAIRS
        {80.00f},  // BATTLE 03 - BEFORE ENTERING WOODEN BRIDGE
        {250.00f}, // BATTLE 04 - END OF WOODEN BRIDGE
        {20.00f},  // BATTLE 04 - END OF WOODEN BRIDGE (Duplicate)
        {50.00f},  // BATTLE 05 - BEFORE MURAMASA (RIGHT BEFORE DOOR)
        {10.00f},  // SAVE 01 - MIDDLE OF FIRST STEPS
        {290.00f}, // BATTLE 06 - PAST FIRST ARCHER CANOPY
        {350.00f}, // BATTLE 07 - PIT AFTER ARCHER CANOPY
        {350.00f}, // FIEND RYU AREA - DON'T CLOSE DOOR UNLESS PLAYER KILLED ALL PREVIOUS ENEMIES
        {80.00f},  // BATTLE 08 - CLAW ROOM
        {80.00f},  // BATTLE 09 - SAVE AREA
        {10.00f},  // RESET BATTLES BEFORE ENTERING BRIDGE
        {120.00f}, // BATTLE 10 - BEFORE RASETSU BRIDGE BATTLE
        {0.00f},   // BUDDAH HEAD - DUMMY DATA
        {250.00f}  // BATTLE 11 - RASETSU
};
extern "C" SpawnCoords masterninjabtlCH14SpawnCoords[] = {
        //// CH1 Start
        //// START - AFTER MURAMASA CUTSCENE (RED GATE) NG2 ARCHER PLACEMENT
        //{ -11.19219685f, 4.00f, 11.25521278f, 0.0f },
        //{ 13.00108051f, 4.00f, -17.73134232f, 0.00f },
        //{ 16.07675171f, -1.0f, -29.52827263f, 0.00f },
        //{ 19.12763214f, -1.5f, -37.46701431f, 0.00f },

        //// START - AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
        //{ -56.49800873f, -1.699999809f, 31.9538784f, 0.0f },

        //// START - AFTER 1st SAVE - 2nd CHEST
        //{ 42.06149673f, -10.60000134f, -72.02714539f, 0.0f },
        //{ 42.44620132f, -10.60000038f, -53.21555328f, 0.0f },
        //{ 32.36677933f, -10.59999943f, -71.96556091f, 0.0f },

        //// START - BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
        //{ 72.96051025f, -4.500015736f, -116.6359253f, 0.0f },

        //// START - BATTLE 06 - After Bridge Before Buddah Cutscene (Grey Ninja)
        //{ 125.3550034f, 18.00f, -109.2900772f, 0.0f },
        //{ 122.9854355f, 18.00f, -111.8772812f, 0.0f },

        //// START - BATTLE 06 - After Bridge Before Buddah Cutscene (IS Ninja)
        //{ 155.3605957f, 10.0f, -112.2211304f, 0.0f },

        //// BATTLE 07 - FIRST LEDGE RUN ARCHER AFTER CUTSCENE
        //{ 72.12442017f, 3.00f, -99.09088898f, 0.0f },
        //{ 68.19638062f, 3.00f, -97.50299835f, 0.0f },
        //{ 68.28087616f, 3.00f, -100.6895676f, 0.0f },

        //// BATTLE 08 - IS NINJA GLASS BREAK
        //{ -1.88998425f, 200.0f, -8.786634445f, 0.0f },
        //{ -1.88998425f, 200.0f, -8.786634445f, 0.0f } // Assuming this is a duplicate of the previous entry

         {7.96138525f, 3.531409979f, -373.8337402f, 0.0f},    // BATTLE 01 - ARCHER SPOT 1
        {21.79188728f, 4.679887772f, -376.6979065f, 0.0f},   // BATTLE 01 - ARCHER SPOT 2
        {25.28119659f, 4.686240673f, -376.8360901f, 0.0f},   // BATTLE 01 - ARCHER SPOT 3
        {7.96138525f, 3.531409979f, -373.8337402f, 0.0f},    // BATTLE 01 - ENEMY SPAWNS AT START (STAIRS)
        {29.2966156f, 4.669300079f, -381.833313f, 0.0f},     // BATTLE 02 - ENEMY SPAWNS AT CORNER (BELOW STAIRS)
        {14.20582199f, 4.678584576f, -379.3608704f, 0.0f},   // BATTLE 02 - ENEMY SPAWNS AT CANOPY
        {17.06440926f, -0.2794894874f, -373.1387024f, 0.0f}, // BATTLE 02 - BOTTOM OF SECOND FLIGHT OF STAIRS
        {62.55176926f, -3.403529406f, -351.232666f, 0.0f},   // BATTLE 03 - WOODEN BRIDGE
        {40.5629425f, -5.462540627f, -349.7573853f, 0.0f},   // BATTLE 04 - END OF WOODEN BRIDGE
        {6.736080647f, -17.87879944f, -308.5863647f, 0.0f},  // FIRST ARCHER (RIGHT)
        {10.40472317f, -17.88925171f, -303.141449f, 0.0f},   // FIRST ARCHER (LEFT)
        {-21.96247101f, -27.88547516f, -280.9872437f, 0.0f}, // SECOND ARCHER (LEFT)
        {-25.49521446f, -27.88930321f, -275.1368713f, 0.0f}, // SECOND ARCHER (RIGHT)
        {1.62230885f, -45.39624405f, -256.299408f, 0.0f},    // SLIGHT BEFORE TENGU
        {-28.95229721f, -48.10957336f, -232.5631714f, 0.0f}, // FIEND RYU WINDMILL SHURIKEN AREA
        {-0.4839556813f, -49.61859894f, -220.8767395f, 0.0f},// FIEND RYU TOP LEFT CORNER
        {-16.94564629f, -45.92889404f, -208.323349f, 0.0f},  // CLAW ROOM ENTRANCE RIGHT SIDE
        {-17.06096268f, -48.2100029f, -201.9911194f, 0.0f},  // CLAW ROOM BEFORE DOOR (SAVE AMBUSH INSIDE)
        {-10.64924622f, -46.03856659f, -196.0012512f, 0.0f}, // CLAW ROOM LEFT SIDE OF CLAW
        {-20.26843643f, -48.12540817f, -190.1728516f, 0.0f}, // OUTSIDE BEFORE SAVE ARCHER SPOT
        {-29.00678825f, -49.60635757f, -183.5658417f, 0.0f}, // 3RD SAVE BEFORE BRIDGE HIDING SPOT
        {-29.60603905f, -43.00f, -122.2449799f, 0.0f},       // RASETSU BY STAIRS
};

extern "C" ChapterData masterNinjaCH14CoordData = {
	masterninjabtlCH14BattleCoords,
	masterninjabtlCH14Tracker,
	masterninjabtlCH14DistanceThreshold,
};
size_t battleCoordsSize = sizeof(masterninjabtlCH14BattleCoords);
size_t trackerSize = sizeof(masterninjabtlCH14Tracker);

extern "C" unsigned char tripleISBytes[] = {
        0x00, 0x00, 0x01, 0x00, 0x44, 0x00, 0x00, 0x00, 0x0E, 0x00, 0xFF, 0xFF,
        0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x09, 0x00, 0x00, 0x00, 0x18, 0x00,
        0x0E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x44, 0x00, 0x00, 0x00, 0x0E, 0x00,
        0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x24, 0x00, 0x08, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x44, 0x00, 0x00, 0x00, 0x0E, 0x00, 0xFF, 0xFF, 0x00, 0x00,
        0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void  __attribute__((naked))InjectReset() {

   /* __asm__ volatile(".intel_syntax noprefix;"
        "cmp rdx,rbx;"
        "jnl qword ptr r14 + 0x1464120;"
        "sub rbx,rdx;"
        "mov[rsp + 50], rbx;"
        "lea rcx,[rsp+50];"*/

       /* "push rax"
        "push rbx;"
        "push rcx;"
        "push rdx;"
        "lea rbx, qword ptr [rip + masterninjabtlCH14Tracker];"
        "mov rdx, qword ptr [rip + baseAddress];"*/
        //"xor rax, rax;"
        //"xor rcx, rcx;"
        //"cmp word ptr [rdx + 0x319CBB4], 0x0000;"
        //"jle resetcounters;"
        //"jmp codeb;"
        //"resetcounters:"
        //"mov [rip + counter], al;"
        //"mov [rip + scounter], al;"
        //"mov [rip + scounter2], al;"
        //"mov [rip + scounter3], al;"
        //"mov [rip + scounter4], al;"
        //"mov [rip + scounter5], al;"
        //"mov [rip + scounter6], al;"
        //"mov [rip + cBattleRespawnCount], al;"
        //"mov [rip + cBattleRespawnCount2], al;"
        //"mov [rip + cBattleRespawnCount3], al;"
        //"mov [rip + cBattleRespawnCount4], al;"
        //"mov [rip + cBattleRespawnCount5], al;"
        //"mov [rip + cBattleRespawnCount6], al;"
        //"mov [rip + entDied], al;"
        //"cBattleTrackerReset:"
        //"cmp rcx, 0x38;"
        //"jae codeb;"
        //"cmp dword ptr [rbx + rcx * 0x04], 0x0101;" // 0101
        //"je cBattleTrackerResetBattle;"
        //"cmp dword ptr [rbx + rcx * 0x04], 0x0F0F;" // 0101
        //"je cBattleTrackerResetBattle;"
        //"cmp dword ptr [rbx + rcx * 0x04], 0xA0A0;" // 0101
        //"je cBattleTrackerResetBattle;"
        //"add rcx, 0x02;"
        //"jmp cBattleTrackerReset;"
        //"cBattleTrackerResetBattle:"
        //"mov dword ptr [rbx + rcx * 4], 0x0000;"
       // "codeb:"
       // "pop rdi;"
       ///* "pop rdx;"
       // "pop rcx;"
       // "pop rbx;"
       // "pop rax;"*/
       // "mov rax,rdx;"
       // "mov rdi,rcx;"
       // "mov rcx, r8;"
       // "repe stosb;"
       // "ret;"
       /* "jmp qword ptr [rip + returnInjectReset];"




        );*/
}

__attribute__((naked)) void InjectSound() {
    __asm__ volatile (
        ".intel_syntax noprefix;"
        "push rsi;"
        "mov rsi, qword ptr [rip + baseAddress];"
        "cmp r8, 0x2;"
        "jne 2f;"
        "cmp byte ptr [rsi + 0x35C421A],0x10;"
        "je CHP14SoundTrack;"
        "cmp r9, 0x3b;"
        "je 1f;"
        "cmp r9, 0x45;"
        "je 0f;"
        "jmp 2f;"
        "0:"
        "mov r9,0x3D;"
        "jmp 2f;"
        "CHP14SoundTrack:"
         "cmp r9,0x3B;"
         "je codesound22;"
        "cmp r9,0x2F;"
        "je codesound22;"
        "jmp 2f;"
        "codesound22:"
        "mov r9,0x4D;"
        "jmp 2f;"
        "1:"
        "mov r9, 0x3E;"
        "2:"
        "mov [rdx],r8d;"
        "xor ebp,ebp;"
        "mov [rdx+04],r9d;"
        "mov rbx,rdx;"
        "mov rax, [rcx+0x130];"
        "pop rsi;"
        "jmp qword ptr [rip + returnInjectSound];"
        "3:"
        );
}

void  __attribute__((naked))InjectTripleIS() {

    __asm__ volatile(".intel_syntax noprefix;"
        "push rcx;"
        "push rsi;"
        "push rdi;"
        "cmp r11, 0x65535;"
        "jle codeISTEST;"
        "mov rcx,0x96;"
        "cmp dword ptr [r11+0x08], 0x0001019B;"
        "jne codeISTEST;"
        "lea rsi, qword ptr [rip + tripleISBytes];"
        "mov rdi,r11;"
        "rep movsb;"
    "codeISTEST:"
         "pop rdi;"
         "pop rsi;"
        "pop rcx;"
        "add r12,rax;"
        "mov [rsp+0x20],rax;"
        "mov eax,0x0000000C;"
        "cmp ax,r9w;"
        "jmp qword ptr [rip + returnInjectTripleIS];"




        );
}



void  __attribute__((naked))InjectDontDisableBattle() {

    __asm__ volatile(".intel_syntax noprefix;"
         "push rbx;"
         "push rcx;"
         "mov rcx, qword ptr [rip + baseAddress];"
         "cmp byte ptr [rcx+0x35C421A],0x10;"
         "jne codeDontDisableBattle;"
         "mov rbx,rcx;"
         "add rbx,0x2DD531E;"
        "cmp rbx,r10;"
        "je ch14DontDisable5138;"
        "jmp codeDontDisableBattle;"
        "ch14DontDisable5138:"
        "cmp word ptr [rcx + 0x2DDB988],0x0000;"//TENGU
        "jnz codeDontDisableBattle;"
        "mov al,0x01;"
        "codeDontDisableBattle:"
        "pop rcx;"
        "pop rbx;"
        "mov [r10-0x02],al;"
        "add r10,0x000001F8;"
        "sub rdi,0x01;"
        "jmp qword ptr [rip + returnInjectDontDisableBattle;"
         

     

        );
}

void ClearTracking() {
    size_t numElements = sizeof(masterninjabtlCH14Tracker) / sizeof(masterninjabtlCH14Tracker[0]);
    for (size_t i = 0; i < numElements; ++i) {
        masterninjabtlCH14Tracker[i].battleStatus = 0x0000;
    }
}

void  __attribute__((naked))InjectTelePlayer() {

    __asm__ volatile(".intel_syntax noprefix;"
        "push rcx;"
        "mov rcx, qword ptr [rip + baseAddress];"
        "cmp bx,0x7100;"
        "jne codeteleplayer;"
        "xorps xmm15,xmm15;"
        "cmp byte ptr [rip + telePlayer], 0x01;"
        "jne codeteleplayer;"
        "mov byte ptr [rcx + 0x319CD97],0x00;"
        "mov byte ptr [rip + telePlayer],0x00;"
        "movups xmm15,[rip + teleCoords];"
        "comiss xmm14,xmm15;"
        "jna codeteleplayer;"
        "movups [rax],xmm15;"
        "movups [rip + teleCoords],xmm15;"
        "mov byte ptr [rcx + 0x6BED027], 0x64;"
        "pop rcx;"
        "addss xmm1, [rax];"
        "movss [rax], xmm1;"
        "movss xmm0, [rdx+0x04];"
        "addss xmm0, [rax+0x04];"
        "jmp qword ptr [rip + returnInjectTelePlayer];"
    "codeteleplayer:"
        "addss xmm1, [rax];"
        "movss [rax], xmm1;"
        "movss xmm0, [rdx+0x04];"
        "addss xmm0, [rax+0x04];"
        "cmp byte ptr [rcx + 0x6BED027], 0x00;"
        "pop rcx;"
        "jz returnHome;"
        "jmp dontReturnHome;"
        "returnHome:"
        "jmp qword ptr[rip + returnInjectTelePlayer]; "
        "dontReturnHome:"
        "push rcx;"
        "mov rcx, qword ptr [rip + baseAddress];"
        "dec byte ptr [rcx + 0x6BED027];"
        "pop rcx;"
        "jmp qword ptr [rip + returnInjectTelePlayer];"
        );
}


void  __attribute__((naked))InjectEntDie() {

    __asm__ volatile(".intel_syntax noprefix;"
        "push rcx;"
        "xor rcx,rcx;"
        "mov [rip + entDied], cx;"
        "mov rcx, qword ptr [rip + baseAddress];"
        "cmp word ptr [rcx], 0x0000;"
        "jle codeentdie;"
        "movzx cx, byte ptr [rbx+0x18];"
        "mov [rip + entDied], cx;"
      "codeentdie:"
         "pop rcx;"
        "mov byte ptr [rbx+0x1A],-01;"
        "mov byte ptr [rax+0x00005B54],0x00;"
        "add rsp,0x58;"
        "jmp qword ptr [rip + returnInjectEntDie];"
        );
}

void  __attribute__((naked))InjectDisableSpawns() {

    __asm__ volatile(".intel_syntax noprefix;"
         "push rax;"
         "mov rax, qword ptr [rip+baseAddress];"
         "lea r8, qword ptr [rax+0x6AE8880];"
         "xor ebx,ebx;"
         "lea rdx, qword ptr [rax+0x1F506F0];"
         "pop rax;"
         "mov r9d,ebx;"
         "cmp byte ptr [rip+cDeleteEnemy],0x01;"
         "mov byte ptr [rip+cDeleteEnemy],0x00;"
         "jne exitDeleteSpawn;"
         "mov rax, qword ptr [rip+baseAddress];"
         "add rax,0x161958F;"
         "jmp rax;"
        "exitDeleteSpawn:"
         "jmp qword ptr [rip + returnInjectDisableSpawns]; "
         //"call qword ptr [rdi+0X15d9560];"

        );
}



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
        "push rsi;"
        "mov rsi,rbx;"
        "mov rbx, qword ptr [rip+baseAddress];"
        "cmp word ptr [rbx+0X319CBB4], 0x0000;"
        "jz codecoords;"
        "mov rdx, [rip+scounter];"
        //CHAPTER 1
       /* "mov rax,[rip + masterninjabtlCH14SpawnCoords];"
        "mov rcx,[rip + masterninjabtlCH14Tracker];"
        "cmp byte ptr [rbx+0x35C421A],0x06;"
        "je coordsCH01;"*/
        "lea rax, qword ptr [rip + masterninjabtlCH14SpawnCoords];"
        "lea rcx, qword ptr [rip + masterninjabtlCH14Tracker];"
        "cmp byte ptr [rbx+0x35C421A],0x10;"
        "je coordsCH14;"
        "jmp codecoords;"
    //CHAPTER 14
    "coordsCH14:"
        "cmp si, 0x27E0;"
        "je coordsCH0114;"
        "cmp si, 0x5138;"
        "je coordsCH01144;"
        "cmp si, 0x3988;"
        "je coordsCH0114a;"
        "cmp si, 0x5320;"
        "je coordsCH01150;"
        "cmp si, 0x7E70;"
        "je coordsCH0114Gauntlet;"
        "jmp codecoords;"
    "coordsCH0114:"
        "cmp DWORD PTR [rcx+0x28], 0x0101;"      // cmp [rcx+0A*4], 0x0101
        "je codecoords;"
        "cmp DWORD PTR [rcx+0x20], 0x0101;"      // cmp [rcx+08*4], 0x0101
        "je coordsCH01143;"
        "cmp DWORD PTR [rcx+0x18], 0x0101;"      // cmp [rcx+06*4], 0x0101
        "je coordsCH01143;"
        "cmp DWORD PTR [rcx+0x10], 0x0101;"      // cmp [rcx+04*4], 0x0101
        "je coordsCH01142;"
        "cmp DWORD PTR [rcx+0x08], 0x0101;"      // cmp [rcx+02*4], 0x0101
        "je coordsCH01141;"
        "cmp DWORD PTR [rcx], 0x0101;"           // cmp [rcx], 0x0101
        "jne codecoords;"

        // Vector operations and additional conditional logic
        "movaps xmm10,  [rax+0x40];"  // movaps xmm10, [rax+10*4]
        "cmp BYTE PTR [rbx+0x21229B8], 0x07;"
        "jae setCoords;"
        "movaps xmm10,  [rax];"
        "cmp BYTE PTR [rip+scounter], 0x01;"
        "jle setCoords;"
        "movaps xmm10,  [rax+0x10];"  // [rax+04*4]
        "cmp BYTE PTR [rip+scounter], 0x02;"
        "jle setCoords;"
        "movaps xmm10,  [rax+0x20];"  // [rax+08*4]
        "cmp BYTE PTR [rip+scounter], 0x03;"
        "jle setCoords;"
        "movaps xmm10,  [rax+0x40];"  // Repeated operation for illustrative purposes
        "jmp setCoords;"
 "coordsCH01141:"
        "movaps xmm10,  [rax+0x70];"  // [rax+1C*4]
        "cmp BYTE PTR [rip+cBattleRespawnCount2], 0x0C;"
        "jae setCoords;"
        "movaps xmm10,  [rax+0x40];"  // [rax+10*4]
        "cmp BYTE PTR [rip+scounter2], 0x04;"
        "jle setCoords;"
        "movaps xmm10,  [rax+0x50];"  // [rax+14*4]
        "cmp BYTE PTR [rip+scounter2], 0x06;"
        "jmp setCoords;"
 "coordsCH01142:"
        "movaps xmm10,  [rax+0x70];"  // [rax+1C*4]
        "cmp BYTE PTR [rip+scounter3], 0x05;"
        "jle setCoords;"
        "movaps xmm10,  [rax+0x60];"  // [rax+18*4]
        "jmp setCoords;"
"coordsCH0114a:"
        "cmp dword ptr [rcx+0x48], 0x0101;"  // [rcx+12*4]
        "je coordsCH01149;"
        "jmp codecoords;"
"coordsCH01143:"
        "cmp byte ptr [rip+cBattleRespawnCount4], 0x08;"
        "jae codecoords;"
        "movaps xmm10,  [rax+0x80];"  // [rax+20*4]
        "jmp setCoords;"
    "coordsCH01144:"
    "cmp dword ptr [rcx+0x40], 0x0101;"  // [rcx+10*4]
    "je coordsCH01148;"
    "cmp dword ptr [rcx+0x38], 0x0101;"  // [rcx+0E*4]
    "je coordsCH01147;"
    "cmp dword ptr [rcx+0x30], 0x0101;"  // [rcx+0C*4]
    "je coordsCH01146;"
    "cmp byte ptr [rip+cBattleRespawnCount6], 0x04;"
    "jae codecoords;"
    "movaps xmm10,  [rax+24*4];"  // [rax+24*4]
    "cmp byte ptr [rip+cBattleRespawnCount6], 0x01;"
    "jle setCoords;"
    "movaps xmm10,  [rax+0x28*4];"
    "jmp setCoords;"
    "coordsCH01146:"
    "movaps xmm10,  [rax+0xD0];"  // [rax+34*4]
    "cmp byte ptr [rip+cBattleRespawnCount2], 0x03;"
    "jae setCoords;"
    "movaps xmm10,  [rax+0xB0];"  // [rax+2C*4]
    "cmp byte ptr [rip+cBattleRespawnCount2], 0x01;"
    "jle setCoords;"
    "movaps xmm10,  [rax+0xC0];"  // [rax+30*4]
    "jmp setCoords;"
    "coordsCH01147:"
    "movaps xmm10,  [rax+0xD0];"  // [rax+34*4]
    "jmp setCoords;"
    //CLAW ROOM
    "coordsCH01148:"
    "movaps xmm10,  [rax+0x100];"  // [rax+40*4]
    "cmp byte ptr [rip+cBattleRespawnCount4], 0x01;"
    "jle setCoords;"
    "movaps xmm10,  [rax+0x110];"  // [rax+44*4]
    "cmp byte ptr [rip+cBattleRespawnCount4], 0x03;"
    "jle setCoords;"
    "movaps xmm10,  [rax+0x120];"  // [rax+48*4]
    "jmp setCoords;"
    "coordsCH01149:"
    "movaps xmm10,  [rax+0x140];"  // [rax+50*4]
    "jmp setCoords;"
    //RASETSU
    "coordsCH01150:"
    "cmp byte ptr [rip+cBattleRespawnCount2], 0x04;"
    "jae codecoords;"
    "movaps xmm10,  [rax+0x150];"  // [rax+54*4]
    "jmp setCoords;"
"coordsCH0114Gauntlet:"
    "movaps xmm10, [rax+0x120];"  // [rax+48*4]
 "setCoords:"
    "movaps [rbx + 0x6AED400],xmm10;"
  "codecoords:"
    "pop rsi;"
    "pop rdx;"
    "pop rcx;"
    "pop rbx;"
    "pop rax;"
    "jmp qword ptr [rip + returnInjectCoords];"
   // //CHAPTER 1
   // "coordsCH01:"
   //     "cmp bx,0xFE68;"
   //     "je coordsCH0101;"
   //     "cmp bx,0x0C20;"
   //     "je coordsCH0101;"
   //     "cmp bx,0x7670;"
   //     "je coordsCH0101;"
   //     "cmp bx,0x1B90;"
   //     "je coordsCH0101;"
   //     "jmp codecoords;"
   // "coordsCH0101:"
   //     //BATTLE 8
   //     "cmp dword ptr [rcx + 0x0E * 0x4], 0x0101;"
   //     "je coordsCH0107;"
   //     //BATTLE 7
   //     "cmp dword ptr [rcx + 0x0C * 0x4], 0x0101;"
   //     "je coordsCH0106;"
   //     //BATTLE 6
   //     "cmp dword ptr [rcx + 0x0A * 0x4], 0x0101;"
   //     "je coordsCH0105;"
   //     //BATTLE 5
   //     "cmp dword ptr [rcx + 0x08 * 0x4], 0x0101;"
   //     "je coordsCH0104;"
   //     //BATTLE 4
   //     "cmp dword ptr [rcx + 0x06 * 0x4], 0x0101;"
   //     "je coordsCH0103;"
   //     //BATTLE 3
   //     "cmp dword ptr [rcx + 0x04 * 0x4], 0x0101;"
   //     "je codecoords;"
   //     //BATTLE 2
   //     "cmp dword ptr [rcx + 0x02 * 0x4], 0x0101;"
   //     "je coordsCH0102;"
   //     //BATTLE 1
   //     "cmp dword ptr [rcx], 0x0101;"
   //     "jne codecoords;"
   //     "movaps xmm10, [rax];"
   //     "cmp byte ptr[rdx], 0x01;"
   //     "je setCoords;"
   //     "movaps xmm10, [rax + 0x04 * 0x4];"
   //     "cmp byte ptr[rdx], 0x02;"
   //     "je setCoords;"
   //     "movaps xmm10, [rax + 0x08 * 0x4];"
   //     "cmp byte ptr[rdx], 0x03;"
   //     "je setCoords;"
   //     "movaps xmm10, [rax + 0x0C * 0x4];"
   //     "cmp byte ptr[rdx], 0x04;"
   //     "je setCoords;"
   //     "jmp codecoords;"
   //     //AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
   //"coordsCH0102:"
   //     "movaps xmm10,[rax+0x10*0x4];"
   //     "jmp setCoords;"
   //     //START - AFTER 1st SAVE - 2nd CHEST
   // "coordsCH0103:"
   //     "movaps xmm10,[rax+0x14*0x4];"
   //     "cmp byte ptr [rdx],0x01;"
   //     "jle setCoords;"
   //     "movaps xmm10,[rax+0x18*0x4];"
   //     "cmp byte ptr [rdx],0x02;"
   //     "jle setCoords;"
   //     "movaps xmm10,[rax+0x1C*0x4];"
   //     "cmp byte ptr [rdx],0x05;"
   //     "jle setCoords;"
   //     "jmp codecoords;"
   //     //BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
   // "coordsCH0104:"
   //     "movaps xmm10,[rax+0x20*0x4];"
   //     "jmp setCoords;"
   //     //BATTLE 06 - BATTLE 06
   // "coordsCH0105:"
   //     "movaps xmm10,[rax+0x24*0x4];"
   //     "cmp byte ptr [rdx],0x02;"
   //     "jle setCoords;"
   //     "movaps xmm10,[rax+0x28*0x4];"
   //     "cmp byte ptr [rdx],0x04;"
   //     "jle setCoords;"
   //     "movaps xmm10,[rax+0x2C*0x4];"
   //     "cmp byte ptr [rdx],0x06;"
   //     "jle setCoords;"
   //     "jmp codecoords;"
   //     //BATTLE 07
   // "coordsCH0106:"
   //     "movaps xmm10,[rax+0x30*0x4];"
   //     "cmp byte ptr [rdx],0x01;"
   //     "jle setCoords;"
   //     "movaps xmm10,[rax+0x34*0x4];"
   //     "cmp byte ptr [rdx],0x02;"
   //     "jle setCoords;"
   //     "movaps xmm10,[rax+0x38*0x4];"
   //     "cmp byte ptr [rdx],0x03;"
   //     "jle setCoords;"
   //     "jmp codecoords;"
   //     //BATTLE 08 - GLASS BREAK IS NINJA
   //     "coordsCH0107:"
   //     "movaps xmm10,[rax+0x3C*0x4];"
   //     "jmp setCoords;"
    

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
            "push r11;"
            "xorps xmm10, xmm10;"
            "xor rbp,rbp;"
            "xor rsi,rsi;"
            "mov r8,[rip+masterNinjaCH14CoordData];"
            "mov r9, [rip+battleCoordsSize];"
            "add r9,r8;"
            "mov rdi, [rip+trackerSize];"
            "add rdi,r9;"
            "mov r11,r8;"
            "mov rcx,0x00;"
            "mov rdx,0x30;"
            "mov rsi, qword ptr [rip+baseAddress];"
            "cmp word ptr [rsi+0X319CBB4], 0x00;"
            "jz codecbattle;"
            "cmp byte ptr [rsi+0x35C421A], 0x10; "
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
        "cmp byte ptr [r8+0x35C421A], 0x10; "
        "je cTriggerEventCH14;"
    "cTriggerEventCH14:"
        "cmp rcx, 0x00;"
        "je cTriggerEventCH1401;"

        "cmp rcx, 0x03;"
        "mov rdx, 0x02;"
        "je cTriggerEventCH1402;"

        "cmp rcx, 0x06;"
        "mov rdx, 0x04;"
        "je cTriggerEventCH1403;"

        "cmp rcx, 0x09;"
        "mov rdx, 0x06;"
        "je cTriggerEventCH1404;"

        "cmp rcx, 0x0C;"
        "mov rdx, 0x08;"
        "je cTriggerEventCH1404a;"

        "cmp rcx, 0x0F;"
        "mov rdx, 0x0A;"
        "je cTriggerEventCH1405;"

        // SAVE 01
        "cmp rcx, 0x12;"
        "je cTriggerEventsDisable;"

        "cmp rcx, 0x15;"
        "mov rdx, 0x0C;"
        "je cTriggerEventCH1406;"

        "cmp rcx, 0x18;"
        "mov rdx, 0x0E;"
        "je cTriggerEventCH1407;"

        // FIEND RYU AREA DONT CLOSE DOOR UNTIL PLAYER KILLS ALL ENEMIES
        "cmp rcx, 0x1B;"
        "je cTriggerEventCH14DoorCheckRyu;"

        "cmp rcx, 0x1E;"
        "mov rdx, 0x10;"
        "je cTriggerEventCH1408;"

        // SAVE AREA
        "cmp rcx, 0x21;"
        "mov rdx, 0x12;"
        "je cTriggerEventCH1409;"

        // RESET BATTLES BEFORE BRIDGE
        "cmp rcx, 0x24;"
        "je cTriggerEventsDisable;"

        // BATTLE 10 BRIDGE
        "cmp rcx, 0x27;"
        "mov rdx, 0x14;"
        "je cTriggerEventCH1410;"

        // BATTLE 11 - RASETSU
        "cmp rcx, 0x2D;"
        "mov rdx, 0x16;"
        "je cTriggerEventCH1411;"

        "jmp codecbattle;"
 
                "cTriggerEventCH1401:"
                "cmp dword ptr [r9], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9], 0x0101;"
                "mov rcx, [r9 + 0x04];"
                "jmp cStartTriggerEvent02;"

                "cTriggerEventCH1402:"
                "cmp dword ptr [r9 + 0x08], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9 + 0x08], 0x0101;"
                "mov rcx, [r9 + 0x0C];"
                "jmp cStartTriggerEvent02;"

                "cTriggerEventCH1403:"
                "cmp dword ptr [r9 + 0x10], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9 + 0x10], 0x0101;"
                "mov rcx, [r9 + 0x14];"
                "jmp cStartTriggerEvent02;"

                "cTriggerEventCH1404:"
                "cmp dword ptr [r9 + 0x18], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9 + 0x18], 0x0101;"
                "mov rcx, [r9 + 0x1C];"
                "jmp cStartTriggerEvent02;"

                "cTriggerEventCH1404a:"
                "cmp dword ptr [r9 + 0x20], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9 + 0x20], 0x0101;"
                "mov rcx, [r9 + 0x24];"
                "jmp cStartTriggerEvent02;"

                "cTriggerEventCH1405:"
                "cmp dword ptr [r9 + 0x28], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9 + 0x28], 0x0101;"
                "mov rcx, [r9 + 0x2C];"
                "jmp cStartTriggerEvent02;"

                "cTriggerEventCH1406:"
                "cmp dword ptr [r8 + 0x2DB0C68], 0x0000;"
                "jnz codecbattle;"
                "cmp dword ptr [r9 + 0x30], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9 + 0x30], 0x0101;"
                "mov rcx, [r9 + 0x34];"
                "jmp cStartTriggerEvent02;"

                "cTriggerEventCH1407:"
                "cmp dword ptr [r8 + 0x2DB0C68], 0x0000;"
                "jnz codecbattle;"
                "cmp dword ptr [r9 + 0x38], 0x0F0F;"
                "je codecbattle;"
                "mov dword ptr [r9 + 0x38], 0x0101;"
                "mov rcx, [r9 + 0x3C];"
                "jmp cStartTriggerEvent02;"

            "cTriggerEventCH14DoorCheckRyu:"
            "cmp dword ptr [r8 + 0x2DE3F68], 0x0000;"  // RASETSU DEFEATED
            "jnz cTriggerWindMillGauntletEvent;"
            "mov byte ptr [r8 + 0x2DAFAA4], 0x00;"
            "cmp byte ptr [r8 + 0x21229B8], 0x00;"
            "jnz codecbattle;"
            "mov byte ptr [r8 + 0x2DAFAA4], 0x01;"
            "jmp codecbattle;"
            "cTriggerWindMillGauntletEvent:"
            "mov byte ptr [r8 + 0x2DE8060], 0x01;"
            "mov byte ptr [r8 + 0x2DE8062], 0x01;"
            "mov byte ptr [r8 + 0x2DE8054], 0x01;"
            "jmp codecbattle;"
            "cTriggerEventCH1408:"
            "cmp dword ptr [r8 + 0x2DB0C68], 0x0000;"
            "jnz codecbattle;"
            "cmp dword ptr [r9 + 0x40], 0x0F0F;"
            "je codecbattle;"
            "mov dword ptr [r9 + 0x40], 0x0101;"
            "mov rcx, [r9 + 0x44];"
            "jmp cStartTriggerEvent02;"
            "cTriggerEventCH1409:"
            "cmp dword ptr [r8 + 0x2DB0C68], 0x0000;"
            "jnz codecbattle;"
            "cmp dword ptr [r9 + 0x48], 0x0F0F;"
            "je codecbattle;"
            "mov dword ptr [r9 + 0x48], 0x0101;"
            "mov rcx, [r9 + 0x4C];"
            "jmp cStartTriggerEvent02;"
            "cTriggerEventCH1410:"
            "cmp dword ptr [r9 + 0x50], 0xA0A0;"
            "je codecbattle;"
            "cmp dword ptr [r9 + 0x50], 0x0F0F;"
            "je cTriggerEventCH1410a;"
            "cmp byte ptr [r8 + 0x2DB0C68], 0x02;"
            "je cTriggerEventCH1410b;"
            "mov rcx, [r9 + 0x54];"
            "mov dword ptr [r9 + 0x50], 0x0101;"
            "jmp cStartTriggerEvent02;"
            "cTriggerEventCH1410a:"
            "cmp byte ptr [r8 + 0x2DE1FE8], 0x00;"
            "jz cTriggerEventCH1410c;"
            "cmp byte ptr [r8 + 0x21229B8], 0x00;"
            "jnz codecbattle;"
            "cmp byte ptr [r8 + 0x2DB0C68], 0x00;"
            "jnz cTriggerEventCH1410b;"
            "movups xmm15,  [r11+0x2A*0x04];"
            "movups  [rip + teleCoords], xmm15;"
            "mov byte ptr [rip + telePlayer], 0x01;"
            "jmp codecbattle;"
            "cTriggerEventCH1410b:"
            "mov dword ptr [r9 + 0x50], 0xA0A0;"
            "mov byte ptr [r8 + 0x2DB0C68], 0x01;"
            "jmp codecbattle;"
            "cTriggerEventCH1410c:"
            "mov dword ptr [r9 + 0x50], 0x0101;"
            "mov rcx, [r9 + 0x54];"
            "jmp cStartTriggerEvent02;"
            "cTriggerEventCH1411:"
            "cmp dword ptr [r8 + 0x2DE5510], 0x0000;"
            "jz codecbattle;"
            "cmp byte ptr [r8 + 0x2DB0C68], 0x02;"
            "je codecbattle;"
            "cmp dword ptr [r9 + 0x58], 0x0F0F;"
            "je codecbattle;"
            "mov dword ptr [r9 + 0x58], 0x0101;"
            "mov rcx, [r9 + 0x5C];"
            "jmp cStartTriggerEvent02;"
    "cTriggerEventsDisable:"
            "cmp rsi, rdx;"
            "ja codecbattle;"
            "mov dword ptr [r9 + rsi * 4], 0x0F0F;"
            "mov byte ptr [rip + counter], 0x00;"
            "mov byte ptr[rip + scounter], 0x00;"
            "mov byte ptr[rip + scounter2], 0x00;"
            "mov byte ptr[rip + scounter3], 0x00;"
            "mov byte ptr[rip + scounter4], 0x00;"
            "mov byte ptr[rip + scounter5], 0x00;"
            "mov byte ptr[rip + scounter6], 0x00;"
            "mov byte ptr[rip + cDeleteEnemy], 0x00;"
            "mov byte ptr[rip + cBattleRespawnCount], 0x00;"
            "mov byte ptr[rip + cBattleRespawnCount2], 0x00;"
            "mov byte ptr[rip + cBattleRespawnCount3], 0x00;"
            "mov byte ptr[rip + cBattleRespawnCount4], 0x00;"
            "mov byte ptr[rip + cBattleRespawnCount5], 0x00;"
            "mov byte ptr[rip + cBattleRespawnCount6], 0x00;"
            "add rsi, 0x02;"
            "jmp cTriggerEventsDisable;"
            "cStartTriggerEvent:"
            "mov rdi, 0x00000000FFFFFFFF;"
            "and rcx, rdi;"
            "add r8, rcx;"
            "mov dword ptr [r8], 0x01000100;"
            "jmp codecbattle;"
            "cStartTriggerEvent02:"
            "mov rdi, 0x00000000FFFFFFFF;"
            "and rcx, rdi;"
            "add r8, rcx;"
            "mov byte ptr[r8], 01;"
            "mov byte ptr[r8 + 02], 01;"
            "codecbattle:"//codecbattle
            "pop r11;"
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
          

     //       //CHAPTER 1
     ////RIGHT AFTER RED GATE  DOOR
     //   "cTriggerEvent01:"
     //       "cmp dword ptr [r9], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9], 0x0101;"
     //       "mov rcx, [r9 + 0x01 * 0x4];"
     //       "jmp cStartTriggerEvent;"
     //       //AFTER 1st SAVE - GREY NINJA BOW ENCOUNTER AFTER WALL RUN (NINJA AMBUSH NEAR CHEST)
     //   "cTriggerEvent02:"
     //       "cmp dword ptr [r9 + 0x02 * 0x4], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9 + 0x02 * 0x4], 0x0101;"
     //       "mov rcx, [r9 + 0x03 * 0x4];"
     //       "jmp cStartTriggerEvent;"
     //       //AFTER 1st SAVE - AFTER CHEST JUMP DOWN
     //    "cTriggerEvent03:"
     //       "cmp dword ptr [r9 + 0x04 * 0x4], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9 + 0x04 * 0x4], 0x0101;"
     //       "mov rcx, [r9 + 0x05 * 0x4];"
     //       "jmp cStartTriggerEvent;"
     //       //AFTER 1st SAVE - 2nd CHEST
     //    "cTriggerEvent04:"
     //       "cmp dword ptr [r9 + 0x06 * 0x4], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9 + 0x06 * 0x4], 0x0101;"
     //       "mov rcx, [r9 + 0x07 * 0x4];"
     //       "jmp cStartTriggerEvent;"
     //       //BATTLE 05 - IS BATTLE - BEFORE 2nd SAVE
     //    "cTriggerEvent05:"
     //       "cmp dword ptr [r9 + 0x08 * 0x4], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9 + 0x08 * 0x4], 0x0101;"
     //       "mov rcx, [r9 + 0x09 * 0x4];"
     //       "jmp cStartTriggerEvent;"
     //       //BATTLE 06 - IS BATTLE - BEFORE 2nd SAVE
     //    "cTriggerEvent06:"
     //       "cmp dword ptr [r9 + 0x0A * 0x4], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9 + 0x0A * 0x4], 0x0101;"
     //       "mov rcx, [r9 + 0x0B * 0x4];"
     //       "jmp cStartTriggerEvent;"
     //       //BATTLE 07 - FIRST LEDGE RUN AFTER BUDDAH CUTSCENE
     //    "cTriggerEvent07:"
     //       "cmp dword ptr [r9 + 0x0C * 0x4], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9 + 0x0C * 0x4], 0x0101;"
     //       "mov  rcx, [r9 + 0x0D * 0x4];"
     //       "jmp cStartTriggerEvent;"
     //       //BATTLE 08 - GLASS BREAK AFTER DOOR
     //   "cTriggerEvent08:"
     //       "cmp dword ptr [r9 + 0x0E * 0x4], 0x0000;"
     //       "jne codecbattle;"
     //       "mov dword ptr [r9 + 0x0E * 0x4], 0x0101;"
     //       "mov rcx, [r9 + 0x0F * 0x4];"
     //       "mov byte ptr[r8 + 0x2E51D80], 0x01;"
     //       "mov byte ptr[r8 + 0x2E51D82], 0x01;"
     //       "jmp codecbattle;"
     //       //CHAPTER 1 END
       

                
      );
    }

  void __attribute__((naked))InjectAMaster() {
        	
        __asm__ volatile(".intel_syntax noprefix;"
            //ORIGINAL CODE
            "movzx edi, byte ptr [rdx];"
            "mov rsi,rcx;"
            "movzx ebp, byte ptr [rdx+01];"
            "xor r12d,r12d;"
            "movzx r14d, word ptr [rdx+04];"
            "push r8;"//NOT ORIGINAL
            "push r9;"//NOT ORIGINAL
            //INJECTED CODE
            "mov byte ptr [rip+cDeleteEnemy],0x00;"
            "lea r8, [rip+masterninjabtlCH14Tracker];"
            "mov r9,qword ptr [rip+baseAddress];"
            "cmp byte ptr [r9+0x35C421A],0x10;"
            "je chapter14;"
            "xor r8,r8;"
            "jmp codea;"
     //CHAPTER 14
       "chapter14:"
            "cmp bx, 0x27E0;"
            "je setenemyCHP1401;"
            "cmp bx, 0x5138;"
            "je setenemyCHP1406;"
            "cmp bx, 0x3988;"
            "je setenemyCHP1409;"
            "cmp bx, 0x1DF8;"
            "je setenemyCHP1409;"
            "cmp bx, 0x5320;"
            "je setenemyCHP1411;"
            "cmp bx, 0x7E70;"
            "je setenemyCHP14Gauntlet;"
            "jmp codea;"
            "setenemyCHP14Gauntlet:"
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [rip+cBattleRespawnCount3], 0x0C;"
            "jae setenemyCHP14GauntletWave2;"
            "cmp byte ptr [r9+0x21229B8], 0x0C;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "cmp byte ptr [r9+0x21229B8], 0x05;"
            "jle fiendism;"
            "cmp byte ptr [r9+0x21229B8], 0x0A;"
            "jle fiendgreym;"
            "inc byte ptr [rip+cBattleRespawnCount3];"
            "jmp fiendmage;"
            "setenemyCHP14GauntletWave2:"
            "cmp byte ptr [r9+0x21229B8], 0x00;"
            "jne codea;"
            "cmp byte ptr [rip+cBattleRespawnCount3], 0x10;"
            "je setenemyCHP14GauntletWave3;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [rdx+0x04], 0x0104;"
            "inc byte ptr [rip+cBattleRespawnCount3];"
            "jmp codea;"
            "setenemyCHP14GauntletWave3:"
            "cmp byte ptr [r9+0x21229B8], 0x00;"
            "jne codea;"
            "cmp byte ptr [rip+cBattleRespawnCount3], 0x12;"
            "jae setenemyCHP14GauntletWave4;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [rdx+0x04], 0x0104;"
            "inc byte ptr [rip+cBattleRespawnCount3];"
            "jmp codea;"
            "setenemyCHP14GauntletWave4:"
            "mov byte ptr [r9+0x35C3CBC], 0x22;"
            "jmp codea;"
            "setenemyCHP1401: "
            "cmp dword ptr [r8+0x0A*4], 0x0101;"
            "je setenemyCHP1405;"
            "cmp dword ptr [r8+0x08*4], 0x0101;"
            "je setenemyCHP1404;"
            "cmp dword ptr [r8+0x06*4], 0x0101;"
            "je setenemyCHP1404;"
            "cmp dword ptr [r8+0x04*4], 0x0101;"
            "je setenemyCHP1403;"
            "cmp dword ptr [r8+0x02*4], 0x0101;"
            "je setenemyCHP1402;"
            "cmp dword ptr [r8], 0x0101;"
            "jne codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x08;"
            "jae codea;"
            "mov dword ptr [r8], 0x0F0F;"
            "cmp byte ptr [rip+cBattleRespawnCount], 0x10;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8], 0x0101;"
            "cmp byte ptr [r9+0x21229B8], 0x07;"
            "jae setenemyCHP1401a;"
            "inc byte ptr [rip+scounter];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "cmp byte ptr [rip+scounter], 0x03;"
            "jle greyninjabow;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "cmp byte ptr [rip+scounter], 0x05;"
            "jle fiendgreym;"
            "cmp byte ptr [rip+scounter], 0x07;"
            "jle fiendism;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "jmp codea;"
            "setenemyCHP1401a: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "inc byte ptr [rip+cBattleRespawnCount];"
            "cmp byte ptr [rip+entDied], 0x2F;"
            "je fiendgreym;"
            "jmp fiendism;"
            "setenemyCHP1402: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x08;"
            "jae setenemyCHP1402a;"
            "inc byte ptr [rip+cBattleRespawnCount2];"
            "inc byte ptr [rip+scounter2];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "inc byte ptr [rip+scounter2];"
            "cmp byte ptr [rip+scounter2], 0x03;"
            "jle fiendgreym;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "jmp codea;"
            "setenemyCHP1402a: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x08;"
            "jae codea;"
            "mov dword ptr [r8+0x02*4], 0x0F0F;"
            "inc byte ptr [rip+cBattleRespawnCount2];"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x1A;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x02*4], 0x0101;"
            "mov byte ptr [rdx+0x04], 0x2F;"
            "cmp byte ptr [rip+entDied], 0x2F;"
            "je codea;"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x0D;"
            "jae codea;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "jmp codea;"
            "setenemyCHP1403: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "cmp byte ptr [rip+cBattleRespawnCount3], 0x00;"
            "jnz setenemyCHP1403a;"
            "inc byte ptr [rip+scounter3];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "cmp byte ptr [rip+scounter3], 0x06;"
            "jle codea;"
            "mov byte ptr [rip+cBattleRespawnCount3], 0x01;"
            "jmp codea;"
            "setenemyCHP1403a: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x06;"
            "jae codea;"
            "mov dword ptr [r8+0x04*4], 0x0F0F;"
            "cmp byte ptr [rip+cBattleRespawnCount3], 0x12;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x04*4], 0x0101;"
            "inc byte ptr [rip+cBattleRespawnCount3];"
            "jmp codea;"
            "setenemyCHP1404: "
            "cmp byte ptr [rip+cBattleRespawnCount4], 0x09;"
            "jae setenemyCHP1404a;"
            "inc byte ptr [rip+cBattleRespawnCount4];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "cmp byte ptr [rip+cBattleRespawnCount4], 0x02;"
            "jle greyninjabow;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "jmp codea;"
            "setenemyCHP1404a: "
            "mov dword ptr [r8+0x08*4], 0x0F0F;"
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x08;"
            "jae codea;"
            "mov dword ptr [r8+0x06*4], 0x0F0F;"
            "mov dword ptr [r8+0x08*4], 0x0F0F;"
            "inc byte ptr [rip+cBattleRespawnCount4];"
            "cmp byte ptr [rip+cBattleRespawnCount4], 0x18;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x06*4], 0x0101;"
            "mov dword ptr [r8+0x08*4], 0x0F0F;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "jmp codea;"
            "setenemyCHP1405: "
            "cmp byte ptr [rip+cBattleRespawnCount5], 0x06;"
            "jae setenemyCHP1405a;"
            "inc byte ptr [rip+cBattleRespawnCount5];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "jmp codea;"
            "setenemyCHP1405a: "
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x06;"
            "jae codea;"
            "mov dword ptr [r8+0x0A*4], 0x0F0F;"
            "inc byte ptr [rip+cBattleRespawnCount5];"
            "cmp byte ptr [rip+cBattleRespawnCount5], 0x14;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x0A*4], 0x0101;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "jmp codea;"

            // Transitioning to setenemyCHP1406 through the logic for battle counts and state changes
            "setenemyCHP1406: "
            "cmp dword ptr [r8+0x10*4], 0x0101;"
            "je setenemyCHP1408;"
            "cmp dword ptr [r8+0x0E*4], 0x0101;"
            "je setenemyCHP1407;"
            "cmp dword ptr [r8+0x0C*4], 0x0101;"
            "je setenemyCHP1406a;"
            "inc byte ptr [rip+cBattleRespawnCount6];"
            "cmp byte ptr [rip+cBattleRespawnCount6], 0x02;"
            "jle greyninjabow;"
            "jmp fiendgreym;"
            "setenemyCHP1406a: "
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x03;"
            "jae setenemyCHP1406c;"
            "mov dword ptr [r8+0x0C*4], 0x0F0F;"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x07;"
            "jae setenemyCHP1406b;"
            "mov dword ptr [r9+0x02DD5328], 0x0101;"
            "inc byte ptr [rip+cBattleRespawnCount2];"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x0C*4], 0x0101;"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x02;"
            "jle greyninjabow;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x2F;"
            "jmp codea;"
            "setenemyCHP1406b: "
            "mov byte ptr [rip+cBattleRespawnCount2], 0x03;"
            "mov dword ptr [r8+0x0C*4], 0x0101;"
            "setenemyCHP1406c: "
            "mov dword ptr [r8+0x0C*4], 0x0F0F;"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x0F;"
            "jae codea;"
            "mov dword ptr [r8+0x0C*4], 0x0101;"
            "cmp byte ptr [r9+0x21229B8], 0x08;"
            "jae codea;"
            "inc byte ptr [rip+cBattleRespawnCount2];"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x2F;"
            "jmp codea;"
            // setenemyCHP1407 logic
            "setenemyCHP1407: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "cmp byte ptr [rip+cBattleRespawnCount3], 0x06;"
            "jae setenemyCHP1407a;"
            "inc byte ptr [rip+cBattleRespawnCount3];"
            "jmp codea;"
            "setenemyCHP1407a: "
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x06;"
            "jae codea;"
            "mov dword ptr [r8+0x0E*4], 0x0F0F;"
            "cmp byte ptr [rip+cBattleRespawnCount3], 0x14;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "inc byte ptr [rip+cBattleRespawnCount3];"
            "mov dword ptr [r8+0x0E*4], 0x0101;"
            "jmp codea;"

            // setenemyCHP1408 and onwards
            "setenemyCHP1408: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "cmp byte ptr [rip+cBattleRespawnCount4], 0x05;"
            "jae setenemyCHP1408a;"
            "inc byte ptr [rip+cBattleRespawnCount4];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "jmp codea;"
            "setenemyCHP1408a: "
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x04;"
            "jae codea;"
            "mov dword ptr [r8+0x10*4], 0x0F0F;"
            "inc byte ptr [rip+cBattleRespawnCount4];"
            "cmp byte ptr [rip+cBattleRespawnCount4], 0x0F;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x10*4], 0x0101;"
            "jmp codea;"
            "setenemyCHP1409: "
            "cmp dword ptr [r8+0x14*4], 0x0101;"
            "je setenemyCHP1410;"
            "cmp dword ptr [r8+0x12*4], 0x0101;"
            "jne codea;"
            "cmp byte ptr [rip+cBattleRespawnCount5], 0x05;"
            "jae setenemyCHP1409a;"
            "inc byte ptr [rip+cBattleRespawnCount5];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "jmp codea;"
            "setenemyCHP1409a: "
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x06;"
            "jae codea;"
            "mov dword ptr [r8+0x12*4], 0x0F0F;"
            "inc byte ptr [rip+cBattleRespawnCount5];"
            "cmp byte ptr [rip+cBattleRespawnCount5], 0x0F;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x12*4], 0x0101;"
            "jmp codea;"

            // setenemyCHP1410 logic
            "setenemyCHP1410: "
            "cmp byte ptr [rip+cBattleRespawnCount6], 0x05;"
            "jae setenemyCHP1410a;"
            "inc byte ptr [rip+cBattleRespawnCount6];"
            "mov byte ptr [rip+canSpawn], 0x01;"
            "jmp codea;"
            "setenemyCHP1410a: "
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x06;"
            "jae codea;"
            "mov dword ptr [r8+0x14*4], 0x0F0F;"
            "inc byte ptr [rip+cBattleRespawnCount6];"
            "cmp byte ptr [rip+cBattleRespawnCount6], 0x0F;"
            "jae codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "mov dword ptr [r8+0x14*4], 0x0101;"
            "jmp codea;"

            // setenemyCHP1411 logic
            "setenemyCHP1411: "
            "mov byte ptr [rdx+0x04], 0xA5;"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x08;"
            "jae setenemyCHP1411a;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "inc byte ptr [rip+cBattleRespawnCount2];"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x02;"
            "jle codea;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "mov byte ptr [rip+entDied], 0x00;"
            "jmp codea;"
            "setenemyCHP1411a: "
            "mov byte ptr [rip+cDeleteEnemy], 0x01;"
            "cmp byte ptr [r9+0x21229B8], 0x03;"
            "jae codea;"
            "mov dword ptr [r8+0x16*4], 0x0F0F;"
            "cmp byte ptr [rip+cBattleRespawnCount2], 0x0A;"
            "jae codea;"
            "mov dword ptr [r8+0x16*4], 0x0101;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "cmp byte ptr [rip+entDied], 0xA5;"
            "jne codea;"
            "mov byte ptr [rip+cDeleteEnemy], 0x00;"
            "inc byte ptr [rip+cBattleRespawnCount2];"
            "mov byte ptr [rdx+0x04], 0xA5;"
            "jmp codea;"
            // fiendism:
            "fiendism: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x70;"
            "jmp codea;"
            // fiendgreym:
            "fiendgreym: "
            "mov byte ptr [rdx+0x1C], 0x03;"
            "mov byte ptr [rdx+0x04], 0x2F;"
            "jmp codea;"
            // fiendmage:
            "fiendmage: "
            "mov byte ptr [rdx+0x04], 0x7C;"
            "jmp codea;"
            // greyninjabow:
            "greyninjabow: "
            "mov byte ptr [rdx+0x04], 0x9D;"
            "mov byte ptr [rdx+0x1C], 0x05;"
            "mov byte ptr [rdx+0x2C], 0x03;"
            "mov byte ptr [rdx+0x30], 0x28;"
            "mov byte ptr [rdx+0x31], 0x00;"
            "mov byte ptr [rdx+0x38], 0x04;"
            "mov byte ptr [rdx+0x3C], 0x29;"
            "mov byte ptr [rdx+0x3D], 0x00;"
            "jmp codea;"

      "codea:"
            "mov byte ptr [rip+canSpawn], 0x00;"
            "mov byte ptr [rip+counter], 0x00;"
            "pop r9;"
            "pop r8;"
 
            "jmp qword ptr [rip + returnInjectA];"
     );
}


  void __attribute__((naked))InjectDelimb1() {

      __asm__ volatile(".intel_syntax noprefix;"
          //ORIGINAL CODE
          "push rcx;"
          "mov rcx, qword ptr [rip+baseAddress];"
          "cmp r14,0xFFFF;"
          "je 2f;"
          "cmp r14,0xC7C;"
          "je 3f;"
          "cmp r14,0xC7A;"
          "je 3f;"
          "cmp r14,0xD6E;"
          "je 3f;"
          "cmp r14,0xCA8;"
          "je 3f;"
          "cmp r14,0x7BB;"
          "je 3f;"
          "movss xmm15, [rip+resistance];"
          "comiss xmm15,[rax+0x18];"
          "jle setDelimb;"
          "jmp setDelimb;"
      "2:"
          "movss xmm15, [rip+resistance];"
          "movss dword ptr [rax+0x18], xmm15;"
          "jmp 1f;"
     "3:"
          "movss xmm15, [rip+newVal3];"
          "movss dword ptr [rax+0x18], xmm15;"
          "cmp byte ptr [rcx+0x211E5CE],0x00;"
          "je 1f;"
          "movss xmm15, [rip+newVal4];"
          "movss dword ptr [rax+0x18], xmm15;"
          "jmp 1f;"
      "setDelimb:"
          "movss xmm15, [rip+newVal1];"
          //"movss xmm15, [rip+newVal3];"
     "setDelimb2:"
          "movss dword ptr [rax+0x18], xmm15;"       
       "1:"
          "movss xmm3, [rax+0x18];"
          "mov rax,[rcx+0x1E37618];"       
          "pop rcx;"
          "cmp byte ptr [rax+0x000003DE],0xFF;"
          "jmp qword ptr [rip+returnInjectDelimb1];"
          );
  }

 /*void __attribute__((naked)) InjectDelimb2() {
    __asm__ volatile(".intel_syntax noprefix;"
         //ORIGINAL CODE
         "movss xmm15, [rip+detectTest];"
         "movss xmm14, [r9+0x01*0x4];"
         "comiss xmm14, xmm15;"
         "je detect1;"
         "jmp 1f;"
       "detect1:"
         "movss xmm15, [rip+detectTest2];"
         "movss xmm14, [r9+0x04*0x4];"
         "comiss xmm14, xmm15;"
         "je detect2;"
         "jmp 1f;"
       "detect2:"
          "movss xmm15, [rip+newVal1];"
          "movss dword ptr [r9 + 0x01 * 0x4],xmm15;"
          "movss xmm15, [rip+newVal2];"
          "movss dword ptr [r9 + 0x04 * 0x4], xmm15;"
       "1:"
         "movups xmmword ptr [r10], xmm0;"
         "movsd qword ptr [r10+0x10], xmm1;"
         "add rsp, 0x20;"
         "jmp qword ptr [rip+returnInjectDelimb2]"
         );
}*/

 void __attribute__((naked)) InjectDelimb2() {
     __asm__ volatile(".intel_syntax noprefix;"
         //ORIGINAL CODE
        /* "movss xmm15, [rip+detectTest];"
         "movss xmm14, [r9+0x01*0x4];"
         "comiss xmm14, xmm15;"
         "je detect1;"
         "jmp 1f;"
         "detect1:"*/
         "cmp bp, 0x7100;"
         "je 1f;"
         "movss xmm15, [rip+detectTest2];"
         "movss xmm14, [r9+0x04*0x4];"
         "comiss xmm14, xmm15;"
         "jle detect2;"
         "addss xmm15, xmm15;"
         "comiss xmm14,xmm15;"
         "je detect2;"
         "jmp 1f;"
         "detect2:"
         "movss xmm15, [rip+newVal2];"
         "movss dword ptr [r9 + 0x00 * 0x8 + 0x10],xmm15;"
         "movss xmm15, [rip+newVal1];"
         "movss dword ptr [r9 + 0x00 * 0x8 + 0x14], xmm15;"
         "movss dword ptr[r9 + 0x00 * 0x8 + 0x04], xmm15;"
         "1:"
         "movups xmmword ptr [r10], xmm0;"
         "movsd qword ptr [r10+0x10], xmm1;"
         "add rsp, 0x20;"
         "jmp qword ptr [rip+returnInjectDelimb2]"
         );
 }

 void __attribute__((naked)) InjectGaja() {

     __asm__ volatile(".intel_syntax noprefix;"
         "push r13;"
         "lea rbp, [rax-0x57];"
         "sub rsp, 0x00000100;"
         "movaps [rax-0x38], xmm6;"
         "mov r13, qword ptr [rip + baseAddress];"
         "cmp byte ptr [r13 + 0x319CBE6], 0x11;"
         "je weaponValid;"
         "cmp byte ptr [r13 + 0x31A2896], 0x11;"
         "je weaponValid;"
         "jmp 1f;"
         "weaponValid:"
         "cmp bx, 0x7988;"
         "je entityGaja;"
         "cmp bx, 0x1288;"
         "je entityGaja;"
         "jmp 1f;"
         "entityGaja:"
         "cmp r9, 0x8e;"
         "je resetGaja;"
         "jmp 1f;"
         "resetGaja:"
         "mov r9, 0x83;"
         "mov rax, rsp;"
         "mov [rax + 0x08], r13;"
        "1:"
         "pop r13;"
         "jmp qword ptr [rip + returnInjectGaja];"
         );
 }



