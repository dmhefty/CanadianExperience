/**
 * \file Game.cpp
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
 * \author Isaac Mayers
 */

#include "pch.h"
#include <memory>
#include "Game.h"
#include "XmlNode.h"
#include "UML.h"
#include <vector>
#include "HaroldPen.h"
#include "Item.h"
#include "MakePenActiveVisitor.h"
#include "IsHaroldPenVisitor.h"
#include "PowerAllBad.h"
#include "PowerAllGood.h"
#include "PowerAllGone.h"
#include "PowerRapidFire.h"
#include "IsHaroldPenVisitor.h"
#include "HaroldPen.h"


using namespace Gdiplus;
using namespace std;
using namespace xmlnode;

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

	
	for (auto item : mItems) {
		item->Draw(graphics, item->GetPosition());
	}

	// From here on you are drawing virtual pixels
	mPlayer.Draw(graphics, 0, Height);

	// ScoreBoard must ALWAYS be drawn last (on top of everything)
	mScoreBoard.Draw(graphics);
}

/**
 * Fire the player's pen when mouse left is pressed
 * \param x Mouse point x location
 * \param y Mouse point y location
 */
void CGame::OnLButtonDown(double x, double y)
{
	// First convert screen pixels to virutal pixels
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;
	
	// pen firing

	// Determine and set the new angle
	double angle = (atan2(Height - oY, oX) - AngleOffset);

	shared_ptr<CItem> currentPen;
	CMakePenActiveVisitor changer(-angle);
	CIsHaroldPenVisitor visitPen;
	for (auto item : mItems)
	{
		item->Accept(&visitPen);
		if (visitPen.IsHaroldPen() && visitPen.IsAttached())
		{
			item->Accept(&changer);
		}

	}

	
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

	if (false) // If pen is fired (bool mFired in Game.h?) do the following
	{
		CIsHaroldPenVisitor isPenVisitor;
		this->Accept(&isPenVisitor);
		auto pen = isPenVisitor.GetPen();

		/*
		for (auto item : someFilteredListOfItems)
		{
			// Check if pen image intersects
			// (check positions + image widths and heights)
			// with other item images
		}
		*/
	}
}

void CGame::Accept(CItemVisitor* visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}

/**
 * Determines and updates the orientation of the player in the game field
 * \param x Mouse x location
 * \param y Mouse y location
 */
void CGame::RotatePlayer(double x, double y)
{
	// First convert screen pixels to virutal pixels
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;
	// Determine and set the new angle
	double angle = atan2(Height - oY, oX) - AngleOffset;
	mPlayer.SetAngle(angle);
}

/**
 * Determines and updates the position and orientation of the pen in the game field
 * \param x Mouse x location
 * \param y Mouse y location
 */
void CGame::RotatePen(double x, double y)
{
	// First convert screen pixels to virutal pixels
	double oX = (x - mXOffset) / mScale;
	double oY = (y - mYOffset) / mScale;
	// Determine and set the new angle
	double angle = (atan2(Height - oY, oX) - AngleOffset) + (3.1415926535f)*3/4;
	CVector pos(61.29437 * sin(angle) - 10.0f, 61.29437f * cos(angle)+(1000.0f-105.0f));
	
	shared_ptr<CItem> currentPen;
	CIsHaroldPenVisitor visitPen;
	for (auto item : mItems)
	{
		item->Accept(&visitPen);
		if (visitPen.IsHaroldPen())
		{
			currentPen = item;
		}
	}
	if (visitPen.IsAttached())
	{
		currentPen->SetLocation(pos);
		currentPen->SetAngle(angle);
	}
}

void CGame::AddItem(shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/**
 * Constructor loads UML data file
 */
CGame::CGame() 
{
	std::wstring filename = L"uml.xml";
	mEmitter.Load(filename);

	shared_ptr<CHaroldPen> hPen = make_shared<CHaroldPen>(CVector(29.0f,1000.0-154.0f), CVector(0.0f,0.0f));
	AddItem(hPen);
}


/**
 * Destructor
 */
CGame::~CGame() 
{

}
