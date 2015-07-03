#pragma once
#include "Sprite.h"
#include "Resources.h"
#include "CCircle.h"

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

	virtual void OnCollision() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void Stop() {}	

	CCircle *collider;
};

