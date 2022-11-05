#pragma once
#include "Tag.h"

class Sound;
class UI*ui;

class PoiBase
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    PoiBase();

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~PoiBase();

    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Update(float deltaTime);

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

protected:
    /// <summary>
    /// 移動処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Move(float deltaTime);

    /// <summary>
    /// 位置調整処理
    /// </summary>
    void AdjustPos();

    /// <summary>
    /// 掬う処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Scoop(float deltaTime);

    /// <summary>
    /// 体力確認処理
    /// </summary>
    void CheckHP();

    /// <summary>
    /// 修理処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Repair(float deltaTime);

    /// <summary>
    /// ボーナス処理
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Bonus(float deltaTime);

    /// <summary>
    /// スコア計算
    /// </summary>
    /// <param name="tag">金魚の種類</param>
    void CalcScore(Tag tag);

    /// <summary>
    /// 当たり判定
    /// </summary>
    void Coll();

    // 位置
    float mPosX;
    float mPosY;

    // スケール
    float mScaleX;
    float mScaleY;

    // スケール(変動用)
    float mFloatScale;

    // ハーフスケール（計算用）
    float mHalfScaleX;
    float mHalfScaleY;

    // コントローラーの入力関連
    int mPadNum;
    int mInputX;
    int mInputY;

    // 速度
    float mSpeed;

    // 画像
    int mImage;

    // 破れ差分
    int mBreakImg[5] = { -1 };

    // 掬う差分
    int mScoopImg[6] = { -1 };

    int mBrokenImg;

    int mBrokenImgF;

    bool mIsFlash;

    // 掬っているかどうか
    bool mIsScoop;

    // 1フレーム目かどうか
    bool mIsFirstFrame;

    // 前フレームでの入力していたかどうか
    bool mPrevInput;

    // アニメーション用
    float mAnimCounter;
    int mAnimNum;

    // ボーナス用
    bool mIsBonus;
    int mBonusCount;
    float mBonusTimer;

    // 耐久値
    int hp;

    // ポイが生きているかどうか
    bool mIsAlive;

    float deadTime;

    // スコア
    int mScore[2] = { 0 };

protected:
    //Soundの生成
    Sound* sound;
};
