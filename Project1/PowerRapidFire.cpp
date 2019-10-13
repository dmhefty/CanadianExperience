/**
 * \file PowerRapidFire.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"

#include <string>
#include "PowerRapidFire.h"

using namespace std;

const wstring PowerRapidFireImageName = L"poweritem/RapidFire.png";

/**
 * Rapid Fire power item constructor
 * \param position Position vector of item
 * \param velocity Velocity vector of item
 * \param game The game pointer
 */
CPowerRapidFire::CPowerRapidFire(CVector position, CVector velocity, CGame* game) :
	CPowerItem(position, velocity, game, PowerRapidFireImageName)
{

}
