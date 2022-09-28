#include "Title.h"
#include "../Game/Game.h"
Title::Title():Base(eType_Scene),m_title_text("C:\\Windows\\Fonts\\msgothic.ttc",64)
{
}
Title::~Title() {
	Base::KillAll();
	Base::Add(new Game());
}
void Title::Draw() {
	m_title_text.Draw(64, 256, 0, 0, 0, "Title");
	m_title_text.Draw(64, 512, 0, 0, 0, "Push Z");
}
void Title::Update(){
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}