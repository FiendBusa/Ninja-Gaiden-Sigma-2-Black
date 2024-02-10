struct BattleCoords {
    float x;
    float y;
    float z;
};

struct BattleTracker {
    unsigned int battleStatus;
    unsigned int battleTriggerOffset;
};

struct DistanceThreshold {
    float distance;
};

struct ChapterData {
    BattleCoords* battleCoords;
    BattleTracker* battleTracker;
    DistanceThreshold* distanceThreshold;
};

extern "C" ChapterData masterNinjaCH1CoordData;

extern "C" BattleCoords masterninjabtlCH2[];
