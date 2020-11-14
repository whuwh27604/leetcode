/* 有多少小于当前数字的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。

 

示例 1：

输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释：
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。
对于 nums[3]=2 存在一个比它小的数字：（1）。
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：

输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：

输入：nums = [7,7,7,7]
输出：[0,0,0,0]
 

提示：

2 <= nums.length <= 500
0 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, size = nums.size(), numsCount[101] = { 0 };

        for (int num : nums) {
            ++numsCount[num];
        }

        int count = 0;
        for (i = 0; i < 101; ++i) {
            if (numsCount[i] != 0) {
                int tmp = numsCount[i];
                numsCount[i] = count;
                count += tmp;
            }
        }

        vector<int> ans(size, 0);
        for (i = 0; i < size; i++) {
            ans[i] = numsCount[nums[i]];
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 8,1,2,2,3 };
    vector<int> actual = o.smallerNumbersThanCurrent(nums);
    vector<int> expected = { 4,0,1,1,3 };
    check.checkIntVector(expected, actual);

    nums = { 6,5,4,8 };
    actual = o.smallerNumbersThanCurrent(nums);
    expected = { 2,1,0,3 };
    check.checkIntVector(expected, actual);

    nums = { 7,7,7,7 };
    actual = o.smallerNumbersThanCurrent(nums);
    expected = { 0,0,0,0 };
    check.checkIntVector(expected, actual);

    nums = { 0,0 };
    actual = o.smallerNumbersThanCurrent(nums);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    nums = { 0,100 };
    actual = o.smallerNumbersThanCurrent(nums);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    nums = { 0,0,0,100,100,100 };
    actual = o.smallerNumbersThanCurrent(nums);
    expected = { 0,0,0,3,3,3 };
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
