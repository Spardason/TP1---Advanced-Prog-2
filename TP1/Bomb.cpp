#include "Bomb.h"


Bomb::Bomb()
	: Collidables(Texture::ID::Bomb)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(&mCenter);
}


Bomb::~Bomb()
{
}
