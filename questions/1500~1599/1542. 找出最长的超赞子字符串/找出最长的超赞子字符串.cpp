/* 找出最长的超赞子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 。请返回 s 中最长的 超赞子字符串 的长度。

「超赞子字符串」需满足满足下述两个条件：

该字符串是 s 的一个非空子字符串
进行任意次数的字符交换后，该字符串可以变成一个回文字符串
 

示例 1：

输入：s = "3242415"
输出：5
解释："24241" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "24142"
示例 2：

输入：s = "12345678"
输出：1
示例 3：

输入：s = "213123"
输出：6
解释："213123" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "231132"
示例 4：

输入：s = "00"
输出：2
 

提示：

1 <= s.length <= 10^5
s 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-longest-awesome-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int i, size = s.size(), maxAwesome = 0, sum = 0, maxBit = (2 << 10);
        vector<int> sums(maxBit, INT_MIN);
        sums[0] = -1;

        for (i = 0; i < size; ++i) {
            sum ^= (1 << (s[i] - '0'));

            if (sums[sum] == INT_MIN) {  // sum第一次出现
                sums[sum] = i;
            }
            else {
                maxAwesome = max(maxAwesome, i - sums[sum]);  // i和sums[sum]之间所有字符都是偶数个，可以形成回文
            }

            for (int bit = 1; bit < maxBit; bit <<= 1) {  // 尝试有一个字符为奇数，也可以构成回文
                if (sums[sum ^ bit] != INT_MIN) {
                    maxAwesome = max(maxAwesome, i - sums[sum ^ bit]);
                }
            }
        }

        return maxAwesome;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.longestAwesome("3242415"));
    check.checkInt(1, o.longestAwesome("12345678"));
    check.checkInt(6, o.longestAwesome("213123"));
    check.checkInt(2, o.longestAwesome("00"));
    check.checkInt(1, o.longestAwesome("9"));
    check.checkInt(3, o.longestAwesome("112"));
    check.checkInt(19, o.longestAwesome("0123456789012345678012345670123456012345012340123012010"));
    check.checkInt(459, o.longestAwesome("012345678901234567801234567012345601234501234012301201001234567890123456780123456701234560123450123401230120100123456789012345678012345670123456012345012340123012010012345678901234567801234567012345601234501234012301201001234567890123456780123456701234560123450123401230120100123456789012345678012345670123456012345012340123012010012345678901234567801234567012345601234501234012301201001234567890123456780123456701234560123450123401230120100123456789012345678012345670123456012345012340123012010"));
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
