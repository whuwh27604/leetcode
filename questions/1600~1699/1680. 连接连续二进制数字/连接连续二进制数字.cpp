/* 连接连续二进制数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，请你将 1 到 n 的二进制表示连接起来，并返回连接结果对应的 十进制 数字对 109 + 7 取余的结果。

 

示例 1：

输入：n = 1
输出：1
解释：二进制的 "1" 对应着十进制的 1 。
示例 2：

输入：n = 3
输出：27
解释：二进制下，1，2 和 3 分别对应 "1" ，"10" 和 "11" 。
将它们依次连接，我们得到 "11011" ，对应着十进制的 27 。
示例 3：

输入：n = 12
输出：505379714
解释：连接结果为 "1101110010111011110001001101010111100" 。
对应的十进制数字为 118505380540 。
对 109 + 7 取余后，结果为 505379714 。
 

提示：

1 <= n <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/concatenation-of-consecutive-binary-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        long long num = 0;
        int shift = 0, mod = 1000000007;

        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {  // 每一次，当i从111...变为1000...时，i的二进制位数增加1
                ++shift;
            }

            num = ((num << shift) + i) % mod;
        }

        return (int)num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.concatenatedBinary(1));
    check.checkInt(6, o.concatenatedBinary(2));
    check.checkInt(27, o.concatenatedBinary(3));
    check.checkInt(505379714, o.concatenatedBinary(12));
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
