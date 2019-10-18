#pragma once
#include "pch.h"
#include <memory>
#include <vector>
#include "Item.h"
#include "UMLAttribute.h"
#include "Vector.h"

class CUML :
	public CItem
{
private:
	int mNumberOfAttributes;

	//pointer to the object for the name assigned to this uml item
	std::shared_ptr<CUMLAttribute> mName;
	
	//vector of 0-3 attributes associated with this uml object
	std::vector<std::shared_ptr<CUMLAttribute> > mAttributes;

	//vector of 0-3 operations associated with this uml object
	std::vector<std::shared_ptr<CUMLAttribute> > mOperations;

	double mWidth = -1;

	double mHeight = -1;

public:
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitUML(this); }

	virtual void Update(double elapsedTime) override;

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override;

	virtual CVector GetDimensions() const override
	{
		return CVector(mWidth, mHeight);
	}

	virtual void Effect() override 
	{ 
		CItem::SetVelocity(CVector(0, 0));
		mDisplayLocation = CItem::GetPosition();
	}

	bool IsDeleted() const { return mDeleted; }

protected:

	CUML(std::shared_ptr<CUMLAttribute> name, std::vector<std::shared_ptr<CUMLAttribute> > attributes, 
		std::vector<std::shared_ptr<CUMLAttribute> > operations, CVector position, CVector velocity, CGame* game);

	bool mHit = false;
	bool mDeleted = false;
	double mTimeDisplayed = 0;
	CVector mDisplayLocation;

};

