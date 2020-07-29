#pragma once


class CGameObject
{
protected:
	bool m_Destroy = false;

	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3 m_Rot;
	D3DXVECTOR3 m_Scale;

public:
	CGameObject() {}
	virtual ~CGameObject(){}

	virtual void Init() = 0; // èÉêàâºëzä÷êî
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// éÊìæ
	D3DXVECTOR3 GetPos() { return m_Pos; }
	D3DXVECTOR3 GetRot() { return m_Rot; }
	D3DXVECTOR3 GetScale() { return m_Scale; }

	D3DXVECTOR3 GetForward()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rot.y, m_Rot.x, m_Rot.z);

		D3DXVECTOR3 forward;
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;

		return forward;
	}

	// ê›íË
	void SetPos(D3DXVECTOR3 Pos) { m_Pos = Pos; }
	void SetRot(D3DXVECTOR3 Rot) { m_Rot = Rot; }
	void SetScale(D3DXVECTOR3 Scale) { m_Scale = Scale; }

	// çÌèúÇ∑ÇÈó\ñÒÇÃÉtÉâÉO
	void SetDestroy() { m_Destroy = true; }

	// çÌèú
	bool Destroy()
	{
		if (m_Destroy)
		{
			Uninit();
			delete this;
			return true;
		}
		else
			return false;
	}

};