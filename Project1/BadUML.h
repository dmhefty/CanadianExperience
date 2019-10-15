#pragma once
#include "UML.h"

class CBadUML :
	public CUML
{
private:
	std::wstring mError;
public:
	CBadUML::CBadUML(std::shared_ptr<CUMLAttribute> name,
		std::vector<std::shared_ptr<CUMLAttribute> > attributes,
		std::vector<std::shared_ptr<CUMLAttribute> > operations,
		CVector position, CVector velocity, CGame* game);

	//TODO -> Accept function to be added aftor visitors are implemented
	virtual void Accept(CItemVisitor* visitor) override 
	{ 
		CUML::Accept(visitor);
		visitor->VisitBadUML(this); 
	}

	virtual void Effect() override;

	void DisplayError() {}
};

