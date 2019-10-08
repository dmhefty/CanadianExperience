#pragma once
#include "UMLAttribute.h"
class CBadUMLAttribute :
	public CUMLAttribute
{
private:
	std::wstring mErrorMessage;

public:
	
	CBadUMLAttribute(std::wstring att, std::wstring em) : CUMLAttribute(att) { mErrorMessage = em; }

	std::wstring GetErrorMessage() { return mErrorMessage; }

	void SetErrorMessage(std::wstring em) { mErrorMessage = em;  }
};

