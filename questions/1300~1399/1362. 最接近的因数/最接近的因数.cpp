/* 最接近的因数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 num，请你找出同时满足下面全部要求的两个整数：

两数乘积等于  num + 1 或 num + 2
以绝对差进行度量，两数大小最接近
你可以按任意顺序返回这两个整数。

 

示例 1：

输入：num = 8
输出：[3,3]
解释：对于 num + 1 = 9，最接近的两个因数是 3 & 3；对于 num + 2 = 10, 最接近的两个因数是 2 & 5，因此返回 3 & 3 。
示例 2：

输入：num = 123
输出：[5,25]
示例 3：

输入：num = 999
输出：[40,25]
 

提示：

1 <= num <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closest-divisors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> Divisors1 = findClosestDivisors(num + 1);
        vector<int> Divisors2 = findClosestDivisors(num + 2);

        return Divisors1[1] - Divisors1[0] < Divisors2[1] - Divisors2[0] ? Divisors1 : Divisors2;
    }

    vector<int> findClosestDivisors(int num) {
        int root = (int)sqrt(num);

        for (int divisor1 = root; divisor1 > 1; --divisor1) {
            int divisor2 = num / divisor1;
            if (divisor1 * divisor2 == num) {
                return { divisor1, divisor2 };
            }
        }

        return { 1, num };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.closestDivisors(8);
    vector<int> expected = { 3,3 };
    check.checkIntVector(expected, actual);

    actual = o.closestDivisors(123);
    expected = { 5,25 };
    check.checkIntVector(expected, actual);

    actual = o.closestDivisors(999);
    expected = { 25,40 };
    check.checkIntVector(expected, actual);

    actual = o.closestDivisors(1);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);
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
