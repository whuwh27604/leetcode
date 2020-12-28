/* 交替位二进制数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

示例 1:

输入: 5
输出: True
解释:
5的二进制数是: 101
示例 2:

输入: 7
输出: False
解释:
7的二进制数是: 111
示例 3:

输入: 11
输出: False
解释:
11的二进制数是: 1011
 示例 4:

输入: 10
输出: True
解释:
10的二进制数是: 1010

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-number-with-alternating-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long allOnes = (n ^ (n >> 1));
        return ((allOnes & (allOnes + 1)) == 0);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.hasAlternatingBits(5));
    check.checkBool(false, o.hasAlternatingBits(7));
    check.checkBool(false, o.hasAlternatingBits(11));
    check.checkBool(true, o.hasAlternatingBits(10));
    check.checkBool(true, o.hasAlternatingBits(1));
    check.checkBool(true, o.hasAlternatingBits(1431655765));
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
