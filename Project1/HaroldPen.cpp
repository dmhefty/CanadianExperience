/**
 * \file HaroldPen.cpp
 *
 * \author David Hefty
 */

#pragma once
#include "pch.h"
#include "HaroldPen.h"
#include "ItemVisitor.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;
using namespace Gdiplus;

/// Pen filename 
const wstring PEN_IMAGE_NAME = L"images/redpen.png";

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

 /**
  * \brief Constructor for CHaroldPen class
  *
  * \param position takes in a position in the form of a CVector
  * \param velocity takes in a velocity in the form of a CVector
  */
CHaroldPen::CHaroldPen(CVector position, CVector velocity) : CItem(position, velocity)
{
	mIsAttached = true; // false for now since we dont have a real attachment to Harold
	mHaroldPenImage = unique_ptr<Bitmap>(Bitmap::FromFile(PEN_IMAGE_NAME.c_str()));
	if (mHaroldPenImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PEN_IMAGE_NAME;
		AfxMessageBox(msg.c_str());
	}
}

/**
* Draw this item
* \param graphics The graphics context to draw on
* \param x X location to draw in virtual pixels
* \param y Y location to draw in virtual pixels
* \param angle Angle of rotation in radians
*/
void CHaroldPen::Draw(Gdiplus::Graphics* graphics, CVector position)
{
	if (!mIsAttached)
	{
		float wid = (float)mHaroldPenImage->GetWidth();
		float hit = (float)mHaroldPenImage->GetHeight();

		auto state = graphics->Save();
		graphics->TranslateTransform((float)position.X(), (float)position.Y());
		graphics->DrawImage(mHaroldPenImage.get(), -wid / 2, -hit / 2,
			wid, hit);
		graphics->Restore(state);
	}
	else
	{
		float wid = (float)mHaroldPenImage->GetWidth();
		float hit = (float)mHaroldPenImage->GetHeight();

		auto state = graphics->Save();
		graphics->TranslateTransform((float)position.X(), (float)(position.Y() - (hit / 1.5f)));
		graphics->RotateTransform((float)(-mAngle * RtoD));
		graphics->DrawImage(mHaroldPenImage.get(), -wid / 2, -hit / 2,
			wid, hit);
		graphics->Restore(state);
	}
}


void CHaroldPen::Update(double elapsedTime)
{
	CItem::Update(elapsedTime);
}



void CHaroldPen::ResetPen()
{
	mAngle = 25.0f;
	mIsAttached = true;
	CItem::SetLocation(CVector(29.0f, 1000.0 - 154.0f));
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

