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

	static CScene* GetScene() { return m_Scene; };
};