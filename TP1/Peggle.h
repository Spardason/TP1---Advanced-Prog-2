#pragma once
#include "GameiInclude.h"
#include "vector"

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
	void CreateCollidables(int nbBombs, int nbBumpers);
	void CollidablesPlacement();

	std::vector<Collidables*> collidables;
	std::vector<Collidables*>::iterator it;

	Canon *canon;
	Background *bg;
	Navi *navi;
	Bomb *bomb;
	Bumper *bumper;
	Sprite *s;
	Sprite *s2;
};

