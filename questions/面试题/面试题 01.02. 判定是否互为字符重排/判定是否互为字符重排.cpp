/* 判定是否互为字符重排.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false
说明：

0 <= len(s1) <= 100
0 <= len(s2) <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-permutation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);

        count(s1, cnt1);
        count(s2, cnt2);

        return cnt1 == cnt2;
    }

    void count(string& s, vector<int>& cnt) {
        for (char c : s) {
            ++cnt[c - 'a'];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.CheckPermutation("abc", "bca"));
    check.checkBool(true, o.CheckPermutation("", ""));
    check.checkBool(false, o.CheckPermutation("abc", "bad"));
    check.checkBool(false, o.CheckPermutation("abc", ""));
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
