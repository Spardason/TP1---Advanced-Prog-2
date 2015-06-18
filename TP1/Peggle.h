#pragma once

#include "GameiInclude.h"

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
	void LoadTextures();

	Canon *canon;
	Sprite *bg;
	Navi *navi;
};

