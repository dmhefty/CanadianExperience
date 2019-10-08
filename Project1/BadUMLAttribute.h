#pragma once
#include "UMLAttribute.h"
class CBadUMLAttribute :
	public CUMLAttribute
{
private:
	std::string mErrorMessage;

public:
	

	std::string GetErrorMessage() { return mErrorMessage; }

	void SetErrorMessage(std::string em) { mErrorMessage = em;  }
};

