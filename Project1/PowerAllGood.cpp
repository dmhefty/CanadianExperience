/**
 * \file PowerAllGood.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"

#include <string>
#include "Game.h"
#include "PowerAllGood.h"
#include "IsBadUMLVisitor.h"

using namespace std;

const wstring PowerAllGoodImageName = L"poweritem/AllGood.png";

/**
 * All Good power item constructor
 * \param position Position vector of item
 * \param velocity Velocity vector of item
 * \param game The game pointer
 */
CPowerAllGood::CPowerAllGood(CVector position, CVector velocity, CGame* game) :
	CPowerItem(position, velocity, game, PowerAllGoodImageName)
{

}

void CPowerAllGood::Effect()
{
	CGame* game = GetGame();
	CIsBadUMLVisitor umlVisitor;
	vector<shared_ptr<CItem> > badUML;
	for (auto item : *game)
	{
		item->Accept(&umlVisitor);
		if (umlVisitor.IsBadUML())
		{
			badUML.push_back(item);
			umlVisitor.Reset();
		}

	}
	for (auto item : badUML)
	{
		game->RemoveItem(item);
		game->IncrementScore(1);
	}
	badUML.clear();

	CPowerItem::Effect();
}
