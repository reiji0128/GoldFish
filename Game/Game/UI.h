#pragma once

class PoiBase;

class UI
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
   UI();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~UI();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update(float deltaTime);

    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw();

    /// <summary>
    /// �X�R�A���Z
    /// </summary>
    /// <returns>���Z��̃X�R�A</returns>
    int IncreaseScore(int incPoint) { nowScore += incPoint; return nowScore; }

    /// <summary>
    /// �X�R�A���_
    /// </summary>
    /// <returns>���_��̃X�R�A</returns>
    int DecreaseScore(int decPosint) { nowScore -= decPosint; return nowScore; }

private:
    //�^�C�}�[�`����WX
    int timerImgX;

    //�^�C�}�[�`����WY
    int timerImgY;

    //�^�C�}�[
    float timer;

    //���Ԍo��
    float timerCounter;

    //�`����WX
    int scoreImgX;

    //�`����WY
    int scoreImgY;

    //���݂̃X�R�A
    int nowScore;

    //�X�R�A�i���o�[
    int ScoreNum;

    PoiBase* poiBase;
};

