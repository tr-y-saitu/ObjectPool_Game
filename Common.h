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

// �萔

static constexpr int ScreenWidth = 1280; // �X�N���[���̕�
static constexpr int ScreenHeight = 960; // �X�N���[���̍���
//static constexpr Vector3 ZeroVector = { 0,0,0 }; // �[���x�N�g��
constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 960;
constexpr int CELL_SIZE = 64;
constexpr int BULLET_SIZE = 8;
constexpr int PLAYER_SIZE = 16;
constexpr int GRID_WIDTH = SCREEN_WIDTH / CELL_SIZE;
constexpr int GRID_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;

enum class ObjectTag
{
    Player, // �v���C���[
    Bullet  // �e
};