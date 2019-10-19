/**
 * \file HaroldPen.cpp
 *
 * \author David Hefty
 * \author Jaideep Prasad
 */

#include "pch.h"
#include <string>
#include <vector>
#include <memory>
#include "HaroldPen.h"
#include "ItemVisitor.h"

using namespace std;
using namespace Gdiplus;

/// Pen filename 
const wstring PenImageName = L"images/redpen.png";

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;


/// One second
const double OneSecond = 1;

 /**
  * \brief Constructor for CHaroldPen class
  *
  * \param position takes in a position in the form of a CVector
  * \param velocity takes in a velocity in the form of a CVector
  * \param game Game we are working in
  */
CHaroldPen::CHaroldPen(CVector position, CVector velocity, CGame* game) : 
	CItem(position, velocity, game)
{
	mIsAttached = true; // false for now since we dont have a real attachment to Harold
	mTravelTime = 0;
	mHaroldPenImage = unique_ptr<Bitmap>(Bitmap::FromFile(PenImageName.c_str()));
	if (mHaroldPenImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PenImageName;
		AfxMessageBox(msg.c_str());
	}
}

/**
* Draw this item
* \param graphics The graphics context to draw on
* \param position Position too draw the pen
*/
void CHaroldPen::Draw(Gdiplus::Graphics* graphics, CVector position)
{
	float wid = (float)mHaroldPenImage->GetWidth();
	float hit = (float)mHaroldPenImage->GetHeight();

	auto state = graphics->Save();

	graphics->TranslateTransform((float)position.X(), (float)(position.Y() - (hit / 1.5f)));

	double angle = mIsAttached ? mAngle : mFiredAngle;

	graphics->RotateTransform((float)(-angle * RtoD));

	graphics->DrawImage(mHaroldPenImage.get(), -wid / 2, -hit / 2,
		wid, hit);
	graphics->Restore(state);
}

/**
* Update Pen item
* \param elapsedTime Real Time Elapsed
*/
void CHaroldPen::Update(double elapsedTime)
{
	if (!mIsAttached)
	{
		mTravelTime += elapsedTime;
		if (mTravelTime < (OneSecond / CItem::GetVelocityMultiplier()))
		{
			CItem::Update(elapsedTime);
		}
		else
		{
			ResetPen();
		}
		
	}
	else
	{
		CItem::Update(elapsedTime);
	}
}

/**
* Resets the pen back to Harold
*/
void CHaroldPen::ResetPen()
{
	mIsAttached = true;
	mTravelTime = 0;
	CItem::SetLocation(CVector(61.29437 * sin(mAngle), 61.29437f * cos(mAngle) + (float)(1000.0 - 95.0)));
	CItem::SetVelocity(CVector(0.0f, 0.0f));
}

/**
 * \brief Acceptor for the HaroldPen visitors
 *
 * \param visitor the visitor item that is doing work
 */
 void CHaroldPen::Accept(CItemVisitor *visitor)
 {
	 visitor->VisitHaroldPen(this);
 }

