#pragma once
#include <list>
#include <vector>
#include <typeinfo> // typeid
#include "main.h"
#include "gameobject.h"
#include "camera.h"
#include "field.h"
#include "model.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "skydome.h"
#include "polygon.h"

#define N_LAYER (3) // レイヤーの数
#define DEPTH0  (0) // カメラとかシステム系(レイヤの順番) 
#define DEPTH1  (1) // オブジェクト
#define DEPTH2  (2) // ２D系

class CScene
{
protected:
	std::list<CGameObject*> m_GameObject[N_LAYER]; // 
	
public:
	CScene(){}
	virtual ~CScene(){}

	virtual void Init()
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

	virtual void Uninit()
	{
		for (int i = 0; i < N_LAYER; i++)
		{
			for (CGameObject* object : m_GameObject[i])
			{
				object->Uninit();
				delete object;
			}
			m_GameObject[i].clear();
		}

		CBullet::Unload();
	}

	virtual void Update()
	{
		for (int i = 0; i < N_LAYER; i++)
		{
			for (CGameObject* object : m_GameObject[i])
				object->Update();

			// オブジェクトの削除 ラムダ式
			m_GameObject[i].remove_if([](CGameObject* object) {return object->Destroy(); });
		}
	}

	virtual void Draw()
	{

		for (int i = 0; i < N_LAYER; i++)// レイヤーの順番で描画
		{
			for (CGameObject* object : m_GameObject[i])
				object->Draw();
		}
	}

	// 
	template <typename T>
	T* AddGameObject( int Layer )
	{
		T* gameObject = new T();
		m_GameObject[Layer].push_back(gameObject);
		gameObject->Init();

		return gameObject;
	}

	// GameObjectを取得(ポインタ)
	// １つしかないもののみ(プレイヤ、カメラとか)
	template <typename T>
	T* GetGameObject(int Layer)
	{
		for (CGameObject* object : m_GameObject[Layer])
		{
			if (typeid(*object) == typeid(T)) // "typeid" で型を調べる
				return (T*)object;
		}
		return NULL;
	}

	// GameObjectを取得(ポインタ)
	// ２つ以上の場合
	template <typename T>
	std::vector<T*> GetGameObjects( int Layer)
	{
		std::vector<T*> objects; // STLの配列
		for (CGameObject* object : m_GameObject[Layer])
		{
			if (typeid(*object) == typeid(T))
				objects.push_back((T*)object);
		}
		return objects;
	}
};