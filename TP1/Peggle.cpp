#include "Peggle.h"

Peggle::Peggle()
	: gameStarted(false)
{
	LoadTextures();
	sp = new SplashScreen();
}

Peggle::~Peggle()
{
	collidables.clear();
	
	if (gameStarted)
	{
		delete bg;
		bg = nullptr;
	
		delete pot;
		pot = nullptr;

		delete canon;
		canon = nullptr;
	}

	delete sp;
	sp = nullptr;	
}

void Peggle::Start()
{

}

void Peggle::Update()
{
	if (!sp->IsVisible() && !gameStarted)
	{
		gameStarted = true;
		StartGame();
	}
}

void Peggle::Draw()
{

}

void Peggle::Stop()
{

}

void Peggle::LoadTextures()
{
	Textures->LoadTexture(Texture::Canon, "Sprites/CanonFinal.png");
	Textures->LoadTexture(Texture::Bg, "Sprites/Background.png");
	Textures->LoadTexture(Texture::Bomb, "Sprites/Collidable1.png");
	Textures->LoadTexture(Texture::Bumper, "Sprites/Collidable2.png");
	Textures->LoadTexture(Texture::Navi, "Sprites/NaviSprite.png");
	Textures->LoadTexture(Texture::Pot, "Sprites/Jar.png");
	Textures->LoadTexture(Texture::SplashScreen, "Sprites/SplashScreen.png");
	Textures->LoadTexture(Texture::LostScreen, "Sprites/LostScreen.png");
}

void Peggle::CreateCollidables(int nbBombs, int nbBumpers)
{
	collidables.clear();
	for (int i = 0; i < nbBombs; i++)
	{
		Bomb *b = new Bomb();
		collidables.push_back(b);
	}

	for (int j = 0; j < nbBumpers; j++)
	{
		Bumper *bp = new Bumper();
		collidables.push_back(bp);
	}
}

void Peggle::CollidablesPlacement()
{
	int index = 0;
	int basePos = -(gApp->GetParam().BackBufferWidth / 3);
	for (it = collidables.begin(); it < collidables.end(); it++)
	{
		if (index % 2 == 0)
		{
			(*it)->SetPosition(basePos + (index * 30), 0);
			index++;
		}
		else
		{
			(*it)->SetPosition(basePos + (index * 30), 50);
			index++;
		}
	}
}

void Peggle::Replay()
{
	for (it = collidables.begin(); it < collidables.end(); it++)
	{
		if (!(*it)->IsVisible())
		{
			(*it)->SetVisible(true);
		}
	}
}

void Peggle::StartGame()
{
	bg = new Background();

	CreateCollidables(10, 10);
	CollidablesPlacement();

	canon = new Canon();
	pot = new Pot();
}
