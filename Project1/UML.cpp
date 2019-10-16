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
	SolidBrush white(Color(255, 255, 255));
	PointF origin(0.0f, 0.0f);
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	double textHeight = 0;
	double textWidth = 0;
	graphics->MeasureString(mName->GetAtt().c_str(), -1, &font, origin, &size);
	textHeight += (double)size.Height;
	/* Draw Name */
	graphics->DrawString(mName->GetAtt().c_str(), -1, &font, origin, &white);
	for (auto att : mAttributes) {
		graphics->MeasureString(att->GetAtt().c_str(), -1, &font, PointF(textHeight, textWidth), &size);
		
			textHeight += (double)size.Height;
		
		if ((double)size.Width != textWidth) {
			textWidth = (double)size.Width;
		}
		/*Draw Attributes*/
		graphics->DrawString(att->GetAtt().c_str(), -1, &font, PointF(textHeight, textWidth), &white);
	}

	for (auto op : mOperations) {
		graphics->MeasureString(op->GetAtt().c_str(), -1, &font, PointF(textHeight, textWidth), &size);
		
			textHeight += (double)size.Height;
		
		if ((double)size.Width != textWidth) {
			textWidth = (double)size.Width;
		}
		/*Draw Operations*/
		graphics->DrawString(op->GetAtt().c_str(), -1, &font, PointF(textHeight, textWidth), &white);
	}
	CVector pos = GetPosition();
	Gdiplus::SolidBrush sb(Gdiplus::Color(255, 255, 193));
	Gdiplus::Rect box((int)(pos.X() - textWidth / 2), (int)(pos.Y() - textHeight / 2), (int)textWidth, (int)textHeight);
	graphics->FillRectangle(&sb, box );
}
