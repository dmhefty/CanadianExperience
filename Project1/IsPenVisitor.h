/**
* \file IsPenVisitor.h
*
* \author Reid Shinabarker
*
* Pen concrete visitor class.
*/


#pragma once
#include "ItemVisitor.h"
#include "HaroldPen.h"

/** Pen concrete visitor */
class CIsPenVisitor :
	public CItemVisitor
{
public:

	virtual void VisitHaroldPen(CHaroldPen* pen) override;

	/** Tells the visitor that this is a pen item
	* \returns True if the item is a pen */
	bool IsPen() { return mIsPen; }

private:
	/// Bool for if this is a pen item or not
	bool mIsPen = false;
};

