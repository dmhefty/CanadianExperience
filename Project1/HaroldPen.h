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

class CHaroldPen :
	public CItem
{
	/// Default constructor (disabled)
	CHaroldPen() = delete;

	/// Copy constructor (disabled)
	CHaroldPen(const CHaroldPen&) = delete;

	CHaroldPen(CVector position, CVector velocity);
};