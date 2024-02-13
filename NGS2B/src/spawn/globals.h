#include <windows.h>
#include <cstdint>

//DLL MODULE BASE ADDRESS
extern "C" DWORD_PTR baseAddress;

//MEM ADDRESS OFFSET OF ACTIVE CHAPTER
extern "C" const unsigned int activeChapterOffset;

//SPAWN LOGIC RESTRICTIVE ENTITY SPAWN COUNTER
extern "C" uint8_t scounter;

//KEEP TRACK OF HOW MANY TIMES ACTIVE SPAWN HAS BEEN RECALLED
extern "C" uint8_t cBattleRespawnCount;

//1 = DELETE ENEMY, 0 = DO NOT DELETE ENEMY
extern "C" uint8_t cDeleteEnemy;

//DETOUR JUMP BACK ADDRESSES
extern "C" DWORD_PTR returnInjectCBattle;
extern "C" DWORD_PTR returnInjectCoords;
extern "C" DWORD_PTR returnInjectC;

//1 = RECALL SPAWN LOOP LOGIC, ACTIVE ENEMY SET TO SPAWN WILL MULTIPLY UNTIL THIS IS SET BACK TO 0
extern "C" uint8_t canSpawn;

