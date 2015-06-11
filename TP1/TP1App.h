#pragma once
#include "D3DApp.h"

class TP1App :
	public D3DApp
{
public:
	TP1App();
	TP1App(HINSTANCE hInstance, std::string WinCaption);
	~TP1App();

	void OnLostDevice()		{}
	void OnResetDevice()	{}

private:

};

