#pragma once

#include "ItemVisitor.h"
#include "Item.h"
#include <memory>
#include <vector>

class CBadUMLVisitor :
	public CItemVisitor
{
public:
	virtual ~CBadUMLVisitor() { mBadUMLs.clear(); }

	virtual void VisitBadUML(CBadUML* badUML) override
	{
		mBadUMLs.push_back(badUML);
	}

	std::vector<CBadUML*> GetGoodUMLs() { return mBadUMLs; }

private:
	std::vector<CBadUML*> mBadUMLs;
};

