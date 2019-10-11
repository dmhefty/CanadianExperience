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
#include "ItemVisitor.h"
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

	/// Set angle for player rotation
	/// \param angle The new angle
	void SetAngle(double angle) { mAngle = angle; }

	void UnAttach() { mIsAttached = false; }
	
	bool GetAttachedState() { return mIsAttached; }

	void ResetPen();

	virtual void Accept(CItemVisitor* visitor) override;

private:
	bool mIsAttached;
	std::unique_ptr<Gdiplus::Bitmap> mHaroldPenImage;
	double mAngle = 25.0f;
	
};