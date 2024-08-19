/* 统计满足 K 约束的子字符串数量 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 二进制 字符串 s 和一个整数 k。

如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：

字符串中 0 的数量最多为 k。
字符串中 1 的数量最多为 k。
返回一个整数，表示 s 的所有满足 k 约束 的
子字符串
的数量。



示例 1：

输入：s = "10101", k = 1

输出：12

解释：

s 的所有子字符串中，除了 "1010"、"10101" 和 "0101" 外，其余子字符串都满足 k 约束。

示例 2：

输入：s = "1010101", k = 2

输出：25

解释：

s 的所有子字符串中，除了长度大于 5 的子字符串外，其余子字符串都满足 k 约束。

示例 3：

输入：s = "11111", k = 1

输出：15

解释：

s 的所有子字符串都满足 k 约束。



提示：

1 <= s.length <= 50
1 <= k <= s.length
s[i] 是 '0' 或 '1'。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int size = (int)s.size(), left = 0, one = 0, zero = 0, count = 0;

        for (int right = 0; right < size; ++right) {
            s[right] == '0' ? ++zero : ++one;

            while (zero > k && one > k) {
                s[left++] == '0' ? --zero : --one;
            }

            count += (right - left + 1);
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(12, o.countKConstraintSubstrings("10101", 1));
    check.checkInt(25, o.countKConstraintSubstrings("1010101", 2));
    check.checkInt(15, o.countKConstraintSubstrings("11111", 1));
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
