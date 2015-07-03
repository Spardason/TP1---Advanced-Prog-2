#include "Bomb.h"


Bomb::Bomb()
	: Collidables(Texture::ID::Bomb)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
{
	SetPivot(mCenter);
	SetID(Components::ID::Bomb);
}


Bomb::~Bomb()
{
}

void Bomb::OnCollision() 
{
	if (IsVisible())
	{
		SetVisible(false);
	}
}
