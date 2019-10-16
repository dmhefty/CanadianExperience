/**
 * \file Emitter.cpp
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "Emitter.h"
#include "XmlNode.h"
#include "Game.h"

using namespace std;
using namespace xmlnode;



/**
 * Loads a file containing characteristics for UML objects
 * \param filePath File path for UML data
 */

void CEmitter::Load(const std::wstring& filePath)
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
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}


	// TODO: DELETE THE FOLLOWING LINES. FOR TESTING PURSPOSES ONLY
	mGame->AddItem(make_shared<CPowerSlow>(CVector(0, 0), CVector(-3, 100), mGame));
	mGame->AddItem(make_shared<CPowerRapidFire>(CVector(-500, 0), CVector(40, 190), mGame));
	mGame->AddItem(make_shared<CPowerAllGone>(CVector(500, 0), CVector(-20, 80), mGame));
}

void CEmitter::AddUML() 
{

	/// Game area width in virtual pixels
	const static int Width = 1250;
	/// Game area height in virtual pixels
	const static int Height = 1000;

	std::vector<std::shared_ptr<CUMLAttribute> > atts(mAttributes.begin(), mAttributes.begin() + 3);
	std::vector<std::shared_ptr<CUMLAttribute> > ops(mOperations.begin(), mOperations.begin() + 3);
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
	const double MaxPosX = Width / 2;

	/// Minimum starting position in the X direction
	const double MinPosX = -1 * Width / 2;

	// Randomize X and Y speeds within limits
	double tempSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double tempSpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);

	// Randomize X position within limits
	double tempPosX = MinPosX + ((double)rand() / RAND_MAX) * (MaxPosX - MinPosX);

	// Limit the X position so that it will not move off the screen with its set X velocity
	if ((tempSpeedX < 0) && (-1 * Width / 2 >= (tempPosX + tempSpeedX * (Height / tempSpeedY))))
	{
		tempPosX = -1 * Width / 2 - (tempSpeedX * (Height / tempSpeedY));
	}

	if ((tempSpeedX > 0) && (Width / 2 <= (tempPosX + tempSpeedX * (Height / tempSpeedY))))
	{
		tempPosX = Width / 2 - (tempSpeedX * (Height / tempSpeedY));
	}

	// Change these lines after randomization of good/bad UMLs
	mGame->AddItem(make_shared<CBadUML>(name, atts, ops, CVector(tempPosX, 60), CVector(tempSpeedX, tempSpeedY), mGame));
	mGame->AddItem(make_shared<CGoodUML>(name, atts, ops, CVector(-tempPosX, 60), CVector(-tempSpeedX, tempSpeedY), mGame));
}