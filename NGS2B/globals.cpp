#include "pch.h"
#include "src/spawn/globals.h"
#include <limits>


DWORD_PTR baseAddress = NULL;
DWORD_PTR inventoryStartAddress = 0x35C3C94;
DWORD_PTR lockcamAdd1 = 0x211E768;
DWORD_PTR lockcamAdd2 = 0x2FF2790;
DWORD_PTR lockcamAdd3 = 0x211E778;
DWORD_PTR playerAnimationOffset = 0x319CC30;


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
uint8_t cBattleRespawnCount7 = 0;
uint8_t cBattleRespawnCount8 = 0;
uint8_t cBattleRespawnCount9 = 0;
uint8_t cBattleRespawnCount10 = 0;
uint8_t cBattleRespawnCount11 = 0;
uint8_t cBattleRespawnCount12 = 0;
uint8_t cBattleRespawnCount13 = 0;
uint8_t cBattleRespawnCount14 = 0;
uint8_t cBattleRespawnCount15 = 0;
uint8_t cBattleRespawnCount16 = 0;
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
DWORD_PTR returnInjectAnim = 0;
DWORD_PTR returnInjectStrigger = 0;
DWORD_PTR returnInjectEntData = 0;
DWORD_PTR returnInjectEntDataAnim = 0;
DWORD_PTR returnInjectClip = 0;
DWORD_PTR returnInjectInventory = 0;
DWORD_PTR returnInjectInventoryCCNew = 0;
DWORD_PTR returnInjectCorpse = 0;
DWORD_PTR returnInjectHalfCut = 0;
DWORD_PTR returnInjectDelimbAnim = 0;
DWORD_PTR returnInjectDelimbFiends = 0;
DWORD_PTR returnInjectAIDodge = 0;
DWORD_PTR returnInjectAIDodgeCMP = 0;
DWORD_PTR returnInjectAIDodgePAddress = 0;
DWORD_PTR returnInjectAIDodgeCan = 0;
DWORD_PTR returnInjectGuilIzunaDmg = 0;
DWORD_PTR returnInjectGuilIzunaDmgJbe = 0;
DWORD_PTR returnInjectBlackSmith = 0;
DWORD_PTR returnInjectWeaponUpgrade = 0;
DWORD_PTR returnInjectWeaponUpgradeDontAllow = 0;
DWORD_PTR returnInjectEssRemoval = 0;
DWORD_PTR returnInjectREHP = 0;
DWORD_PTR returnInjectScytheDelimb = 0;
DWORD_PTR returnInjectScytheDelimbAddress = 0;
DWORD_PTR returnInjectFreeCam = 0;
DWORD_PTR returnInjectFreeCamCall = 0;
DWORD_PTR returnInjectLockCam = 0;
DWORD_PTR returnInjectAirFrame = 0;
DWORD_PTR returnInjectSpecialEffects = 0;
DWORD_PTR returnInjectBloom = 0;
DWORD_PTR returnInjectFOV = 0;
DWORD_PTR returnInjectSpecialEffectsApply = 0;
DWORD_PTR injectSpecialEffectsApplyCMP = 0x211E753;
DWORD_PTR injectSpecialEffectsJNE = 0xF2E7F6;

DWORD_PTR injectSpecialEffectsJa = 0x1031F3C;

DWORD_PTR returnInjectIFrames = 0;
DWORD_PTR returnInjectInput = 0;

DWORD_PTR striggerOffset = 0;

DWORD_PTR returnInjectAttackCancel = 0;
DWORD_PTR attackCancelJNE = 0xF56866;
DWORD_PTR attackCancelMOV = 0x1914C20;
DWORD_PTR attackCancelMOVRSI = 0x2FA65C8;

DWORD_PTR returnInjectDiffLoad = 0;

uint8_t canSpawn = 0;
//DONT ASK
uint8_t canspawn2 = 0;

//WATER DRAGON CAN PERFORM WATER ATTACKS
bool canWaterDragonAttacks = false;
bool canWaterDragonOT = false;


uint8_t minimumspawn = 0;
uint8_t maximumspawn = 0;
uint8_t chpstage = 0;

float resistance = 0.50f;
float detectTest = 1.70f;
float detectTest2 = 50.0f;
float newVal1 = 1.0f;
float newVal2 = 100.0f;
float newVal3 = 1.20f;
float newVal4 = 1.20f;
float teleCoords = 0.00f;
float telePlayer = 0.00f;
float resistancemax = -1.00f;
float guilthrowDmgMulp = 1.50f;
float scytheDelimbMulp = 4.00f;
float enmaDelimbMulp = 3.00f;
float femaleDelimbMulp = 2.50f;
float highDelimbMulp = 1.80f;


int randomNumber = 0;
int needNum = 0;

