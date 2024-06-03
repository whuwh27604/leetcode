/* 删除星号以后字典序最小的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 。它可能包含任意数量的 '*' 字符。你的任务是删除所有的 '*' 字符。

当字符串还存在至少一个 '*' 字符时，你可以执行以下操作：

删除最左边的 '*' 字符，同时删除该星号字符左边一个字典序 最小 的字符。如果有多个字典序最小的字符，你可以删除它们中的任意一个。
请你返回删除所有 '*' 字符以后，剩余字符连接而成的
字典序最小
 的字符串。



示例 1：

输入：s = "aaba*"

输出："aab"

解释：

删除 '*' 号和它左边的其中一个 'a' 字符。如果我们选择删除 s[3] ，s 字典序最小。

示例 2：

输入：s = "abc"

输出："abc"

解释：

字符串中没有 '*' 字符。



提示：

1 <= s.length <= 105
s 只含有小写英文字母和 '*' 字符。
输入保证操作可以删除所有的 '*' 字符。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string clearStars(string s) {
        map<char, vector<int>> indices;
        int size = (int)s.size(), count = 0;

        for (int i = 0; i < size; ++i) {
            if (s[i] == '*') {
                ++count;
                int idx = indices.begin()->second.back();
                s[idx] = '*';
                indices.begin()->second.pop_back();
                if (indices.begin()->second.empty()) {
                    indices.erase(indices.begin());
                }
            }
            else {
                indices[s[i]].push_back(i);
            }
        }

        string ans(size - 2 * count, 0);

        for (int i = 0, j = 0; i < size; ++i) {
            if (s[i] != '*') {
                ans[j++] = s[i];
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("aab", o.clearStars("aaba*"));
    check.checkString("abc", o.clearStars("abc"));
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
