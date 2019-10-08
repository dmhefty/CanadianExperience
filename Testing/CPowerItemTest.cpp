#include "pch.h"
#include "CppUnitTest.h"
#include "PowerItem.h"
#include "Vector.h"
#include <string>


using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const wstring PowerItemImageName = L"poweritem/SlowFall.png";

namespace Testing
{
	TEST_CLASS(CPowerItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestPowerItemConstructor)
		{
			CVector position(0.0f, 0.0f);
			CVector velocity(0.0f, 0.0f);
			CPowerItem::CItem poweritem(position, velocity, PowerItemImageName);
		}

	};
}