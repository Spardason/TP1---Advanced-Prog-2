#pragma once
#include "Sprite.h"
#include "Resources.h"

/*
*	This is the class that handle the background
*
*/

class Background :
	public Sprite
{
public:
	// Ctor/Dtor
	Background();
	~Background();

private:
	// Member Variables
	D3DXVECTOR3 mCenter;
};

