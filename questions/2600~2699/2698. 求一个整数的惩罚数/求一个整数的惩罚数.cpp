/* 求一个整数的惩罚数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，请你返回 n 的 惩罚数 。

n 的 惩罚数 定义为所有满足以下条件 i 的数的平方和：

1 <= i <= n
i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i 。


示例 1：

输入：n = 10
输出：182
解释：总共有 3 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
因此，10 的惩罚数为 1 + 81 + 100 = 182
示例 2：

输入：n = 37
输出：1478
解释：总共有 4 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
- 36 ，因为 36 * 36 = 1296 ，且 1296 可以分割成 1 + 29 + 6 。
因此，37 的惩罚数为 1 + 81 + 100 + 1296 = 1478


提示：

1 <= n <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

int maxNum = 1000;
vector<int> punishmentNumbers(maxNum + 1, 0);

bool check(string& s, int size, int start, int sum, int target) {
    if (start == size && sum == target) {
        return true;
    }

    if (sum > target) {
        return false;
    }

    int num = 0;
    for (int i = start; i < size; ++i) {
        num = num * 10 + s[i] - '0';
        if (check(s, size, i + 1, sum + num, target)) {
            return true;
        }
    }

    return false;
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;

        for (int i = 1; i <= maxNum; ++i) {
            punishmentNumbers[i] = punishmentNumbers[i - 1];
            int num = i * i;
            string s = to_string(num);
            if (check(s, (int)s.size(), 0, 0, i)) {
                punishmentNumbers[i] += num;
            }
        }
    }
}

class Solution {
public:
    int punishmentNumber(int n) {
        init();

        return punishmentNumbers[n];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(182, o.punishmentNumber(10));
    check.checkInt(1478, o.punishmentNumber(37));
    check.checkInt(1, o.punishmentNumber(1));
    check.checkInt(10804657, o.punishmentNumber(1000));
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
