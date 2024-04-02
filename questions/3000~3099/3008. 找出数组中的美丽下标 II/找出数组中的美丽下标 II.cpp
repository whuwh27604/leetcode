/* 找出数组中的美丽下标 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s 、字符串 a 、字符串 b 和一个整数 k 。

如果下标 i 满足以下条件，则认为它是一个 美丽下标 ：

0 <= i <= s.length - a.length
s[i..(i + a.length - 1)] == a
存在下标 j 使得：
0 <= j <= s.length - b.length
s[j..(j + b.length - 1)] == b
|j - i| <= k
以数组形式按 从小到大排序 返回美丽下标。



示例 1：

输入：s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15
输出：[16,33]
解释：存在 2 个美丽下标：[16,33]。
- 下标 16 是美丽下标，因为 s[16..17] == "my" ，且存在下标 4 ，满足 s[4..11] == "squirrel" 且 |16 - 4| <= 15 。
- 下标 33 是美丽下标，因为 s[33..34] == "my" ，且存在下标 18 ，满足 s[18..25] == "squirrel" 且 |33 - 18| <= 15 。
因此返回 [16,33] 作为结果。
示例 2：

输入：s = "abcd", a = "a", b = "a", k = 4
输出：[0]
解释：存在 1 个美丽下标：[0]。
- 下标 0 是美丽下标，因为 s[0..0] == "a" ，且存在下标 0 ，满足 s[0..0] == "a" 且 |0 - 0| <= 4 。
因此返回 [0] 作为结果。


提示：

1 <= k <= s.length <= 5 * 105
1 <= a.length, b.length <= 5 * 105
s、a、和 b 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class KMP {
public:
    KMP(string& patt) {
        pattern = patt;
        size = pattern.size();
        fail.resize(size, 0);
        initFail();
    }

    void initFail() {
        for (int i = 1; i < size; ++i) {  // KMP算法求fail数组
            int j = fail[i - 1];

            while (j != 0 && pattern[j] != pattern[i]) {
                j = fail[j - 1];
            }

            if (pattern[j] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
    }

    int search(string& text) {  // 在text中查找pattern，返回第一个匹配的位置
        int len = text.size(), i = 0, j = 0;

        for (; i < len; ++i) {
            while (j != 0 && pattern[j] != text[i]) {
                j = fail[j - 1];
            }

            if (pattern[j] == text[i]) {
                ++j;
            }

            if (j == size) {
                return i - size + 1;
            }
        }

        return len;
    }

    int searchCount(string& text) {  // 在text中查找pattern，返回匹配的个数
        int len = text.size(), i = 0, j = 0, count = 0;

        for (; i < len; ++i) {
            while (j != 0 && pattern[j] != text[i]) {
                j = fail[j - 1];
            }

            if (pattern[j] == text[i]) {
                ++j;
            }

            if (j == size) {
                ++count;
                j = fail[j - 1];
            }
        }

        return count;
    }

    vector<int> searchAll(string& text) {  // 在text中查找pattern，返回所有匹配的下标
        int len = text.size(), i = 0, j = 0;
        vector<int> indices;

        for (; i < len; ++i) {
            while (j != 0 && pattern[j] != text[i]) {
                j = fail[j - 1];
            }

            if (pattern[j] == text[i]) {
                ++j;
            }

            if (j == size) {
                indices.push_back(i - size + 1);
                j = fail[j - 1];
            }
        }

        return indices;
    }

    vector<int> fail;  // fail[i]表示pattern[0, i - 1]的最长公共前后缀
    string pattern;
    int size;
};

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        KMP kmpA(a), kmpB(b);
        vector<int> indices1 = kmpA.searchAll(s);
        vector<int> indices2 = kmpB.searchAll(s);

        int j = 0, size1 = indices1.size(), size2 = indices2.size();
        vector<int> ans;

        for (int i = 0; i < size1; ++i) {
            while (j < size2 && indices1[i] - indices2[j] > k) {
                ++j;
            }

            if (j < size2 && abs(indices1[i] - indices2[j]) <= k) {
                ans.push_back(indices1[i]);
            }
        }

        return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<int> actual = o.beautifulIndices("isawsquirrelnearmysquirrelhouseohmy", "my", "squirrel", 15);
    vector<int> expected = { 16,33 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulIndices("abcd", "a", "a", 4);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulIndices("frkxslnnn", "rkxsl", "n", 2);
    expected = {  };
    check.checkIntVector(expected, actual);
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
