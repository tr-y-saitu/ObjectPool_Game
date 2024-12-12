#pragma once
#include "Common.h"
#include "Unit.h"
#include "PoolTemplate.h"
#include "Bullet.h"

class Unit;

/// <summary>
/// 格子作成
/// </summary>
class Grid
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Grid();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Grid();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	
	/// <summary>
	/// 更新
	/// </summary>
	void Update(Unit* player);
	
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void add(Unit* unit);
	void remove(Unit* unit);
	void hitCheck(Unit* player);
	bool collisionCheck(Unit* a, Unit* b);
private:

	void spawnBullets(int count);

	// 定数
	int HorizontalSplit	= 64;	// 横分割数
	int VerticalSplit	= 64;	// 縦分割数
	int GridSizeWidth	= 64;	// 格子の幅
	int GridSizeHeight	= 64;	// 格子の高さ


	// グリッド状のセルリスト
	vector<vector<list<Unit*>>> cellList;
	ObjectPool<Bullet> bulletPool;
};
