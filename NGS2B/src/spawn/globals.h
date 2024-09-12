#include <windows.h>
#include <cstdint>
#include <vector>

//DLL MODULE BASE ADDRESS
extern "C" DWORD_PTR baseAddress;

//INVENTORY START ADDRESS
extern "C" DWORD_PTR inventoryStartAddress;

//LOCK CAM ADDRESS
extern "C" DWORD_PTR lockcamAdd1;
extern "C" DWORD_PTR lockcamAdd2;
extern "C" DWORD_PTR lockcamAdd3;

//SPECIAL EFFECTS JA OFFSET
extern "C" DWORD_PTR injectSpecialEffectsJa;

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
extern "C" uint8_t cBattleRespawnCount7;
extern "C" uint8_t cBattleRespawnCount8;
extern "C" uint8_t cBattleRespawnCount9;
extern "C" uint8_t cBattleRespawnCount10;
extern "C" uint8_t cBattleRespawnCount11;
extern "C" uint8_t cBattleRespawnCount12;
extern "C" uint8_t cBattleRespawnCount13;
extern "C" uint8_t cBattleRespawnCount14;
extern "C" uint8_t cBattleRespawnCount15;
extern "C" uint8_t cBattleRespawnCount16;

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
extern "C" DWORD_PTR returnInjectAnim;
extern "C" DWORD_PTR returnInjectStrigger;
extern "C" DWORD_PTR returnInjectEntData;
extern "C" DWORD_PTR returnInjectEntDataAnim;
extern "C" DWORD_PTR returnInjectClip;
extern "C" DWORD_PTR returnInjectInventory;
extern "C" DWORD_PTR returnInjectInventoryCCNew;
extern "C" DWORD_PTR returnInjectCorpse;
extern "C" DWORD_PTR returnInjectHalfCut;
extern "C" DWORD_PTR returnInjectDelimbAnim;
extern "C" DWORD_PTR returnInjectDelimbFiends;
extern "C" DWORD_PTR returnInjectAIDodge;
extern "C" DWORD_PTR returnInjectAIDodgeCMP;
extern "C" DWORD_PTR returnInjectAIDodgePAddress;
extern "C" DWORD_PTR returnInjectAIDodgeCan;
extern "C" DWORD_PTR returnInjectGuilIzunaDmg;
extern "C" DWORD_PTR returnInjectGuilIzunaDmgJbe;
extern "C" DWORD_PTR returnInjectBlackSmith;
extern "C" DWORD_PTR returnInjectWeaponUpgrade;
extern "C" DWORD_PTR returnInjectWeaponUpgradeDontAllow;
extern "C" DWORD_PTR returnInjectEssRemoval;
extern "C" DWORD_PTR returnInjectREHP;
extern "C" DWORD_PTR returnInjectScytheDelimb;
extern "C" DWORD_PTR returnInjectScytheDelimbAddress;
extern "C" DWORD_PTR returnInjectFreeCam;
extern "C" DWORD_PTR returnInjectFreeCamCall;
extern "C" DWORD_PTR returnInjectLockCam;
extern "C" DWORD_PTR returnInjectAirFrame;
extern "C" DWORD_PTR returnInjectSpecialEffects;
extern "C" DWORD_PTR returnInjectBloom;
extern "C" DWORD_PTR returnInjectFOV;
extern "C" DWORD_PTR returnInjectSpecialEffectsApply;
extern "C" DWORD_PTR injectSpecialEffectsApplyCMP;
extern "C" DWORD_PTR injectSpecialEffectsJNE;
extern "C" DWORD_PTR playerAnimationOffset;
extern "C" DWORD_PTR returnInjectIFrames;
extern "C" DWORD_PTR returnInjectInput;
extern "C" DWORD_PTR returnInjectAttackCancel;
extern "C" DWORD_PTR attackCancelJNE;
extern "C" DWORD_PTR attackCancelMOV;
extern "C" DWORD_PTR attackCancelMOVRSI;
extern "C" DWORD_PTR returnInjectDiffLoad;

//extern "C" DWORD_PTR returnInjectAlpha;

//1 = RECALL SPAWN LOOP LOGIC, ACTIVE ENEMY SET TO SPAWN WILL MULTIPLY UNTIL THIS IS SET BACK TO 0
extern "C" uint8_t canSpawn;
//DONT ASK
extern "C" uint8_t canspawn2;

