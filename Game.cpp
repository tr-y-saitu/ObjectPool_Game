#include "Game.h"
#include "Player.h"
#include "Grid.h"

Game::Game()
{
    player = new Player();
    grid = new Grid();
}

Game::~Game()
{
    delete grid;
    delete player;
}

void Game::Initialize()
{
    player->Initialize();
    grid->Initialize();
}

void Game::Update()
{
    grid->Update(player);
    player->Update();
    grid->HitCheck(player);
}

void Game::Draw()
{
    grid->Draw();
    player->Draw();
}