#pragma once
#include <string>
class CUMLAttribute
{
private:
	std::wstring mAttribute;

public:
	
	CUMLAttribute(std::wstring att) : mAttribute(att) {}

	/** returns the uml attribute stored in this item
	*/
	std::wstring GetAtt() { return mAttribute; }

	void SetAtt(std::wstring att) { mAttribute = att; }
};

