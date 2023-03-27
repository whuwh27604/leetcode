// 质数减法运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

int maxNum = 1000;
vector<int> primes;

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        vector<bool> isPrime(maxNum + 1, true);

        for (int i = 2; i <= maxNum; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }

            for (int j = 0; j < (int)primes.size() && i * primes[j] <= maxNum; ++j) {
                isPrime[i * primes[j]] = false;

                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
    }
}

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        init();
        int prev = 0;

        for (int& num : nums) {
            if (num <= prev) {
                return false;
            }

            auto iter = lower_bound(primes.begin(), primes.end(), num - prev);
            if (iter != primes.begin()) {
                --iter;
                num -= *iter;
            }

            prev = num;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,9,6,10 };
    check.checkBool(true, o.primeSubOperation(nums));

    nums = { 6,8,11,12 };
    check.checkBool(true, o.primeSubOperation(nums));

    nums = { 998,2 };
    check.checkBool(true, o.primeSubOperation(nums));

    nums = { 1 };
    check.checkBool(true, o.primeSubOperation(nums));

    nums = { 5,8,3 };
    check.checkBool(false, o.primeSubOperation(nums));

    nums = { 2,2 };
    check.checkBool(false, o.primeSubOperation(nums));
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
