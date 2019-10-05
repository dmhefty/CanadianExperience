#pragma once
#include "UMLAttribute.h"
class CBadUMLAttribute :
	public CUMLAttribute
{
private:
	std::string mErrorMessage;

public:
	CBadUMLAttribute(std::string att, std::string em) : 
		CUMLAttribute(att) { mErrorMessage = em; }

	std::string GetErrorMessage() { return mErrorMessage; }

};

