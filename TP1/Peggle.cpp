#include "Peggle.h"

Peggle::Peggle()
{
	LoadTextures();

	bg = new Sprite(Texture::Bg);
	std::cout << "Sprite 1 size: " << bg->GetTextureInfos()->infos.Width << ", " << bg->GetTextureInfos()->infos.Height << std::endl;;

	canon = new Canon();
	//canon->SetRotation(180 * (PI / 180));
	std::cout << "Sprite 2 size: " << canon->GetTextureInfos()->infos.Width << ", " << canon->GetTextureInfos()->infos.Height;

	navi = new Navi();
}

Peggle::~Peggle()
{

}

void Peggle::Start()
{

}

void Peggle::Update()
{
	//// mvmnt test
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
	////std::cout << s->GetPosition().x << ", " << s->GetPosition().y << std::endl;
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
}
