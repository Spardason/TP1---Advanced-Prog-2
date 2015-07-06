#pragma once
#include "Sprite.h"
#include "Resources.h"

/*
*	This is the class for all the text display on screen
*	Mostly handle visibility and placement
*/

class Text :
	public Sprite
{
public:
	// Ctor/Dtor
	Text();
	Text(Texture::ID id, D3DXVECTOR2 pos, bool visibility);
	~Text();

private:
	// Member variables
	D3DXVECTOR3 mCenter;
};

