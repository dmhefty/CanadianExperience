/**
 * \file Game.cpp
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "Game.h"

using namespace Gdiplus;

/// Game area width in virtual pixels
const static int Width = 1250;
/// Game area height in virtual pixels
const static int Height = 1000;

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
	mPlayer.Draw(graphics, 400, 10, 10);
}

/**
 * Updates game status
 * \param elapsedTime Time since last game tick
 */
void CGame::Update(double elapsedTime)
{
	
}

/**
 * Loads a file containing characteristics for UML objects
 * \param filePath File path for UML data
 */
void CGame::Load(std::string filePath)
{

}
