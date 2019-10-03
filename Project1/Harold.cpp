/**
 * \file Harold.cpp
 *
 * \author Isaac Mayers
 */
#include "pch.h"
#include "Harold.h"
#include <string>
#include <memory>
using namespace std;
using namespace Gdiplus;


/// Fish filename 
const wstring HaroldImageName = L"images/harold.png";
/**
* Constructor
* \param game Game Harold is a member of
*/
CHarold(CGame* game)
{
	mHaroldImage = unique_ptr<Bitmap>(Bitmap::FromFile(HaroldImageName.c_str()));
	if (mHaroldImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += HaroldImageName;
		AfxMessageBox(msg.c_str());
	}
}

 /**
 * Draw this item
 * \param graphics The graphics context to draw on
 * \param x X location to draw in virtual pixels
 * \param y Y location to draw in virtual pixels
 * \param angle Angle of rotation in radians
 */
void CHarold::Draw(Gdiplus::Graphics* graphics, double x, double y, double angle)
{
	float wid = (float)mHaroldImage->GetWidth();
	float hit = (float)mHaroldImage->GetHeight();
	/// Constant ratio to convert radians to degrees
	const double RtoD = 57.295779513;

	auto state = graphics->Save();
	graphics->TranslateTransform((float)x, (float)y);
	graphics->RotateTransform((float)(-angle * RtoD));
	graphics->DrawImage(mHaroldImage.get(), -wid / 2, -hit / 2,
		wid, hit);
	graphics->Restore(state);
}