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
#include "BadUMLAttribute.h"
#include "ItemVisitor.h"
#include "Emitter.h"

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

	CEmitter mEmitter;
	

	///List of all items on screen
	std::vector<std::shared_ptr<CItem> > mItems;

	
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

	void Accept(CItemVisitor* visitor);

	void RotatePlayer(double x, double y);

	void RotatePen(double x, double y);

	int GetHeight() { return Height; }
	int GetWidth() { return Width; }


	void AddItem(std::shared_ptr<CItem> item);


};

