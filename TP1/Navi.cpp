#include "Navi.h"


Navi::Navi()
	: Sprite(Texture::ID::Navi)
	, SPEED(100)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f)
{
	SetPivot(&mCenter);
}


Navi::~Navi()
{

}

void Navi::Update()
{
	float dt = gTimer->GetDeltaTime();

	Move(dt);
	
}

void Navi::Move(float dt)
{
	SetPosition(GetPosition().x + 0.5, GetPosition().y + 0.5);
}
