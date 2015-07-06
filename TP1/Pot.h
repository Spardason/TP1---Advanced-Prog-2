#pragma once
#include "Sprite.h"
#include "Resources.h"
#include "CRectangle.h"

/*
*	This is the class for the bucket 
*	Handle all the bucket actions
*/

class Pot :
	public Sprite
{
public:
	// Ctor/Dtor
	Pot();
	~Pot();

	// Parent Methods
	void OnCollision();
	void Start() {}
	void Update();
	void Stop() {}

private:
	// Private Methods
	void Move(float dt);

	// Member Variable
	D3DXVECTOR3 mCenter;
	CRectangle *mCollider;

	// Const Variables
	const int BASE_Y;
	const int SPEED;
	const int LEFT_BORDER;
	const int RIGHT_BORDER;

	
};

