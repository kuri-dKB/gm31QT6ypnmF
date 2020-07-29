#pragma once

#include "gameobject.h"

class CBullet : public CGameObject
{
private:
	static class CModel* m_Model; // 前方宣言
	// スタティックだとモデルを何体だそうが1つのモデルを使いまわせる

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