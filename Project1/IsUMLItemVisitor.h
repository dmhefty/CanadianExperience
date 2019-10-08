/**
 * \file IsUMLItemVisitor.h
 *
 * \author David Hefty
 *
 * Item visitor to determine if an Item is a CUML item
 */

#pragma once
#include "ItemVisitor.h"

 /** visitor class for determining if a CItem object is a CCUML */
class CIsUMLItemVisitor :
	public CItemVisitor
{
public:
	/**
	* Visits an Item object and determines if it is a UML object
	* \param uml the CUML object in question
	*/
	virtual void VisitUML(CUML* uml) override { mIsUML = true; }

	/**
	* Determines if a UML object has been visited
	* \return bool for if an UML object was visited
	*/
	bool IsUML() { return mIsUML; }

private:
	bool mIsUML = false;
};
