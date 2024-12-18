#include "Unit.h"

/// <summary>
/// コンストラクタ
/// </summary>
Unit::Unit()
{
    // 処理なし
}


Unit::Unit(ObjectTag myTag)
    : tag   (myTag)
{
    // 処理なし
}

/// <summary>
    /// デストラクタ
    /// </summary>
Unit::~Unit()
{

}

void Unit::Initialize()
{
}

void Unit::Update()
{
    if (!active) return;

    position += velocity;

    if (position.x < 0 || position.x + BULLET_SIZE > SCREEN_WIDTH) velocity.x = -velocity.x;
    if (position.y < 0 || position.y + BULLET_SIZE > SCREEN_HEIGHT) velocity.y = -velocity.y;
}

void Unit::Draw()
{
    if (active) {
        DrawBox(
            static_cast<int>(position.x),
            static_cast<int>(position.y),
            static_cast<int>(position.x + BULLET_SIZE),
            static_cast<int>(position.y + BULLET_SIZE),
            GetColor(255, 255, 255),
            TRUE
        );
    }
}

// 当たり判定のメソッド
bool Unit::CheckCollision(Unit* other)
{
    // このUnitとother（別のUnit）との衝突判定
    float left1 = position.x;
    float top1 = position.y;
    float right1 = position.x + BULLET_SIZE;
    float bottom1 = position.y + BULLET_SIZE;

    float left2 = other->position.x;
    float top2 = other->position.y;
    float right2 = other->position.x + BULLET_SIZE;
    float bottom2 = other->position.y + BULLET_SIZE;

    // 矩形が重なっているか判定
    return !(right1 <= left2 || left1 >= right2 || bottom1 <= top2 || top1 >= bottom2);
}
