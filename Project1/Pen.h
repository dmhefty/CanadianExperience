/**
 * \file Pen.h
 *
 * \author David Hefty
 *
 * Class for the Pen item
 */

#pragma once
#include "Item.h"
#include "Vector.h"

class CPen :
	public CItem
{
	/// Default constructor (disabled)
	CPen() = delete;

	/// Copy constructor (disabled)
	CPen(const CPen&) = delete;

	CPen(CVector position, CVector velocity);
};

