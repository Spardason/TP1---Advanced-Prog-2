#include "Bumper.h"


Bumper::Bumper()
	: Collidables(Texture::ID::Bumper)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(mCenter);
	SetID(Components::ID::Bumper);
}


Bumper::~Bumper()
{
}
