#pragma once
#include "Sprite.h"
#include "Resources.h"

/*
*	Class for the base collidables
*	Contains all the functionnality of the collidables
*/

class Collidables :
	public Sprite
{
public:
	Collidables();
	Collidables(Texture::ID id);
	~Collidables();

	virtual bool OnCollision() { return true; }
	virtual void Start() {}
	virtual void Update() {}
	virtual void Stop() {}

private:
	D3DXVECTOR2 pos;
};

