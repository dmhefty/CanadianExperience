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

 /** visitor class for makeing a pen item active */
class CMakePenActiveVisitor :
	public CItemVisitor
{
public:
	CMakePenActiveVisitor(double angle) : mAngle(angle)
	{}

	/**
	* Visits a pen object and sets it to active
	* \param HaroldPen the CHaroldPen object being made active
	*/
	virtual void VisitHaroldPen(CHaroldPen* HaroldPen) override;

private:
	double mAngle;
};


