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
	void Replay();
	void StartGame();

	std::vector<Collidables*> collidables;
	std::vector<Collidables*>::iterator it;

	bool gameStarted;

	Pot *pot;
	Canon *canon;
	Background *bg;
	Navi *navi;
	Bomb *bomb;
	Bumper *bumper;
	SplashScreen *sp;
	LostScreen *ls;
};

