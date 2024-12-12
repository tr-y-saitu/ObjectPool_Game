#include "Unit.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Unit::Unit()
{
    // �����Ȃ�
}


Unit::Unit(ObjectTag myTag)
    : tag   (myTag)
{
    // �����Ȃ�
}

/// <summary>
    /// �f�X�g���N�^
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

    position += velocity / 4;

    // Screen boundary collision
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

// �����蔻��̃��\�b�h
bool Unit::CheckCollision(Unit* other)
{
    // ����Unit��other�i�ʂ�Unit�j�Ƃ̏Փ˔���
    float left1 = position.x;
    float top1 = position.y;
    float right1 = position.x + BULLET_SIZE;
    float bottom1 = position.y + BULLET_SIZE;

    float left2 = other->position.x;
    float top2 = other->position.y;
    float right2 = other->position.x + BULLET_SIZE;
    float bottom2 = other->position.y + BULLET_SIZE;

    // ��`���d�Ȃ��Ă��邩����
    return !(right1 <= left2 || left1 >= right2 || bottom1 <= top2 || top1 >= bottom2);
}