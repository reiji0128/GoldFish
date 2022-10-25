#include "Collision.h"
#include "DxLib.h"
#include <math.h>

Collision::CollInfo Collision::plyColl[2] = { NULL };
Collision::CollInfo Collision::fishColl[30] = { NULL };

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::CollUpdateP(float x, float y, float r,int num)
{
    plyColl[num].x = x;
    plyColl[num].y = y;
    plyColl[num].r = r;
}

void Collision::CollUpdateF(float x, float y, float r, int num)
{
    fishColl[num].x = x;
    fishColl[num].y = y;
    fishColl[num].r = r;
}

void Collision::CollCheck()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            float vecX = plyColl[i].x - fishColl[j].x;
            float vecY = plyColl[i].y - fishColl[i].y;
            float vec = (float)sqrt(vecX * vecX + vecY * vecY);

            if (vec <= plyColl[i].r + fishColl[j].r)
            {
                //“–‚½‚Á‚½
            }
        }
    }
}