//WATER DRAGON CAN PERFORM WATER ATTACKS
extern "C" bool canWaterDragonAttacks;
extern "C" bool canWaterDragonOT;


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
extern "C" float resistancemax;
extern "C" float guilthrowDmgMulp;


extern "C" float teleCoords;
extern "C" float telePlayer;

//RANDOM NUMBER FOR VARIOUS PURPOSES
extern "C" int randomNumber;
extern "C" int needNum;

//STRIGGER ADDRESS (OFFSET)
extern "C" DWORD_PTR striggerOffset;

//PLAYER AND ENEMY TARGET INFORMATION
extern "C" uint8_t ent;
extern "C" uint64_t enthitadd;
extern "C" uint64_t enthitadd2;
extern "C" uint8_t state;

//ANIM MANIPULATION THINGS
extern "C" uint16_t fsDelimbTable[];
extern "C" uint16_t fsFloorTable[];
extern "C" uint16_t shurTable[];
extern "C" uint16_t fsMoveTable[];
extern "C" uint16_t halfcut;
extern "C" uint16_t floorcutcry;
extern "C" uint16_t floorcutcryleg;
extern "C" bool canHalfCut;

extern "C" bool inventoryCCNew;

//FIX FOR TOO MANY LYCANS ON SCREEN CAUSING GLITCHES
extern "C" float corpseTimer;
extern "C" float corpseTimerLycans;

extern "C" uint16_t halfCutEnts[];

extern "C" uint16_t lycanHalfCutTable[];

//BLACK SMITH
extern "C" uint16_t masterUpgradeCost;
extern "C" uint16_t warriorUpgradeCost;
extern "C" uint16_t weaponUpgradeCost;
extern "C" bool canUpgradeWep;

//ENEMY HP MULP
struct REHPTable {
    unsigned int entID;
    float hpMulp;
};

//ATTACK CANCEL TABLE
struct attackCancelTable {
    uint16_t attackAnim;
    uint16_t cancelAnim;
    uint32_t cancelInput;
};

extern "C" std::vector<attackCancelTable> attackCancelList;

extern "C" int attackCancelListSize;

//STORES PLAYERS CONTROLLER INPUT
extern "C" uint32_t userInput;

extern "C" REHPTable reHPTable[];

extern "C" uint16_t specialEffectTable[];

extern "C" BYTE diffInjected;

//TODO - DATASTRUCTURE
extern "C" float scytheDelimbMulp;
extern "C" float highDelimbMulp;
extern "C" float enmaDelimbMulp;
extern "C" float femaleDelimbMulp;

//NG2 Shine
extern "C" bool ng2Shine;

//ENEMY AI
extern "C" bool isNinjaGrabSpeed;
extern "C" bool greyNinjaGrabSpeed;
extern "C" bool zedGrabSpeed;
extern "C" bool lizGrabSpeedTail;

extern "C" float bloomIntensity;

//AUDIO
extern "C" BYTE mainMenuTrack;
extern "C" BYTE ch1HeroTrack;
extern "C" BYTE ch14HeroTrack;
extern "C" bool configChime;

//Gameplay
extern "C" bool animationSmoothing;
extern "C" bool quickSelectBlur;
extern "C" BYTE microStutter;
extern "C" float fovValue;
extern "C" bool whiteFlash;
extern "C" bool disableEssence;
extern "C" bool hasFullAirborneIframes;
extern "C" bool ultimateNinja;

//DANGER ZONE
extern "C" bool instantResume;

//CAMERA
extern "C" bool isFreeCamAll;
extern "C" bool isFreeCamIzunaOnly;

//FREE CAM TABLE
//extern "C" uint16_t freeCamTable[];

//DEBUG
extern "C" bool noClip;
extern "C" bool freezeEnemies;
extern "C" bool disableDelimb;
extern "C" bool windowAlwaysReadInputs;

//SPAWN
extern "C" bool ch1RasetsuDisableMinions;

//INTERFACE
extern "C" bool vibrantMainMenu;
extern "C" DWORD_PTR menuIDOffset;
extern "C" DWORD_PTR vibrantMainMenuAddress[];
extern "C" bool skipCH1StatueEncOne;
extern "C" bool skipCH4Statue;
extern "C" bool saveLastFrame;

