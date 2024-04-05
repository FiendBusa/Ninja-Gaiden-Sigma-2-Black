#pragma once
#include <Windows.h>


extern "C" size_t battleCoordsSize;
extern "C" size_t trackerSize;
extern "C" unsigned char tripleISBytes[];


void InjectCBattle();
void InjectCoords();
void InjectAMaster();
void InjectDisableSpawns();
void InjectDelimb1();
void InjectDelimb2();
void InjectGaja();
void InjectEntDie();
void InjectDontDisableBattle();
void InjectReset();
void ClearTracking();
void InjectTelePlayer();
void InjectTripleIS();
void InjectSound();

