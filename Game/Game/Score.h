#pragma once

class Score
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Score();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Score();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

    /// <summary>
    /// スコア加算
    /// </summary>
    /// <returns>加算後のスコア</returns>
    int IncreaseScore(int incPoint) { nowScore += incPoint; return nowScore; }

    /// <summary>
    /// スコア減点
    /// </summary>
    /// <returns>減点後のスコア</returns>
    int DecreaseScore(int decPosint) { nowScore -= decPosint; return nowScore; }

private:
    //描画座標X
    int scoreImgX[2];

    //描画座標Y
    int scoreImgY;

    //現在のスコア
    int nowScore;
};

