#pragma once

#include "ItemVisitor.h"
#include "Item.h"
#include <memory>
#include <vector>

class CGoodUMLVisitor :
	public CItemVisitor
{
public:
	virtual ~CGoodUMLVisitor() { mGoodUMLs.clear(); }

	virtual void VisitGoodUML(CGoodUML* goodUML) override 
	{
		mGoodUMLs.push_back(goodUML);
	}

	std::vector<CGoodUML*> GetGoodUMLs() { return mGoodUMLs; }

private:
	std::vector<CGoodUML*> mGoodUMLs;
};

