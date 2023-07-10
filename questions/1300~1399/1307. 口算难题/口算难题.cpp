/* 口算难题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个方程，左边用 words 表示，右边用 result 表示。

你需要根据以下规则检查方程是否可解：

每个字符都会被解码成一位数字（0 - 9）。
每对不同的字符必须映射到不同的数字。
每个 words[i] 和 result 都会被解码成一个没有前导零的数字。
左侧数字之和（words）等于右侧数字（result）。
如果方程可解，返回 True，否则返回 False。



示例 1：

输入：words = ["SEND","MORE"], result = "MONEY"
输出：true
解释：映射 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
所以 "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
示例 2：

输入：words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
输出：true
解释：映射 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
所以 "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
示例 3：

输入：words = ["THIS","IS","TOO"], result = "FUNNY"
输出：true
示例 4：

输入：words = ["LEET","CODE"], result = "POINT"
输出：false


提示：

2 <= words.length <= 5
1 <= words[i].length, results.length <= 7
words[i], result 只含有大写英文字母
表达式中使用的不同字符数最大为 10
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        init(words, result);

        return DFS(0, 0);
    }

    void init(vector<string>& words, string& result) {
        coefficients.clear();
        letters.clear();
        isLead.clear();
        rangeLow.clear();
        rangeHigh.clear();
        used.clear();

        isLead.resize(127, false);
        getCoefficients(words, result);
        n = coefficients.size();
        rangeLow.resize(n + 1, 0);
        rangeHigh.resize(n + 1, 0);
        estimateRange();
        used.resize(10, false);
    }

    void getCoefficients(vector<string>& words, string& result) {
        vector<int> count(127, 0);
        vector<pair<int, int>> coeff;

        for (auto& word : words) {
            int val = 1;
            for (int i = word.size() - 1; i >= 0; --i) {
                count[word[i]] += val;
                val *= 10;
            }
            if (word.size() > 1) {
                isLead[word[0]] = true;
            }
        }

        int val = 1;
        for (int i = result.size() - 1; i >= 0; --i) {
            count[result[i]] -= val;
            val *= 10;
        }
        if (result.size() > 1) {
            isLead[result[0]] = true;
        }

        for (char c = 'A'; c <= 'Z'; ++c) {
            if (count[c] != 0) {
                coeff.push_back({ abs(count[c]),c });
            }
        }

        sort(coeff.begin(), coeff.end());

        for (int i = coeff.size() - 1; i >= 0; --i) {  // 按照系数的绝对值排序，大的排前面
            char c = coeff[i].second;
            coefficients.push_back(count[c]);
            letters.push_back(c);
        }
    }

    void estimateRange() {
        for (int i = 1; i < n; ++i) {
            rangeLow[i] = estimate(i, false);
            rangeHigh[i] = estimate(i, true);
        }
    }

    int estimate(int index, bool isMax) {
        // 估计最小值时，从高位到低位，正数优先选小的，负数优先选大的；估计最大值时，从高位到低位，正数优先选大的，负数优先选小的
        int sum = 0, pos = (isMax ? 9 : 0), neg = (isMax ? 0 : 9);

        for (int i = index; i < n; ++i) {
            if (coefficients[i] > 0) {
                sum += (coefficients[i] * pos++);
            }
            else {
                sum += (coefficients[i] * neg--);
            }
        }

        return sum;
    }

    bool DFS(int index, int sum) {
        if (index == n) {
            return sum == 0;
        }

        for (int d = isLead[letters[index]] ? 1 : 0; d < 10; ++d) {
            if (!used[d]) {
                int tmp = sum + coefficients[index] * d;
                if (-tmp >= rangeLow[index + 1] && -tmp <= rangeHigh[index + 1]) {
                    used[d] = true;

                    if (DFS(index + 1, tmp)) {
                        return true;
                    }

                    used[d] = false;
                }
            }
        }

        return false;
    }

private:
    vector<int> coefficients;
    vector<char> letters;
    vector<bool> isLead;
    vector<int> rangeLow;
    vector<int> rangeHigh;
    vector<bool> used;
    int n;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "SEND","MORE" };
    check.checkBool(true, o.isSolvable(words, "MONEY"));

    words = { "SIX","SEVEN","SEVEN" };
    check.checkBool(true, o.isSolvable(words, "TWENTY"));

    words = { "THIS","IS","TOO" };
    check.checkBool(true, o.isSolvable(words, "FUNNY"));

    words = { "HOPE","THIS","HELPS","OTHER" };
    check.checkBool(true, o.isSolvable(words, "PEOPLE"));

    words = { "THAT","IS","WHY","IT","IS" };
    check.checkBool(true, o.isSolvable(words, "TRUE"));

    words = { "A","B" };
    check.checkBool(true, o.isSolvable(words, "A"));

    words = { "LEET","CODE" };
    check.checkBool(false, o.isSolvable(words, "POINT"));
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
