#pragma once
#include <vector>

class Collision
{
public:
    ~Collision();

    struct Circle
    {
        float x;
        float y;
        float r;
    };

    static void CreateInstance();

    static void DeleteInstance();

    static void PlayerCollUpdate(float x, float y, float r, int num);

    static void FishCollUpdate(float x, float y, float r);

    static void AddFishColl(Circle fish);

    static void RemoveFishColl(int i);

    static void RemoveAll();

    static void CollCheck();

private:
    Collision();

    static Collision* instance;

    static Circle plyColl[2];

    std::vector<Circle> fishColl;

    static int fishCount;

    Circle fishCollInit;

    static int poolSize;
};
