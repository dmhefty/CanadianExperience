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
		std::wstring error,
		CVector position, CVector velocity, CGame* game);

	virtual void Accept(CItemVisitor* visitor) override 
	{ 
		CUML::Accept(visitor);
		visitor->VisitBadUML(this); 
	}

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;

	virtual void Effect() override;

	// TODO: replace code below with return mError after constructor is updated
	std::wstring GetMessageOnHit() { return mError; } 
};

