/* 统计包含给定前缀的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words 和一个字符串 pref 。

返回 words 中以 pref 作为 前缀 的字符串的数目。

字符串 s 的 前缀 就是  s 的任一前导连续字符串。

 

示例 1：

输入：words = ["pay","attention","practice","attend"], pref = "at"
输出：2
解释：以 "at" 作为前缀的字符串有两个，分别是："attention" 和 "attend" 。
示例 2：

输入：words = ["leetcode","win","loops","success"], pref = "code"
输出：0
解释：不存在以 "code" 作为前缀的字符串。
 

提示：

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] 和 pref 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-words-with-a-given-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0, i, size = pref.size();

        for (string& word : words) {
            for (i = 0; i < size && i < (int)word.size() && word[i] == pref[i]; ++i) {}

            if (i == size) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "pay","attention","practice","attend" };
    check.checkInt(2, o.prefixCount(words, "at"));

    words = { "leetcode","win","loops","success" };
    check.checkInt(0, o.prefixCount(words, "code"));
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
