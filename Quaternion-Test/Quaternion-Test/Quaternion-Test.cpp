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

		TEST_METHOD(getImFunction)
		{
			Quaternion q = Quaternion(1, 2, 73, 4);

			// In range
			Assert::AreEqual(2.0, q.getIm(0));
			Assert::AreEqual(73.0, q.getIm(1));
			Assert::AreEqual(4.0, q.getIm(2));

			// Out of range
			Assert::AreEqual(-DBL_MAX, q.getIm(-1));
			Assert::AreEqual(-DBL_MAX, q.getIm(3));

		}

		TEST_METHOD(EqualityOperator)
		{

			Quaternion q1 = Quaternion(1, 2, 73, 4);
			Quaternion q2 = Quaternion(1, 2, 73, 4);
			Quaternion q3 = Quaternion(1, 2, 73, 5);

			Assert::IsTrue(q1 == q2);
			Assert::IsFalse(q1 == q3);
		}

		TEST_METHOD(NegateOperator)
		{

			Quaternion q1 = Quaternion(1, 2, 73, 4);
			Quaternion q2 = Quaternion(0, 0, 0, 0);
			

			Assert::IsTrue(-q1 == Quaternion(-1, -2, -73, -4));
			Assert::IsTrue(-q2 == Quaternion(0, 0, 0, 0));
		}

		TEST_METHOD(MultOperator)
		{

			Quaternion q1 = Quaternion(1, 3, 4, 3);
			Quaternion q2 = Quaternion(4, -1, 2, -3);


			Assert::IsTrue(q1 * q2 == Quaternion(8, -7, 24, 19));
			Assert::IsTrue(2.0 * q1 == q1 * 2.0);
		}

		TEST_METHOD(ConjFunction)
		{

			Quaternion q1 = Quaternion(1, 3, 4, 3);
			Quaternion q2 = Quaternion(4, -1, 2, -3);


			Assert::IsTrue(q1.conj() == Quaternion(1, -3, -4, -3));
			Assert::IsTrue(q2.conj() == Quaternion(4, 1, -2, 3));
		}

		TEST_METHOD(NormFunction) {

			Quaternion q1 = Quaternion(1, 3, 4, 3);
			Quaternion q2 = Quaternion(1, 3, -4, -3);

			Assert::IsTrue(q1.norm() == sqrt(35));
			Assert::IsTrue(q2.norm() == sqrt(35));

		}

		TEST_METHOD(UnitVectorFunction) {

			Quaternion q1 = Quaternion(1, 1, 1, 1);

			Assert::IsTrue(q1.getUnitVector() == Quaternion(0.5, 0.5, 0.5, 0.5));

		}

		TEST_METHOD(AddOperator) {

			Quaternion q1 = Quaternion(1, 3, 4, 3);
			Quaternion q2 = Quaternion(1, 3, -4, 3);
			Quaternion q3 = Quaternion(9, 9, 9, 9);

			Assert::IsTrue(q1 + q2 == Quaternion(2, 6, 0, 6));
			Assert::IsTrue(q1 + q3 == Quaternion(10, 12, 13, 12));
			Assert::IsTrue(2.0 + q1 == q1 + 2.0);

		}

		TEST_METHOD(SubstractOperator) {

			Quaternion q1 = Quaternion(1, 3, 4, 3);
			Quaternion q2 = Quaternion(1, 3, -4, 3);
			Quaternion q3 = Quaternion(9, 9, 9, 9);

			Assert::IsTrue(q1 - q2 == Quaternion(0, 0, 8, 0));
			Assert::IsTrue(q1 - q3 == Quaternion(-8, -6, -5, -6));

		}

		TEST_METHOD(DivOperator) {

			Quaternion q1 = Quaternion(4, 0, 8, 0);

			Assert::IsTrue(q1 / 2.0 == Quaternion(2, 0, 8, 0));
			Assert::IsTrue(q1 / 0 == Quaternion(-DBL_MAX, 0, 8, 0));

		}





	
	};
}
