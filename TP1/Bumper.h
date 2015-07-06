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
	// Ctor/Dtor
	Bumper();
	~Bumper();

	// Parent Methods
	void OnCollision();
	void Start() {}
	void Update() {}
	void Stop() {}

private:
	// Member variables
	D3DXVECTOR3 mCenter;

	// Const Variables
	const int RADIUS;
};

