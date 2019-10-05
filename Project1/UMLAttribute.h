#pragma once
#include <string>
class CUMLAttribute
{
private:
	std::string attribute;

public:
	CUMLAttribute(std::string att) : attribute(att) {};

	/** returns the uml attribute stored in this item
	*/
	std::string GetAtt() { return attribute; }
};

