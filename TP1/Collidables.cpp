#include "Collidables.h"


Collidables::Collidables()
{

}

Collidables::Collidables(Texture::ID id)
	: Sprite(id)
{
	collider = new CCircle(this, 0, 0, GetTextureInfos()->infos.Width);
}

Collidables::~Collidables()
{
	delete collider;
	collider = nullptr;
}
