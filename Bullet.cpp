#include "Bullet.h"

/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet()
{
    direction = Vector3::ZeroVector;
    position = Vector3::ZeroVector;
    tag = ObjectTag::Bullet;
}

/// <summary>
/// デストラクタ
/// </summary>
Bullet::~Bullet()
{
}

