#pragma once
#include "Collidables.h"

/*
*	This is the class for the bumper collidable
*	Handle all the bomb actions (same as collidable by heritage)
*/

class Bumper :
	public Collidables
{
public:
	Bumper();
	~Bumper();

	bool OnCollision() { return true; }
	void Start() {}
	void Update() {}
	void Stop() {}
};

