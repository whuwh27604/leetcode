/* 平方数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。

示例1:

输入: 5
输出: True
解释: 1 * 1 + 2 * 2 = 5
 

示例2:

输入: 3
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-square-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int root = (int)sqrt(c);
        for (int a = 0; a <= root; a++) {
            int squareB = (c - a * a);
            int b = (int)sqrt(squareB);
            if ((b * b) == squareB) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.judgeSquareSum(5));
    check.checkBool(true, o.judgeSquareSum(0));
    check.checkBool(true, o.judgeSquareSum(1));
    check.checkBool(true, o.judgeSquareSum(2));
    check.checkBool(false, o.judgeSquareSum(3));
    check.checkBool(true, o.judgeSquareSum(4));
    check.checkBool(false, o.judgeSquareSum(6));
    check.checkBool(false, o.judgeSquareSum(7));
    check.checkBool(true, o.judgeSquareSum(8));
    check.checkBool(true, o.judgeSquareSum(9));
    check.checkBool(true, o.judgeSquareSum(10));
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
