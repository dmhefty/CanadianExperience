/**
 * \file Item.cpp
 *
 * \author David Hefty
 */

#pragma once
#include "pch.h"
#include "Item.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;
using namespace Gdiplus;


/**
 * \brief Constructor for CItem class
 *
 * \param position takes in a position in the form of a CVector
 * \param velocity takes in a velocity in the form of a CVector
 */
CItem::CItem(CVector position, CVector velocity, wstring imageLocation) : mPosition(position), mVelocity(velocity)
{
	mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(imageLocation.c_str()));
	if (mItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += imageLocation;
		AfxMessageBox(msg.c_str());
	}
}

/**
 * \brief Sets the location of the item on the screen
 *
 * \param position the desired position of the item on the screen as a CVector
 */
void CItem::SetLocation(CVector position)
{
	CVector tempPos(position);
	mPosition = tempPos;
}

/**
 * \brief Sets the velocity of the item on the screen
 *
 * \param velocity the desired velocity of the item on the screen as a CVector
 */
void CItem::SetVelocity(CVector velocity)
{
	CVector tempVel(velocity);
	mVelocity = tempVel;
}


/**
* Draw this item
* \param graphics The graphics context to draw on
* \param x X location to draw in virtual pixels
* \param y Y location to draw in virtual pixels
* \param angle Angle of rotation in radians
*/
void CItem::Draw(Gdiplus::Graphics* graphics, CVector position)
{
	float wid = (float)mItemImage->GetWidth();
	float hit = (float)mItemImage->GetHeight();

	auto state = graphics->Save();
	graphics->TranslateTransform((float)position.X(), (float)position.Y());
	graphics->DrawImage(mItemImage.get(), -wid / 2, -hit / 2,
		wid, hit);
	graphics->Restore(state);
}

/**
 * \brief Updates the velocity based on how long has passed since the last update
 *
 * \param elapsedTime a time, in seconds, that says how long it has been since the last update
 */
void CItem::Update(double elapsedTime)
{
	CVector newPos = GetPosition() + mVelocity * elapsedTime;

	SetLocation(newPos);
}




