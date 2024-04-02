/* 匹配模式数组的子数组数目 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 nums ，和一个下标从 0 开始长度为 m 的整数数组 pattern ，pattern 数组只包含整数 -1 ，0 和 1 。

大小为 m + 1 的
子数组
 nums[i..j] 如果对于每个元素 pattern[k] 都满足以下条件，那么我们说这个子数组匹配模式数组 pattern ：

如果 pattern[k] == 1 ，那么 nums[i + k + 1] > nums[i + k]
如果 pattern[k] == 0 ，那么 nums[i + k + 1] == nums[i + k]
如果 pattern[k] == -1 ，那么 nums[i + k + 1] < nums[i + k]
请你返回匹配 pattern 的 nums 子数组的 数目 。



示例 1：

输入：nums = [1,2,3,4,5,6], pattern = [1,1]
输出：4
解释：模式 [1,1] 说明我们要找的子数组是长度为 3 且严格上升的。在数组 nums 中，子数组 [1,2,3] ，[2,3,4] ，[3,4,5] 和 [4,5,6] 都匹配这个模式。
所以 nums 中总共有 4 个子数组匹配这个模式。
示例 2：

输入：nums = [1,4,4,1,3,5,5,3], pattern = [1,0,-1]
输出：2
解释：这里，模式数组 [1,0,-1] 说明我们需要找的子数组中，第一个元素小于第二个元素，第二个元素等于第三个元素，第三个元素大于第四个元素。在 nums 中，子数组 [1,4,4,1] 和 [3,5,5,3] 都匹配这个模式。
所以 nums 中总共有 2 个子数组匹配这个模式。


提示：

2 <= n == nums.length <= 106
1 <= nums[i] <= 109
1 <= m == pattern.length < n
-1 <= pattern[i] <= 1
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

    vector<int> fail;  // fail[i]表示pattern[0, i - 1]的最长公共前后缀
    string pattern;
    int size;
};

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        string text(n - 1, 0), patt(m, 0);

        for (int i = 0; i < n - 1; ++i) {
            text[i] = (nums[i] == nums[i + 1] ? 'a' : (nums[i] < nums[i + 1] ? 'b' : 'c'));
        }

        for (int i = 0; i < m; ++i) {
            patt[i] = (pattern[i] == 0 ? 'a' : (pattern[i] == 1 ? 'b' : 'c'));
        }

        KMP kmp(patt);

        return kmp.searchCount(text);
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<int> nums = { 1,2,3,4,5,6 };
    vector<int> pattern = { 1,1 };
    check.checkInt(4, o.countMatchingSubarrays(nums, pattern));

    nums = { 1,4,4,1,3,5,5,3 };
    pattern = { 1,0,-1 };
    check.checkInt(2, o.countMatchingSubarrays(nums, pattern));
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
