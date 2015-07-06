#include "LostScreen.h"


LostScreen::LostScreen()
	: Sprite(Texture::ID::LostScreen)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
	, wannaReplay(false)
{
	SetVisible(false);
	SetPivot(mCenter);
	SetPosition(0.f, 0.f);
	SetRotationRad(D3DX_PI, 0.f, D3DX_PI);
}


LostScreen::~LostScreen()
{

}

void LostScreen::Update()
{
	if (IsVisible())
	{
		if (gDInput->keyDown(DIKEYBOARD_SPACE))
		{
			wannaReplay = true;
			SetVisible(false);
		}
	}
}
