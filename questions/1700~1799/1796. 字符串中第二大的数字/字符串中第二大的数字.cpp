/* 字符串中第二大的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个混合字符串 s ，请你返回 s 中 第二大 的数字，如果不存在第二大的数字，请你返回 -1 。

混合字符串 由小写英文字母和数字组成。

 

示例 1：

输入：s = "dfa12321afd"
输出：2
解释：出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
示例 2：

输入：s = "abc1111"
输出：-1
解释：出现在 s 中的数字只包含 [1] 。没有第二大的数字。
 

提示：

1 <= s.length <= 500
s 只包含小写英文字母和（或）数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-largest-digit-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                int num = c - '0';
                if (num > first) {
                    second = first;
                    first = num;
                }
                else if (num > second && num < first) {
                    second = num;
                }
            }
        }

        return second;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.secondHighest("dfa12321afd"));
    check.checkInt(-1, o.secondHighest("abc1111"));
    check.checkInt(-1, o.secondHighest("z"));
    check.checkInt(0, o.secondHighest("0111"));
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
