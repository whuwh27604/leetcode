/* 数组中紧跟 key 之后出现最频繁的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，同时给你一个整数 key ，它在 nums 出现过。

统计 在 nums 数组中紧跟着 key 后面出现的不同整数 target 的出现次数。换言之，target 的出现次数为满足以下条件的 i 的数目：

0 <= i <= n - 2
nums[i] == key 且
nums[i + 1] == target 。
请你返回出现 最多 次数的 target 。测试数据保证出现次数最多的 target 是唯一的。

 

示例 1：

输入：nums = [1,100,200,1,100], key = 1
输出：100
解释：对于 target = 100 ，在下标 1 和 4 处出现过 2 次，且都紧跟着 key 。
没有其他整数在 key 后面紧跟着出现，所以我们返回 100 。
示例 2：

输入：nums = [2,2,2,2,3], key = 2
输出：2
解释：对于 target = 2 ，在下标 1 ，2 和 3 处出现过 3 次，且都紧跟着 key 。
对于 target = 3 ，在下标 4 出出现过 1 次，且紧跟着 key 。
target = 2 是紧跟着 key 之后出现次数最多的数字，所以我们返回 2 。
 

提示：

2 <= nums.length <= 1000
1 <= nums[i] <= 1000
测试数据保证答案是唯一的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-frequent-number-following-key-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int i, size = nums.size(), maxFreq = 0, maxFreqNum = 0;
        unordered_map<int, int> counts;

        for (i = 0; i < size - 1; ++i) {
            if (nums[i] == key) {
                ++counts[nums[i + 1]];
            }
        }

        for (auto& count : counts) {
            if (count.second > maxFreq) {
                maxFreq = count.second;
                maxFreqNum = count.first;
            }
        }

        return maxFreqNum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,100,200,1,100 };
    check.checkInt(100, o.mostFrequent(nums, 1));

    nums = { 2,2,2,2,3 };
    check.checkInt(2, o.mostFrequent(nums, 2));

    nums = { 2,1,2,1,3 };
    check.checkInt(1, o.mostFrequent(nums, 2));
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
