#include "Peggle.h"

Peggle::Peggle()
{
	LoadTextures();

	bg = new Background();



	canon = new Canon();
}

Peggle::~Peggle()
{
	collidables.clear();
	

	delete canon;
	canon = nullptr;

	delete bg;
	bg = nullptr;
}

void Peggle::Start()
{

}

void Peggle::Update()
{

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
	int posX = -50;
	for (it = collidables.begin(); it < collidables.end(); it++)
	{
		if ( < collidables.end / 2)
		{
			c
		}
		else
		{
			i = 0;
			collidables[i]->SetPosition(posX + (i * 30), 30);
		}
	}
}
