/* 统计 1 显著的字符串的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s。

请你统计并返回其中 1 显著 的
子字符串
 的数量。

如果字符串中 1 的数量 大于或等于 0 的数量的 平方，则认为该字符串是一个 1 显著 的字符串 。



示例 1：

输入：s = "00011"

输出：5

解释：

1 显著的子字符串如下表所示。

i	j	s[i..j]	0 的数量	1 的数量
3	3	1	0	1
4	4	1	0	1
2	3	01	1	1
3	4	11	0	2
2	4	011	1	2
示例 2：

输入：s = "101101"

输出：16

解释：

1 不显著的子字符串如下表所示。

总共有 21 个子字符串，其中 5 个是 1 不显著字符串，因此有 16 个 1 显著子字符串。

i	j	s[i..j]	0 的数量	1 的数量
1	1	0	1	0
4	4	0	1	0
1	4	0110	2	2
0	4	10110	2	3
1	5	01101	2	3


提示：

1 <= s.length <= 4 * 104
s 仅包含字符 '0' 和 '1'。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int)s.size(), sqrtN = (int)sqrt(n);
        vector<int> indices0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                indices0.push_back(i);
            }
        }

        int total0 = (int)indices0.size();
        if (total0 == 0) {
            return n * (n + 1) / 2;
        }

        indices0.push_back(n);
        int idx0 = 0, subs = 0;

        for (int left = 0; left < n; ++left) {  // 枚举合法子串的左端点
            if (indices0[idx0] < left) {
                ++idx0;  // 维护indices0[idx0]指向left右边第一个0的位置
            }

            if (s[left] == '1') {  // cnt0 == 0的子串肯定都是合法的
                subs += (indices0[idx0] - left);
            }

            for (int cnt0 = 1; cnt0 <= sqrtN && idx0 + cnt0 <= total0; ++cnt0) {  // 枚举合法子串0的个数
                int right1 = indices0[idx0 + cnt0 - 1];  // 第cnt0个0的位置
                int right2 = indices0[idx0 + cnt0] - 1;  // 第cnt0 + 1个0的前一个位置
                int cnt1 = right1 - left + 1 - cnt0;
                if (cnt1 >= cnt0 * cnt0) {  // 1的个数已经够了，[right1, right2]都可以作为右端点
                    subs += (right2 - right1 + 1);
                }
                else {  // 1的个数不够，还要从right1开始补充1
                    int add1 = cnt0 * cnt0 - cnt1;
                    if (right2 - right1 >= add1) {
                        subs += (right2 - right1 - add1 + 1);
                    }
                }
            }
        }

        return subs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(5, o.numberOfSubstrings("00011"));
    check.checkInt(16, o.numberOfSubstrings("101101"));
    check.checkInt(221, o.numberOfSubstrings("000111011010001110110100011101101000111011010001110110100011101101"));
    check.checkInt(0, o.numberOfSubstrings("0"));
    check.checkInt(1, o.numberOfSubstrings("1"));
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
