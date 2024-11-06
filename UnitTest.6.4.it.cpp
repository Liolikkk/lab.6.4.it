#include "pch.h"
#include "CppUnitTest.h"
#include "../lab.6.4.it/lab.6.4.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { 1, 0, 3, 0, 5, 6, 0, 8, 9, 10 };
			int expectedCount = 3;
			Assert::AreEqual(CountZeros(arr, 10), expectedCount);
		}
	};
}
