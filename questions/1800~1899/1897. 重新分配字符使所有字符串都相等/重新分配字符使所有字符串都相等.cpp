/* 重新分配字符使所有字符串都相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words（下标 从 0 开始 计数）。

在一步操作中，需先选出两个 不同 下标 i 和 j，其中 words[i] 是一个非空字符串，接着将 words[i] 中的 任一 字符移动到 words[j] 中的 任一 位置上。

如果执行任意步操作可以使 words 中的每个字符串都相等，返回 true ；否则，返回 false 。

 

示例 1：

输入：words = ["abc","aabc","bc"]
输出：true
解释：将 words[1] 中的第一个 'a' 移动到 words[2] 的最前面。
使 words[1] = "abc" 且 words[2] = "abc" 。
所有字符串都等于 "abc" ，所以返回 true 。
示例 2：

输入：words = ["ab","a"]
输出：false
解释：执行操作无法使所有字符串都相等。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/redistribute-characters-to-make-all-strings-equal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count('z' + 1, 0);

        for (string& word : words) {
            for (char c : word) {
                ++count[c];
            }
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (count[c] % words.size() != 0) {
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

    vector<string> words = { "abc","aabc","bc" };
    check.checkBool(true, o.makeEqual(words));

    words = { "ab","a" };
    check.checkBool(false, o.makeEqual(words));

    words = { "z" };
    check.checkBool(true, o.makeEqual(words));
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
