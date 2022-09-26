#pragma once
#include "../Base/Base.h"
#define MAP_WIDTH 40
#define MAP_HEIGHT 22
#define MAP_TIP_SIZE 32
class Map :public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
	int GetTip(const CVector2D& PostAppMessage);
	int GetTip(int col, int raw);
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect);
};