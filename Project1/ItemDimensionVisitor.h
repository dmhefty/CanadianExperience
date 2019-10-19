#pragma once

#include "ItemVisitor.h"
#include "Vector.h"
#include "Item.h"

/// Visitor to access an item's dimensions
class CItemDimensionVisitor :
	public CItemVisitor
{
public:
	virtual void VisitItem(CItem* item) override { mItemDimension = item->GetDimensions(); }

	CVector* GetDimensions() { return &mItemDimension; }

private:
	CVector mItemDimension;
};

