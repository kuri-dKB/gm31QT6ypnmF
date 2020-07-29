#pragma once

#include "gameobject.h"

class CEnemy : public CGameObject
{
private:
	class CModel* m_Model;
	// 前方宣言(ポインタ変数の場合のみ可能)
public:
	CEnemy() {}
	~CEnemy() {}

	void Init();
	void Uninit();
	void Update();
	void Draw();
};