#include "Navi.h"


Navi::Navi()
	: Sprite(Texture::ID::Navi)
	, SPEED(10)
	, mRotation(0)
	, mDir(0.f, 0.f, 0.f)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(mCenter);
	SetVisible(false);
}

Navi::Navi(D3DXVECTOR2 basePos)
	: Sprite(Texture::ID::Navi)
	, SPEED(100)
	, mRotation(0)
	, mDir(0.f, 0.f, 0.f)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(mCenter);
	SetPosition(basePos.x, basePos.y);
	SetVisible(false);
}

Navi::~Navi()
{

}

void Navi::Activate(D3DXVECTOR2 pos)
{
	SetPosition(pos.x, pos.y);
	SetVisible(true);
}

void Navi::Deactivate()
{
	SetVisible(false);
}

void Navi::Update()
{
	float dt = gTimer->GetDeltaTime();

	if (isVisible)
	{
		Move(dt);
	}
}

void Navi::Move(float dt)
{	
	static float timer = 0;

	D3DXVECTOR3 tempPos = GetPosition();
	mDir = -D3DXVECTOR3(-sinf(mRotation), cosf(mRotation), 0.f);

	//mPos += mDir * SPEED * dt;
	tempPos += mDir * SPEED * dt;

	SetPosition(tempPos.x, tempPos.y);

	timer += dt;

	if (timer >= 5.f)
	{
		Deactivate();
		timer = 0.f;
	}
}


