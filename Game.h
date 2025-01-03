#pragma once
#include "Common.h"
#include "Unit.h"
#include "PoolTemplate.h"

class Grid;
class Player;

/// <summary>
/// ゲーム
/// </summary>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	Grid* grid;
	Unit* player;
	//ObjectPool<Unit> unitPool;
};

