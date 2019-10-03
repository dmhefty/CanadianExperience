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
	float mScale;
	float mXOffset;
	float mYOffset;

//pointer to the player object
	std::unique_ptr<CHarold> mPlayer;

//The game coreboard object
	CScoreBoard mScoreBoard;

//list of all items on screen
	std::vector<std::unique_ptr<CItem> > mItems;

public:
/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);
	
	void Update(double elapsedTime);

	void Load(std::string filePath);


};

