/* 优美的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N) 满足如下两个条件中的一个，我们就称这个数组为一个优美的排列。条件：

第 i 位的数字能被 i 整除
i 能被第 i 位上的数字整除
现在给定一个整数 N，请问可以构造多少个优美的排列？

示例1:

输入: 2
输出: 2
解释:

第 1 个优美的排列是 [1, 2]:
  第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
  第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除

第 2 个优美的排列是 [2, 1]:
  第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
  第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
说明:

N 是一个正整数，并且不会超过15。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-arrangement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        int ans = 0;

        DFS((1 << n) - 1, 1, n, ans);

        return ans;
    }

    void DFS(int choseable, int index, int n, int& ans) {
        if (index > n) {
            ++ans;
            return;
        }

        for (int bit = (1 << (n - 1)), num = 1; bit != 0; bit >>= 1, ++num) {
            if ((bit & choseable) != 0 && (num % index == 0 || index % num == 0)) {
                DFS(choseable ^ bit, index + 1, n, ans);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.countArrangement(1));
    check.checkInt(2, o.countArrangement(2));
    check.checkInt(3, o.countArrangement(3));
    check.checkInt(8, o.countArrangement(4));
    check.checkInt(10, o.countArrangement(5));
    check.checkInt(36, o.countArrangement(6));
    check.checkInt(41, o.countArrangement(7));
    check.checkInt(132, o.countArrangement(8));
    check.checkInt(250, o.countArrangement(9));
    check.checkInt(700, o.countArrangement(10));
    check.checkInt(750, o.countArrangement(11));
    check.checkInt(4010, o.countArrangement(12));
    check.checkInt(4237, o.countArrangement(13));
    check.checkInt(10680, o.countArrangement(14));
    check.checkInt(24679, o.countArrangement(15));
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
