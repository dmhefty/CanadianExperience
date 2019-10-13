/**
 * \file PowerItem.h
 *
 * \author Isaac Mayers
 * \author Jaideep Prasad
 *
 * Class for the powerup, PowerItem
 */


#pragma once
#include "Item.h"
#include "ItemVisitor.h"
#include "Vector.h"
#include <string>
#include <memory>

/* Describes PowerItem class */
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

protected:
	CPowerItem(CVector position, CVector velocity, std::wstring PowerItemImageName);

private:
	std::unique_ptr<Gdiplus::Bitmap> mPowerItemImage;

};

