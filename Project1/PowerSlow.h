/**
 * \file PowerSlow.h
 *
 * \author Isaac Mayers
 *
 * Slow power item class
 */
#pragma once

#include <string>
#include "PowerItem.h"

/* Slow power-up class*/
class CPowerSlow :
	public CPowerItem
{
public:
	CPowerSlow(CVector position, CVector velocity, CGame* game);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPowerSlow(this); }
};

