/**
 * \file PowerAllBad.h
 *
 * \author Jaideep Prasad
 *
 * All Gone (Nuke) power item class
 */

#pragma once

#include <string>
#include "PowerItem.h"

 /**
  * All Bad power item class
  */
class CPowerAllGone : public CPowerItem
{
public:
	CPowerAllGone(CVector position, CVector velocity);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPowerAllGone(this); }
};

