#include "pch.h"
#include "UML.h"

using namespace Gdiplus;

CUML::CUML(std::shared_ptr<CUMLAttribute> name, 
	std::vector<std::shared_ptr<CUMLAttribute> > attributes, 
	std::vector<std::shared_ptr<CUMLAttribute> > operations, 
	CVector position, CVector velocity, CGame* game) :
	CItem(position, velocity, game) {
	mName = name;
	mAttributes = attributes;
	mOperations = operations;


}


//TODO -> implement drawing for uml items
void CUML::Draw(Graphics* graphics, CVector position) {
	Pen drawPen(Color(255, 255, 193));
	// Determine the text height
	RectF size;
	SolidBrush black(Color(0, 0, 0));
	PointF origin(0.0f, 0.0f);
	double textHeight = 0;
	double textWidth = 0;
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
	graphics->MeasureString(mName->GetAtt().c_str(), -1, &font, origin, &size);
	textHeight = (double)size.Height;
	textWidth = (double)size.Width;
	for (auto att : mAttributes) {
		graphics->MeasureString(att->GetAtt().c_str(), -1, &font, origin, &size);
		
			textHeight += (double)size.Height;
		
		if ((double)size.Width > textWidth) {
			textWidth = (double)size.Width;
		}
	}

	for (auto op : mOperations) {
		graphics->MeasureString(op->GetAtt().c_str(), -1, &font, origin, &size);

		textHeight += (double)size.Height;

		if ((double)size.Width > textWidth) {
			textWidth = (double)size.Width;
		}

	}
	SolidBrush sb(Gdiplus::Color(255, 255, 193));
	Rect box((int)(position.X() - textWidth / 2), (int)(position.Y() - textHeight / 2), (int)textWidth, (int)textHeight);
	graphics->FillRectangle(&sb, box );
	PointF strloc(position.X(), position.Y());
	strloc.Y = strloc.Y - textHeight / 2;
	graphics->MeasureString(mName->GetAtt().c_str(), -1, &font, strloc, &size);
	strloc.X = strloc.X - (double)size.Width / 2;
	/*Draw Name*/
	graphics->DrawString(mName->GetAtt().c_str(), -1, &font, strloc, &black);
	strloc.X = strloc.X + (double)size.Width / 2;
	strloc.X = strloc.X - textWidth / 2;
	for (auto att : mAttributes) {
		graphics->MeasureString(att->GetAtt().c_str(), -1, &font, strloc, &size);
		strloc.Y = strloc.Y + (double)size.Height;
		/*Draw Attributes*/
		graphics->DrawString(att->GetAtt().c_str(), -1, &font, strloc, &black);
	}

	for (auto op : mOperations) {
		graphics->MeasureString(op->GetAtt().c_str(), -1, &font, strloc, &size);
		strloc.Y = strloc.Y + (double)size.Height;
		/*Draw Operations*/
		graphics->DrawString(op->GetAtt().c_str(), -1, &font, strloc, &black);
	}
}

