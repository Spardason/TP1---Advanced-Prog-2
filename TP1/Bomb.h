#pragma once
#include "Collidables.h"

/*
*	This is the class for the bomb collidable
*	Handle all the bomb actions (same as collidable by heritage)
*/

class Bomb :
	public Collidables
{
public:
	Bomb();
	~Bomb();

	bool OnCollision() { return true; }
	void Start() {}
	void Update() {}
	void Stop() {}

private:
	D3DXVECTOR3 mCenter;
};

