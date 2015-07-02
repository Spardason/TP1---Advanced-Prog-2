#include "Bomb.h"


Bomb::Bomb()
	: Collidables(Texture::ID::Bomb)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetID(Components::ID::Bomb);
	SetPivot(mCenter);
}


Bomb::~Bomb()
{
}
