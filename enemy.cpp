
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "model.h"
#include "enemy.h"

void CEnemy::Init()
{
	m_Model = new CModel();
	m_Model->Load("asset\\model\\cube.obj");

	m_Pos = D3DXVECTOR3(2.0f, 1.0f, 0.0f);
	m_Rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

}

void CEnemy::Uninit()
{
	m_Model->Unload();
	delete m_Model;
}

void CEnemy::Update()
{

}

void CEnemy::Draw()
{
	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rot.y, m_Rot.x, m_Rot.z);
	D3DXMatrixTranslation(&trans, m_Pos.x, m_Pos.y, m_Pos.z);

	world = scale * rot * trans;

	CRenderer::SetWorldMatrix(&world);

	m_Model->Draw();
}