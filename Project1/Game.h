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
/// Game area width in virtual pixels
	const static int Width = 1250;
/// Game area height in virtual pixels
	const static int Height = 1000;

	float mScale;
	float mXOffset;
	float mYOffset;

//pointer to the player object
	std::unique_ptr<CHarold> mPlayer;

//pointer to the scoreboard object
	std::unique_ptr<CScoreBoard> mScoreBoard;

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
	
	
	//void OnLButtonDown(int x, int y);
	void Load(std::string filePath);


};

