#pragma once
#include "Sprite.h"
#include "Resources.h"

/*
*	This is the class that handle the SplashScreen
*
*/

class SplashScreen :
	public Sprite
{
public:
	// Ctor/tor
	SplashScreen();
	~SplashScreen();

	// Parent Methods
	void Start() {}
	void Update();
	void Stop() {}

private:
	// Member Varables
	D3DXVECTOR3 mCenter;
};

