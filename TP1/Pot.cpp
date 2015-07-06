#include "Pot.h"


Pot::Pot()
	: Sprite(Texture::ID::Pot)
	, SPEED(100)
	, LEFT_BORDER(-(gApp->GetParam().BackBufferWidth / 2))
	, RIGHT_BORDER(gApp->GetParam().BackBufferWidth / 2)
	, BASE_Y(-250)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetID(Components::ID::Pot);
	mCollider = new CRectangle(this, -mCenter.x, -mCenter.y, GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2);
	SetPivot(mCenter);
	SetRotationRad(0.f, 0.f, D3DX_PI);
	SetPosition(0.f, BASE_Y);
}


Pot::~Pot()
{

}

// Update of the pot
void Pot::Update()
{
	float dt = gTimer->GetDeltaTime();

	Move(dt);
}


// Method that handle the move from left to right of the pot
void Pot::Move(float dt)
{
	static int dir = 1;
	float xMove = GetPosition().x;
	if (GetPosition().x >= RIGHT_BORDER)
	{
		dir = -1;
	}

	else if (GetPosition().x <= LEFT_BORDER)
	{
		dir = 1;
	}

	xMove += SPEED * dt * dir;
	mCollider->SetPosition(xMove, GetPosition().y);
	SetPosition(xMove, GetPosition().y);
}

// Does nothing special when colliding
void Pot::OnCollision()
{
	
}
