#include "pch.h"
#include "CppUnitTest.h"
#include "../../Quaternion-Project/Quaternion.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuaternionTest
{
	TEST_CLASS(QuaternionTest)
	{
	public:
		
		TEST_METHOD(OutputOperator)
		{
			Quaternion q = Quaternion(1, -1, 0, 1);
			std::ostringstream out;
			out << q;
			
			Assert::AreEqual(0, out.str().compare("[ 1 + -1i + 0j + 1k ]"));
		}
	};
}
