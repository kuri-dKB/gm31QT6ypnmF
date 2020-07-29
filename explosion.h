#pragma once

#include "gameobject.h"

class CExplosion : public CGameObject
{
private:
	ID3D11Buffer*             m_VertexBuffer = NULL;
	ID3D11ShaderResourceView* m_Texture = NULL;

	int m_Count = 0;
public:
	void Load();
	void Unload();

	void Init();
	void Uninit();
	void Update();
	void Draw();
};

