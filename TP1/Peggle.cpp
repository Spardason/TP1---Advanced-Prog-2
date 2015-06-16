#include "Peggle.h"

Peggle::Peggle()
{
	Textures->LoadTexture(Texture::Canon, "Sprites\CanonFinal.png");
	Textures->LoadTexture(Texture::Bg, "Background.jpg");
	Textures->LoadTexture(Texture::Bomb, "Sprites\Collidable1.png");
	Textures->LoadTexture(Texture::Bumper, "Sprites\Collidable2.png");
	Textures->LoadTexture(Texture::Navi, "Sprites\NaviSprite.png");;

	Sprite* s = new Sprite(Texture::Bg);
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

}

void Peggle::Draw()
{

}

void Peggle::Stop()
{

}
