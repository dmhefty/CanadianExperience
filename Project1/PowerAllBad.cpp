/**
 * \file PowerAllBad.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"

#include <string>
#include "Game.h"
#include "PowerAllBad.h"
#include "IsGoodUMLVisitor.h"

using namespace std;

const wstring PowerAllBadImageName = L"poweritem/AllBad.png";

/**
 * All Bad power item constructor
 * \param position Position vector of item
 * \param velocity Velocity vector of item
 * \param game The game pointer
 */
CPowerAllBad::CPowerAllBad(CVector position, CVector velocity, CGame* game) :
	CPowerItem(position, velocity, game, PowerAllBadImageName)
{

}

void CPowerAllBad::Effect()
{
	CGame* game = GetGame();
	CIsGoodUMLVisitor umlVisitor;

	for (auto item : *game)
	{
		item->Accept(&umlVisitor);
		if (umlVisitor.IsGoodUML())
		{
			item->Effect();
			game->DecrementUnfairScore();
			umlVisitor.Reset();
		}

	}

	CPowerItem::Effect();
}
