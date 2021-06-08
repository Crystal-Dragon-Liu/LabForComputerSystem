
#include "DataProcessExperiment/Experiment1.h"

enum class OVERFLOW_TYPE
{
    POSITIVE_OVERFLOW,
    NEGATIVE_OVERFLOW,
    NO_OVERFLOW
};

void showBytes(BytePointer start, std::size_t len)
{
    std::size_t i;
    for(i = 0; i < len; i++) {printf(" %.2x", start[i]);}
    printf("\n");
}

void showInt(int x){showBytes(reinterpret_cast<BytePointer>(&x), sizeof(int));}
void showFloat(float x){showBytes(reinterpret_cast<BytePointer>(&x), sizeof(float));}
void showPointer(void* x){showBytes(reinterpret_cast<BytePointer>(&x), sizeof(void*));}

/*2.10*/
void inplaceSwap(IntPtr x, IntPtr y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverseArray(int a[], int cnt)
{
    int first, last;
    for(first = 0, last = cnt - 1; first <= last; first++, last--)
    {
        if(a[first] != a[last]) /// essential step for reverse arrays correctly.
            inplaceSwap(&a[first], &a[last]);
    }
}
void printArray(int a[], int cnt)
{
    int index = 0;
    for(; index <= cnt - 1; index++)
        std::cout << a[index] << std::endl;        
}

/*2.12*/
int getEfficientData(int orgData){return 0xFF & orgData;}
int get212BData(int orgData){return orgData ^~ 0xFF;} /// use ^~ to complement the data.
int get212CData(int orgData){return orgData | 0xFF;}

/*2.30*/
/*Determine whether arguments can be added without overflow.*/
OVERFLOW_TYPE tadd_os(int x, int y)
{
    auto s = x + y;
    if(x > 0 && y > 0 && s < 0) return OVERFLOW_TYPE::POSITIVE_OVERFLOW;
    else if(x < 0 && y < 0 && s > 0) return OVERFLOW_TYPE::NEGATIVE_OVERFLOW;
    else return OVERFLOW_TYPE::NO_OVERFLOW;
}