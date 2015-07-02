#pragma once
#include "Sprite.h"
#include "Resources.h"

class SplashScreen :
	public Sprite
{
public:
	SplashScreen();
	~SplashScreen();

	void Start() {}
	void Update();
	void Stop() {}

private:
	D3DXVECTOR3 mCenter;
	//D3DXVECTOR3 mPos;
};

