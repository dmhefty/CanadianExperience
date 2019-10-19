/**
 * \file PowerItem.h
 *
 * \author Isaac Mayers
 * \author Jaideep Prasad
 *
 * Class for the powerup, PowerItem
 */


#pragma once
#include <string>
#include <memory>
#include "Item.h"
#include "ItemVisitor.h"
#include "Vector.h"

/// Describes PowerItem class
class CPowerItem :
	public CItem
{
public:
	/// Default constructor (disabled)
	CPowerItem() = delete;

	/// Copy constructor (disabled)
	CPowerItem(const CItem&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;
	virtual void Update(double elapsedTime) override;

	/// Basic Destructor
	~CPowerItem() {};

	/// Accept Visitor
	virtual void Accept(CItemVisitor* visitor) {}

	virtual CVector GetDimensions() const override 
	{ 
		return CVector((double)mPowerItemImage->GetWidth(),
			(double)mPowerItemImage->GetHeight());
	}

	virtual void Effect() override 
	{ 
		CItem::SetLocation(CVector(-100, -1000));
		CItem::SetVelocity(CVector(0, 0));
	}

	bool IsActive() const { return mIsActive; }

protected:
	CPowerItem(CVector position, CVector velocity, CGame* game,
		std::wstring PowerItemImageName);
	bool mIsActive = false;
	double mTimeActive = 0;

private:
	std::unique_ptr<Gdiplus::Bitmap> mPowerItemImage;
};

