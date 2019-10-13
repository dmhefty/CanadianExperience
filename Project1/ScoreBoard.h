/**
 * \file ScoreBoard.h
 *
 * \author Jaideep Prasad
 *
 * Class for the game score board
 */

#pragma once

/**
 * Game score board class
 */
class CScoreBoard
{
public:
	CScoreBoard();

	// Do not use copy constructor
	CScoreBoard(const CScoreBoard&) = delete;

	virtual ~CScoreBoard();

	void Draw(Gdiplus::Graphics* graphics);

	/*
	 * Increases correct counter by 1.
	 */
	void IncrementCorrect() { mCorrect++; } 

	/*
	 * Increases missed counter by 1.
	 */
	void IncrementMissed() { mMissed++; }

	/*
	 * Increases unfair counter by 1.
	 */
	void IncrementUnfair() { mUnfair++; }

private:
	/// Number of hits on good UML objects by the player
	int mCorrect = 0;
	/// Number of good UML objects the player failed to hit
	int mMissed = 0;
	/// Number of hits on bad UML objects by the player
	int mUnfair = 0;
};

