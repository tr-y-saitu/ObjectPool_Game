#pragma once
#include "Common.h"
#include "Unit.h"
#include "PoolTemplate.h"
#include "Bullet.h"

class Unit;

/// <summary>
/// �i�q�쐬
/// </summary>
class Grid
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Grid();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Grid();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();
	
	/// <summary>
	/// �X�V
	/// </summary>
	void Update(Unit* player);
	
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	void add(Unit* unit);
	void remove(Unit* unit);
	void hitCheck(Unit* player);
	bool collisionCheck(Unit* a, Unit* b);
private:

	void spawnBullets(int count);

	// �萔
	int HorizontalSplit	= 64;	// ��������
	int VerticalSplit	= 64;	// �c������
	int GridSizeWidth	= 64;	// �i�q�̕�
	int GridSizeHeight	= 64;	// �i�q�̍���


	// �O���b�h��̃Z�����X�g
	vector<vector<list<Unit*>>> cellList;
	ObjectPool<Bullet> bulletPool;
};
