/**
 * \file Game.h
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
 * \author Isaac Mayers
 *
 * System class for the UML Wars Game
 */

#pragma once
#include "pch.h"
#include <string>
#include <memory>
#include <vector>
#include "Harold.h"
#include "ScoreBoard.h"
#include "Item.h"
#include "UMLAttribute.h"

class CGame
{
private:
	/// Window resizing factor for virtual pixels
	float mScale = 0; 
	/// Window width offset for virtual pixels
	float mXOffset = 0; 
	/// Window height offset for virtual pixels
	float mYOffset = 0; 

	/// Game area width in virtual pixels
	const static int Width = 1250;
	/// Game area height in virtual pixels
	const static int Height = 1000;

	///Player of the game
	CHarold mPlayer;

	///The game scoreboard object
	CScoreBoard mScoreBoard;

	///List of all items on screen
	std::vector<std::shared_ptr<CItem> > mItems;

	//lists to store uml components
	///list of possible good uml names
	std::vector<std::shared_ptr<CUMLAttribute> > mNames;
	///list of possible bad uml names
	std::vector<std::shared_ptr<CUMLAttribute> > mNamesBad;
	///list of possible good uml attributes
	std::vector<std::shared_ptr<CUMLAttribute> > mAttributes;
	///list of possible bad uml attributes
	std::vector<std::shared_ptr<CUMLAttribute> > mAttributesBad;
	///list of possible good uml operations
	std::vector<std::shared_ptr<CUMLAttribute> > mOperations;
	///list of possible bad uml operations
	std::vector<std::shared_ptr<CUMLAttribute> > mOperationsBad;
public:

	//copy constructor (disabled)
	CGame(const CGame&) = delete;

	//default constructor
	CGame();

	//destructor
	virtual ~CGame();
	
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	void OnLButtonDown(double x, double y);
	
	void Update(double elapsedTime);

	void RotatePlayer(double x, double y);

	void Load(const std::wstring &filePath);


};

