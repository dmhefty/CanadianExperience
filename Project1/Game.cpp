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
						
						}

						if (itemName == L"name") {
							
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
