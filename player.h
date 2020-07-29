#pragma once

#include "gameobject.h"

class CPlayer : public CGameObject // åpè≥
{
private:
	CModel* m_Model;
	
public:
	CPlayer() {}
	~CPlayer() {}

	void Init();
	void Uninit();
	void Update();
	void Draw();
};

