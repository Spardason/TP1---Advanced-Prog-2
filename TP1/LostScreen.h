#pragma once
#include "Sprite.h"
#include "Resources.h"

class LostScreen :
	public Sprite
{
public:
	LostScreen();
	~LostScreen();

	void Start() {}
	void Update();
	void Stop() {}
};

