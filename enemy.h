#pragma once

#include "gameobject.h"

class CEnemy : public CGameObject
{
private:
	class CModel* m_Model;
	// �O���錾(�|�C���^�ϐ��̏ꍇ�̂݉\)
public:
	CEnemy() {}
	~CEnemy() {}

	void Init();
	void Uninit();
	void Update();
	void Draw();
};