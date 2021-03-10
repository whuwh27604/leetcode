/* 检查二进制字符串字段.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s ，该字符串 不含前导零 。

如果 s 最多包含 一个由连续的 '1' 组成的字段 ，返回 true​​​ 。否则，返回 false 。

 

示例 1：

输入：s = "1001"
输出：false
解释：字符串中的 1 没有形成一个连续字段。
示例 2：

输入：s = "110"
输出：true
 

提示：

1 <= s.length <= 100
s[i]​​​​ 为 '0' 或 '1'
s[0] 为 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool hasZero = false;

        for (char c : s) {
            if (c == '1') {
                if (hasZero) {
                    return false;
                }
            }
            else {
                hasZero = true;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(false, o.checkOnesSegment("1001"));
    check.checkBool(true, o.checkOnesSegment("110"));
    check.checkBool(true, o.checkOnesSegment("1"));
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
