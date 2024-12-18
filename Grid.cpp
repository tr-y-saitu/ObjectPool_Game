#include "Common.h"
#include "Grid.h"

/// <summary>
/// コンストラクタ
/// </summary>
Grid::Grid()
    : bulletPool(5000)
{
    // cellList の初期化
    cellList.resize(HorizontalSplit);  // 横の分割数にリサイズ
    for (int x = 0; x < HorizontalSplit; ++x) {
        cellList[x].resize(VerticalSplit);  // 縦の分割数にリサイズ
    }
}

/// <summary>
/// デストラクタ
/// </summary>
Grid::~Grid()
{
}

/// <summary>
/// 初期化
/// </summary>
void Grid::Initialize()
{
    spawnBullets(5000);
}


/// <summary>
/// 更新
/// </summary>
void Grid::Update(Unit* player)
{
    // 格子ごとに処理
    for (int x = 0; x < HorizontalSplit; ++x)
    {
        for (int y = 0; y < VerticalSplit; ++y)
        {
            auto& cell = cellList[x][y];
            for (auto it = cell.begin(); it != cell.end(); )
            {
                Unit* unit = *it;
                if (!unit->active) {
                    // 非アクティブなユニットは削除し、プールに戻す
                    it = cell.erase(it);
                    bulletPool.Add(static_cast<Bullet*>(unit));  // 使用後にプールに戻す
                }
                else {
                    unit->Update();  // アクティブなユニットは更新処理
                    ++it;
                }
            }
        }
    }
}

/// <summary>
/// 描画
/// </summary>
void Grid::Draw()
{
	// 横ループ回数
	int horizonSplitCount = ScreenWidth / HorizontalSplit;
	
	// 縦ループ回数
	int verticalSplitCount = ScreenHeight / VerticalSplit;

	// グリッド描画
    for (int i = 0; i < horizonSplitCount; i++)
    {
        for (int j = 0; j < verticalSplitCount; j++)
        {
            // 各グリッドの左上と右下の座標を計算して描画
            int left    = i * GridSizeWidth;
            int top     = j * GridSizeHeight;
            int right   = left + GridSizeWidth;
            int bottom  = top + GridSizeHeight;

            DrawBox(left, top, right, bottom, GetColor(0, 255, 0), false);
        }
    }

    // 弾丸を表示
    for (int x = 0; x < HorizontalSplit; ++x)
    {
        for (int y = 0; y < VerticalSplit; ++y)
        {
            auto& cell = cellList[x][y];
            for (auto it = cell.begin(); it != cell.end(); )
            {
                Unit* unit = *it;
                if (unit->active)
                {
                    unit->Draw();  // アクティブなユニットは更新処理
                    ++it;
                }
            }
        }
    }

}


void Grid::Add(Unit* unit)
{
    int cx = static_cast<int>(unit->position.x) / CELL_SIZE;
    int cy = static_cast<int>(unit->position.y) / CELL_SIZE;
    if (cx >= 0 && cx < GRID_WIDTH && cy >= 0 && cy < GRID_HEIGHT) {
        cellList[cx][cy].push_back(unit);
    }
}

void Grid::Remove(Unit* unit)
{
    int cx = static_cast<int>(unit->position.x) / CELL_SIZE;
    int cy = static_cast<int>(unit->position.y) / CELL_SIZE;
    if (cx >= 0 && cx < GRID_WIDTH && cy >= 0 && cy < GRID_HEIGHT) {
        cellList[cx][cy].Remove(unit);
    }
}

void Grid::HitCheck(Unit* player)
{
    for (int x = 0; x < HorizontalSplit; ++x)
    {
        for (int y = 0; y < VerticalSplit; ++y)
        {
            auto& unitList = cellList[x][y];
            for (auto it = unitList.begin(); it != unitList.end();)
            {
                Unit* unit = *it;
                if (unit->active && collisionCheck(player, unit))
                {
                    unit->active = false; // 弾丸を非アクティブにする
                    it = unitList.erase(it); // 当たり判定で消されたユニットをリストから削除
                }
                else
                {
                    ++it; // ユニットが非アクティブでない場合、次のユニットへ進む
                }
            }
        }
    }
}

bool Grid::collisionCheck(Unit* a, Unit* b)
{
    return (a->position - b->position).Length() < PLAYER_SIZE * 4;
}

// Bulletをランダムな位置で生成
void Grid::spawnBullets(int count)
{
    for (int i = 0; i < count; ++i) {
        Bullet* bullet = bulletPool.Create();  // プールからBulletを取得
        if (bullet) {
            // ランダムな位置に配置
            int x = rand() % HorizontalSplit;  // ランダムな横座標
            int y = rand() % VerticalSplit;    // ランダムな縦座標

            bullet->position.x = rand() % SCREEN_WIDTH;
            bullet->position.y = rand() % SCREEN_HEIGHT;
            bullet->velocity.x = rand() % 10 - 5;  // ランダムな速度
            bullet->velocity.y = rand() % 10 - 5;  // ランダムな速度
            bullet->active = true;

            // ランダムなセルに弾を追加
            cellList[x][y].push_back(bullet);
        }
    }
}
