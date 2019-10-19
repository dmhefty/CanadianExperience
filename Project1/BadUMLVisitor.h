#pragma once

#include "ItemVisitor.h"
#include "Item.h"
#include <memory>
#include <vector>

/// Visits incorrect UML attribute item
class CBadUMLVisitor :
	public CItemVisitor
{
public:
	virtual ~CBadUMLVisitor() { mBadUMLs.clear(); }

	/// visits a badUML object
	/// \param badUML Object we are visiting
	virtual void VisitBadUML(CBadUML* badUML) override
	{
		mBadUMLs.push_back(badUML);
	}

	/// Getter for 
	std::vector<CBadUML*> GetBadUMLs() { return mBadUMLs; }

private:
	std::vector<CBadUML*> mBadUMLs;
};

