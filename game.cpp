#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "game.h"
#include "title.h"
#include "gameobject.h"
#include "model.h"
#include "player.h"
#include "camera.h"
#include "field.h"
#include "skydome.h"

void CGame::Init()
{
	CBullet::Load();

	AddGameObject<CCamera>(DEPTH0);
	AddGameObject<CField>(DEPTH1);
	AddGameObject<CSkydome>(DEPTH1);
	AddGameObject<CPlayer>(DEPTH1);

	AddGameObject<CEnemy>(DEPTH1)->SetPos(D3DXVECTOR3(-5.0f, 0.0f, 5.0f));
	AddGameObject<CEnemy>(DEPTH1)->SetPos(D3DXVECTOR3(0.0f, 0.0f, 5.0f));
	AddGameObject<CEnemy>(DEPTH1)->SetPos(D3DXVECTOR3(5.0f, 0.0f, 5.0f));

	AddGameObject<CPolygon>(DEPTH2);
}

void CGame::Uninit()
{
	CScene::Uninit();

	CBullet::Unload();
}

void CGame::Update()
{
	CScene::Update();

	if (CInput::GetKeyTrigger(VK_RETURN))
	{
		CManager::SetScene<CTitle>();
	}
}