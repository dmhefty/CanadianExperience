/**
 * \file HaroldPen.h
 *
 * \author David Hefty
 * \author Jaideep Prasad
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

	// New constructor
	CHaroldPen(CVector position, CVector velocity, CGame* game);

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;
	virtual void Update(double elapsedTime) override;

	/// Set angle for player rotation
	/// \param angle The new angle
	void SetAngle(double angle) { mAngle = angle; }

	//Unattach pen from Harold
	void UnAttach() { mIsAttached = false; mFiredAngle = mAngle; }
	
	//Gets state of pen attached to Harold
	bool GetAttachedState() { return mIsAttached; }

	void ResetPen();

	virtual void Accept(CItemVisitor* visitor) override;

	virtual void Effect() override 
	{
		CItem::SetVelocity(CVector(0, 0)); 
		CItem::SetLocation(CVector(1000, -1000));
	}

	virtual CVector GetDimensions() const override
	{
		return CVector((double)mHaroldPenImage->GetWidth(),
			(double)mHaroldPenImage->GetHeight());
	}

private:
	bool mIsAttached;
	double mTravelTime;
	std::unique_ptr<Gdiplus::Bitmap> mHaroldPenImage;
	double mAngle = 25.0f;
	double mFiredAngle = 25.0f;
};