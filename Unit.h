#pragma once

#include "Vector.h"

/// <summary>
/// ���j�b�g
/// </summary>
class Unit
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Unit();

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="myTag"></param>
	Unit(ObjectTag myTag);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Unit();

	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();

	bool CheckCollision(Unit* other);

	Vector3		position;	// ���W
	Vector3 velocity;  // Velocity
	bool active;
	ObjectTag	tag;		// �^�O
	Vector3		direction;	// �ړ�����
private:

protected:
};

