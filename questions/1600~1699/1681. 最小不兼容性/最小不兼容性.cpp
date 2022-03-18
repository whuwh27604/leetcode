/* 最小不兼容性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums​​​ 和一个整数 k 。你需要将这个数组划分到 k 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。

一个子集的 不兼容性 是该子集里面最大值和最小值的差。

请你返回将数组分成 k 个子集后，各子集 不兼容性 的 和 的 最小值 ，如果无法分成分成 k 个子集，返回 -1 。

子集的定义是数组中一些数字的集合，对数字顺序没有要求。

 

示例 1：

输入：nums = [1,2,1,4], k = 2
输出：4
解释：最优的分配是 [1,2] 和 [1,4] 。
不兼容性和为 (2-1) + (4-1) = 4 。
注意到 [1,1] 和 [2,4] 可以得到更小的和，但是第一个集合有 2 个相同的元素，所以不可行。
示例 2：

输入：nums = [6,3,8,1,3,1,2,2], k = 4
输出：6
解释：最优的子集分配为 [1,2]，[2,3]，[6,8] 和 [1,3] 。
不兼容性和为 (2-1) + (3-2) + (8-6) + (3-1) = 6 。
示例 3：

输入：nums = [5,3,3,6,3,3], k = 3
输出：-1
解释：没办法将这些数字分配到 3 个子集且满足每个子集里没有相同数字。
 

提示：

1 <= k <= nums.length <= 16
nums.length 能被 k 整除。
1 <= nums[i] <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-incompatibility
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int size = nums.size(), maxBit = (1 << size), inf = 1000000000;
        vector<int> incompatibilities(maxBit, -1);
        incompatibilities[0] = 0;

        sort(nums.begin(), nums.end());

        if (k == 1) {  // 所有数据在一个组，不能有重复的数，最小不兼容性是最大最小值的差
            for (int i = 1; i < size; ++i) {
                if (nums[i] == nums[i - 1]) {
                    return -1;
                }
            }

            return nums[size - 1] - nums[0];
        }
        else if (k == size) {  // 每个num一组，所有组的不兼容性都是0
            return 0;
        }
        else {
            int ans = minIncompatibility(nums, size / k, maxBit - 1, incompatibilities);
            return ans >= inf ? -1 : ans;
        }
    }

    void getSubsets(vector<int>& nums, int len, int mask, int chosen, int start, vector<int>& subset, vector<int>& incompatibilities) {
        if (subset.size() == len) {  // 已选出一个subset，计算incompatibilities
            incompatibilities[mask] = min(incompatibilities[mask], subset.back() - subset[0] + minIncompatibility(nums, len, mask ^ chosen, incompatibilities));
            return;
        }

        int size = nums.size(), chosable = mask ^ chosen, prev = (start == 0 ? -1 : nums[start - 1]);

        for (int i = start, bit = (1 << start); i < size; ++i, bit <<= 1) {  // 还不满长度，继续选择num
            if ((chosable & bit) != 0 && nums[i] != prev) {  // 不能选相同的num
                chosen ^= bit;  // 选中它
                subset.push_back(nums[i]);

                getSubsets(nums, len, mask, chosen, i + 1, subset, incompatibilities);

                chosen ^= bit;  // 回溯，遍历所有可能的子集
                subset.pop_back();
            }
        }
    }

    int minIncompatibility(vector<int>& nums, int len, int mask, vector<int>& incompatibilities) {
        int inf = 1000000000;
        int& ans = incompatibilities[mask];

        if (ans != -1) {
            return ans;
        }
        ans = inf;

        vector<int> subset;
        getSubsets(nums, len, mask, 0, 0, subset, incompatibilities);

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,1,4 };
    check.checkInt(4, o.minimumIncompatibility(nums, 2));

    nums = { 6,3,8,1,3,1,2,2 };
    check.checkInt(6, o.minimumIncompatibility(nums, 4));

    nums = { 5,3,3,6,3,3 };
    check.checkInt(-1, o.minimumIncompatibility(nums, 3));

    nums = { 12,8,6,6,12,1,7,9,8,9,1,9 };
    check.checkInt(22, o.minimumIncompatibility(nums, 4));
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
