/* 数组中的K-diff数对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组和一个整数 k, 你需要在数组里找到不同的 k-diff 数对。这里将 k-diff 数对定义为一个整数对 (i, j), 其中 i 和 j 都是数组中的数字，且两数之差的绝对值是 k.

示例 1:

输入: [3, 1, 4, 1, 5], k = 2
输出: 2
解释: 数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个1，但我们只应返回不同的数对的数量。
示例 2:

输入:[1, 2, 3, 4, 5], k = 1
输出: 4
解释: 数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
示例 3:

输入: [1, 3, 1, 5, 4], k = 0
输出: 1
解释: 数组中只有一个 0-diff 数对，(1, 1)。
注意:

数对 (i, j) 和数对 (j, i) 被算作同一数对。
数组的长度不超过10,000。
所有输入的整数的范围在 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-diff-pairs-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int diffPairs = 0;
        unordered_map<int, int> numsCount;

        if (k < 0) {
            return 0;
        }

        for (unsigned int i = 0; i < nums.size(); i++) {
            auto iter = numsCount.find(nums[i]);
            if (iter == numsCount.end()) {
                numsCount[nums[i]] = 1;
            }
            else {
                iter->second += 1;
            }
        }

        if (k == 0) {
            for (auto iter = numsCount.begin(); iter != numsCount.end(); iter++) {
                if (iter->second >= 2) {
                    diffPairs++;
                }
            }
        }
        else {
            for (auto iter = numsCount.begin(); iter != numsCount.end(); iter++) {
                if (numsCount.find(iter->first + k) != numsCount.end()) {
                    diffPairs++;
                }
            }
        }        

        return diffPairs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3, 1, 4, 1, 5 };
    check.checkInt(2, o.findPairs(nums, 2));

    nums = { 1, 2, 3, 4, 5 };
    check.checkInt(4, o.findPairs(nums, 1));

    nums = { 1, 3, 1, 5, 4 };
    check.checkInt(1, o.findPairs(nums, 0));

    nums = { 1, 2, 3, 4, 5 };
    check.checkInt(0, o.findPairs(nums, -1));

    nums = {  };
    check.checkInt(0, o.findPairs(nums, 0));

    nums = {  };
    check.checkInt(0, o.findPairs(nums, 1));

    nums = { 1 };
    check.checkInt(0, o.findPairs(nums, 0));

    nums = { 1 };
    check.checkInt(0, o.findPairs(nums, 1));

    nums = { 1,2 };
    check.checkInt(1, o.findPairs(nums, 1));

    nums = { 1,2 };
    check.checkInt(0, o.findPairs(nums, 0));

    nums = { 2,2 };
    check.checkInt(0, o.findPairs(nums, 1));

    nums = { 2,2 };
    check.checkInt(1, o.findPairs(nums, 0));

    nums = { 3,3,3,4,4,4,4 };
    check.checkInt(2, o.findPairs(nums, 0));

    nums = { 3,3,3,4,4,4,4 };
    check.checkInt(1, o.findPairs(nums, 1));
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
