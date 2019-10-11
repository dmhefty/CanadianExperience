#include "pch.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Vector.h"
#include "HaroldPen.h"
#include <string>

using namespace Gdiplus;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Pen filename 
const wstring PEN_IMAGE_NAME = L"images/redpen.png";

/** Mock class for testing CItem */
class CItemMock : public CItem
{
public:
	CItemMock(CVector position, CVector velocity) : CItem(position, velocity) {}

	virtual void Draw(Gdiplus::Graphics* graphics, CVector position) override {}

	virtual void Accept(CItemVisitor* visitor) override {}

};


namespace Testing
{
	TEST_CLASS(ItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestItemConstructor)
		{
			CVector position(0.0f, 0.0f);
			CVector velocity(0.0f, 0.0f);
			CItemMock item(position, velocity);
		}

		

	};
}