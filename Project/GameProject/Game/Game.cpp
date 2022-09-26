#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "Map.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene) {
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(300, 540), false));
	Base::Add(new Enemy(CVector2D(1280+256 * 1, 540), true));
	Base::Add(new Enemy(CVector2D(1280+256 * 2, 540), true));
	Base::Add(new Enemy(CVector2D(1280+256 * 3, 540), true));
	Base::Add(new Goal(CVector2D(2048, 540)));
}
Game::~Game() {
	Base::KillAll();
	Base::Add(new Title());
}
void Game::Update() {
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}