#pragma once

#include "gameobject.h"

class CSkydome : public CGameObject // åpè≥
{
private:
	CModel* m_Model;

public:
	CSkydome() {}
	~CSkydome() {}

	void Init();
	void Uninit();
	void Update();
	void Draw();
};
