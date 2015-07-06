#include "Canon.h"

Canon::Canon()
	: Sprite(Texture::ID::Canon)
	, SHOT_SPEED(1)
	, ROT_SPEED(5)
	, mRotation(0)
	, mShotTimer(0)
	, mBullet(nullptr)
	, mPivot(GetTextureInfos()->infos.Width/2, GetTextureInfos()->infos.Height, 0.f)
	, live(3)
{
	SetPivot(mPivot);
	SetPosition(0.f, gApp->GetParam().BackBufferHeight/2);

	D3DXVECTOR2 pos(GetPosition());

	// Create the bullet with it's starting position
	mBullet = new Navi(pos);
	// Desactivate the bulle on spawn
	mBullet->Deactivate();
}


Canon::~Canon()
{
	delete mBullet;
	mBullet = nullptr;
}

// Update of the canon
void Canon::Update()
{
	float dt = gTimer->GetDeltaTime();

	Rotate(dt);
	Shoot(dt);
	UpdateLive();
}

// Method that handle the rotate of the canon
void Canon::Rotate(float dt)
{
	float maxRot = D3DX_PI / 2;
	float maxRotNeg = -D3DX_PI / 2;

	if (gDInput->keyDown(DIKEYBOARD_D))
	{
		if (mRotation <= maxRot)
		{
			mRotation += ROT_SPEED * dt;
			SetRotationRad(0.f, 0.f, mRotation);
		}
	    else
		{
			mRotation = maxRot;
		}
	}

	if (gDInput->keyDown(DIKEYBOARD_A))
	{
		if (mRotation >= maxRotNeg)
		{
			mRotation -= ROT_SPEED * dt;
			SetRotationRad(0.f, 0.f, mRotation);
		}
		else
		{
			mRotation = maxRotNeg;
		}
	}
}

// Method that handle the shooting of the canon
void Canon::Shoot(float dt)
{
	mShotTimer += dt;

	if (gDInput->keyDown(DIKEYBOARD_SPACE) && mShotTimer >= SHOT_SPEED && !mBullet->IsVisible() && live > 0)
	{
		D3DXVECTOR3 dir(-sinf(mRotation), cosf(mRotation), 0.f);
		D3DXVECTOR3 pos(dir * GetTextureInfos()->infos.Height);
		D3DXVECTOR3 newPos(GetPosition() - pos);

		mShotTimer = 0;
		mBullet->SetRotation(mRotation);
		mBullet->Activate(newPos);
	}
}

// Method that handle the live of the player 
void Canon::UpdateLive()
{
	if (mBullet->GetGotLife())
	{
		mBullet->SetGotLife(false);
		live++;
	}

	if (mBullet->GetLostLife())
	{
		mBullet->SetLostLife(false);
		live--;
	}

	if (live > 3)
	{
		live = 3;
	}
}

// Method to desactivate the canon
void Canon::Deactivate()
{
	mRotation = 0;
	live = 3;
	SetVisible(false);
	mBullet->Deactivate();
}

// Method to activat ethe canon
void Canon::Activate()
{
	live = 3;
	SetVisible(true);
}
