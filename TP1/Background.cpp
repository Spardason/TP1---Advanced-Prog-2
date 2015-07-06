#include "Background.h"

Background::Background()
	: Sprite(Texture::ID::Bg)
	, mCenter(GetTextureInfos()->infos.Width/2, GetTextureInfos()->infos.Height/2, 0.f)
{
	SetPivot(mCenter);
	SetRotationRad(0.f, 0.f, D3DX_PI);
}


Background::~Background()
{
}
