/* 到目标字符串的最短距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 环形 字符串数组 words 和一个字符串 target 。环形数组 意味着数组首尾相连。

形式上， words[i] 的下一个元素是 words[(i + 1) % n] ，而 words[i] 的前一个元素是 words[(i - 1 + n) % n] ，其中 n 是 words 的长度。
从 startIndex 开始，你一次可以用 1 步移动到下一个或者前一个单词。

返回到达目标字符串 target 所需的最短距离。如果 words 中不存在字符串 target ，返回 -1 。



示例 1：

输入：words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
输出：1
解释：从下标 1 开始，可以经由以下步骤到达 "hello" ：
- 向右移动 3 个单位，到达下标 4 。
- 向左移动 2 个单位，到达下标 4 。
- 向右移动 4 个单位，到达下标 0 。
- 向左移动 1 个单位，到达下标 0 。
到达 "hello" 的最短距离是 1 。
示例 2：

输入：words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
输出：1
解释：从下标 0 开始，可以经由以下步骤到达 "leetcode" ：
- 向右移动 2 个单位，到达下标 3 。
- 向左移动 1 个单位，到达下标 3 。
到达 "leetcode" 的最短距离是 1 。
示例 3：

输入：words = ["i","eat","leetcode"], target = "ate", startIndex = 0
输出：-1
解释：因为 words 中不存在字符串 "ate" ，所以返回 -1 。


提示：

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 和 target 仅由小写英文字母组成
0 <= startIndex < words.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int size = words.size();

        for (int i = 0; i < size; ++i) {
            if (words[(startIndex + i) % size] == target || words[(startIndex + size - i) % size] == target) {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "hello","i","am","leetcode","hello" };
    check.checkInt(1, o.closetTarget(words, "hello", 1));

    words = { "a","b","leetcode" };
    check.checkInt(1, o.closetTarget(words, "leetcode", 0));

    words = { "i","eat","leetcode" };
    check.checkInt(-1, o.closetTarget(words, "ate", 0));
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
