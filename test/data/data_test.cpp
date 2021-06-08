#include "DataProcessExperiment/Experiment1.h"
#include "gtest/gtest.h"
#include "AllocatorExperiment/AllocatorExperiment.h"
#include <vector>


TEST(MyAllocatorBasicTest, test1)
{
    int ia[5] = {0, 1, 2, 3, 4};
    unsigned int i;
    std::vector<int, YB::allocator<int> > iv(ia, ia+5);
    for(i = 0; i < iv.size(); i++){std::cout << iv[i] << ' ';}
    std::cout << std::endl;
}


TEST(MyDataProcessBasicTest, DISABLED_test1)
{
    int iVal = 0x87654321;
    float fVal = static_cast<float>(iVal);
    int* pVal = &iVal;
    showInt(iVal);
    showFloat(fVal);
    showPointer(pVal); /// linux 64.
}

TEST(MyDataProcessBasicTest, DISABLED_test2)
{
    int iVal = 0x3039;
    BytePointer pVal = reinterpret_cast<BytePointer>(&iVal);
    showBytes(pVal, 1);
    showBytes(pVal, 2);
    showBytes(pVal, 3);

    const char* s = "abcdef";
    showBytes((BytePointer)s, strlen(s));
}


/*2.10-2.11*/
TEST(MyDataProcessBasicTest, DISABLED_test3)
{
    // int a[4] = {1, 2, 3, 4};
    // reverseArray(a, 4);
    // printArray(a, 4);

    // when the size is not a even num. the method doesn't work.
    int a[5] = {1, 2, 3, 4, 5};
    reverseArray(a, 5);
    printArray(a, 5);
}

/*2.12 A, B, C*/
TEST(MyDataProcessBasicTest, test4)
{
    int iVal = 0x87654321;
    int result_a = getEfficientData(iVal);
    ASSERT_EQ(result_a, 0x00000021);
    int result_b = get212BData(iVal);
    ASSERT_EQ(result_b, 0x789ABC21);
    int result_c = get212CData(iVal);
    ASSERT_EQ(result_c, 0x876543FF);
    short x = 12345;
    short mx = -x;
    showBytes(reinterpret_cast<BytePointer>(&x), sizeof(short));
    showBytes(reinterpret_cast<BytePointer>(&mx), sizeof(short));

}