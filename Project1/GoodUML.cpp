/**
 * \file GoodUML.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "GoodUML.h"
#include "Game.h"

using namespace Gdiplus;

const double OneSecond = 1;

CGoodUML::CGoodUML(std::shared_ptr<CUMLAttribute> name,
	std::vector<std::shared_ptr<CUMLAttribute>> attributes,
	std::vector<std::shared_ptr<CUMLAttribute>> operations,
	CVector position, CVector velocity, CGame* game) :
	CUML::CUML(name, attributes, operations, position, velocity, game)
{

}

void CGoodUML::Draw(Gdiplus::Graphics* graphics, CVector position)
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
				PointF((REAL)mDisplayLocation.X(), (REAL)mDisplayLocation.Y()), &red);
		}
		else
		{
			mDeleted = true;
		}
	}
}

void CGoodUML::Effect()
{
	if (!mHit)
	{
		mHit = true;
		CUML::Effect();
		GetGame()->IncrementScore(-1);
	}
}
