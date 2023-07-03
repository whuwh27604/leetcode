/* 和等于目标值的质数对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 。如果两个整数 x 和 y 满足下述条件，则认为二者形成一个质数对：

1 <= x <= y <= n
x + y == n
x 和 y 都是质数
请你以二维有序列表的形式返回符合题目要求的所有 [xi, yi] ，列表需要按 xi 的 非递减顺序 排序。如果不存在符合要求的质数对，则返回一个空数组。

注意：质数是大于 1 的自然数，并且只有两个因子，即它本身和 1 。



示例 1：

输入：n = 10
输出：[[3,7],[5,5]]
解释：在这个例子中，存在满足条件的两个质数对。
这两个质数对分别是 [3,7] 和 [5,5]，按照题面描述中的方式排序后返回。
示例 2：

输入：n = 2
输出：[]
解释：可以证明不存在和为 2 的质数对，所以返回一个空数组。


提示：

1 <= n <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

const int maxN = 1000000;
vector<int> primes;
vector<bool> isPrimes(maxN + 1, true);

void EulerFilter() {
    isPrimes[0] = isPrimes[1] = false;

    for (int num = 2; num <= maxN; ++num) {
        if (isPrimes[num]) {
            primes.push_back(num);
        }

        for (int prime : primes) {
            int composite = num * prime;
            if (composite > maxN) {
                break;
            }

            isPrimes[composite] = false;

            if (num % prime == 0) {
                break;
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        EulerFilter();
    }
}

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;

        init();

        for (int prime : primes) {
            int primePair = n - prime;
            if (primePair < prime) {
                break;
            }

            if (isPrimes[primePair]) {
                ans.push_back({ prime, primePair });
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> actual = o.findPrimePairs(10);
    vector<vector<int>> expected = { {3,7},{5,5} };
    check.checkIntVectorVector(expected, actual);

    actual = o.findPrimePairs(2);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    actual = o.findPrimePairs(1000000);
    expected = getIntVectorVector("./testcase1.txt");
    check.checkIntVectorVector(expected, actual);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
