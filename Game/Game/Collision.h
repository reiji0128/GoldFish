#pragma once

class Collision
{
public:
    Collision();
    ~Collision();

    struct CollInfo
    {
        float x;
        float y;
        float r;
    };

    static void CollUpdateP(float x, float y, float r, int num);

    static void CollUpdateF(float x, float y, float r, int num);

    static void CollCheck();

private:
    static CollInfo plyColl[2];
    static CollInfo fishColl[30];
};
