/**
 * \file ScoreBoard.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"
#include <string>
#include "ScoreBoard.h"

using namespace std;
using namespace Gdiplus;

/**
 * Score board constructor
 */
CScoreBoard::CScoreBoard()
{
}


/**
 * Score board destructor
 */
CScoreBoard::~CScoreBoard()
{
}

/**
 * Draws the scores to the window screen
 */
void CScoreBoard::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(to_wstring(mCorrect).c_str(), -1, &font, PointF(100, 50), &green);
	graphics->DrawString(L"Correct", -1, &font, PointF(80, 100), &green);
	graphics->DrawString(to_wstring(mUnfair).c_str(), -1, &font, PointF(670, 50), &green);
	graphics->DrawString(L"Unfair", -1, &font, PointF(655, 100), &green);
	graphics->DrawString(to_wstring(mMissed).c_str(), -1, &font, PointF(1200, 50), &green);
	graphics->DrawString(L"Missed", -1, &font, PointF(1180, 100), &green);

	mCorrect++;
	mUnfair += 3;
	mMissed += 10;
}
