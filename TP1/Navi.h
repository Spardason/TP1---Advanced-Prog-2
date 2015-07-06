#pragma once
#include "Sprite.h"
#include "Resources.h"
#include "Bomb.h"
#include "Bumper.h"
#include "Pot.h"
#include "CCircle.h"

/*
*	This is the class for the Bullet
*	Handle all the bullet actions 
*/

class Navi :
	public Sprite
{
public:
	// Ctor/Dtor
	Navi();
	Navi(D3DXVECTOR2 basePos);
	~Navi();

	// Parent Methods
	void Start() {}
	void Update();
	void Stop() {}

	// Getters/Setters
	void SetRotation(float rot){ mRotation = rot; }
	bool GetGotLife() { return mGotLife; }
	void SetGotLife(bool toggle) { mGotLife = toggle; }
	bool GetLostLife() { return mLostLife; }
	void SetLostLife(bool toggle){ mLostLife = toggle; }

	// Public Methods
	void Activate(D3DXVECTOR3 pos);
	void Deactivate();

private:
	// Private Methods
	void Move(float dt);
	void CheckCollision();
	void CheckBorder();

	// Member Variables
	bool mGotLife;
	bool mLostLife;
	CCircle *mCollider;
	D3DXVECTOR3 mCenter;
	D3DXVECTOR2 mDir;
	float mRotation;

	// Const Variables
	const float GRAVITY;
	const int RIGHT_BORDER;
	const int LEFT_BORDER;
	const int BOTTOM_BORDER;
	const int RADIUS;
	const int SPEED;
};

