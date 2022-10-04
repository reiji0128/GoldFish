#pragma once

// �O���錾
class PoiBase;

class PoiManager final
{
public:
    /// <summary>
    /// �C���X�^���X�̍쐬
    /// </summary>
    static void CreateInstance();

    /// <summary>
    /// �C���X�^���X�̍폜
    /// </summary>
    static void DeleteInstance();

    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="deltaTime">1�t���[���̌o�ߎ���</param>
    static void Update(float deltaTime);

    /// <summary>
    /// �`�揈��
    /// </summary>
    static void Draw();

private:
    /// <summary>
    /// �V���O���g��
    /// </summary>
    PoiManager();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~PoiManager();

    // �|�C�}�l�[�W���[�̎���
    static PoiManager* mInstance;

    // �|�C�̔z��
    PoiBase* poiList[2];

};