/**
 * \file ItemVisitor.h
 *
 * \author David Hefty
 *
 * Item visitor base class.
 */


#pragma once

 // Forward references to all Item types
class CUML;
class CPowerItem;
class CHaroldPen;

/** Item visitor base class */
class CItemVisitor
{
public:
	virtual ~CItemVisitor() {}

	/** Visit a CUML object
	 * \param UML UML item we are visiting */
	virtual void VisitUML(CUML* uml) {}

	/** Visit a CPowerItem object
	 * \param poweritem specific item we are visiting */
	virtual void VisitPowerItem(CPowerItem* poweritem) {}

	/** Visit a CHaroldPen object
	 * \param pen specific HaroldPen we are visiting */
	virtual void VisitHaroldPen(CHaroldPen* pen) {}


};