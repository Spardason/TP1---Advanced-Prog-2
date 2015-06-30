#pragma once
#include "Sprite.h"
#include "Resources.h"
#include "Navi.h"

/*
*	This is the class fro the canon
*	Handle all the canon actions
*/

class Canon :
	public Sprite
{
public:
	Canon();
	~Canon();

	void Start() {}
	void Update();
	void Stop() {}

private:
	void Rotate(float dt);
	void Shoot(float dt);

	const int SHOT_SPEED;
	const int ROT_SPEED;
	float mRotation;
	float mShotTimer;

	Navi *mBullet;

	D3DXVECTOR3 mPivot;
};

