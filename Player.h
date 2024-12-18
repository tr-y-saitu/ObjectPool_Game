#pragma once
#include "Common.h"
#include "Unit.h"

/// <summary>
/// プレイヤー
/// </summary>
class Player : public Unit
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:
	const int HitBoxSize = 16;
	const int MoveSpeed = 4;	// 移動速度

	/// <summary>
	/// 移動更新
	/// </summary>
	void UpdateMove();
};

