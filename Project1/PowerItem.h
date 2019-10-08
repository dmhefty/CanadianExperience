/**
 * \file PowerItem.h
 *
 * \author Isaac Mayers
 * 
 *
 * Class for the powerup, PowerItem
 */


#pragma once
#include "Item.h"
#include "ItemVisitor.h"
#include "Vector.h"
/* Describes PowerItem class */
class CPowerItem :
	public CItem
{
public:
	/// Default constructor (disabled)
	CPowerItem() = delete;

	/// Copy constructor (disabled)
	CPowerItem(const CItem&) = delete;

	CPowerItem(CVector position, CVector velocity);

	/// Basic Destructor
	~CPowerItem() {};

	/// Accept Visitor
	void Accept(CItemVisitor visitor);

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;
	virtual void Update(double elapsedTime) override;
private:
	std::unique_ptr<Gdiplus::Bitmap> mPowerItemImage;
};

