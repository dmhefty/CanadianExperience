/**
 * \file PowerAllBad.h
 *
 * \author Jaideep Prasad
 *
 * All Good power item class
 */

#pragma once

#include <string>
#include "PowerItem.h"

 /**
  * All Good power item class
  */
class CPowerAllGood : public CPowerItem
{
public:
	CPowerAllGood(CVector position, CVector velocity);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPowerAllGood(this); }
};

