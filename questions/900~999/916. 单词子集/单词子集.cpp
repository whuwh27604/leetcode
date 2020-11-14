/* 单词子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们给出两个单词数组 A 和 B。每个单词都是一串小写字母。

现在，如果 b 中的每个字母都出现在 a 中，包括重复出现的字母，那么称单词 b 是单词 a 的子集。 例如，“wrr” 是 “warrior” 的子集，但不是 “world” 的子集。

如果对 B 中的每一个单词 b，b 都是 a 的子集，那么我们称 A 中的单词 a 是通用的。

你可以按任意顺序以列表形式返回 A 中所有的通用单词。

 

示例 1：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
输出：["facebook","google","leetcode"]
示例 2：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
输出：["apple","google","leetcode"]
示例 3：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
输出：["facebook","google"]
示例 4：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
输出：["google","leetcode"]
示例 5：

输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
输出：["facebook","leetcode"]
 

提示：

1 <= A.length, B.length <= 10000
1 <= A[i].length, B[i].length <= 10
A[i] 和 B[i] 只由小写字母组成。
A[i] 中所有的单词都是独一无二的，也就是说不存在 i != j 使得 A[i] == A[j]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> universals;
        vector<int> merged(26, 0);

        for (string& wordB : B) {
            vector<int> lettersB(26, 0);
            countLetters(wordB, lettersB);
            mergeB(merged, lettersB);
        }

        for (string& wordA : A) {
            vector<int> lettersA(26, 0);
            countLetters(wordA, lettersA);

            if (noless(lettersA, merged)) {
                universals.push_back(wordA);
            }
        }

        return universals;
    }

    void countLetters(string& word, vector<int>& letters) {
        for (char c : word) {
            ++letters[c - 'a'];
        }
    }

    void mergeB(vector<int>& merged, vector<int>& lettersB) {
        for (int i = 0; i < 26; ++i) {
            if (lettersB[i] > merged[i]) {
                merged[i] = lettersB[i];
            }
        }
    }

    bool noless(vector<int>& lettersA, vector<int>& merged) {
        for (int i = 0; i < 26; ++i) {
            if (lettersA[i] < merged[i]) {
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

    vector<string> A = { "amazon","apple","facebook","google","leetcode" };
    vector<string> B = { "e","o" };
    vector<string> actual = o.wordSubsets(A, B);
    vector<string> expected = { "facebook","google","leetcode" };
    check.checkStringVector(expected, actual);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "e","l" };
    actual = o.wordSubsets(A, B);
    expected = { "apple","google","leetcode" };
    check.checkStringVector(expected, actual);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "e","oo" };
    actual = o.wordSubsets(A, B);
    expected = { "facebook","google" };
    check.checkStringVector(expected, actual);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "eo","lo" };
    actual = o.wordSubsets(A, B);
    expected = { "google","leetcode" };
    check.checkStringVector(expected, actual);

    A = { "amazon","apple","facebook","google","leetcode" };
    B = { "ec","oc","ceo" };
    actual = o.wordSubsets(A, B);
    expected = { "facebook","leetcode" };
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
