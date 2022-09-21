/* 最小偶倍数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）。
 

示例 1：

输入：n = 5
输出：10
解释：5 和 2 的最小公倍数是 10 。
示例 2：

输入：n = 6
输出：6
解释：6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
 

提示：

1 <= n <= 150

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/smallest-even-multiple
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return ((n & 1) == 0) ? n : n * 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(10, o.smallestEvenMultiple(5));
    check.checkInt(6, o.smallestEvenMultiple(6));
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
