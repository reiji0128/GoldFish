#include "Collision.h"
#include "FishManager.h"

Collision* Collision::instance = nullptr;

Collision::Circle Collision::plyColl[2] = { NULL };

int Collision::fishCount;

Collision::Collision()
{
    instance = this;
    fishCount = 0;
    fishCollInit = { 0 };
    for (int i = 0; i < FishManager::GetPoolSize(); i++)
    {
        AddFishColl(fishCollInit);
    }
}

Collision::~Collision()
{

}

void Collision::CreateInstance()
{
    if (!instance)
    {
        instance = new Collision();
    }
}

void Collision::DeleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

void Collision::PlayerCollUpdate(float x, float y, float r, int num)
{
    plyColl[num].x = x;
    plyColl[num].y = y;
    plyColl[num].r = r;
}

void Collision::FishCollUpdate(float x, float y, float r)
{
    fishCount++;
    if (FishManager::GetPoolSize() > fishCount)
    {
        fishCount = 0;
    }
    auto box = instance->fishColl[fishCount];
    box->x = x;
    box->y = y;
    box->r = r;
}

void Collision::AddFishColl(Circle* fish)
{
    instance->fishColl.push_back(fish);
}

void Collision::RemoveFishColl(int i)
{
    instance->fishColl.erase(instance->fishColl.begin() + i);
}

void Collision::RemoveAll()
{
    while (!instance->fishColl.empty())
    {
        delete instance->fishColl.back();

        instance->fishColl.pop_back();
    }
}

void Collision::CollCheck()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < instance->fishColl.size(); j++)
        {
            auto box = instance->fishColl[j];

            float vecX = plyColl[i].x - box->x;
            float vecY = plyColl[i].y - box->y;
            float vec = (float)sqrt(vecX * vecX + vecY * vecY);

            if (vec <= plyColl[i].r + box->r)
            {
                // “–‚½‚Á‚Ä‚¢‚é
                int tmp = 0;
            }
        }
    }
}
