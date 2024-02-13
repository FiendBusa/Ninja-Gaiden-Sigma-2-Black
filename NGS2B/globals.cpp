#include "pch.h"
#include "src/spawn/globals.h"


DWORD_PTR baseAddress = NULL;


const unsigned int activeChapterOffset = 0x35C421A;


uint8_t scounter = 0;
uint8_t cBattleRespawnCount = 0;
uint8_t cDeleteEnemy = 0;

DWORD_PTR returnInjectCBattle = 0;
DWORD_PTR returnInjectCoords = 0;
DWORD_PTR returnInjectC = 0;

uint8_t canSpawn = 0;