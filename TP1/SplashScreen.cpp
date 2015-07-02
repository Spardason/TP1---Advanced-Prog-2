#include "SplashScreen.h"


SplashScreen::SplashScreen()
	: Sprite(Texture::ID::SplashScreen)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
	//, mPos(0.f, 0.f, 0.f)
{
	SetPivot(mCenter);
	SetPosition(0.f, 0.f);
	SetRotationRad(D3DX_PI, 0.f, D3DX_PI);
}


SplashScreen::~SplashScreen()
{

}

void SplashScreen::Update()
{
	if (gDInput->keyDown(DIKEYBOARD_SPACE))
	{
		SetVisible(false);
	}
}
