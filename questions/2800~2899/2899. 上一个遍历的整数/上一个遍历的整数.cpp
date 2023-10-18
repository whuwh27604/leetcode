/* 上一个遍历的整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 words ，其中 words[i] 要么是一个字符串形式的正整数，要么是字符串 "prev" 。

我们从数组的开头开始遍历，对于 words 中的每个 "prev" 字符串，找到 words 中的 上一个遍历的整数 ，定义如下：

k 表示到当前位置为止的连续 "prev" 字符串数目（包含当前字符串），令下标从 0 开始的 整数 数组 nums 表示目前为止遍历过的所有整数，同时用 nums_reverse 表示 nums 反转得到的数组，那么当前 "prev" 对应的 上一个遍历的整数 是 nums_reverse 数组中下标为 (k - 1) 的整数。
如果 k 比目前为止遍历过的整数数目 更多 ，那么上一个遍历的整数为 -1 。
请你返回一个整数数组，包含所有上一个遍历的整数。



示例 1：

输入：words = ["1","2","prev","prev","prev"]
输出：[2,1,-1]
解释：
对于下标为 2 处的 "prev" ，上一个遍历的整数是 2 ，因为连续 "prev" 数目为 1 ，同时在数组 reverse_nums 中，第一个元素是 2 。
对于下标为 3 处的 "prev" ，上一个遍历的整数是 1 ，因为连续 "prev" 数目为 2 ，同时在数组 reverse_nums 中，第二个元素是 1 。
对于下标为 4 处的 "prev" ，上一个遍历的整数是 -1 ，因为连续 "prev" 数目为 3 ，但总共只遍历过 2 个整数。
示例 2：

输入：words = ["1","prev","2","prev","prev"]
输出：[1,2,1]
解释：
对于下标为 1 处的 "prev" ，上一个遍历的整数是 1 。
对于下标为 3 处的 "prev" ，上一个遍历的整数是 2 。
对于下标为 4 处的 "prev" ，上一个遍历的整数是 1 ，因为连续 "prev" 数目为 2 ，同时在数组 reverse_nums 中，第二个元素是 1 。


提示：

1 <= words.length <= 100
words[i] == "prev" 或 1 <= int(words[i]) <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> nums, ans;
        int prevs = 0;

        for (string& word : words) {
            if (word[0] == 'p') {
                ++prevs;
                int size = nums.size();
                if (size < prevs) {
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(nums[size - prevs]);
                }
            }
            else {
                prevs = 0;
                nums.push_back(stoi(word));
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "1","2","prev","prev","prev" };
    vector<int> actual = o.lastVisitedIntegers(words);
    vector<int> expected = { 2,1,-1 };
    check.checkIntVector(expected, actual);

    words = { "1","prev","2","prev","prev" };
    actual = o.lastVisitedIntegers(words);
    expected = { 1,2,1 };
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
