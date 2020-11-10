/* 爬楼梯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

class Solution {
public:
    int climbStairs(int n) {
        // f(n) = f(n - 2) + f(n - 1)，不可递归调用climbStairs，否则很快就会堆栈溢出
        if ((n == 1) || (n == 2)) {
            return n;
        }

        int way1 = 1;
        int way2 = 2;
        int way3;
        for (int i = 3; i <= n; i++) {
            way3 = way1 + way2;
            way1 = way2;
            way2 = way3;
        }

        return way3;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.climbStairs(1));
    check.checkInt(2, o.climbStairs(2));
    check.checkInt(3, o.climbStairs(3));
    check.checkInt(5, o.climbStairs(4));
    check.checkInt(8, o.climbStairs(5));
    check.checkInt(1134903170, o.climbStairs(44));
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
