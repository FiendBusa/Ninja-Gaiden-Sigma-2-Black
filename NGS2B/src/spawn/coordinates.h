

struct BattleCoords {
    float x;
    float y;
    float z;
};

struct SpawnCoords {
	float x;
	float y;
	float z;
    float garb;
};


struct BattleTracker {
    unsigned int battleStatus;
    unsigned int battleTriggerOffset;
};

struct DistanceThreshold {
    float distance;
};

struct ChapterData {

    BattleCoords* masterninjabtlCH14BattleCoords;
    BattleTracker* masterninjabtlCH14Tracker;
    DistanceThreshold* masterninjabtlCH14DistanceThreshold;
};




