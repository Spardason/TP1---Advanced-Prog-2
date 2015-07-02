#include "Canon.h"

Canon::Canon()
	: Sprite(Texture::ID::Canon)
	, SHOT_SPEED(1)
	, ROT_SPEED(5)
	, mRotation(0)
	, mShotTimer(0)
	, mBullet(nullptr)
	, mPivot(GetTextureInfos()->infos.Width/2, GetTextureInfos()->infos.Height, 0.f)
{
	SetPivot(mPivot);
	SetPosition(0.f, gApp->GetParam().BackBufferHeight/2);

	D3DXVECTOR2 pos(GetPosition());
	mBullet = new Navi(pos);
	mBullet->Deactivate();
}


Canon::~Canon()
{
	delete mBullet;
	mBullet = nullptr;
}

void Canon::Update()
{
	float dt = gTimer->GetDeltaTime();

	Rotate(dt);
	Shoot(dt);
}

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

void Canon::Shoot(float dt)
{
	mShotTimer += dt;

	if (gDInput->keyDown(DIKEYBOARD_SPACE) && mShotTimer >= SHOT_SPEED && !mBullet->IsVisible())
	{
		D3DXVECTOR2 dir(-sinf(mRotation), cosf(mRotation));
		D3DXVECTOR2 pos(GetPosition());

		mShotTimer = 0;
		mBullet->SetRotation(mRotation);
		mBullet->Activate(pos);
		std::cout << "PEW!" << std::endl;
	}
}
