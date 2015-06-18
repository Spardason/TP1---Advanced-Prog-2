#include "Peggle.h"

Peggle::Peggle()
{
	Textures->LoadTexture(Texture::Canon, "Sprites/CanonFinal.png");
	Textures->LoadTexture(Texture::Bg, "Background.jpg");
	Textures->LoadTexture(Texture::Bomb, "Sprites/Collidable1.png");
	Textures->LoadTexture(Texture::Bumper, "Sprites/Collidable2.png");
	Textures->LoadTexture(Texture::Navi, "Sprites/NaviSprite.png");;

	s = new Sprite(Texture::Bg);

	Sprite* s2 = new Sprite(Texture::Canon);
}

Peggle::~Peggle()
{

}

void Peggle::Start()
{

}

void Peggle::Update()
{
	// mvmnt test
	if (gDInput->keyDown(DIKEYBOARD_W))
	{
		s->SetPosition(s->GetPosition().x, s->GetPosition().y - 1);
	}

	if (gDInput->keyDown(DIKEYBOARD_A))
	{
		s->SetPosition(s->GetPosition().x - 1, s->GetPosition().y);
	}

	std::cout << s->GetPosition().x << ", " << s->GetPosition().y << std::endl;
}

void Peggle::Draw()
{

}

void Peggle::Stop()
{

}
