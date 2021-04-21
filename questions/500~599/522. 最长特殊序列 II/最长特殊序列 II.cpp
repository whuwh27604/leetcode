/* 最长特殊序列 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。

子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。

输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。

 

示例：

输入: "aba", "cdc", "eae"
输出: 3
 

提示：

所有给定的字符串长度不会超过 10 。
给定字符串列表的长度将在 [2, 50 ] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-uncommon-subsequence-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        vector<unordered_map<string, int>> strings(11);
        classify(strs, strings);  // 先按照字符串长度分类并去重

        for (int len = 10; len >= 0; --len) {  // 从最长的开始查找，一旦存在LUS，就不用再找更短的了
            if (LUSExist(strings, len)) {
                return len;
            }
        }

        return -1;
    }

    void classify(vector<string>& strs, vector<unordered_map<string, int>>& strings) {
        for (string& str : strs) {
            ++strings[str.size()][str];
        }
    }

    bool LUSExist(vector<unordered_map<string, int>>& strings, int len) {
        for (auto iter = strings[len].begin(); iter != strings[len].end(); ++iter) {
            if (iter->second == 1 && !isSubSeq(iter->first, strings, len)) {
                return true;  // 某个字符串出现超过1次，那么它肯定不是LUS。检查它是不是某个比它长的字符串的子序列，如果不是的，那么它就是LUS了。
            }
        }

        return false;
    }

    bool isSubSeq(const string& s, vector<unordered_map<string, int>>& strings, int len) {
        for (int i = len + 1; i < 11; ++i) {
            if (isSubSeq(s, strings[i])) {
                return true;
            }
        }

        return false;
    }

    bool isSubSeq(const string& s, unordered_map<string, int>& strings) {
        for (auto iter = strings.begin(); iter != strings.end(); ++iter) {
            if (isSubSeq(s, iter->first)) {
                return true;
            }
        }

        return false;
    }

    bool isSubSeq(const string& s1, const string& s2) {
        int i = -1, size = s2.size();

        for (char c : s1) {
            for (i += 1; i < size && s2[i] != c; ++i) {}
            if (i == size) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> strs = { "aba","cdc","eae" };
    check.checkInt(3, o.findLUSlength(strs));

    strs = { "aaa","aaa","aa" };
    check.checkInt(-1, o.findLUSlength(strs));

    strs = { "aabbcc", "aabbcc","cb","abc" };
    check.checkInt(2, o.findLUSlength(strs));

    strs = { "aaa","acb" };
    check.checkInt(3, o.findLUSlength(strs));
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
