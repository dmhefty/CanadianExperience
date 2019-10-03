#include "pch.h"
#include "CppUnitTest.h"
#include "Harold.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
		
		TEST_METHOD(TestHaroldConstructor)
		{
			CHarold harold(CGame * game);
		}

	};
}