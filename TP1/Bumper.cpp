#include "Bumper.h"


Bumper::Bumper()
	: Collidables(Texture::ID::Bumper)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
{
	SetPivot(mCenter);
	SetID(Components::ID::Bumper);
	collider = new CCircle(this, GetPosition().x, GetPosition().y, GetTextureInfos()->infos.Width / 2);
}


Bumper::~Bumper()
{
	delete collider;
	collider = nullptr;
}

// Does nothing special when colliding
void Bumper::OnCollision()
{

}
