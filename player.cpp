
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "scene.h"
#include "model.h"
#include "bullet.h"
#include "player.h"



void CPlayer::Init()
{
	m_Model = new CModel();
	m_Model->Load("asset\\model\\torus.obj"); // "\\"でないと読み込めない

	m_Pos = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	m_Rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

}

void CPlayer::Uninit()
{
	m_Model->Unload();
	delete m_Model;
}

void CPlayer::Update()
{
	// 移動
	if (CInput::GetKeyPress('A'))
	{
		m_Pos.x -= 0.1f;
	}
	if (CInput::GetKeyPress('D'))
	{
		m_Pos.x += 0.1f;
	}
	if (CInput::GetKeyPress('W'))
	{
		m_Pos.z += 0.1f;
	}
	if (CInput::GetKeyPress('S'))
	{
		m_Pos.z -= 0.1f;
	}

	 //弾発射
	if (CInput::GetKeyTrigger(VK_SPACE))
	{
		CScene* scene = CManager::GetScene();
		scene->AddGameObject<CBullet>(DEPTH1)->SetPos(m_Pos);
	}
}

void CPlayer::Draw()
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
