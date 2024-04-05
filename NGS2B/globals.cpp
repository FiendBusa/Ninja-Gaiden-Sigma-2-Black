#include "pch.h"
#include "src/spawn/globals.h"


DWORD_PTR baseAddress = NULL;


const unsigned int activeChapterOffset = 0x35C421A;
const unsigned int deleteSpawnSkipAddress = 0x161958F;


uint8_t scounter = 0;
uint8_t scounter2 = 0;
uint8_t scounter3 = 0;
uint8_t scounter4 = 0;
uint8_t scounter5 = 0;
uint8_t scounter6 = 0;
uint8_t cBattleRespawnCount = 0;
uint8_t cBattleRespawnCount2 = 0;
uint8_t cBattleRespawnCount3 = 0;
uint8_t cBattleRespawnCount4 = 0;
uint8_t cBattleRespawnCount5 = 0;
uint8_t cBattleRespawnCount6 = 0;
uint8_t cDeleteEnemy = 0;
uint8_t counter = 0;
uint8_t entDied = 0;


DWORD_PTR returnInjectCBattle = 0;
DWORD_PTR returnInjectCoords = 0;
DWORD_PTR returnInjectC = 0;
DWORD_PTR returnInjectA = 0;
DWORD_PTR returnInjectDisableSpawns = 0;
DWORD_PTR returnInjectDelimb1 = 0;
DWORD_PTR returnInjectDelimb2 = 0;
DWORD_PTR returnInjectGaja = 0;
DWORD_PTR returnInjectEntDie = 0;
DWORD_PTR returnInjectDontDisableBattle = 0;
DWORD_PTR returnInjectReset = 0;
DWORD_PTR returnInjectTelePlayer = 0;
DWORD_PTR returnInjectTripleIS = 0;
DWORD_PTR returnInjectSound = 0;

uint8_t canSpawn = 0;

uint8_t minimumspawn = 0;
uint8_t maximumspawn = 0;
uint8_t chpstage = 0;

float resistance = 0.50f;
float detectTest = 1.70f;
float detectTest2 = 50.0f;
float newVal1 = 1.0f;
float newVal2 = 100.0f;
float newVal3 = 1.70f;
float newVal4 = 2.00f;
float teleCoords = 0.00f;
float telePlayer = 0.00f;


