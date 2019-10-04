/**
 * \file Game.cpp
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
 * \author Isaac Mayers
 */

#include "pch.h"
#include "Game.h"

using namespace Gdiplus;

// Half Pi radians
const double AngleOffset = 3.14159 / 2.0;

/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height) {
	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	mYOffset = 0;
	if (height > Height * mScale) {
		mYOffset = (float)((height - Height * mScale) / 2);
	}

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// From here on you are drawing virtual pixels
	mScoreBoard.Draw(graphics);
	mPlayer.Draw(graphics, 0, Height);
}

/**
 * Fire the player's pen when mouse left is pressed
 * \param x Mouse point x location
 * \param y Mouse point y location
 */
void CGame::OnLButtonDown(double x, double y)
{
	//TODO: implement pen firing
}

/**
 * Updates game status
 * \param elapsedTime Time since last game tick
 */
void CGame::Update(double elapsedTime)
{
	for (auto item : mItems)
	{
		item->Update(elapsedTime);
	}
}

/**
 * Determines and updates the orientation of the player in the game field
 * \param x Mouse x location
 * \param y Mouse y location
 */
void CGame::RotatePlayer(double x, double y)
{
	double angle = atan2(Height - y, x - Width/2.0) - AngleOffset;
	mPlayer.SetAngle(angle);
}

/**
 * Loads a file containing characteristics for UML objects
 * \param filePath File path for UML data
 */
void CGame::Load(std::string filePath)
{

}

CGame::CGame() {
	Load("uml.xml");
}

CGame::~CGame() {}