/* 最少交换次数来组合所有的 1 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
交换 定义为选中一个数组中的两个 互不相同 的位置并交换二者的值。

环形 数组是一个数组，可以认为 第一个 元素和 最后一个 元素 相邻 。

给你一个 二进制环形 数组 nums ，返回在 任意位置 将数组中的所有 1 聚集在一起需要的最少交换次数。

 

示例 1：

输入：nums = [0,1,0,1,1,0,0]
输出：1
解释：这里列出一些能够将所有 1 聚集在一起的方案：
[0,0,1,1,1,0,0] 交换 1 次。
[0,1,1,1,0,0,0] 交换 1 次。
[1,1,0,0,0,0,1] 交换 2 次（利用数组的环形特性）。
无法在交换 0 次的情况下将数组中的所有 1 聚集在一起。
因此，需要的最少交换次数为 1 。
示例 2：

输入：nums = [0,1,1,1,0,0,1,1,0]
输出：2
解释：这里列出一些能够将所有 1 聚集在一起的方案：
[1,1,1,0,0,0,0,1,1] 交换 2 次（利用数组的环形特性）。
[1,1,1,1,1,0,0,0,0] 交换 2 次。
无法在交换 0 次或 1 次的情况下将数组中的所有 1 聚集在一起。
因此，需要的最少交换次数为 2 。
示例 3：

输入：nums = [1,1,0,0,1]
输出：0
解释：得益于数组的环形特性，所有的 1 已经聚集在一起。
因此，需要的最少交换次数为 0 。
 

提示：

1 <= nums.length <= 105
nums[i] 为 0 或者 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-swaps-to-group-all-1s-together-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int window = getOnes(nums);

        return getMinSwaps(nums, window);
    }

    int getOnes(vector<int>& nums) {
        int ones = 0;

        for (int num : nums) {
            if (num == 1) {
                ++ones;
            }
        }

        return ones;
    }

    int getMinSwaps(vector<int>& nums, int window) {
        int i, size = nums.size(), swaps = 0, minSwaps = INT_MAX;

        for (i = 0; i < size + window; ++i) {
            if (nums[i % size] == 0) {
                ++swaps;
            }

            if (i == window - 1) {
                minSwaps = swaps;
            }
            else if (i >= window) {
                if (nums[i - window] == 0) {
                    --swaps;
                }

                minSwaps = min(minSwaps, swaps);
            }
        }

        return minSwaps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,1,0,1,1,0,0 };
    check.checkInt(1, o.minSwaps(nums));

    nums = { 0,1,1,1,0,0,1,1,0 };
    check.checkInt(2, o.minSwaps(nums));

    nums = { 1,1,0,0,1 };
    check.checkInt(0, o.minSwaps(nums));

    nums = { 1 };
    check.checkInt(0, o.minSwaps(nums));

    nums = { 0 };
    check.checkInt(0, o.minSwaps(nums));

    nums = { 0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1 };
    check.checkInt(12, o.minSwaps(nums));
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
