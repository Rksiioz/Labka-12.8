#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 12.8/Laba 12.8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			LinkedList list;
			list.push_back("first");

			Node* current = list.getHead();

			Assert::AreEqual(string("first"), current->data);
		}
	};
}
