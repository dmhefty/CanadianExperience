#pragma once
#include "pch.h"
#include <string>
#include <memory>
#include "Harold.h"
#include "ScoreBoard.h"
class CGame
{
private:
/// Game area width in virtual pixels
	const static int Width = 1250;
/// Game area height in virtual pixels
	const static int Height = 1000;

//pointer to the player object
	std::unique_ptr<CHarold> mPlayer;

//pointer to the scoreboard object
	std::unique_ptr<CScoreBoard> mScoreBoard;

public:
/**
* Draw the game area
* \param graphics The GDI+ graphics context to draw on
* \param width Width of the client window
* \param height Height of the client window
*/
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);
	
	
	void Load(std::string filePath);


};

