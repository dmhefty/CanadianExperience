/**
 * \file PowerItem.cpp
 *
 * \author Isaac Mayers
 * \author Jaideep Prasad
 */

#include "pch.h"
#include "PowerItem.h"
#include <string>
#include <memory>

using namespace std;
using namespace Gdiplus;
/* PowerItem image name*/
const wstring PowerItemImageName = L"poweritem/SlowFall.png";

/* Constructor */
CPowerItem::CPowerItem(CVector position, CVector velocity, const wstring &imageName) : 
	CItem(position, velocity, imageName)
{

}

