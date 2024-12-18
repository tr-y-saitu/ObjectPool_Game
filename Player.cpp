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
	// 移動更新
	UpdateMove();
}

void Player::UpdateMove()
{
    // 入力情報取得
    auto input = GetJoypadInputState(DX_INPUT_KEY_PAD1);

    // 方向の初期化
	direction = Vector3::ZeroVector;

    // 入力による移動
	if (input & PAD_INPUT_LEFT) { direction += Vector3::LeftVector; }
	if (input & PAD_INPUT_RIGHT){ direction += Vector3::RightVector; }
	if (input & PAD_INPUT_UP){ direction += Vector3::UpVector; }
	if (input & PAD_INPUT_DOWN){ direction += Vector3::DownVector; }

	// 移動値があれば
	if (direction.Length() > 0)
	{
		// 正規化
		direction.Normalize();
	}

	// 移動量を出す
	auto velocity = direction * MoveSpeed;

	// 移動
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
