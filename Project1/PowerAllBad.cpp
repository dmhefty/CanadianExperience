/**
 * \file PowerAllBad.cpp
 *
 * \author Jaideep Prasad
 */

#include "pch.h"

#include <string>
#include "PowerAllBad.h"

using namespace std;

const wstring PowerAllBadImageName = L"poweritem/AllBad.png";

/**
 * All Bad power item constructor
 * \param position Position vector of item
 * \param velocity Velocity vector of item
 */
CPowerAllBad::CPowerAllBad(CVector position, CVector velocity) :
	CPowerItem(position, velocity, PowerAllBadImageName)
{

}
