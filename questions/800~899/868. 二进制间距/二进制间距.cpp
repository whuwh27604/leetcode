/* 二进制间距.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 N，找到并返回 N 的二进制表示中两个连续的 1 之间的最长距离。 

如果没有两个连续的 1，返回 0 。

 

示例 1：

输入：22
输出：2
解释：
22 的二进制是 0b10110 。
在 22 的二进制表示中，有三个 1，组成两对连续的 1 。
第一对连续的 1 中，两个 1 之间的距离为 2 。
第二对连续的 1 中，两个 1 之间的距离为 1 。
答案取两个距离之中最大的，也就是 2 。
示例 2：

输入：5
输出：2
解释：
5 的二进制是 0b101 。
示例 3：

输入：6
输出：1
解释：
6 的二进制是 0b110 。
示例 4：

输入：8
输出：0
解释：
8 的二进制是 0b1000 。
在 8 的二进制表示中没有连续的 1，所以返回 0 。
 

提示：

1 <= N <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-gap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int countOne = 0, consecutiveZeros = 0, maxConsecutiveZeros = 0;

        while (N != 0) {
            int oneOrZero = (N % 2);
            if (oneOrZero == 1) {
                countOne++;
                maxConsecutiveZeros = max(maxConsecutiveZeros, consecutiveZeros);
                consecutiveZeros = 0;
            }
            else {
                if (countOne != 0) {
                    consecutiveZeros++;
                }
            }

            N /= 2;
        }

        if (countOne == 1) {
            return 0;
        }
        return (maxConsecutiveZeros + 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.binaryGap(22));
    check.checkInt(2, o.binaryGap(5));
    check.checkInt(1, o.binaryGap(6));
    check.checkInt(0, o.binaryGap(8));
    check.checkInt(0, o.binaryGap(1));
    check.checkInt(0, o.binaryGap(2));
    check.checkInt(1, o.binaryGap(3));
    check.checkInt(0, o.binaryGap(4));
    check.checkInt(1, o.binaryGap(7));
    check.checkInt(27, o.binaryGap(134217729));
    check.checkInt(7, o.binaryGap(2065));
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
