/* 最小和分割.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 num ，请你将它分割成两个非负整数 num1 和 num2 ，满足：

num1 和 num2 直接连起来，得到 num 各数位的一个排列。
换句话说，num1 和 num2 中所有数字出现的次数之和等于 num 中所有数字出现的次数。
num1 和 num2 可以包含前导 0 。
请你返回 num1 和 num2 可以得到的和的 最小 值。

注意：

num 保证没有前导 0 。
num1 和 num2 中数位顺序可以与 num 中数位顺序不同。


示例 1：

输入：num = 4325
输出：59
解释：我们可以将 4325 分割成 num1 = 24 和 num2 = 35 ，和为 59 ，59 是最小和。
示例 2：

输入：num = 687
输出：75
解释：我们可以将 687 分割成 num1 = 68 和 num2 = 7 ，和为最优值 75 。


提示：

10 <= num <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        int size = s.size();
        if ((size & 1) == 1) {
            s.push_back('0');
            size += 1;
        }

        sort(s.begin(), s.end());
        string s1, s2;

        for (int i = 0; i < size; i += 2) {
            s1.push_back(s[i]);
            s2.push_back(s[i + 1]);
        }

        return stoi(s1) + stoi(s2);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(59, o.splitNum(4325));
    check.checkInt(75, o.splitNum(687));
    check.checkInt(1, o.splitNum(10));
    check.checkInt(1, o.splitNum(100));
    check.checkInt(17, o.splitNum(980));
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
