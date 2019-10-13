#pragma once

#include "ItemVisitor.h"
#include "Vector.h"
#include "Item.h"

class CItemDimensionVisitor :
	public CItemVisitor
{
public:
	virtual void VisitItem(CItem* item) override { mItemDimension = item->GetDimensions(); }

	CVector* GetDimensions() { return &mItemDimension; }

private:
	CVector mItemDimension;
};

