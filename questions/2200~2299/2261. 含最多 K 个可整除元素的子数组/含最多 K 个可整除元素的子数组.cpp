/* 含最多 K 个可整除元素的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和两个整数 k 和 p ，找出并返回满足要求的不同的子数组数，要求子数组中最多 k 个可被 p 整除的元素。

如果满足下述条件之一，则认为数组 nums1 和 nums2 是 不同 数组：

两数组长度 不同 ，或者
存在 至少 一个下标 i 满足 nums1[i] != nums2[i] 。
子数组 定义为：数组中的连续元素组成的一个 非空 序列。

 

示例 1：

输入：nums = [2,3,3,2,2], k = 2, p = 2
输出：11
解释：
位于下标 0、3 和 4 的元素都可以被 p = 2 整除。
共计 11 个不同子数组都满足最多含 k = 2 个可以被 2 整除的元素：
[2]、[2,3]、[2,3,3]、[2,3,3,2]、[3]、[3,3]、[3,3,2]、[3,3,2,2]、[3,2]、[3,2,2] 和 [2,2] 。
注意，尽管子数组 [2] 和 [3] 在 nums 中出现不止一次，但统计时只计数一次。
子数组 [2,3,3,2,2] 不满足条件，因为其中有 3 个元素可以被 2 整除。
示例 2：

输入：nums = [1,2,3,4], k = 4, p = 1
输出：10
解释：
nums 中的所有元素都可以被 p = 1 整除。
此外，nums 中的每个子数组都满足最多 4 个元素可以被 1 整除。
因为所有子数组互不相同，因此满足所有限制条件的子数组总数为 10 。
 

提示：

1 <= nums.length <= 200
1 <= nums[i], p <= 200
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-divisible-elements-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int i, j, size = nums.size();
        vector<int> presums(size + 1, 0);
        unordered_set<string> subArrays;

        getPresums(nums, presums, p);

        for (i = 0; i < size; ++i) {
            string s;

            for (j = i; j < size; ++j) {
                s += to_string(nums[j]);
                s += 'A';

                if (presums[j + 1] - presums[i] <= k) {
                    subArrays.insert(s);
                }
            }
        }

        return subArrays.size();
    }

    void getPresums(vector<int>& nums, vector<int>& presums, int p) {
        int i, size = nums.size();

        for (i = 0; i < size; ++i) {
            if (nums[i] % p == 0) {
                presums[i + 1] = 1;
            }
        }

        for (i = 1; i <= size; ++i) {
            presums[i] += presums[i - 1];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,3,2,2 };
    check.checkInt(11, o.countDistinct(nums, 2, 2));

    nums = { 1,2,3,4 };
    check.checkInt(10, o.countDistinct(nums, 4, 1));

    nums = { 16,17,4,12,3 };
    check.checkInt(14, o.countDistinct(nums, 4, 1));

    nums = { 4 };
    check.checkInt(1, o.countDistinct(nums, 2, 2));

    nums = { 4,121,144,188,110,101,186,180,49,94,99,99,91,52,42,82,102,115,73,83,173,86,143,31,112,104,152,21,177,12,116,13,180,101,118,32,143,132,164,38,59,99,44,101,45,182,196,29,53,15,152,41,29,198,138,30,78,193,16,49,172,50,77,115,196,62,94,38,193,98,114,42,126,178,5,150,31,51,57,40,81,79,186,136,106,36,192,34,170,13,32,78,74,45,75,151,189,173,144,48,100,188,84,123,50,45,138,166,99,200,130,42,152,149,3,170,156,95,20,179,31,15,68,61,74,117,160,42,140,88,62,151,61,32,168,116,92,173,53,81,35,14,25,123,82,138,145,61,66,69,124,107,44,134,60,65,79,133,20,44,193,103,188,113,107,181,149,126,2,35,52,6,71,84,136,145,181,17,24,36,32,68,166,81,56,66,165,98,11,105,156,165 };
    check.checkInt(18457, o.countDistinct(nums, 12, 45));
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
