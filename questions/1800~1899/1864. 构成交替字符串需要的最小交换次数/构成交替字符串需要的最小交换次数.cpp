/* 构成交替字符串需要的最小交换次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s ，现需要将其转化为一个 交替字符串 。请你计算并返回转化所需的 最小 字符交换次数，如果无法完成转化，返回 -1 。

交替字符串 是指：相邻字符之间不存在相等情况的字符串。例如，字符串 "010" 和 "1010" 属于交替字符串，但 "0100" 不是。

任意两个字符都可以进行交换，不必相邻 。

 

示例 1：

输入：s = "111000"
输出：1
解释：交换位置 1 和 4："111000" -> "101010" ，字符串变为交替字符串。
示例 2：

输入：s = "010"
输出：0
解释：字符串已经是交替字符串了，不需要交换。
示例 3：

输入：s = "1110"
输出：-1
 

提示：

1 <= s.length <= 1000
s[i] 的值为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int ones = 0, zeros = 0;
        count(s, ones, zeros);

        if (ones == zeros + 1) {
            return countSwaps(s, '1');
        }
        else if (zeros == ones + 1) {
            return countSwaps(s, '0');
        }
        else if (ones == zeros) {
            return min(countSwaps(s, '0'), countSwaps(s, '1'));
        }
        else {
            return -1;
        }
    }

    void count(string& s, int& ones, int& zeros) {
        for (char c : s) {
            if (c == '1') {
                ++ones;
            }
            else {
                ++zeros;
            }
        }
    }

    int countSwaps(string& s, char start) {
        int diff = 0;

        for (char c : s) {
            if (c != start) {
                ++diff;
            }

            start = start == '0' ? '1' : '0';
        }

        return diff / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minSwaps("111000"));
    check.checkInt(0, o.minSwaps("010"));
    check.checkInt(-1, o.minSwaps("1110"));
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
