/* 出现最频繁的偶数元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，返回出现最频繁的偶数元素。

如果存在多个满足条件的元素，只需要返回 最小 的一个。如果不存在这样的元素，返回 -1 。

 

示例 1：

输入：nums = [0,1,2,2,4,4,1]
输出：2
解释：
数组中的偶数元素为 0、2 和 4 ，在这些元素中，2 和 4 出现次数最多。
返回最小的那个，即返回 2 。
示例 2：

输入：nums = [4,4,4,9,2,4]
输出：4
解释：4 是出现最频繁的偶数元素。
示例 3：

输入：nums = [29,47,21,41,13,37,25,7]
输出：-1
解释：不存在偶数元素。
 

提示：

1 <= nums.length <= 2000
0 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/most-frequent-even-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        int maxFreq = 0, maxFreqEven = 0;

        for (int num : nums) {
            if ((num & 1) == 0) {
                ++count[num];
            }
        }

        if (count.empty()) {
            return -1;
        }

        for (auto& kv : count) {
            if (kv.second > maxFreq) {
                maxFreq = kv.second;
                maxFreqEven = kv.first;
            }
            else if (kv.second == maxFreq && kv.first < maxFreqEven) {
                maxFreqEven = kv.first;
            }
        }

        return maxFreqEven;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,1,2,2,4,4,1 };
    check.checkInt(2, o.mostFrequentEven(nums));

    nums = { 4,4,4,9,2,4 };
    check.checkInt(4, o.mostFrequentEven(nums));

    nums = { 29,47,21,41,13,37,25,7 };
    check.checkInt(-1, o.mostFrequentEven(nums));
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
