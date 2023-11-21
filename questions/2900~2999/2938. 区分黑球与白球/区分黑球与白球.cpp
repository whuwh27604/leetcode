/* 区分黑球与白球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
桌子上有 n 个球，每个球的颜色不是黑色，就是白色。

给你一个长度为 n 、下标从 0 开始的二进制字符串 s，其中 1 和 0 分别代表黑色和白色的球。

在每一步中，你可以选择两个相邻的球并交换它们。

返回「将所有黑色球都移到右侧，所有白色球都移到左侧所需的 最小步数」。



示例 1：

输入：s = "101"
输出：1
解释：我们可以按以下方式将所有黑色球移到右侧：
- 交换 s[0] 和 s[1]，s = "011"。
最开始，1 没有都在右侧，需要至少 1 步将其移到右侧。
示例 2：

输入：s = "100"
输出：2
解释：我们可以按以下方式将所有黑色球移到右侧：
- 交换 s[0] 和 s[1]，s = "010"。
- 交换 s[1] 和 s[2]，s = "001"。
可以证明所需的最小步数为 2 。
示例 3：

输入：s = "0111"
输出：0
解释：所有黑色球都已经在右侧。


提示：

1 <= n == s.length <= 105
s[i] 不是 '0'，就是 '1'。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int size = s.size(), white = 0;

        for (int i = 0; i < size; ++i) {
            if (s[i] == '0') {
                steps += ((long long)i - white++);
            }
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(1, o.minimumSteps("101"));
    check.checkLongLong(2, o.minimumSteps("100"));
    check.checkLongLong(0, o.minimumSteps("0111"));
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
