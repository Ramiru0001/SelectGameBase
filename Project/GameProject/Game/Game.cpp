#include "Game.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene) {
}
Game::~Game() {
	Base::KillAll();
	Base::Add(new Title());
}
void Game::Update() {
	/*if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}*/
}