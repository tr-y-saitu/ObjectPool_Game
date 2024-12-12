#pragma once
#include "Common.h"


/// <summary>
/// 3次元ベクトル
/// </summary>
class Vector3
{
public:
	// 定数
	static const Vector3 ZeroVector;	// ゼロベクトル
	static const Vector3 UpVector;		// 上ベクトル
	static const Vector3 DownVector;	// 下ベクトル
	static const Vector3 LeftVector;	// 左ベクトル
	static const Vector3 RightVector;	// 右ベクトル

	float x;												//要素ｘ
	float y;												//要素ｙ
	float z;												//要素ｚ

	Vector3() { x = 0.0f; y = 0.0f; z = 0.0f; }				//コンストラクタ
	Vector3(const Vector3& v) { x = v.x; y = v.y; z = v.z; }//コピーコンストラクタ
	Vector3(float v);										//一つの引数で初期化
	Vector3(float aug_x, float aug_y, float aug_z);			//それぞれの引き数で初期化
	virtual ~Vector3() {}									//デストラクタ

	void SetX(float aug_x) { x = aug_x; }					//要素ｘをセット
	void SetY(float aug_y) { y = aug_y; }					//要素ｙをセット
	void SetZ(float aug_z) { z = aug_z; }					//要素ｚをセット
	void Set(float aug_x, float aug_y, float aug_z);		//要素をセット
	float Length();											//長さ
	Vector3 Normalize();									//正規化
	void Print();											//値の表示

	//friendなので、アクセス演算子無視で直接アクセス可能
	Vector3& operator = (const Vector3& a);					//ベクトルの代入	
	friend bool operator == (Vector3& a, Vector3& b);		//ベクトルの比較
	friend Vector3 operator + (Vector3& a, Vector3& b);		//ベクトルの足し算	
	Vector3& operator += (const Vector3& a);				//足し算＋代入
	friend Vector3 operator - (Vector3& a, Vector3& b);		//ベクトルの引き算
	Vector3& operator -= (const Vector3& a);				//引き算＋代入
	friend float operator * (Vector3& a, Vector3& b);		//ベクトルの内積
	friend Vector3 operator * (Vector3& a, float n);		//スカラー倍
	friend Vector3 operator * (float n, Vector3& a);		//スカラー倍
	Vector3& operator *= (const float n);					//スカラー倍＋代入
	friend Vector3 operator / (Vector3& a, float n);		//スカラー除算
	friend Vector3 operator / (float n, Vector3& a);		//スカラー除算
	Vector3& operator /= (const float n);					//スカラー除算＋代入
	friend Vector3 operator % (Vector3& V1, Vector3& V2);	//ベクトルの外積	
	Vector3& operator %= (const Vector3& a);				//外籍＋代入
};