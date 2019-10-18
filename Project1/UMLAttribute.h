#pragma once
#include <string>
class CUMLAttribute
{
private:
	std::wstring mAttribute;
	std::wstring mError = L"";
public:
	
	CUMLAttribute(std::wstring att) : mAttribute(att) {}

	/** returns the uml attribute stored in this item
	*/
	std::wstring GetAtt() { return mAttribute; }

	virtual std::wstring GetErrorMessage() { return L"Unfair!"; }

	void SetAtt(std::wstring att) { mAttribute = att; }
};

