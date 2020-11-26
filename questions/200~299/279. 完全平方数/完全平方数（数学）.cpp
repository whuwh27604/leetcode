/* 完全平方数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 首先，任何数最多只需要4个完全平方数相加可得。当n=4^k*(8m+7)时，需要4个数，不能再少
        if (is4k8m7(n)) {
            return 4;
        }

        int root = (int)sqrt(n);
        if (root * root == n) {  // 如果n本身是完全平方数，返回1
            return 1;
        }

        for (int i = 1; i <= root; ++i) {  // 枚举所有2个完全平方数的情况
            int left = n - i * i;
            int leftRoot = (int)sqrt(left);
            if (leftRoot * leftRoot == left) {
                return 2;
            }
        }

        return 3;  // 最后剩下的就只能是3个完全平方数的和
    }

    bool is4k8m7(int n) {
        while ((n & 0b11) == 0) {  // 4的倍数
            n >>= 2;
        }

        return (n & 0b111) == 7;  // n % 8
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numSquares(1));
    check.checkInt(2, o.numSquares(2));
    check.checkInt(3, o.numSquares(12));
    check.checkInt(2, o.numSquares(13));
    check.checkInt(4, o.numSquares(65535));
    check.checkInt(4, o.numSquares(165535));
    check.checkInt(4, o.numSquares(2147483647));
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
