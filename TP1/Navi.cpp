#include "Navi.h"


Navi::Navi()
	: Sprite(Texture::ID::Navi)
	, SPEED(10)
	, mRotation(0)
	, mDir(0.f, 0.f, 0.f)
	, mPos(0.f, 0.f, 0.f)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(&mCenter);
	SetVisible(false);
}

Navi::Navi(D3DXVECTOR2 basePos)
	: Sprite(Texture::ID::Navi)
	, SPEED(100)
	, mRotation(0)
	, mDir(0.f, 0.f, 0.f)
	, mPos(basePos)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(&mCenter);
	SetPosition(mPos.x, mPos.y);
	SetVisible(false);
}

Navi::~Navi()
{

}

void Navi::Activate(D3DXVECTOR2 pos)
{
	SetPosition(pos.x, pos.y);
	SetVisible(true);
	mPos.x = pos.x;
	mPos.y = pos.y;
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

	mDir = -D3DXVECTOR3(-sinf(mRotation), cosf(mRotation), 0.f);

	mPos += mDir * SPEED * dt;

	SetPosition(mPos.x, mPos.y);

	timer += dt;

	if (timer >= 5.f)
	{
		Deactivate();
		timer = 0.f;
	}
}


