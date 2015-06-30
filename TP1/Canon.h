#pragma once
#include "Sprite.h"
#include "Resources.h"

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

	void Start();
	void Update();
	void Stop();

private:
	const int SHOT_SPEED;
	const int ROT_SPEED;

	D3DXVECTOR2 pos;
};

