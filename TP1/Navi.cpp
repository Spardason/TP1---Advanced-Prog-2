#include "Navi.h"


Navi::Navi()
	: Sprite(Texture::ID::Navi)
	, SPEED(0)
	, RADIUS(0)
	, RIGHT_BORDER(0)
	, LEFT_BORDER(0)
	, BOTTOM_BORDER(0)
	, mRotation(0)
	, mDir(0.f, 0.f)
	, mCenter(0.f, 0.f, 0.f)
{
	
}

Navi::Navi(D3DXVECTOR2 basePos)
	: Sprite(Texture::ID::Navi)
	, SPEED(200)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
	, RIGHT_BORDER(-(gApp->GetParam().BackBufferWidth / 2))
	, LEFT_BORDER(gApp->GetParam().BackBufferWidth / 2)
	, BOTTOM_BORDER(-(gApp->GetParam().BackBufferHeight / 2))
	, mRotation(0)
	, mDir(0.f, 0.f)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	collider = new CCircle(this, 0.f, 0.f, RADIUS);
	SetID(Components::ID::Ball);
	SetPivot(mCenter);
	SetPosition(basePos.x, basePos.y);
	SetVisible(false);
}

Navi::~Navi()
{

}

void Navi::Activate(D3DXVECTOR3 pos)
{
	mDir = -D3DXVECTOR2(-sinf(mRotation), cosf(mRotation));
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
		CheckCollision();
		CheckBorder();
		Move(dt);
	}

	mDir.y -= 2 * dt;

	
}

void Navi::Move(float dt)
{	
	static float timer = 0;

	D3DXVECTOR2 tempPos = GetPosition();

	tempPos += mDir * SPEED * dt;

	collider->SetPosition(tempPos.x, tempPos.y);
	SetPosition(tempPos.x, tempPos.y);

	timer += dt;

	//if (timer >= 5.f)
	//{
	//	Deactivate();
	//	timer = 0.f;
	//}
}

void Navi::CheckCollision()
{
	//Go through each collider collided with though the LookForCollision Function
	for each (Collider* col in collider->LookForCollisions())
	{
		mDir = D3DXVECTOR2(GetPosition().x, GetPosition().y) - col->GetPosition();
		D3DXVec2Normalize(&mDir, &mDir);

		//If one of the collider is a bomb
		if (col->GetGameObject()->GetID() == Components::Bomb)
		{
			//Consider that collider's component a bomb
			col->SetEnabled(false);
			static_cast<Bomb*>(col->GetGameObject())->OnCollision();
		}

		if (col->GetGameObject()->GetID() == Components::Bumper)
		{
			static_cast<Bumper*>(col->GetGameObject())->OnCollision();
		}
	}
}

void  Navi::CheckBorder()
{
	if (GetPosition().x <= RIGHT_BORDER)
	{
		mDir.x = -mDir.x;
	}

	if (GetPosition().x >= LEFT_BORDER)
	{
		mDir.x = -mDir.x;
	}

	if (GetPosition().y <= BOTTOM_BORDER)
	{
		Deactivate();
	}
}


