/**
 * \file BadUML.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "BadUML.h"
#include "Game.h"

using namespace Gdiplus;

const double OneSecond = 1;

CBadUML::CBadUML(std::shared_ptr<CUMLAttribute> name, 
	std::vector<std::shared_ptr<CUMLAttribute>> attributes, 
	std::vector<std::shared_ptr<CUMLAttribute>> operations,
	std::wstring error, 
	CVector position, CVector velocity, CGame* game) :
	CUML::CUML(name, attributes, operations, position, velocity, game)
{
	mError = error;
}

void CBadUML::Draw(Gdiplus::Graphics* graphics, CVector position)
{
	CUML::Draw(graphics, position);
	if (mHit)
	{
		if (mTimeDisplayed <= OneSecond)
		{
			FontFamily fontFamily(L"Arial");
			Gdiplus::Font font(&fontFamily, 16);

			SolidBrush red(Color(255, 0, 0));

			graphics->DrawString(GetMessageOnHit().c_str(), -1, &font, 
				PointF((REAL) mDisplayLocation.X(), (REAL) mDisplayLocation.Y()), &red);
		}
		else
		{
			mDeleted = true;
		}
	}
}

void CBadUML::Effect()
{
	if (!mHit)
	{
		mHit = true;
		CUML::Effect();
		GetGame()->IncrementScore(1);
	}
}