//PLAYER AND ENEMY TARGET INFORMATION
uint8_t ent;
uint64_t enthitadd;
uint64_t enthitadd2;
uint8_t state;

bool inventoryCCNew = false;
bool canHalfCut = false;

float corpseTimer = std::numeric_limits<float>::infinity();
float corpseTimerLycans = 1800.00f;

//ANIM MANIPULATION THINGS
uint16_t fsDelimbTable[]{
    0x322,
    0x246,
    0x250,
    0x25A,
    0x1F5,
    0xC7A,
    0xC7C,
    0xD6E,
    0xD66,
    0xCA8,
    0x7BB,
    0x3A6,
    

};

uint16_t fsFloorTable[]{
	0x231,
	0x431,
	0x1E3,
	0x110,
	0x15E,
	0x118,
	0x11C

};

uint16_t halfCutEnts[]{
    0x9C,
    0x08,
    0x9D,
    0x04,
    0x7C,
    0xA1,
    0x28,
    0x70,
    0x2F,
    0x38,
    0xF1

};

uint16_t shurTable[] = {
    0x03B6, // 950
    0x03B7, // 951
    0x03B8, // 952
    0x03B9, // 953
    0x03BA, // 954
    0x03BB, // 955
    0x03BC, // 956
    0x03BD, // 957
    0x03BE, // 958
    0x03BF, // 959
    0x03C0, // 960
    0x0DF4, // DF4
    0x0E01, // E01
    0x0E02, // E02
    0x0E03, // E03
    0x0E04, // E04
    0x0E05, // E05
    0x0E06, // E06
    0x0E07, // E07
    0x0E08, // E08
    0x0E09, // E09
    0x0E10, // E10
    0x0E11, // E11
    0x0135, // 309
    0x0196, // 406
    0x0140, // 320
    0x0139  // 313
};

uint16_t fsMoveTable[] = {
    0x0C7A, // C7A
    0x0C7C, // C7C
    0x0D6E, // D6E
    0x0CA8, // CA8
    0x0D66, // D66
    0x07BB  // 7BB
};

uint16_t lycanHalfCutTable[] = {
    0x049A, //DS
    0x049E, //BOTA 0E
    0x04A2, //CLAWS 0B
    0x04A6, //SCYTHE
};

uint16_t specialEffectTable[] = {
    0x002B,//IS THROW
    0x0023//INC SHURIKEN
};

uint16_t halfcut = 0;
uint16_t floorcutcry = 0;
uint16_t floorcutcryleg = 0;

//BLACK SMITH
uint16_t weaponUpgradeCost = 30000;
uint16_t masterUpgradeCost = 30000;
uint16_t warriorUpgradeCost = 20000;
bool canUpgradeWep = false;

//REHP
REHPTable reHPTable[] = {
    {0x39, 0.50f },//WATER DRAGON
    //{0x9D, 1.50f },//GREY NINJA (LOW HP ARCHER FIX)
};

std::vector<attackCancelTable> attackCancelList;

int attackCancelListSize = 0;

uint32_t userInput = 0x00000000;

//FREE CAMERA TABLE
//uint16_t freeCamTable[] = {
//    0x015,
//    0x0B6,
//    0x01D
//};

BYTE diffInjected = 0;

//NG2 SHINE
bool ng2Shine = true;

//ENEMY AI
bool isNinjaGrabSpeed = false;
bool greyNinjaGrabSpeed = false;
bool zedGrabSpeed = false;
bool lizGrabSpeedTail = true;

float bloomIntensity = 0.25f;

//AUDIO
BYTE mainMenuTrack = 0x3E;
BYTE ch1HeroTrack = 0x3D;
BYTE ch14HeroTrack = 0x4D;
bool configChime = true;

//GAMEPLAY
bool animationSmoothing = true;
bool quickSelectBlur = false;
BYTE microStutter = 0x00;
float fovValue = 1.0f;
bool whiteFlash = true;
bool disableEssence = false;
bool hasFullAirborneIframes = false;
bool ultimateNinja = false;


//DANGER ZONE
bool instantResume = false;

//CAMERA
bool isFreeCamAll = false;
bool isFreeCamIzunaOnly = true;

//DEBUG
bool noClip = false;
bool freezeEnemies = false;
bool disableDelimb = false;
bool windowAlwaysReadInputs = false;

//SPAWN
bool ch1RasetsuDisableMinions = false;
bool skipCH1StatueEncOne = false;
bool skipCH4Statue = false;

//INTERFACE
bool vibrantMainMenu = true;
DWORD_PTR menuIDOffset = 0x1F22AE0; //WHAT SECTION OF THE MENU IS ACTIVE
DWORD_PTR vibrantMainMenuAddress[] = {
    0xDCC255,
    0xDCC269
};
bool saveLastFrame = false;
