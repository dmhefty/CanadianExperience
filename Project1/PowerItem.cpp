/**
 * \file PowerItem.cpp
 *
 * \author Isaac Mayers
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "PowerItem.h"
#include <string>
#include <memory>

using namespace std;
using namespace Gdiplus;

/**
 * \brief Constructor for CPowerItem class
 *
 * \param position takes in a position in the form of a CVector
 * \param velocity takes in a velocity in the form of a CVector
 * \param game takes in the game pointer
 * \param PowerItemImageName takes the image name of the power item as a string
 */
CPowerItem::CPowerItem(CVector position, CVector velocity, CGame* game, wstring PowerItemImageName) :
	CItem(position, velocity, game)
{
	mPowerItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(PowerItemImageName.c_str()));
	if (mPowerItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PowerItemImageName;
		AfxMessageBox(msg.c_str());
	}
}

/* Draw power item*/
void CPowerItem::Draw(Gdiplus::Graphics* graphics, CVector position)
{
	float wid = (float)mPowerItemImage->GetWidth();
	float hit = (float)mPowerItemImage->GetHeight();

	auto state = graphics->Save();
	graphics->TranslateTransform((float)position.X(), (float)position.Y());
	graphics->DrawImage(mPowerItemImage.get(), -wid / 2, -hit / 2,
		wid, hit);
	graphics->Restore(state);
}

/* Update Image */
void CPowerItem::Update(double elapsedTime)
{
	CItem::Update(elapsedTime);
}