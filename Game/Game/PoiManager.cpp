#include "PoiManager.h"
#include "PoiBase.h"
#include "PoiRed.h"
#include "PoiBlue.h"

// PoiManager���̂ւ̃|�C���^��`
PoiManager* PoiManager::mInstance = nullptr;

/// <summary>
/// �R���X�g���N�^
/// </summary>
PoiManager::PoiManager()
{
    mInstance = nullptr;
    poiList[0] = new PoiRed();
    poiList[1] = new PoiBlue();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PoiManager::~PoiManager()
{
    for (auto list : poiList)
    {
        delete list;
    }
}

/// <summary>
/// �|�C�}�l�[�W���[�̐���
/// </summary>
void PoiManager::CreateInstance()
{
    if (!mInstance)
    {
        mInstance = new PoiManager();
    }
}

/// <summary>
/// �|�C�}�l�[�W���[�̍폜
/// </summary>
void PoiManager::DeleteInstance()
{
    if (mInstance)
    {
        delete mInstance;
        mInstance = nullptr;
    }
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
void PoiManager::Update(float deltaTime)
{
    for (auto list : mInstance->poiList)
    {
        list->Update(deltaTime);
    }
}

/// <summary>
/// �`�揈��
/// </summary>
void PoiManager::Draw()
{
    for (auto list : mInstance->poiList)
    {
        list->Draw();
    }
}
