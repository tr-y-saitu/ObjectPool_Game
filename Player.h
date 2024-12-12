#pragma once
#include "Common.h"
#include "Unit.h"

/// <summary>
/// �v���C���[
/// </summary>
class Player : public Unit
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Player();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// �X�V
	/// </summary>
	void Update() override;

	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override;

private:
	const int HitBoxSize = 16;
	const int MoveSpeed = 1;	// �ړ����x

	/// <summary>
	/// �ړ��X�V
	/// </summary>
	void UpdateMove();
};

