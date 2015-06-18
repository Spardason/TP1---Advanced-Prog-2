#pragma once
#include "Sprite.h"
#include "Resources.h"
class Collidables :
	public Sprite
{
public:
	Collidables();
	Collidables(Texture::ID id);
	~Collidables();
};

