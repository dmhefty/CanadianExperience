/**
 * \file PowerItem.cpp
 *
 * \author Isaac Mayers
 */

#include "pch.h"
#include "PowerItem.h"
#include <string>
#include <memory>

using namespace std;
using namespace Gdiplus;
/* PowerItem image name*/
const wstring PowerItemImageName = L"poweritem/SlowFall.png";

/* Constructor */
CPowerItem::CPowerItem(CVector position, CVector velocity) : CItem(position, velocity, PowerItemImageName)
{
	mPowerItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(PowerItemImageName.c_str()));
	if (mPowerItemImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += PowerItemImageName;
		AfxMessageBox(msg.c_str());
	}
}

/* Draw power item*/
void CPowerItem::Draw(Gdiplus::Graphics* graphics, CVector position)
{
	CItem::Draw(graphics, position);
}
/* Accept Visitor*/
void CPowerItem::Accept(CItemVisitor visitor)
{
	visitor.VisitPowerItem(this);
}
/* Update Image */
void CPowerItem::Update(double elapsedTime)
{
	CItem::Update(elapsedTime);
}