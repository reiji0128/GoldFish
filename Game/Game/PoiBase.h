#pragma once

class PoiBase
{
public:
    /// <summary>
    /// コンストラクタ.
    /// </summary>
    PoiBase();

    /// <summary>
    /// デストラクタ.
    /// </summary>
    virtual ~PoiBase();

    /// <summary>
    /// 更新処理.
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Update(float deltaTime);

    /// <summary>
    /// 描画処理.
    /// </summary>
    void Draw();

    /// <summary>
    /// 移動処理.
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Move(float deltaTime);

    /// <summary>
    /// 位置調整処理.
    /// </summary>
    void AdjustPos();

    /// <summary>
    /// 掬う処理.
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Scoop(float deltaTime);

    /// <summary>
    /// 体力減少処理
    /// </summary>
    /// <param name="num">減少させる数値</param>
    void DecHP(int num);

    void CheckHP();

    /// <summary>
    /// 修理処理.
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Repair(float deltaTime);

    /// <summary>
    /// ボーナス処理,
    /// </summary>
    /// <param name="deltaTime">1フレームの経過時間</param>
    void Bonus(float deltaTime);

protected:

    float mPosX;
    float mPosY;

    float mScaleX;
    float mScaleY;

    float mFloatScale;

    float mHalfScaleX;
    float mHalfScaleY;

    int mPadNum;
    int mInputX;
    int mInputY;

    float mSpeed;

    int mImage;

    int mBreakImg[5];

    int mScoopImg[3];

    bool mIsScoop;

    bool mIsFirstFrame;

    bool mPrevInput;

    float mAnimCounter;
    int mAnimNum;

    bool mIsBonus;
    int mBonusCount;
    float mBonusCounter;

    bool mIsDead;

    float deadTime;

    int mScore;

};
