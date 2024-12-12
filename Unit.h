#pragma once

#include "Vector.h"

/// <summary>
/// ユニット
/// </summary>
class Unit
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Unit();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="myTag"></param>
	Unit(ObjectTag myTag);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Unit();

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();

	bool CheckCollision(Unit* other);

	Vector3		position;	// 座標
	Vector3 velocity;  // Velocity
	bool active;
	ObjectTag	tag;		// タグ
	Vector3		direction;	// 移動方向
private:

protected:
};

