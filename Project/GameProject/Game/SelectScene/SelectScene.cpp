#include "SelectScene.h"
#include "../ShareNum.h"

SelectScene::SelectScene() :Base(eType_Scene) {
	ShareNum::GameNum = 0;
}
void SelectScene::Draw() {
	//選択中のタイトルを大きく表示
	//ミニゲームを作ったらstateを増やす
	switch (ShareNum::GameNum) {
	case eState_GameTitle:
		FONT_T()->Draw(500, 500, 0, 0, 0, "GameTitle");
		break;
	}
}
void SelectScene::Update() {
	if (PUSH(CInput::eUp)) {
		if (ShareNum::GameNum > 0) {
			ShareNum::GameNum--;
		}
	}
	if (PUSH(CInput::eDown)) {
		if (ShareNum::GameNum < ShareNum::MaxGame - 1) {
			ShareNum::GameNum++;
		}
	}
	if (PUSH(CInput::eButton10)) {
		Base::KillAll();
		switch (ShareNum::GameNum) {
		case eState_GameTitle:
			//Base::Add(new ミニゲームのクラス);
			break;
		}
	}
}
