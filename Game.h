#pragma once
#include "Common.h"
#include "Unit.h"
#include "PoolTemplate.h"

class Grid;
class Player;

/// <summary>
/// �Q�[��
/// </summary>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

private:
	Grid* grid;
	Unit* player;
	//ObjectPool<Unit> unitPool;
};

