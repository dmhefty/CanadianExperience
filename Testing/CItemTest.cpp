#include "pch.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Vector.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Pen filename 
const wstring PEN_IMAGE_NAME = L"images/redpen.png";

namespace Testing
{
	TEST_CLASS(HaroldTest)
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
			CItem item(position, velocity, PEN_IMAGE_NAME);
		}

		TEST_METHOD(TestItemSetAndMove)
		{
			// testing base initialization
			CVector position(0.0f, 0.0f);
			CVector velocity(1.0f, 1.0f);
			CItem item(position, velocity, PEN_IMAGE_NAME);
			Assert::IsTrue(item.GetPosition().X() == 0.0f && item.GetPosition().Y() == 0.0f, L"Testing starting location 0, 0");

			// testing getters and setters
			CVector position2(2.0f, 3.0f);
			CVector velocity2(10.3f, 20.5f);
			item.SetLocation(position2);
			item.SetVelocity(velocity2);
			Assert::IsTrue(item.GetPosition().X() == 2.0f && item.GetPosition().Y() == 3.0f, L"Testing location at 2, 3");
			Assert::IsTrue(item.GetVelocity().X() == 10.3f && item.GetVelocity().Y() == 20.5f, L"Testing velocity at 10.3, 20.5");
			
			// testing update function
			item.SetLocation(position);
			item.SetVelocity(velocity);
			item.Update(20.0f); // move 20 seconds
			Assert::IsTrue(item.GetPosition().X() == 20.0f && item.GetPosition().Y() == 20.0f,
				L"Testing: starting location 0, 0 and moving 20 seconds at 1, 1 to position 20, 20");
			Assert::IsFalse(item.GetPosition().X() == 5.0f, L"Double checking that bad values return false");
		}

	};
}