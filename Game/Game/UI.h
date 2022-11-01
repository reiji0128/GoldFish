#pragma once

class PoiBase;

class UI
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
   UI();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~UI();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update(float deltaTime);

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
    //タイマー描画座標X
    int timerImgX;

    //タイマー描画座標Y
    int timerImgY;

    //タイマー
    float timer;

    //時間経過
    float timerCounter;

    //描画座標X
    int scoreImgX;

    //描画座標Y
    int scoreImgY;

    //現在のスコア
    int nowScore;

    //スコアナンバー
    int ScoreNum;

    PoiBase* poiBase;
};

