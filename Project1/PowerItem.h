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
/* Describes PowerItem class */
class CPowerItem :
	public CItem
{
public:
	/// Default constructor (disabled)
	CPowerItem() = delete;

	/// Copy constructor (disabled)
	CPowerItem(const CItem&) = delete;

	/// Basic Destructor
	~CPowerItem() {};

	/// Accept Visitor
	virtual void Accept(CItemVisitor* visitor) {}

protected:
	CPowerItem(CVector position, CVector velocity, const std::wstring &imageName);

};

