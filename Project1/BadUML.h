#pragma once
#include "UML.h"
class CBadUML :
	public CUML
{
private:
	std::wstring mError;
public:
	//TODO -> Accept function to be added aftor visitors are implemented
	//virtual void Accept(CVisitor visitor);

	void DisplayError() {}
};

