/* 数组中字符串的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个由字母和数字组成的字符串的 值 定义如下：

如果字符串 只 包含数字，那么值为该字符串在 10 进制下的所表示的数字。
否则，值为字符串的 长度 。
给你一个字符串数组 strs ，每个字符串都只由字母和数字组成，请你返回 strs 中字符串的 最大值 。



示例 1：

输入：strs = ["alic3","bob","3","4","00000"]
输出：5
解释：
- "alic3" 包含字母和数字，所以值为长度 5 。
- "bob" 只包含字母，所以值为长度 3 。
- "3" 只包含数字，所以值为 3 。
- "4" 只包含数字，所以值为 4 。
- "00000" 只包含数字，所以值为 0 。
所以最大的值为 5 ，是字符串 "alic3" 的值。
示例 2：

输入：strs = ["1","01","001","0001"]
输出：1
解释：
数组中所有字符串的值都是 1 ，所以我们返回 1 。


提示：

1 <= strs.length <= 100
1 <= strs[i].length <= 9
strs[i] 只包含小写英文字母和数字。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxValue = 0;

        for (string& str : strs) {
            bool letter = false;

            for (char c : str) {
                if (c < '0' || c > '9') {
                    letter = true;
                    break;
                }
            }

            maxValue = max(maxValue, letter ? (int)str.size() : stoi(str));
        }

        return maxValue;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> strs = { "alic3","bob","3","4","00000" };
    check.checkInt(5, o.maximumValue(strs));

    strs = { "1","01","001","0001" };
    check.checkInt(1, o.maximumValue(strs));
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
