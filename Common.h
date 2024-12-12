#pragma once
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <memory> 
#include "DxLib.h"
#include "Vector.h"
#include "vector"
#include "list"
#include <memory>
#include <cmath>
#include <algorithm>


using namespace std;

// 定数

static constexpr int ScreenWidth = 1280; // スクリーンの幅
static constexpr int ScreenHeight = 960; // スクリーンの高さ
//static constexpr Vector3 ZeroVector = { 0,0,0 }; // ゼロベクトル
constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 960;
constexpr int CELL_SIZE = 64;
constexpr int BULLET_SIZE = 8;
constexpr int PLAYER_SIZE = 16;
constexpr int GRID_WIDTH = SCREEN_WIDTH / CELL_SIZE;
constexpr int GRID_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;

enum class ObjectTag
{
    Player, // プレイヤー
    Bullet  // 弾
};