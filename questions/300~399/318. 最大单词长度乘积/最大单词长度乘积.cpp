/* 最大单词长度乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

示例 1:

输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16
解释: 这两个单词为 "abcw", "xtfn"。
示例 2:

输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4
解释: 这两个单词为 "ab", "cd"。
示例 3:

输入: ["a","aa","aaa","aaaa"]
输出: 0
解释: 不存在这样的两个单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int i, j, size = words.size(), maximumProduct = 0;
        vector<int> nums(size);

        words2Nums(words, nums);

        for (i = 0; i < size - 1; ++i) {
            int maxLen1 = words[i].size(), maxLen2 = 0;

            for (j = i + 1; j < size; ++j) {
                if ((nums[i] & nums[j]) == 0) {
                    maxLen2 = max(maxLen2, (int)words[j].size());
                }
            }

            maximumProduct = max(maximumProduct, maxLen1 * maxLen2);
        }

        return maximumProduct;
    }

    void words2Nums(vector<string>& words, vector<int>& nums) {
        int index = 0;

        for (string& word : words) {
            nums[index++] = string2Int(word);
        }
    }

    int string2Int(string& word) {
        int num = 0;

        for (char c : word) {
            num |= (1 << (c - 'a'));
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "abcw","baz","foo","bar","xtfn","abcdef" };
    check.checkInt(16, o.maxProduct(words));

    words = { "a","ab","abc","d","cd","bcd","abcd" };
    check.checkInt(4, o.maxProduct(words));

    words = { "a","aa","aaa","aaaa" };
    check.checkInt(0, o.maxProduct(words));

    words = { "a","z" };
    check.checkInt(1, o.maxProduct(words));
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
