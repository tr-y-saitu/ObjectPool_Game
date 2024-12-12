#pragma once
#include "Common.h"
#include "Unit.h"
#include "PoolTemplate.h"

class Grid;
class Player;

/// <summary>
/// ƒQ[ƒ€
/// </summary>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize();

	/// <summary>
	/// XV
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw();

private:
	Grid* grid;
	Unit* player;
	//ObjectPool<Unit> unitPool;
};

