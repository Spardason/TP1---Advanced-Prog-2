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


	//bool OnCollision() { return true; }
	void Start() {}
	void Update();
	void Stop() {}

private:
	void Move(float dt);

	D3DXVECTOR3 mCenter;
	const int SPEED;
};

