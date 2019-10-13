#include "pch.h"
#include "CppUnitTest.h"
#include "ScoreBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreBoardTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestConstructor)
		{
			CScoreBoard scoreBoard;
		}

	};
}