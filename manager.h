#pragma once


class CManager
{
private:
	// static �̃����o�ϐ������ꍇ�� cpp �ł�����x�錾���Ȃ����Ȃ��Ƃ����Ȃ�
	static class CScene* m_Scene;
public:
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();

	template<typename T>
	static void SetScene()
	{
		if (m_Scene != NULL)
		{// ���݂̃V�[�����폜
			m_Scene->Uninit();
			delete m_Scene;
		}

		// �V�����V�[��������
		T* scene = new T();
		m_Scene = scene;
		scene->Init();
	}

	static CScene* GetScene() { return m_Scene; };
};