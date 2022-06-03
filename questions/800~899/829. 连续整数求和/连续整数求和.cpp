/* 连续整数求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。 

 

示例 1:

输入: n = 5
输出: 2
解释: 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
示例 2:

输入: n = 9
输出: 3
解释: 9 = 4 + 5 = 2 + 3 + 4
示例 3:

输入: n = 15
输出: 4
解释: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 

提示:

1 <= n <= 109​​​​​​​

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/consecutive-numbers-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // a + (a + 1) + (a + 2) + ... + (a + k - 1) = n
        // (2a + k - 1) * k / 2 = n
        // a = (n - (k - 1) * k / 2) / k
        int count = 1, maxK = (int)sqrt(2 * n);

        for (int k = 2; k <= maxK; ++k) {
            if ((n - (k - 1) * k / 2) % k == 0) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.consecutiveNumbersSum(1));
    check.checkInt(1, o.consecutiveNumbersSum(2));
    check.checkInt(2, o.consecutiveNumbersSum(3));
    check.checkInt(1, o.consecutiveNumbersSum(4));
    check.checkInt(2, o.consecutiveNumbersSum(5));
    check.checkInt(2, o.consecutiveNumbersSum(6));
    check.checkInt(2, o.consecutiveNumbersSum(7));
    check.checkInt(1, o.consecutiveNumbersSum(8));
    check.checkInt(3, o.consecutiveNumbersSum(9));
    check.checkInt(4, o.consecutiveNumbersSum(15));
    check.checkInt(3, o.consecutiveNumbersSum(100));
    check.checkInt(10, o.consecutiveNumbersSum(1000000000));
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
