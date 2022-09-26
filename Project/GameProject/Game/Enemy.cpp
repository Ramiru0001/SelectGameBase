#include "Enemy.h"
#include "Bullet.h"
Enemy::Enemy(const CVector2D& pos) : Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_rad = 16;
}
void Enemy::Update() {
	//�J�E���g�A�b�v
	m_cnt++;
	//�v���C���[���擾
	Base* b = Base::FindObject(eType_Player);
	//�v���C���[�������
	if (b) {
		//�^�[�Q�b�g�ւ̃x�N�g��
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 120) {
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}
	//CVector2D vec =b->m_pos  - m_pos;
	//m_ang = atan2(vec.x, vec.y);
}

void Enemy::Collision(Base* b) {

}
void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}