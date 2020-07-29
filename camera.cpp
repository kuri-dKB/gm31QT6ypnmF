#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "camera.h"
#include "input.h"
#include "model.h"
#include "player.h"



void CCamera::Init()
{
	m_Pos = D3DXVECTOR3(0.0f, 2.0f, -4.0f);   // 位置
	m_Target = D3DXVECTOR3(0.0f, 1.7f, 0.0f); // 注視点



}

void CCamera::Uninit()
{

}

void CCamera::Update()
{
	// 注視点
	CPlayer* player = CManager::GetScene()->GetGameObject<CPlayer>(DEPTH1);
	m_Target = player->GetPos();

	// トップビュー
	//m_Pos = m_Target + D3DXVECTOR3(0.0f, 20.0f, -10.0f);

	// 3人称
	D3DXVECTOR3 forward = player->GetForward();
	m_Pos = m_Target - forward * 5.0f + D3DXVECTOR3(0.0f, 2.0f, 0.0f);

}

void CCamera::Draw()
{
	

	// ビューマトリクス設定
	//D3DXMATRIX viewMatrix;
	D3DXMatrixLookAtLH(&m_ViewMatrix, &m_Pos, &m_Target, &D3DXVECTOR3(0.0f,1.0f, 0.0f));
	
	CRenderer::SetViewMatrix(&m_ViewMatrix);

	// プロジェクションマトリクス設定
	D3DXMATRIX projectionMatrix;
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, 1.0f,
		(float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);

	CRenderer::SetProjectionMatrix(&projectionMatrix);
}