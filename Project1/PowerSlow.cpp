/**
 * \file PowerSlow.cpp
 *
 * \author Isaac Mayers
 */

#include "pch.h"

#include <string>
#include "PowerSlow.h"

using namespace std;

const wstring PowerSlowImageName = L"poweritem/SlowFall.png";

/**
 * All Slow power item constructor
 * \param position Position vector of item
 * \param velocity Velocity vector of item
 */
CPowerSlow::CPowerSlow(CVector position, CVector velocity, CGame* game) :
	CPowerItem(position, velocity, game, PowerSlowImageName)
{

}
