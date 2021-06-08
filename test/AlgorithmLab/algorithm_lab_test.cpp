#include "gtest/gtest.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

void elimDups(std::vector<std::string>& wordVec)
{
    //sort
    std::sort(wordVec.begin(), wordVec.end());
    // unique 重排输入范围，使每个单词出现一次
    auto end_iter = std::unique(wordVec.begin(), wordVec.end());
    wordVec.erase(end_iter, wordVec.end());
}

/* a function that replace the lambda-> [sz](const std::string& a){return a.size() >= sz;}  */
bool check_size(const std::string& s, std::string::size_type sz){return s.size() >= sz;}
bool isShorter(const std::string& s1, const std::string& s2){return s1.size() < s2.size();}
void printStrVec(const std::vector<std::string>& strVec){for(std::size_t i = 0; i < strVec.size(); i++) std::cout << strVec[i] << " "; std::cout<< std::endl;}

void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    // get a iterator which points to the first elem which is bigger than 'sz'
    // auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string& a){return a.size() >= sz;});
    auto wc = std::find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
    //calculate the length of strings whose size is bigger than 'sz'
    auto count = words.end() - wc;
    std::cout << count << std::endl;

    // print the goddamn words.
    std::for_each(wc, words.end(), [](const std::string& a){std::cout << a << std::endl;}); // lambda that print all the data expected.
}


TEST(MyAlgorithmBasicTest, test1)
{
    std::vector<int> testDataInt(4, 1);
    // 元素相加
    int sum = std::accumulate(testDataInt.begin(), testDataInt.end(), 0);
    ASSERT_EQ(sum, 4);
    // 字符串拼接
    std::vector<std::string> testDataStr{"a", "b", "c"};
    std::string testDataStrSum = std::accumulate(testDataStr.begin(), testDataStr.end(), std::string(""));
    ASSERT_EQ(testDataStrSum, std::string("abc"));
    // 对比两个容器的元素是否相同
    std::vector<int> testDataInt1{1, 2, 3};
    std::vector<int> testDataInt2{1, 2, 3};
    ASSERT_EQ(std::equal(testDataInt1.cbegin(), testDataInt1.cend(), testDataInt2.cbegin()), true);

    // 向容器中写入指定元素。
    std::vector<int> testDataInt3(3, 0);
    std::fill(testDataInt2.begin(), testDataInt2.end(), 0);
    std::fill_n(testDataInt1.begin(), testDataInt1.size(), 0); //不检查越界。
    ASSERT_EQ(std::equal(testDataInt2.cbegin(), testDataInt2.cend(), testDataInt3.cbegin()), true);
    ASSERT_EQ(std::equal(testDataInt1.cbegin(), testDataInt1.cend(), testDataInt3.cbegin()), true);
    // 插入迭代器
    std::vector<int> testDataInt4{1, 2, 3, 4};
    std::vector<int> testDataInt5{1, 2, 3, 4, 5};
    std::vector<int> testDataTarInt6{1, 2, 3, 4, 5, 0, 0, 0, 0};
    auto backIter = std::back_inserter(testDataInt4);
    *backIter = 5;
    ASSERT_EQ(std::equal(testDataInt5.cbegin(), testDataInt5.cend(), testDataInt4.cbegin()), true);
    auto backIter1 = std::back_inserter(testDataInt4); /// 创建一个插入迭代器，用这个迭代器作为目标迭代器，向后插入４个０元素。
    std::fill_n(backIter1, 4, 0);
    ASSERT_EQ(std::equal(testDataInt4.cbegin(), testDataInt4.cend(), testDataTarInt6.cbegin()), true);

    // 将begin 和end　范围内的数据复制到a2处。
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1)/ sizeof(*a1)];
    auto ret = std::copy(std::begin(a1), std::end(a1), a2); // 指向末尾的指针, 不可访问
    std::cout << *(ret-1) << std::endl;

    // 消除重复单词
    std::vector<std::string> wordVecTar{"fox", "jumps", "over", "quick", "red", "slow", "the", "turtle"};
    std::vector<std::string> wordVecInput{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    // sort
    // elimDups(wordVecInput);
    // ASSERT_EQ(wordVecInput.size(), wordVecTar.size());
    
    // 向算法传递函数1. 输入二元谓词
    // std::sort(wordVecInput.begin(), wordVecInput.end(), isShorter);
    // std::stable_sort(wordVecInput.begin(), wordVecInput.end(), isShorter); /// 维持相等元素之间的相对位置，此例为字典序
    // printStrVec(wordVecInput);

    // output all the words whose size is bigger than a specific value.
    biggies(wordVecInput, 6);
}