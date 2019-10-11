/**
 * \file IsHaroldPenVisitor.h
 *
 * \author David Hefty
 *
 * Item visitor to determine if an Item is a HaroldPen
 */

#pragma once
#include "ItemVisitor.h"
#include "HaroldPen.h"

/** visitor class for determining if a CItem object is a CHaroldPen */
class CIsHaroldPenVisitor :
	public CItemVisitor
{
public:
	/**
	* Visits an Item object and determines if it is a HaroldPen object
	* \param HaroldPen the CHaroldPen object in question
	*/
	virtual void VisitHaroldPen(CHaroldPen* HaroldPen) override 
	{ 
		mIsHaroldPen = true; 
		mPen = HaroldPen;
	}

	CHaroldPen* GetPen() const { return mPen; }
	virtual void VisitHaroldPen(CHaroldPen* HaroldPen) override { mIsHaroldPen = true; mAttachedState = HaroldPen->GetAttachedState(); }

	/**
	* Determines if a HaroldPen object has been visited
	* \return bool for if an HaroldPen object was visited
	*/
	bool IsHaroldPen() { return mIsHaroldPen; }
	bool IsAttached() { return mAttachedState; }

private:
	bool mIsHaroldPen = false;
	CHaroldPen* mPen = nullptr;
	bool mAttachedState = false;
};
