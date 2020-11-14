/* 整数替换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 n，你可以做如下操作：

1. 如果 n 是偶数，则用 n / 2替换 n。
2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
n 变为 1 所需的最小替换次数是多少？

示例 1:

输入:
8

输出:
3

解释:
8 -> 4 -> 2 -> 1
示例 2:

输入:
7

输出:
4

解释:
7 -> 8 -> 4 -> 2 -> 1
或
7 -> 6 -> 3 -> 2 -> 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        return llongReplacement(n);
    }

    int llongReplacement(long long n) {
        if (n < 3) {
            return (int)(n - 1);
        }

        if (n % 2 == 0) {
            return llongReplacement(n / 2) + 1;
        }

        return min(llongReplacement(n - 1), llongReplacement(n + 1)) + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.integerReplacement(1));
    check.checkInt(1, o.integerReplacement(2));
    check.checkInt(2, o.integerReplacement(3));
    check.checkInt(2, o.integerReplacement(4));
    check.checkInt(3, o.integerReplacement(5));
    check.checkInt(4, o.integerReplacement(7));
    check.checkInt(3, o.integerReplacement(8));
    check.checkInt(32, o.integerReplacement(INT_MAX));
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
