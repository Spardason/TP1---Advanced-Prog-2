#pragma once
#include "Sprite.h"
#include "Resources.h"

/*
*	This is the class for the bucket 
*	Handle all the bucket actions
*/

class Pot :
	public Sprite
{
public:
	Pot();
	~Pot();

	bool OnCollision() { return true; }
	void Start() {}
	void Update() {}
	void Stop() {}

private:
	const int SPEED;
};

