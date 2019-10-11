/**
 * \file PowerFast.cpp
 *
 * \author Isaac Mayers
 */

#include "pch.h"

#include <string>
#include "PowerFast.h"

using namespace std;

const wstring PowerFastImageName = L"poweritem/FastFall.png";

/**
 * All Fast power item constructor
 * \param position Position vector of item
 * \param velocity Velocity vector of item
 */
CPowerFast::CPowerFast(CVector position, CVector velocity) :
	CPowerItem(position, velocity, PowerFastImageName)
{

}
