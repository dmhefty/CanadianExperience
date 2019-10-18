/**
 * \file GoodUML.h
 *
 * \author Akhil Alluri
 * \author Jaideep Prasad
 *
 * Class for GoodUMLs
 */

#pragma once

#include <string>
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

	/* Accepts Visitor
	* \param visitor Visitor to be Accepted
	*/
	virtual void Accept(CItemVisitor* visitor) 
	{ 
		CUML::Accept(visitor);
		visitor->VisitGoodUML(this); 
	}

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;

	virtual void Effect() override;

	//Getter for Unfair message for Good UMLs
	std::wstring GetMessageOnHit() const { return L"Unfair!"; }
};

