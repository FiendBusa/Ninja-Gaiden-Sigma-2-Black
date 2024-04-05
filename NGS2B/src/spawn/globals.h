#include <windows.h>
#include <cstdint>

//DLL MODULE BASE ADDRESS
extern "C" DWORD_PTR baseAddress;

//MEM ADDRESS OFFSET OF ACTIVE CHAPTER
extern "C" const unsigned int activeChapterOffset;

extern "C" const unsigned int deleteSpawnSkipAddress;

//SPAWN LOGIC RESTRICTIVE ENTITY SPAWN COUNTER
extern "C" uint8_t scounter; 
extern "C" uint8_t scounter2;
extern "C" uint8_t scounter3;
extern "C" uint8_t scounter4;
extern "C" uint8_t scounter5;
extern "C" uint8_t scounter6;
//LOOSE ENTITY SPAWN COUNTER
extern "C" uint8_t counter;

//KEEP TRACK OF HOW MANY TIMES ACTIVE SPAWN HAS BEEN RECALLED
extern "C" uint8_t cBattleRespawnCount;
extern "C" uint8_t cBattleRespawnCount2;
extern "C" uint8_t cBattleRespawnCount3;
extern "C" uint8_t cBattleRespawnCount4;
extern "C" uint8_t cBattleRespawnCount5;
extern "C" uint8_t cBattleRespawnCount6;

//1 = DELETE ENEMY, 0 = DO NOT DELETE ENEMY
extern "C" uint8_t cDeleteEnemy;

//WHAT ENEMY WAS LAST KILLED BY PLAYER
extern "C" uint8_t entDied;

//DETOUR JUMP BACK ADDRESSES
extern "C" DWORD_PTR returnInjectCBattle;
extern "C" DWORD_PTR returnInjectCoords;
extern "C" DWORD_PTR returnInjectC;
extern "C" DWORD_PTR returnInjectA;
extern "C" DWORD_PTR returnInjectDisableSpawns;
extern "C" DWORD_PTR returnInjectDelimb1;
extern "C" DWORD_PTR returnInjectDelimb2;
extern "C" DWORD_PTR returnInjectGaja;
extern "C" DWORD_PTR returnInjectEntDie;
extern "C" DWORD_PTR returnInjectDontDisableBattle;
extern "C" DWORD_PTR returnInjectReset;
extern "C" DWORD_PTR returnInjectTelePlayer;
extern "C" DWORD_PTR returnInjectTripleIS;
extern "C" DWORD_PTR returnInjectSound;

//1 = RECALL SPAWN LOOP LOGIC, ACTIVE ENEMY SET TO SPAWN WILL MULTIPLY UNTIL THIS IS SET BACK TO 0
extern "C" uint8_t canSpawn;

extern "C" uint8_t minimumspawn;
extern "C" uint8_t maximumspawn;
extern "C" uint8_t chpstage;

extern "C" float resistance;
extern "C" float detectTest;
extern "C" float detectTest2;
extern "C" float newVal1;
extern "C" float newVal2;
extern "C" float newVal3;
extern "C" float newVal4;

extern "C" float teleCoords;
extern "C" float telePlayer;



