#pragma once
#include"gameobject.h"

class CPolygon : public CGameObject
{
private:
	ID3D11Buffer*              m_VertexBuffer = NULL; // ���_�o�b�t�@
	ID3D11ShaderResourceView*  m_Texture = NULL;      // D11�̃e�N�X�`���Ǝv���Ă���
public:
	CPolygon(){}
	~CPolygon(){}

	void Init();
	void Uninit();
	void Update();
	void Draw();


};
