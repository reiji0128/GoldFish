#pragma once

class Score
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Score();

    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Score();

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
    //�`����WX
    int scoreImgX[2];

    //�`����WY
    int scoreImgY;

    //���݂̃X�R�A
    int nowScore;
};

