/* 得到山形数组的最少删除次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们定义 arr 是 山形数组 当且仅当它满足：

arr.length >= 3
存在某个下标 i （从 0 开始） 满足 0 < i < arr.length - 1 且：
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
给你整数数组 nums​ ，请你返回将 nums 变成 山形状数组 的​ 最少 删除次数。

 

示例 1：

输入：nums = [1,3,1]
输出：0
解释：数组本身就是山形数组，所以我们不需要删除任何元素。
示例 2：

输入：nums = [2,1,1,5,6,2,3,1]
输出：3
解释：一种方法是将下标为 0，1 和 5 的元素删除，剩余元素为 [1,5,6,3,1] ，是山形数组。
示例 3：

输入：nums = [4,3,2,1,1,2,3,1]
输出：4
提示：

输入：nums = [1,2,3,4,4,3,2,1]
输出：1
 

提示：

3 <= nums.length <= 1000
1 <= nums[i] <= 109
题目保证 nums 删除一些元素后一定能得到山形数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-removals-to-make-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> LISs(nums.size()), reverseLISs(nums.size());

        getLISs(nums, LISs);
        reverse(nums.begin(), nums.end());
        getLISs(nums, reverseLISs);

        return getMinRemovals(LISs, reverseLISs);
    }

    void getLISs(vector<int>& nums, vector<int>& LISs) {
        int i, size = nums.size(), len = 1;
        vector<int> incNums = { nums[0] };
        LISs[0] = 1;

        for (i = 1; i < size; ++i) {
            if (nums[i] > incNums[len - 1]) {
                incNums.push_back(nums[i]);
                LISs[i] = ++len;
            }
            else {
                auto iter = upper_bound(incNums.begin(), incNums.end(), nums[i] - 1);
                *iter = nums[i];
                LISs[i] = distance(incNums.begin(), iter) + 1;
            }
        }
    }

    int getMinRemovals(vector<int>& LISs, vector<int>& reverseLISs) {
        int i, size = LISs.size(), maxMountain = 0;

        for (i = 0; i < size; ++i) {
            if (LISs[i] > 1 && reverseLISs[size - 1 - i] > 1) {  // 必须要能够形成一个山，所以LIS最少长度需要2
                maxMountain = max(maxMountain, LISs[i] + reverseLISs[size - 1 - i]);
            }
        }

        return size - maxMountain + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,1 };
    check.checkInt(0, o.minimumMountainRemovals(nums));

    nums = { 2,1,1,5,6,2,3,1 };
    check.checkInt(3, o.minimumMountainRemovals(nums));

    nums = { 4,3,2,1,1,2,3,1 };
    check.checkInt(4, o.minimumMountainRemovals(nums));

    nums = { 1,2,3,4,4,3,2,1 };
    check.checkInt(1, o.minimumMountainRemovals(nums));

    nums = { 100,92,89,77,74,66,64,66,64 };
    check.checkInt(6, o.minimumMountainRemovals(nums));
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
