#pragma once


class CManager
{
private:
	// static ‚Ìƒƒ“ƒo•Ï”‚ğì‚éê‡‚Í cpp ‚Å‚à‚¤ˆê“xéŒ¾‚µ‚È‚¨‚³‚È‚¢‚Æ‚¢‚¯‚È‚¢
	static class CScene* m_Scene;
public:
	static void Init();
	static void Uninit();
	static void Update();
	static void Draw();

	static CScene* GetScene() { return m_Scene; };
};