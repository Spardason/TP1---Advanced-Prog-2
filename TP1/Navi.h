#pragma once
#include "Sprite.h"
#include "Resources.h"

/*
*	This is the class for the Bullet
*	Handle all the bullet actions 
*/

class Navi :
	public Sprite
{
public:
	Navi();
	~Navi();

	void Start() {}
	void Update() {}
	void Stop() {}

private:
	const int SPEED;
};

