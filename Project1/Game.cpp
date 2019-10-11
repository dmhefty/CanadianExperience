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
 * Loads a file containing characteristics for UML objects
 * \param filePath File path for UML data
 */
void CGame::Load(const std::wstring &filePath)
{
	
	
	std::shared_ptr<CUMLAttribute> attribute;
	try
	{
		//Open document to read
		std::shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filePath);
		
		

		for (auto node : root->GetChildren())
		{
			if (node->GetType() == NODE_ELEMENT)
			{
				
				for (auto item : node->GetChildren()) 
				{
					if (item->GetType() == NODE_ELEMENT) {
						std::wstring itemName = item->GetName();
					//	
						std::wstring error = item->GetAttributeValue(L"bad", L"");
						std::wstring text;
						if (item->GetNumChildren() > 0) {
							text = item->GetChild(0)->GetValue();
							
						}
						else {
							text = L"";
						}
						
						if (error == L"") {
							attribute = make_shared<CUMLAttribute>(text);
						}
						else {
							attribute = make_shared<CBadUMLAttribute>(text, error);
						}

						if (itemName == L"name") {
							if (error == L"") {
								mNames.push_back(attribute);
							}
							else {
								mNamesBad.push_back(attribute);
							}
						}
						else if (itemName == L"attribute") {
							if (error == L"") {
								mAttributes.push_back(attribute);
							}
							else {
								mAttributesBad.push_back(attribute);
							}
						}
						else if (itemName == L"operation") {
							if (error == L"") {
								mOperations.push_back(attribute);
							}
							else {
								mOperationsBad.push_back(attribute);
							}
						}
					}
					
				}

				
				
				
			}
		}
	}
	catch(CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}

	std::vector<std::shared_ptr<CUMLAttribute> > atts(mAttributes.begin(), mAttributes.begin() + 2);	
	std::vector<std::shared_ptr<CUMLAttribute> > ops(mOperations.begin(), mOperations.begin());
	std::shared_ptr<CUMLAttribute> name = make_shared<CUMLAttribute>(mNames[0]->GetAtt());

	// Code to randomize position and velocity of items. This should probably be moved to the item classes
	// themselves and the position and vector parameters removed, but for now it'll be here.

	/// Maximum speed in the X direction in
	/// in pixels per second
	const double MaxSpeedX = 20;

	/// Maximum speed in the Y direction in
	/// in pixels per second
	const double MaxSpeedY = 40;

	/// Minimum speed in the X direction in
	/// in pixels per second
	const double MinSpeedX = -20;

	/// Minimum speed in the Y direction in
	/// in pixels per second
	const double MinSpeedY = 20;

	/// Maximum starting position in the X direction
	const double MaxPosX = CGame::Width/2;

	/// Minimum starting position in the X direction
	const double MinPosX = -1 * CGame::Width/2;

	// Randomize X and Y speeds within limits
	double tempSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double tempSpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);

	// Randomize X position within limits
	double tempPosX = MinPosX + ((double)rand() / RAND_MAX) * (MaxPosX - MinPosX);

	// Limit the X position so that it will not move off the screen with its set X velocity
	if ((tempSpeedX < 0) && (-1 * CGame::Width/2 >= (tempPosX + tempSpeedX * (CGame::Height / tempSpeedY))))
	{
		tempPosX = -1 * CGame::Width/2 - (tempSpeedX * (CGame::Height / tempSpeedY));
	}

	if ((tempSpeedX > 0) && (CGame::Width/2 <= (tempPosX + tempSpeedX * (CGame::Height / tempSpeedY))))
	{
		tempPosX = CGame::Width/2 - (tempSpeedX * (CGame::Height / tempSpeedY));
	}

	std::shared_ptr<CUML> mUML = make_shared<CUML>(name, atts, ops, CVector(tempPosX, 60), CVector(tempSpeedX, tempSpeedY), L"");
	mItems.push_back(mUML);

	// TODO: EVENTUALLY REMOVE THE FOLLOWING LINES. FOR TESTING PURPOSES ONLY
	mItems.push_back(make_shared<CPowerAllBad>(CVector(-600, 80), CVector(50, 60)));
	mItems.push_back(make_shared<CPowerAllGood>(CVector(-500, 0), CVector(10, 90)));
	mItems.push_back(make_shared<CPowerAllGone>(CVector(600, 0), CVector(-190, 280)));
	mItems.push_back(make_shared<CPowerRapidFire>(CVector(0, 0), CVector(-3, 150)));
}

/**
 * Constructor loads UML data file
 */
CGame::CGame() 
{
	std::wstring filename = L"uml.xml";
	Load(filename);
}


/**
 * Destructor
 */
CGame::~CGame() 
{

}
