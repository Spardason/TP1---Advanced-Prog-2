#pragma once
#include "GameiInclude.h"
#include "vector"
#include "Text.h"
#include <algorithm>

/*
*	This is the main game class, wich will contain all game objects 
*	Handle all the game actions and the relations between objects
*/

class Peggle :
	public Component
{
public:
	//Ctor/Dtor
	Peggle();
	~Peggle();

	// Parent Methods
	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	// Private Methods
	void LoadTextures();
	void CreateCollidables(int nbBombs, int nbBumpers);
	void CollidablesPlacement(int nbInRow, int spacing);
	void Replay();
	void StartGame();
	void UpdateLive();
	void GameOver();

	// Member Variables
	std::vector<Collidables*> collidables;
	std::vector<Collidables*>::iterator it;

	bool gameStarted;
	bool gameOver;

	Text *three;
	Text *two;
	Text *one;
	Text *zero;
	Text *balls;
	Pot *pot;
	Canon *canon;
	Background *bg;
	Navi *navi;
	Bomb *bomb;
	Bumper *bumper;
	SplashScreen *sp;
	LostScreen *ls;
};

