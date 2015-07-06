#include "Navi.h"


Navi::Navi()
	: Sprite(Texture::ID::Navi)
	, SPEED(0)
	, RADIUS(0)
	, RIGHT_BORDER(0)
	, LEFT_BORDER(0)
	, BOTTOM_BORDER(0)
	, GRAVITY(0)
	, mRotation(0)
	, mDir(0.f, 0.f)
	, mCenter(0.f, 0.f, 0.f)
	, mGotLife(false)
	, mLostLife(false)
{
	
}

Navi::Navi(D3DXVECTOR2 basePos)
	: Sprite(Texture::ID::Navi)
	, SPEED(200)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
	, RIGHT_BORDER(-(gApp->GetParam().BackBufferWidth / 2))
	, LEFT_BORDER(gApp->GetParam().BackBufferWidth / 2)
	, BOTTOM_BORDER(-(gApp->GetParam().BackBufferHeight / 2))
	, GRAVITY(2.5)
	, mRotation(0)
	, mDir(0.f, 0.f)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
	, mGotLife(false)
	, mLostLife(false)
{
	mCollider = new CCircle(this, 0.f, 0.f, RADIUS);
	SetID(Components::ID::Ball);
	SetPivot(mCenter);
	SetPosition(basePos.x, basePos.y);
	SetVisible(false);
}

Navi::~Navi()
{

}

// Method to activate the bullet
void Navi::Activate(D3DXVECTOR3 pos)
{
	mDir = -D3DXVECTOR2(-sinf(mRotation), cosf(mRotation));
	SetPosition(pos.x, pos.y);
	SetVisible(true);
}

// Method to desactivate the bullet
void Navi::Deactivate()
{
	SetVisible(false);
}

// Update of teh bullet
void Navi::Update()
{
	float dt = gTimer->GetDeltaTime();

	if (isVisible)
	{
		CheckCollision();
		CheckBorder();
		Move(dt);
	}

	mDir.y -= GRAVITY * dt;	
}

// Method that handle the move of the bullet
void Navi::Move(float dt)
{	
	D3DXVECTOR2 tempPos = GetPosition();

	tempPos += mDir * SPEED * dt;

	mCollider->SetPosition(tempPos.x, tempPos.y);
	SetPosition(tempPos.x, tempPos.y);
}

// Method that check the collision with other objects
// If there is a collision on a bomb or the pot do specifics actions
void Navi::CheckCollision()
{
	//Go through each collider collided with through the LookForCollision Function
	for each (Collider* col in mCollider->LookForCollisions())
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

		//If one of the collider is a Pot
		if (col->GetGameObject()->GetID() == Components::Pot)
		{
			// Consider it is a pot
			static_cast<Pot*>(col->GetGameObject())->OnCollision();
			mGotLife = true;
			// Desactivate the bullet
			Deactivate();
		}
	}
}

// Method to check for the borders of the screen
// If its the bottom of the screen remove the ball and remove a life
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
		mLostLife = true;
		Deactivate();
	}
}


