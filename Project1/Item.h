/**
 * \file Item.h
 *
 * \author David Hefty
 *
 * Basic parent Item class
 */

#pragma once
#include "Vector.h"
#include "ItemVisitor.h"
#include <string>
#include <memory>



 /**
  * \brief Basic parent Item class
  *
  * This class implements the base for all other item classes. Provides
  * position, location, and ways to set them
  */
class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	CItem(CVector position, CVector velocity, std::wstring imageLocation);

	/// Basic Destructor
	virtual ~CItem() {};

	virtual void SetLocation(CVector position);
	virtual void SetVelocity(CVector velocity);

	/** The location of the item
	* \returns position Item's position as a vector in pixels */
	CVector GetPosition() { return mPosition; }
	
	/** The velocity of the item
	* \returns velocity Item's velocity as a vector in pixels */
	CVector GetVelocity() { return mVelocity; }

	/** 
	 * \brief Meant to display the graphic for the object using gdiplus
	 *
	 * Pure Virtual Draw since it can't be drawn as a basic Item
	 */
	virtual void Draw(Gdiplus::Graphics* graphics, CVector position);

	virtual void Update(double elapsedTime);

	// TODO -> implement acceptor once visitors are made
	virtual void Accept(CItemVisitor* visitor) = 0;


private:
	/// Current position of the item on the screen
	CVector mPosition;
	/// Current velocity of the item in pixels/sec
	CVector mVelocity;
	/// Image file for the object
	std::unique_ptr<Gdiplus::Bitmap> mItemImage = nullptr;

};

