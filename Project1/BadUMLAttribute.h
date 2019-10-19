#pragma once
#include "UMLAttribute.h"

/// Incorrect UML attribute
class CBadUMLAttribute :
	public CUMLAttribute
{
private:
	std::wstring mErrorMessage;

public:
	
	CBadUMLAttribute(std::wstring att, std::wstring em) : CUMLAttribute(att) { mErrorMessage = em; }

	virtual std::wstring GetErrorMessage() override { return mErrorMessage; }

	void SetErrorMessage(std::wstring em) { mErrorMessage = em;  }
};

