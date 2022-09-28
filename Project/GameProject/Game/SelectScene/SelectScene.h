#pragma once
#include <Gllibrary.h>
#include "../../Base/Base.h"
#include "../ShareNum.h"

class SelectScene :public Base {
	enum {
		//ゲームタイトルのstateを作る
		eState_GameTitle
	};
private:
	CFont titletext[10];
public:
	SelectScene();
	void Draw();
	void Update();
	void SetText();
};