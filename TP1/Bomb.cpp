#include "Bomb.h"


Bomb::Bomb()
	: Collidables(Texture::ID::Bomb)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
	, RADIUS(GetTextureInfos()->infos.Width / 2)
{
	SetPivot(mCenter);
	SetID(Components::ID::Bomb);
	collider = new CCircle(this, GetPosition().x, GetPosition().y, GetTextureInfos()->infos.Width / 2);
}


Bomb::~Bomb()
{
	delete collider;
	collider = nullptr;
}

// Set the bomb invisible when the ball collides with it
void Bomb::OnCollision() 
{
	if (IsVisible())
	{
		SetVisible(false);
	}
}
