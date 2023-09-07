/* 统计对称整数的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 low 和 high 。

对于一个由 2 * n 位数字组成的整数 x ，如果其前 n 位数字之和与后 n 位数字之和相等，则认为这个数字是一个对称整数。

返回在 [low, high] 范围内的 对称整数的数目 。



示例 1：

输入：low = 1, high = 100
输出：9
解释：在 1 到 100 范围内共有 9 个对称整数：11、22、33、44、55、66、77、88 和 99 。
示例 2：

输入：low = 1200, high = 1230
输出：4
解释：在 1200 到 1230 范围内共有 4 个对称整数：1203、1212、1221 和 1230 。


提示：

1 <= low <= high <= 104
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

int maxNum = 10000;
vector<int> presum(maxNum + 1, 0);

vector<int> toDigit(int n) {
    vector<int> digits;

    while (n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    return digits;
}

void count() {
    for (int n = 1; n <= maxNum; ++n) {
        presum[n] = presum[n - 1];
        vector<int> digits = toDigit(n);
        int size = digits.size();
        if ((size & 1) == 1) {
            continue;
        }

        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size / 2; ++i) {
            sum1 += digits[i];
        }
        for (int i = size / 2; i < size; ++i) {
            sum2 += digits[i];
        }

        if (sum1 == sum2) {
            ++presum[n];
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        count();
    }
}

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        init();

        return presum[high] - presum[low - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(9, o.countSymmetricIntegers(1, 100));
    check.checkInt(4, o.countSymmetricIntegers(1200, 1230));
    check.checkInt(624, o.countSymmetricIntegers(1, 10000));
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
