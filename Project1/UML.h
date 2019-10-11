#pragma once
#include "pch.h"
#include <memory>
#include <vector>
#include "Item.h"
#include "UMLAttribute.h"
#include "Vector.h"

class CUML :
	public CItem
{
private:
	int mNumberOfAttributes;

	//pointer to the object for the name assigned to this uml item
	std::shared_ptr<CUMLAttribute> mName;
	
	//vector of 0-3 attributes associated with this uml object
	std::vector<std::shared_ptr<CUMLAttribute> > mAttributes;

	//vector of 0-3 operations associated with this uml object
	std::vector<std::shared_ptr<CUMLAttribute> > mOperations;

	virtual void Accept(CItemVisitor* visitor) override;

public:
	//TODO -> Accept function to be added aftor visitors are implemented
	virtual void Accept(CItemVisitor* visitor) { visitor->VisitUML(this); }

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;

	CUML(std::shared_ptr<CUMLAttribute> name, std::vector<std::shared_ptr<CUMLAttribute> > attributes, 
		std::vector<std::shared_ptr<CUMLAttribute> > operations, CVector position, CVector velocity);

};

