/* 不含连续1的非负整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 连续的1 的个数。

示例 1:

输入: 5
输出: 5
解释:
下面是带有相应二进制表示的非负整数<= 5：
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。
说明: 1 <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        if (num == 1 || num == 2) {
            return num + 1;
        }
        else if (num == 3) {
            return 3;
        }

        vector<int> binary = toBinary(num);
        return getIntegersByBits(binary.size()) + getIntegersLeftmostBit(binary);
    }

    vector<int> toBinary(int num) {
        vector<int> binary;

        while (num != 0) {
            binary.push_back(num & 1);
            num >>= 1;
        }

        reverse(binary.begin(), binary.end());
        return binary;
    }

    int getIntegersByBits(int size) {
        int total = 3;
        vector<int> dp(size);
        dp[1] = dp[2] = 1;

        for (int i = 3; i < size; ++i) {
            // 每一次，前两位固定是10，从第三位开始，可以选1或者0，如果选1，就是dp[i - 2]的个数；如果选0，则可以在前面加一个1，所以等价于dp[i - 1]的个数
            dp[i] = dp[i - 2] + dp[i - 1];
            total += dp[i];
        }

        return total;
    }

    void getSequenceNums(int size, vector<int>& dp) {
        int i, end0 = 1, end1 = 1;

        dp[0] = 1, dp[1] = 2;  // 剩下0个位置也是一种选择
        for (i = 2; i < size; ++i) {
            int tmp = end0;  // 0后面可以接0和1，1后面只能接0
            end0 += end1;
            end1 = tmp;
            dp[i] = end0 + end1;
        }
    }

    int getIntegersLeftmostBit(vector<int>& binary) {
        int i, size = binary.size(), integers = 0;
        bool mustBeZero = true;  // 最高位是1，接下来一位必须是0

        vector<int> dp(size - 1);  // 前两位固定是10，最多只需要算到size-2的个数
        getSequenceNums(size - 1, dp);

        for (i = 1; i < size; ++i) {
            if (binary[i] == 0) {
                mustBeZero = false;  // 已经满足必须为0的条件，接下来不必为0
            }
            else {
                integers += dp[size - i - 1];  // 当前n[i]是1，那么选择0，剩下的位数所有非连续1的序列都满足要求
                if (mustBeZero) {
                    return integers;  // 如果只能选择0，那么已经找寻了所有的可能
                }
                else {
                    mustBeZero = true;  // 如果不是必须为0，那么可以选择1，然后继续往右寻找。此时下一位必须为0。
                }
            }
        }

        return integers + 1;  // 如果没有在循环中返回，说明n本身是一个满足要求的数
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.findIntegers(1));
    check.checkInt(3, o.findIntegers(2));
    check.checkInt(3, o.findIntegers(3));
    check.checkInt(4, o.findIntegers(4));
    check.checkInt(5, o.findIntegers(5));
    check.checkInt(5, o.findIntegers(6));
    check.checkInt(5, o.findIntegers(7));
    check.checkInt(6, o.findIntegers(8));
    check.checkInt(7, o.findIntegers(9));
    check.checkInt(8, o.findIntegers(10));
    check.checkInt(8, o.findIntegers(11));
    check.checkInt(8, o.findIntegers(12));
    check.checkInt(8, o.findIntegers(13));
    check.checkInt(8, o.findIntegers(14));
    check.checkInt(8, o.findIntegers(15));
    check.checkInt(9, o.findIntegers(16));
    check.checkInt(10, o.findIntegers(17));
    check.checkInt(22, o.findIntegers(64));
    check.checkInt(514229, o.findIntegers(100000000));
    check.checkInt(2178309, o.findIntegers(1000000000));
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
