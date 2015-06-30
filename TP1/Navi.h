#pragma once
#include "Sprite.h"
#include "Resources.h"

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


	//bool OnCollision() { return true; }
	void Start() {}
	void Update();
	void Stop() {}

	void SetRotation(float rot){ mRotation = rot; }

	void Activate(D3DXVECTOR2 pos);
	void Deactivate();

private:
	void Move(float dt);

	D3DXVECTOR3 mCenter;
	D3DXVECTOR3 mDir;
	D3DXVECTOR3 mPos;

	float mRotation;
	const int SPEED;
};

