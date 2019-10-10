/**
* \file IsPowerRapidFireVisitor.h
*
* \author Reid Shinabarker
*
* RapidFire power concrete visitor class.
*/


#pragma once
#include "ItemVisitor.h"
//#include "PowerRapidFire.h"

/** RapidFire power concrete visitor */
class CIsPowerRapidFireVisitor :
	public CItemVisitor
{
public:

	virtual void VisitPowerRapidFire(CPowerRapidFire* rapidfire) override;

	/** Tells the visitor that this is an RapidFire power item
	* \returns True if the item is an RapidFire power item */
	bool IsPowerRapidFire() { return mIsPowerRapidFire; }

private:
	/// Bool for if this is a pen item or not
	bool mIsPowerRapidFire = false;
};