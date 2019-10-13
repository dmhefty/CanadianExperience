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
CItem::CItem(CVector position, CVector velocity) : mPosition(position), mVelocity(velocity)
{
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
 * \brief Updates the velocity based on how long has passed since the last update
 *
 * \param elapsedTime a time, in seconds, that says how long it has been since the last update
 */
void CItem::Update(double elapsedTime)
{
	CVector newPos = GetPosition() + mVelocity * elapsedTime;

	SetLocation(newPos);
}




