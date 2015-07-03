#pragma once
#include "Sprite.h"
#include "Resources.h"
#include "Bomb.h"
#include "Bumper.h"
#include "CCircle.h"

/*
*	This is the class for the Bullet
*	Handle all the bullet actions 
*/

class Navi :
	public Sprite
{
public:
	Navi();
	Navi(D3DXVECTOR2 basePos);
	~Navi();

	void Start() {}
	void Update();
	void Stop() {}

	void SetRotation(float rot){ mRotation = rot; }

	void Activate(D3DXVECTOR3 pos);
	void Deactivate();

private:
	void Move(float dt);
	void CheckCollision();
	void CheckBorder();

	CCircle *collider;

	D3DXVECTOR3 mCenter;
	D3DXVECTOR2 mDir;

	float mRotation;

	const int RIGHT_BORDER;
	const int LEFT_BORDER;
	const int BOTTOM_BORDER;

	const int RADIUS;
	const int SPEED;
};

