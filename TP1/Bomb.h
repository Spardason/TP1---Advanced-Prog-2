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
	// Ctor/Dtor
	Bomb();
	~Bomb();

	// Parent Methods
	void OnCollision();
	void Start() {}
	void Update() {}
	void Stop() {}

private:
	// Member Variables
	D3DXVECTOR3 mCenter;

	// Const variables
	const int RADIUS;
};

