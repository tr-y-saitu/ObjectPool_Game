#pragma once
#include "Common.h"


/// <summary>
/// 3�����x�N�g��
/// </summary>
class Vector3
{
public:
	// �萔
	static const Vector3 ZeroVector;	// �[���x�N�g��
	static const Vector3 UpVector;		// ��x�N�g��
	static const Vector3 DownVector;	// ���x�N�g��
	static const Vector3 LeftVector;	// ���x�N�g��
	static const Vector3 RightVector;	// �E�x�N�g��

	float x;												//�v�f��
	float y;												//�v�f��
	float z;												//�v�f��

	Vector3() { x = 0.0f; y = 0.0f; z = 0.0f; }				//�R���X�g���N�^
	Vector3(const Vector3& v) { x = v.x; y = v.y; z = v.z; }//�R�s�[�R���X�g���N�^
	Vector3(float v);										//��̈����ŏ�����
	Vector3(float aug_x, float aug_y, float aug_z);			//���ꂼ��̈������ŏ�����
	virtual ~Vector3() {}									//�f�X�g���N�^

	void SetX(float aug_x) { x = aug_x; }					//�v�f�����Z�b�g
	void SetY(float aug_y) { y = aug_y; }					//�v�f�����Z�b�g
	void SetZ(float aug_z) { z = aug_z; }					//�v�f�����Z�b�g
	void Set(float aug_x, float aug_y, float aug_z);		//�v�f���Z�b�g
	float Length();											//����
	Vector3 Normalize();									//���K��
	void Print();											//�l�̕\��

	//friend�Ȃ̂ŁA�A�N�Z�X���Z�q�����Œ��ڃA�N�Z�X�\
	Vector3& operator = (const Vector3& a);					//�x�N�g���̑��	
	friend bool operator == (Vector3& a, Vector3& b);		//�x�N�g���̔�r
	friend Vector3 operator + (Vector3& a, Vector3& b);		//�x�N�g���̑����Z	
	Vector3& operator += (const Vector3& a);				//�����Z�{���
	friend Vector3 operator - (Vector3& a, Vector3& b);		//�x�N�g���̈����Z
	Vector3& operator -= (const Vector3& a);				//�����Z�{���
	friend float operator * (Vector3& a, Vector3& b);		//�x�N�g���̓���
	friend Vector3 operator * (Vector3& a, float n);		//�X�J���[�{
	friend Vector3 operator * (float n, Vector3& a);		//�X�J���[�{
	Vector3& operator *= (const float n);					//�X�J���[�{�{���
	friend Vector3 operator / (Vector3& a, float n);		//�X�J���[���Z
	friend Vector3 operator / (float n, Vector3& a);		//�X�J���[���Z
	Vector3& operator /= (const float n);					//�X�J���[���Z�{���
	friend Vector3 operator % (Vector3& V1, Vector3& V2);	//�x�N�g���̊O��	
	Vector3& operator %= (const Vector3& a);				//�O�Ё{���
};