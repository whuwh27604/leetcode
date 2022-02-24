/* 找到和为给定整数的三个连续整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 num ，请你返回三个连续的整数，它们的 和 为 num 。如果 num 无法被表示成三个连续整数的和，请你返回一个 空 数组。

 

示例 1：

输入：num = 33
输出：[10,11,12]
解释：33 可以表示为 10 + 11 + 12 = 33 。
10, 11, 12 是 3 个连续整数，所以返回 [10, 11, 12] 。
示例 2：

输入：num = 4
输出：[]
解释：没有办法将 4 表示成 3 个连续整数的和。
 

提示：

0 <= num <= 1015

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 == 0) {
            num /= 3;
            return { num - 1, num, num + 1 };
        }

        return {};
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<long long> actual = o.sumOfThree(33);
    vector<long long> expected = { 10,11,12 };
    check.checkLongLongVector(expected, actual);

    actual = o.sumOfThree(4);
    expected = {  };
    check.checkLongLongVector(expected, actual);

    actual = o.sumOfThree(0);
    expected = { -1,0,1 };
    check.checkLongLongVector(expected, actual);
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
