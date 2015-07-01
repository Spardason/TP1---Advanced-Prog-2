#include "Pot.h"


Pot::Pot()
	: Sprite(Texture::ID::Pot)
	, SPEED(100)
	, LEFT_BORDER(-(gApp->GetParam().BackBufferWidth / 2))
	, RIGHT_BORDER(gApp->GetParam().BackBufferWidth / 2)
	, mPos(0.f, -250, 0.f)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(&mCenter);
	SetRotation(0.f, 0.f, D3DX_PI);
	SetPosition(mPos.x, mPos.y);
}


Pot::~Pot()
{

}

void Pot::Update()
{
	float dt = gTimer->GetDeltaTime();

	Move(dt);
}

void Pot::Move(float dt)
{
	static int dir = 1;
	if (mPos.x >= RIGHT_BORDER)
	{
		dir = -1;
	}

	else if (mPos.x <= LEFT_BORDER)
	{
		dir = 1;
	}

	mPos.x += SPEED * dt * dir;
	SetPosition(mPos.x, mPos.y);
}
