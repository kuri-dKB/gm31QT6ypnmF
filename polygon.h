#pragma once
#include"gameobject.h"

class CPolygon : public CGameObject
{
private:
	ID3D11Buffer*              m_VertexBuffer = NULL; // 頂点バッファ
	ID3D11ShaderResourceView*  m_Texture = NULL;      // D11のテクスチャと思っていい
public:
	CPolygon(){}
	~CPolygon(){}

	void Init();
	void Uninit();
	void Update();
	void Draw();


};
