#include "Bullet.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Bullet::Bullet()
{
    direction = Vector3::ZeroVector;
    position = Vector3::ZeroVector;
    tag = ObjectTag::Bullet;
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Bullet::~Bullet()
{
}

