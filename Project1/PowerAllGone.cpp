/**
 * \file PowerAllGone.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"

#include <string>
#include "PowerAllGone.h"

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
