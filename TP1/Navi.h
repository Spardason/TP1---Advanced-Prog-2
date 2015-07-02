#pragma once
#include "Sprite.h"
#include "Resources.h"
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

	void Activate(D3DXVECTOR2 pos);
	void Deactivate();

private:
	void Move(float dt);

	CCircle *collider;

	D3DXVECTOR3 mCenter;
	D3DXVECTOR3 mDir;

	float mRotation;
	const int SPEED;
};

