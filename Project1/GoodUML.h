/**
 * \file GoodUML.h
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
 *
 * Class for GoodUMLs
 */

#pragma once

#include "UML.h"

/**
 * Class for Good UML objects
 */
class CGoodUML :
	public CUML
{
public:
	CGoodUML::CGoodUML(std::shared_ptr<CUMLAttribute> name,
		std::vector<std::shared_ptr<CUMLAttribute> > attributes,
		std::vector<std::shared_ptr<CUMLAttribute> > operations,
		CVector position, CVector velocity, CGame* game);

	//TODO -> Accept function to be added aftor visitors are implemented
	virtual void Accept(CItemVisitor* visitor) 
	{ 
		CUML::Accept(visitor);
		visitor->VisitGoodUML(this); 
	}

	virtual void Effect() override;

	void DisplayUnfair() {} // TODO DISPLAY "UNFAIR" WHEN HIT
};

