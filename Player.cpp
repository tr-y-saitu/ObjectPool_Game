#include "Player.h"


Player::Player()
{
	direction = Vector3::ZeroVector;
	position = {ScreenWidth / 2, ScreenHeight / 2,0};
	tag = ObjectTag::Player;
}

Player::~Player()
{
}

void Player::Initialize()
{
	
}

void Player::Update()
{
	// �ړ��X�V
	UpdateMove();
}

void Player::UpdateMove()
{
    // ���͏��擾
    auto input = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // �����̏�����
	direction = Vector3::ZeroVector;

    // ���͂ɂ��ړ�
	if (input & PAD_INPUT_LEFT) { direction += {-4,0,0}; }
	if (input & PAD_INPUT_RIGHT) { direction += {4,0,0}; }
	if (input & PAD_INPUT_UP) { direction += {0,-4,0}; }
	if (input & PAD_INPUT_DOWN) { direction += {0,4,0}; }
	/*if (input & PAD_INPUT_LEFT) { direction += Vector3::LeftVector; }
	if (input & PAD_INPUT_RIGHT){ direction += Vector3::RightVector; }
	if (input & PAD_INPUT_UP){ direction += Vector3::UpVector; }
	if (input & PAD_INPUT_DOWN){ direction += Vector3::DownVector; }*/

	// �ړ��l�������
	if (direction.Length() > 0)
	{
		// ���K��
		direction.Normalize();
	}

	// �ړ��ʂ��o��
	auto velocity = direction * MoveSpeed;

	// �ړ�
	position += velocity;
}

void Player::Draw()
{
	float offset = HitBoxSize / 2;

	DrawBox(position.x - offset,
			position.y - offset,
			position.x + offset,
			position.y + offset
			,GetColor(255,0,0),
			true);
}