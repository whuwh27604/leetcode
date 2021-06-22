/* 字符串的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;

        sort(s.begin(), s.end());

        do {
            ans.push_back(s);
        } while (next(s));

        return ans;
    }

    bool next(string& s) {
        int i, j, size = s.size();

        for (i = size - 2; i >= 0 && s[i] >= s[i + 1]; --i) {}

        if (i == -1) {
            return false;
        }

        for (j = size - 1; s[j] <= s[i]; --j) {}

        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.permutation("a");
    vector<string> expected = { "a" };
    check.checkStringVector(expected, actual);

    actual = o.permutation("ab");
    expected = { "ab","ba" };
    check.checkStringVector(expected, actual);

    actual = o.permutation("aa");
    expected = { "aa" };
    check.checkStringVector(expected, actual);

    actual = o.permutation("abc");
    expected = { "abc","acb","bac","bca","cab","cba" };
    check.checkStringVector(expected, actual);
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
