/* 在区间范围内统计奇数数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。

 

示例 1：

输入：low = 3, high = 7
输出：3
解释：3 到 7 之间奇数数字为 [3,5,7] 。
示例 2：

输入：low = 8, high = 10
输出：1
解释：8 到 10 之间奇数数字为 [9] 。
 

提示：

0 <= low <= high <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-odd-numbers-in-an-interval-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.countOdds(3, 7));
    check.checkInt(3, o.countOdds(3, 8));
    check.checkInt(1, o.countOdds(8, 10));
    check.checkInt(2, o.countOdds(8, 11));
    check.checkInt(0, o.countOdds(8, 8));
    check.checkInt(1, o.countOdds(9, 9));
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
