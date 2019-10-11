#include "pch.h"
#include "UML.h"


CUML::CUML(std::shared_ptr<CUMLAttribute> name, 
	std::vector<std::shared_ptr<CUMLAttribute> > attributes, 
	std::vector<std::shared_ptr<CUMLAttribute> > operations, 
	CVector position, CVector velocity) :
	CItem(position, velocity) {
	mName = name;
	mAttributes = attributes;
	mOperations = operations;


}

void CUML::Accept(CItemVisitor* visitor)
{
	visitor->VisitUML(this);
}

//TODO -> implement drawing for uml items
void CUML::Draw(Gdiplus::Graphics* graphics, CVector position) {
	Gdiplus::Pen drawPen(Gdiplus::Color(255, 255, 193));
	// Determine the text height
	Gdiplus::RectF size;
	Gdiplus::PointF origin(0.0f, 0.0f);
	Gdiplus::FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	double textHeight = 0;
	double textWidth = 0;
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

	graphics->MeasureString(mName->GetAtt().c_str(), -1, &font, origin, &size);
	textHeight += (double)size.Height;

	CVector pos = GetPosition();
	Gdiplus::SolidBrush sb(Gdiplus::Color(255, 255, 193));
	Gdiplus::Rect box((int)(pos.X() - textWidth / 2), (int)(pos.Y() - textHeight / 2), (int)textWidth, (int)textHeight);
	graphics->FillRectangle(&sb, box );
}
