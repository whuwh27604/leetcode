/* 最大回文数乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 n ，返回 可表示为两个 n 位整数乘积的 最大回文整数 。因为答案可能非常大，所以返回它对 1337 取余 。

 

示例 1:

输入：n = 2
输出：987
解释：99 x 91 = 9009, 9009 % 1337 = 987
示例 2:

输入： n = 1
输出： 9
 

提示:

1 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-palindrome-product
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        int ans[9] = { 0,9,987,123,597,677,1218,877,475 };

        return ans[n];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(9, o.largestPalindrome(1));
    check.checkInt(987, o.largestPalindrome(2));
    check.checkInt(475, o.largestPalindrome(8));
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
