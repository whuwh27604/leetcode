/* 使字符串平衡的最小交换次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，下标从 0 开始 ，且长度为偶数 n 。字符串 恰好 由 n / 2 个开括号 '[' 和 n / 2 个闭括号 ']' 组成。

只有能满足下述所有条件的字符串才能称为 平衡字符串 ：

字符串是一个空字符串，或者
字符串可以记作 AB ，其中 A 和 B 都是 平衡字符串 ，或者
字符串可以写成 [C] ，其中 C 是一个 平衡字符串 。
你可以交换 任意 两个下标所对应的括号 任意 次数。

返回使 s 变成 平衡字符串 所需要的 最小 交换次数。

 

示例 1：

输入：s = "][]["
输出：1
解释：交换下标 0 和下标 3 对应的括号，可以使字符串变成平衡字符串。
最终字符串变成 "[[]]" 。
示例 2：

输入：s = "]]][[["
输出：2
解释：执行下述操作可以使字符串变成平衡字符串：
- 交换下标 0 和下标 4 对应的括号，s = "[]][[]" 。
- 交换下标 1 和下标 5 对应的括号，s = "[[][]]" 。
最终字符串变成 "[[][]]" 。
示例 3：

输入：s = "[]"
输出：0
解释：这个字符串已经是平衡字符串。
 

提示：

n == s.length
2 <= n <= 106
n 为偶数
s[i] 为'[' 或 ']'
开括号 '[' 的数目为 n / 2 ，闭括号 ']' 的数目也是 n / 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-string-balanced
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = 0, swaps = 0;

        for (char c : s) {
            if (c == '[') {
                ++left;
            }
            else {
                ++right;
            }

            if (right > left) {
                swaps = max(swaps, right - left);
            }
        }

        return (swaps + 1) / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.minSwaps("[]"));
    check.checkInt(1, o.minSwaps("]["));
    check.checkInt(1, o.minSwaps("][]["));
    check.checkInt(2, o.minSwaps("]]][[["));
    check.checkInt(3, o.minSwaps("]]]]][[[[["));
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
