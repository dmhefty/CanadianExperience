/**
 * \file IsPenVisitor.cpp
 *
 * \author Reid Shinabarker
 */

#include "pch.h"
#include "IsPenVisitor.h"

/** \brief Visit a CHaroldPen object
* \param pen Pen item we are visiting */
void CIsPenVisitor::VisitHaroldPen(CHaroldPen* pen)
{
	mIsPen = true;
}
