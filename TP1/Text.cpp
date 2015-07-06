#include "Text.h"

Text::Text()
{

}

Text::Text(Texture::ID id, D3DXVECTOR2 pos, bool visibility)
	: Sprite(id)
	, mCenter(GetTextureInfos()->infos.Width / 2, GetTextureInfos()->infos.Height / 2, 0.f )
{
	SetPivot(mCenter);
	SetRotationRad(D3DX_PI, 0.f, D3DX_PI);
	SetVisible(visibility);
	SetPosition(pos.x + mCenter.x, pos.y - mCenter.y);
}

Text::~Text()
{
}
