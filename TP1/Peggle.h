#pragma once
#include "Engine.h"
#include "Component.h"
#include "Sprite.h"
#include "Resources.h"
class Peggle :
	public Component
{
public:
	Peggle();
	~Peggle();

	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	Sprite* s;
};

