#include "Peggle.h"

Peggle::Peggle()
{
	LoadTextures();

	//bg = new Sprite(Texture::ID::Bg);

	canon = new Canon();
	navi = new Navi();
	//std::cout << canon->GetPosition().x;
	//canon->SetPosition(100, 100);
	//D3DXVECTOR2 pos(canon->GetPosition().x, canon->GetPosition().y);

	//canon->SetPosition(0, 0);
	//canon->SetRotation(180 * (PI / 180));
	//canon->SetPosition(pos.x, pos.y);
	
	//navi = new Navi();
	//navi->SetPosition(-150, -200);
	//bomb = new Bomb();
	//bomb->SetPosition(100, 100);
	//bumper = new Bumper();
}

Peggle::~Peggle()
{
	delete canon;
	canon = nullptr;
}

void Peggle::Start()
{

}

void Peggle::Update()
{
	// mvmnt test
	//if (gDInput->keyDown(DIKEYBOARD_W))
	//{
	//	//s->SetPosition(s->GetPosition().x, s->GetPosition().y - 1);
	//}
	//
	//if (gDInput->keyDown(DIKEYBOARD_A))
	//{
	//	//s->SetPosition(s->GetPosition().x - 1, s->GetPosition().y);
	//}
	//
	//std::cout << s->GetPosition().x << ", " << s->GetPosition().y << std::endl;
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
