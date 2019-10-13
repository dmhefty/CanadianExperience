/**
 * \file PowerAllGood.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"

#include <string>
#include "PowerAllGood.h"

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
