#pragma once
#include "Sprite.h"
#include "Resources.h"

/*
*	This is the class that handle the Lostscreen
*
*/

class LostScreen :
	public Sprite
{
public:
	// Ctor/Dtor
	LostScreen();
	~LostScreen();

	// Parent Methods
	void Start() {}
	void Update();
	void Stop() {}

	// Getters/Setters
	bool GetWannaReplay(){ return wannaReplay; }
	void SetWannaReplay(bool toggle){ wannaReplay = toggle; }

private:
	// Member Variables
	D3DXVECTOR3 mCenter;
	bool wannaReplay;
};

