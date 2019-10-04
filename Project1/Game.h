/**
 * \file Game.h
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
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

class CGame
{
private:
	float mScale = 0;
	float mXOffset = 0;
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

public:

	//copy constructor (disabled)
	CGame(const CGame&) = delete;

	//default constructor
	CGame();

	//destructor
	~CGame();
	
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

	void OnLButtonDown(LONG x, LONG y);
	
	void Update(double elapsedTime);

	void Load(std::string filePath);


};

