#pragma once


class CManager
{
private:
	// static のメンバ変数を作る場合は cpp でもう一度宣言しなおさないといけない
	static class CScene* m_Scene;
public:
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();

	static CScene* GetScene() { return m_Scene; };
};