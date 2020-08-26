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

#define N_LAYER (3) // ���C���[�̐�
#define DEPTH0  (0) // �J�����Ƃ��V�X�e���n(���C���̏���) 
#define DEPTH1  (1) // �I�u�W�F�N�g
#define DEPTH2  (2) // �QD�n

class CScene
{
protected:
	std::list<CGameObject*> m_GameObject[N_LAYER]; // 
	
public:
	CScene(){}
	virtual ~CScene(){}

	virtual void Init() = 0; // �������z�֐�
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
	}

	virtual void Update()
	{
		for (int i = 0; i < N_LAYER; i++)
		{
			for (CGameObject* object : m_GameObject[i])
				object->Update();

			// �I�u�W�F�N�g�̍폜 �����_��
			m_GameObject[i].remove_if([](CGameObject* object) {return object->Destroy(); });
		}
	}

	virtual void Draw()
	{

		for (int i = 0; i < N_LAYER; i++)// ���C���[�̏��Ԃŕ`��
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

	// GameObject���擾(�|�C���^)
	// �P�����Ȃ����̂̂�(�v���C���A�J�����Ƃ�)
	template <typename T>
	T* GetGameObject(int Layer)
	{
		for (CGameObject* object : m_GameObject[Layer])
		{
			if (typeid(*object) == typeid(T)) // "typeid" �Ō^�𒲂ׂ�
				return (T*)object;
		}
		return NULL;
	}

	// GameObject���擾(�|�C���^)
	// �Q�ȏ�̏ꍇ
	template <typename T>
	std::vector<T*> GetGameObjects( int Layer)
	{
		std::vector<T*> objects; // STL�̔z��
		for (CGameObject* object : m_GameObject[Layer])
		{
			if (typeid(*object) == typeid(T))
				objects.push_back((T*)object);
		}
		return objects;
	}
};