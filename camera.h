#pragma once
#include "gameobject.h"

class CCamera : public CGameObject
{
private:
	D3DXMATRIX m_ViewMatrix;

	D3DXVECTOR3 m_Target;

public:
	CCamera() {}
	~CCamera() {}

	void Init();
	void Uninit();
	void Update();
	void Draw();

	D3DXMATRIX GetViewMatrix() { return m_ViewMatrix; }

};