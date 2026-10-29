#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_6.4_rec/PR_6.4.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest064rec
{
    TEST_CLASS(UnitTest064rec)
    {
    public:
        TEST_METHOD(TestMinIndexRec)
        {
            double a[] = { 3.5, 1.2, -4.5, 0.5, -2.1 };
            Assert::AreEqual(2, MinIndex(a, 5, 1, 0));
        }

        TEST_METHOD(TestSumBetweenNegativesRec)
        {
            double a[] = { 2.0, -1.0, 3.5, 4.5, -2.0, 5.0 };
            Assert::AreEqual(8.0, SumBetweenNegatives(a, 6), 1e-6);
        }

        TEST_METHOD(TestTransformRec)
        {
            double a[] = { 0.5, 2.5, -0.8, 5.0, 0.2, 3.1 };
            Transform(a, 6);
            Assert::AreEqual(0.5, a[0], 1e-6);
            Assert::AreEqual(-0.8, a[1], 1e-6);
            Assert::AreEqual(0.2, a[2], 1e-6);
            Assert::AreEqual(2.5, a[3], 1e-6);
            Assert::AreEqual(5.0, a[4], 1e-6);
            Assert::AreEqual(3.1, a[5], 1e-6);
        }
    };
}
