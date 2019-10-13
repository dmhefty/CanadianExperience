/**
 * \file PowerAllBad.h
 *
 * \author Jaideep Prasad
 *
 * All Bad power item class
 */

#pragma once

#include <string>
#include "PowerItem.h"

/**
 * All Bad power item class 
 */
class CPowerAllBad : public CPowerItem
{
public:
	CPowerAllBad(CVector position, CVector velocity, CGame* game);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPowerAllBad(this); }
};

