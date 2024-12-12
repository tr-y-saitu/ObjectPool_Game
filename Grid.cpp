#include "Common.h"
#include "Grid.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Grid::Grid()
    : bulletPool(5000)
{
    // cellList �̏�����
    cellList.resize(HorizontalSplit);  // ���̕������Ƀ��T�C�Y
    for (int x = 0; x < HorizontalSplit; ++x) {
        cellList[x].resize(VerticalSplit);  // �c�̕������Ƀ��T�C�Y
    }
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Grid::~Grid()
{
}

/// <summary>
/// ������
/// </summary>
void Grid::Initialize()
{
    spawnBullets(5000);
}


/// <summary>
/// �X�V
/// </summary>
void Grid::Update(Unit* player)
{
    // �i�q���Ƃɏ���
    for (int x = 0; x < HorizontalSplit; ++x)
    {
        for (int y = 0; y < VerticalSplit; ++y)
        {
            auto& cell = cellList[x][y];
            for (auto it = cell.begin(); it != cell.end(); )
            {
                Unit* unit = *it;
                if (!unit->active) {
                    // ��A�N�e�B�u�ȃ��j�b�g�͍폜���A�v�[���ɖ߂�
                    it = cell.erase(it);
                    bulletPool.add(static_cast<Bullet*>(unit));  // �g�p��Ƀv�[���ɖ߂�
                }
                else {
                    unit->Update();  // �A�N�e�B�u�ȃ��j�b�g�͍X�V����
                    ++it;
                }
            }
        }
    }
}

/// <summary>
/// �`��
/// </summary>
void Grid::Draw()
{
	// �����[�v��
	int horizonSplitCount = ScreenWidth / HorizontalSplit;
	
	// �c���[�v��
	int verticalSplitCount = ScreenHeight / VerticalSplit;

	// �O���b�h�`��
    for (int i = 0; i < horizonSplitCount; i++)
    {
        for (int j = 0; j < verticalSplitCount; j++)
        {
            // �e�O���b�h�̍���ƉE���̍��W���v�Z���ĕ`��
            int left    = i * GridSizeWidth;
            int top     = j * GridSizeHeight;
            int right   = left + GridSizeWidth;
            int bottom  = top + GridSizeHeight;

            DrawBox(left, top, right, bottom, GetColor(0, 255, 0), false);
        }
    }

    // �e�ۂ�\��
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
                    unit->Draw();  // �A�N�e�B�u�ȃ��j�b�g�͍X�V����
                    ++it;
                }
            }
        }
    }

}


void Grid::add(Unit* unit)
{
    int cx = static_cast<int>(unit->position.x) / CELL_SIZE;
    int cy = static_cast<int>(unit->position.y) / CELL_SIZE;
    if (cx >= 0 && cx < GRID_WIDTH && cy >= 0 && cy < GRID_HEIGHT) {
        cellList[cx][cy].push_back(unit);
    }
}

void Grid::remove(Unit* unit)
{
    int cx = static_cast<int>(unit->position.x) / CELL_SIZE;
    int cy = static_cast<int>(unit->position.y) / CELL_SIZE;
    if (cx >= 0 && cx < GRID_WIDTH && cy >= 0 && cy < GRID_HEIGHT) {
        cellList[cx][cy].remove(unit);
    }
}

void Grid::hitCheck(Unit* player)
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
                    unit->active = false; // �e�ۂ��A�N�e�B�u�ɂ���
                    it = unitList.erase(it); // �����蔻��ŏ����ꂽ���j�b�g�����X�g����폜
                }
                else
                {
                    ++it; // ���j�b�g����A�N�e�B�u�łȂ��ꍇ�A���̃��j�b�g�֐i��
                }
            }
        }
    }
}

bool Grid::collisionCheck(Unit* a, Unit* b)
{
    return (a->position - b->position).Length() < PLAYER_SIZE * 4;
}

// Bullet�������_���Ȉʒu�Ő���
void Grid::spawnBullets(int count)
{
    for (int i = 0; i < count; ++i) {
        Bullet* bullet = bulletPool.create();  // �v�[������Bullet���擾
        if (bullet) {
            // �����_���Ȉʒu�ɔz�u
            int x = rand() % HorizontalSplit;  // �����_���ȉ����W
            int y = rand() % VerticalSplit;    // �����_���ȏc���W

            bullet->position.x = rand() % SCREEN_WIDTH;
            bullet->position.y = rand() % SCREEN_HEIGHT;
            bullet->velocity.x = rand() % 10 - 5;  // �����_���ȑ��x
            bullet->velocity.y = rand() % 10 - 5;  // �����_���ȑ��x
            bullet->active = true;

            // �����_���ȃZ���ɒe��ǉ�
            cellList[x][y].push_back(bullet);
        }
    }
}
