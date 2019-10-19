#pragma once
#include "UML.h"

/// Incorrect UML object
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

	/* Accepts Visitor
	* \param visitor Visitor to be Accepted
	*/
	virtual void Accept(CItemVisitor* visitor) override 
	{ 
		CUML::Accept(visitor);
		visitor->VisitBadUML(this); 
	}

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;

	virtual void Effect() override;

	// Gets Error Message
	std::wstring GetMessageOnHit() const { return mError; } 
};

