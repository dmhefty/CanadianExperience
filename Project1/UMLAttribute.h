#pragma once
#include <string>
class CUMLAttribute
{
private:
	std::string mAttribute;

public:
	
	CUMLAttribute(std::string att) : mAttribute(att) {}

	/** returns the uml attribute stored in this item
	*/
	std::string GetAtt() { return mAttribute; }

	void SetAtt(std::string att) { mAttribute = att; }
};

