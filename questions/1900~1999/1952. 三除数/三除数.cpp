/* 三除数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 。如果 n 恰好有三个正除数 ，返回 true ；否则，返回 false 。

如果存在整数 k ，满足 n = k * m ，那么整数 m 就是 n 的一个 除数 。

 

示例 1：

输入：n = 2
输出：false
解释：2 只有两个除数：1 和 2 。
示例 2：

输入：n = 4
输出：true
解释：4 有三个除数：1、2 和 4 。
 

提示：

1 <= n <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-divisors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isThree(int n) {
        unordered_set<int> threes = { 4,9,25,49,121,169,289,361,529,841,961,1369,1681,1849,2209,2809,3481,3721,4489,5041,5329,6241,6889,7921,9409 };

        return threes.count(n) != 0;  // 只能是100以内质数的平方
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(false, o.isThree(1));
    check.checkBool(false, o.isThree(2));
    check.checkBool(false, o.isThree(16));
    check.checkBool(true, o.isThree(4));
    check.checkBool(true, o.isThree(97 * 97));
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
