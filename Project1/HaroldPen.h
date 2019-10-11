/**
 * \file HaroldPen.h
 *
 * \author David Hefty
 *
 * Class for the HaroldPen item
 */

#pragma once
#include "Item.h"
#include "Vector.h"
#include <string>

class CHaroldPen :
	public CItem
{
public:
	/// Default constructor (disabled)
	CHaroldPen() = delete;

	/// Copy constructor (disabled)
	CHaroldPen(const CHaroldPen&) = delete;

	CHaroldPen(CVector position, CVector velocity);

	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitHaroldPen(this); }

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;
	virtual void Update(double elapsedTime) override;

private:
	bool mIsAttached;
	std::wstring mHaroldPenImage;
	
};