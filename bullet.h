#pragma once

#include "gameobject.h"

class CBullet : public CGameObject
{
private:
	static class CModel* m_Model; // �O���錾
	// �X�^�e�B�b�N���ƃ��f�������̂�������1�̃��f�����g���܂킹��

public:
	CBullet(){}
	~CBullet(){}

	static void Load();
	static void Unload();

	void Init();
	void Uninit();
	void Update();
	void Draw();
};