
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "model.h"
#include "explosion.h"
#include "bullet.h"


class CModel* CBullet::m_Model;

void CBullet::Load()
{
	m_Model = new CModel();
	m_Model->Load("asset\\model\\bullet.obj");
}

void CBullet::Unload()
{
	m_Model->Unload();
	delete m_Model;
}

void CBullet::Init()
{
	m_Pos = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_Rot = D3DXVECTOR3(1.5f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

void CBullet::Uninit()
{

}

void CBullet::Update()
{
	m_Pos.z += 0.1f;
	
	// 移動制限
	if (m_Pos.z > 10.0f)
	{
		SetDestroy();
		return;
	}

	// 敵との当たり判定
	CScene* scene = CManager::GetScene();
	std::vector<CEnemy*> enemylist = scene->GetGameObjects<CEnemy>(DEPTH1);

	for (CEnemy* enemy : enemylist)
	{
		D3DXVECTOR3 enemyPos = enemy->GetPos();

		D3DXVECTOR3 direction = m_Pos - enemyPos;
		float length = D3DXVec3Length(&direction);

		if (length < 2.0f) // 当たり判定の半径
		{
			scene->AddGameObject<CExplosion>(1)->SetPos(m_Pos); // エフェクト

			enemy->SetDestroy();
			SetDestroy();
			return;
		}
	}



}

void CBullet::Draw()
{
	// マトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rot.y, m_Rot.x, m_Rot.z);
	D3DXMatrixTranslation(&trans, m_Pos.x, m_Pos.y, m_Pos.z);

	world = scale * rot * trans;

	CRenderer::SetWorldMatrix(&world);

	// マテリアル設定
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	CRenderer::SetMaterial(material);


	m_Model->Draw();

}