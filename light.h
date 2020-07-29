#pragma once

#include "gameobject.h"

class CLight : public CGameObject
{
private:
	CModel* m_Model;

public:

	void Init();
	void Draw();
};