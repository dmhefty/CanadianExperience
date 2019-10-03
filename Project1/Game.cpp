#include "pch.h"
#include "Game.h"

using namespace Gdiplus;
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height) {
	// Fill the background with black
	SolidBrush brush(Color::White);
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
}

void CGame::Update(Gdiplus::Graphics* graphics, double elapsedTime)
{
	mScoreBoard.Draw(graphics);
}

void CGame::Load(std::string filePath)
{

}
