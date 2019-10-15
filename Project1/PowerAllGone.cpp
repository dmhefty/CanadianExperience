/**
 * \file PowerAllGone.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"

#include <string>
#include "Game.h"
#include "PowerAllGone.h"
#include "IsUMLItemVisitor.h"
#include "IsBadUMLVisitor.h"

using namespace std;

const wstring PowerAllGoneImageName = L"poweritem/Nuke.png";

/**
 * All Gone (nuke) power item constructor
 * \param position Position vector of item
 * \param velocity Velocity vector of item
 * \param game The game pointer
 */
CPowerAllGone::CPowerAllGone(CVector position, CVector velocity, CGame* game) :
	CPowerItem(position, velocity, game, PowerAllGoneImageName)
{

}

void CPowerAllGone::Effect()
{
	CGame* game = GetGame();
	CIsUMLItemVisitor umlVisitor;
	vector<shared_ptr<CItem> > allUML;
	for (auto item : *game)
	{
		item->Accept(&umlVisitor);
		if (umlVisitor.IsUML())
		{
			allUML.push_back(item);
			umlVisitor.Reset();
		}
		
	}

	CIsBadUMLVisitor badVisitor;
	for (auto item : allUML)
	{
		item->Accept(&badVisitor);
		if (badVisitor.IsBadUML()) game->IncrementScore(1);
		else game->IncrementScore(-1);
		game->RemoveItem(item);
		badVisitor.Reset();
	}
	allUML.clear();

	CPowerItem::Effect();
}
