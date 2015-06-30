#pragma once
#include "GameiInclude.h"

/*
*	This is the main game class, wich will contain all game objects 
*	Handle all the game actions and the relations between objects
*/

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
	Bomb *bomb;
	Bumper *bumper;
	Sprite *s;
	Sprite *s2;
};

