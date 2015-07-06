#pragma once
#include "Sprite.h"
#include "Resources.h"
#include "Navi.h"

/*
*	This is the class fro the canon
*	Handle all the canon actions
*	It also contains all the live of the player 
*/

class Canon :
	public Sprite
{
public:
	// Ctor/Dtor
	Canon();
	~Canon();

	// Parent Methods
	void Start() {}
	void Update();
	void Stop() {}

	// Getters/Setters
	int GetLive() { return live; }

	// Public Methods
	void Deactivate();
	void Activate();

private:
	// Private Methods
	void Rotate(float dt);
	void Shoot(float dt);
	void UpdateLive();
	
	// Member Variables
	int live;
	float mRotation;
	float mShotTimer;
	Navi *mBullet;
	D3DXVECTOR3 mPivot;

	// Const Variables
	const int SHOT_SPEED;
	const int ROT_SPEED;
	

	
};

