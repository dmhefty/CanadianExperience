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

	SolidBrush green(Color(200, 250, 200));
	graphics->DrawString(to_wstring(mCorrect).c_str(), -1, &font, PointF(-575, 50), &green);
	graphics->DrawString(L"Correct", -1, &font, PointF(-650, 100), &green);
	graphics->DrawString(to_wstring(mMissed).c_str(), -1, &font, PointF(-25, 50), &green);
	graphics->DrawString(L"Missed", -1, &font, PointF(-100, 100), &green);
	graphics->DrawString(to_wstring(mUnfair).c_str(), -1, &font, PointF(500, 50), &green);
	graphics->DrawString(L"Unfair", -1, &font, PointF(450, 100), &green);
}
