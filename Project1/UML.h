#pragma once
#include <memory>
#include <vector>
#include "Item.h"
#include "UMLAttribute.h"

class CUML :
	public CItem
{
private:
	int numberOfAttributes;

	//pointer to the object for the name assigned to this uml item
	std::unique_ptr<CUMLAttribute> name;
	
	//vector of 0-3 attributes associated with this uml object
	std::vector<std::shared_ptr<CUMLAttribute> > attributes;

	//vector of 0-3 operations associated with this uml object
	std::vector<std::shared_ptr<CUMLAttribute> > operations;




public:
	//TODO -> Accept function to be added aftor visitors are implemented
	//virtual void Accept(CVisitor visitor) = 0;
};

