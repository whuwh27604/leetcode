/* 将字符串翻转到单调递增.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个由 '0' 和 '1' 组成的字符串，是以一些 '0'（可能没有 '0'）后面跟着一些 '1'（也可能没有 '1'）的形式组成的，那么该字符串是单调递增的。

我们给出一个由字符 '0' 和 '1' 组成的字符串 S，我们可以将任何 '0' 翻转为 '1' 或者将 '1' 翻转为 '0'。

返回使 S 单调递增的最小翻转次数。

 

示例 1：

输入："00110"
输出：1
解释：我们翻转最后一位得到 00111.
示例 2：

输入："010110"
输出：2
解释：我们翻转得到 011111，或者是 000111。
示例 3：

输入："00011000"
输出：2
解释：我们翻转得到 00000000。
 

提示：

1 <= S.length <= 20000
S 中只包含字符 '0' 和 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flip-string-to-monotone-increasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int i, size = S.size(), minFlips = INT_MAX;
        vector<int> preSum(size, 0);

        preSum[0] = (S[0] == '1' ? 1 : 0);
        for (i = 1; i < size; ++i) {
            preSum[i] = preSum[i - 1] + (S[i] == '1' ? 1 : 0);
        }

        // 逐一检查将S转换成000...000, 000...001,000...011,...,001...111,011...111,111...111需要多少次
        for (i = 0; i < size; ++i) {
            int firstHalfTo0 = preSum[i];
            int secondHalfTo1 = (size - 1 - i) - (preSum[size - 1] - preSum[i]);
            minFlips = min(minFlips, firstHalfTo0 + secondHalfTo1);
        }

        return min(minFlips, size - preSum[size - 1]);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minFlipsMonoIncr("00110"));
    check.checkInt(2, o.minFlipsMonoIncr("010110"));
    check.checkInt(2, o.minFlipsMonoIncr("00011000"));
    check.checkInt(1, o.minFlipsMonoIncr("1110"));
    check.checkInt(0, o.minFlipsMonoIncr("0"));
    check.checkInt(0, o.minFlipsMonoIncr("1"));
    check.checkInt(0, o.minFlipsMonoIncr("01"));
    check.checkInt(1, o.minFlipsMonoIncr("10"));
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
