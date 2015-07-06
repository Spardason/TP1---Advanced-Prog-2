#include "Collidables.h"


Collidables::Collidables()
{

}

Collidables::Collidables(Texture::ID id)
	: Sprite(id)
{
	
}

Collidables::~Collidables()
{
	delete collider;
	collider = nullptr;
}
