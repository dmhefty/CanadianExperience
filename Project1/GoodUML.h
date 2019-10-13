#pragma once

#include "UML.h"

class CGoodUML :
	public CUML
{
public:
	//TODO -> Accept function to be added aftor visitors are implemented
	virtual void Accept(CItemVisitor* visitor) { visitor->VisitUML(this); }
};

