/**
 * \file PowerFast.h
 *
 * \author Isaac Mayers
 *
 * Fast power item class
 */
#pragma once

#include <string>
#include "PowerItem.h"


 /* Slow power-up class*/
class CPowerFast :
	public CPowerItem
{
public:
	CPowerFast(CVector position, CVector velocity, CGame* game);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitPowerFast(this); }
};

