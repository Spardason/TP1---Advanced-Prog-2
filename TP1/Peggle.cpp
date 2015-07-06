#include "Peggle.h"

Peggle::Peggle()
	: gameStarted(false)
	, gameOver(false)
{
	LoadTextures();
	sp = new SplashScreen();
	ls = new LostScreen();
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

		delete one;
		one = nullptr;

		delete two;
		two = nullptr;

		delete three;
		three = nullptr;

		delete zero;
		zero = nullptr;

		delete balls;
		balls = nullptr;
	}

	delete ls;
	ls = nullptr;

	delete sp;
	sp = nullptr;	
}

void Peggle::Start()
{

}

// Main Update
void Peggle::Update()
{
	if (!sp->IsVisible() && !gameStarted && !gameOver)
	{
		gameStarted = true;
		StartGame();
	}

	if (gameStarted)
	{
		UpdateLive();
	}

	if (gameOver)
	{
		ls->SetVisible(true);
		GameOver();	
	}

	if (ls->GetWannaReplay())
	{
		ls->SetWannaReplay(false);
		gameOver = false;
		Replay();
	}

}

void Peggle::Draw()
{

}

void Peggle::Stop()
{

}

// Method to load all the textures
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
	Textures->LoadTexture(Texture::BallsText, "Sprites/Balls.png");
	Textures->LoadTexture(Texture::OneText, "Sprites/Un.png");
	Textures->LoadTexture(Texture::TwoText, "Sprites/Deux.png");
	Textures->LoadTexture(Texture::ThreeText, "Sprites/Trois.png");
	Textures->LoadTexture(Texture::ZeroText, "Sprites/Zero.png");
}

// Create all the obstacles of the game, can specify a number for each 
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

	std::random_shuffle(collidables.begin(), collidables.end());
}

// Place all the obstacles on the screen 
// Specify the number in one row, will  make any number of rows needed to spawn all objects
// Specify the spacing to have what you want
void Peggle::CollidablesPlacement(int nbInRow, int spacing)
{
	int index = 0;
	int basePos = -(gApp->GetParam().BackBufferWidth / 3 + 15);

	for (it = collidables.begin(); it != collidables.end(); it++)
	{
		float x = (index % nbInRow);
		float y = (index / nbInRow);

		(*it)->SetPosition(basePos + x * spacing, y * spacing - spacing);
		(*it)->collider->SetPosition(basePos + x * spacing, y * spacing - spacing);

		index++;
	}
}

// Method that handle the replay when the lostscreen is on and the player press space
void Peggle::Replay()
{
	bg->SetVisible(true);
	canon->Activate();
	one->SetVisible(false);
	two->SetVisible(false);
	three->SetVisible(false);
	zero->SetVisible(false);
	balls->SetVisible(true);
	pot->SetVisible(true);

	for (it = collidables.begin(); it < collidables.end(); it++)
	{
		if (!(*it)->IsVisible())
		{
			(*it)->SetVisible(true);
			(*it)->collider->SetEnabled(true);
		}
	}
}

// Method that handle the start of the game when the splashscreen is on and the player press space
void Peggle::StartGame()
{
	bg = new Background();

	CreateCollidables(20, 20);
	CollidablesPlacement(10, 60);

	balls = new Text(Texture::ID::BallsText, D3DXVECTOR2(-(float)gApp->GetParam().BackBufferWidth / 2, (float)gApp->GetParam().BackBufferHeight / 2), true);
	zero = new Text(Texture::ID::ZeroText, D3DXVECTOR2(-(float)gApp->GetParam().BackBufferWidth / 3, (float)gApp->GetParam().BackBufferHeight / 2.5), false);
	one = new Text(Texture::ID::OneText, D3DXVECTOR2(-(float)gApp->GetParam().BackBufferWidth / 3, (float)gApp->GetParam().BackBufferHeight / 2.5), false);
	two = new Text(Texture::ID::TwoText, D3DXVECTOR2(-(float)gApp->GetParam().BackBufferWidth / 3, (float)gApp->GetParam().BackBufferHeight / 2.5), false);
	three = new Text(Texture::ID::ThreeText, D3DXVECTOR2(-(float)gApp->GetParam().BackBufferWidth / 3, (float)gApp->GetParam().BackBufferHeight / 2.5), true);

	canon = new Canon();
	pot = new Pot();
}

// Method that update the live for the main loop
void Peggle::UpdateLive()
{
	switch (canon->GetLive())
	{
	case 0:
		one->SetVisible(false);
		two->SetVisible(false);
		three->SetVisible(false);
		zero->SetVisible(true);
		gameOver = true;
		break;
	case 1:
		one->SetVisible(true);
		two->SetVisible(false);
		three->SetVisible(false);
		zero->SetVisible(false);
		break;
	case 2:
		one->SetVisible(false);
		two->SetVisible(true);
		three->SetVisible(false);
		zero->SetVisible(false);
		break;
	case 3:
		one->SetVisible(false);
		two->SetVisible(false);
		three->SetVisible(true);
		zero->SetVisible(false);
		break;
	default:
		break;
	}
}

// Method that handle the game over when the player loses all his balls
void Peggle::GameOver()
{
	canon->Deactivate();
	bg->SetVisible(false);
	one->SetVisible(false);
	two->SetVisible(false);
	three->SetVisible(false);
	zero->SetVisible(false);
	balls->SetVisible(false);
	pot->SetVisible(false);

	for (it = collidables.begin(); it < collidables.end(); it++)
	{
		if ((*it)->IsVisible())
		{
			(*it)->SetVisible(false);
		}
	}
}
