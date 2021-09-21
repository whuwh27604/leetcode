/* 构造元素不等于两相邻元素平均值的数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 下标从 0 开始 的数组 nums ，数组由若干 互不相同的 整数组成。你打算重新排列数组中的元素以满足：重排后，数组中的每个元素都 不等于 其两侧相邻元素的 平均值 。

更公式化的说法是，重新排列的数组应当满足这一属性：对于范围 1 <= i < nums.length - 1 中的每个 i ，(nums[i-1] + nums[i+1]) / 2 不等于 nums[i] 均成立 。

返回满足题意的任一重排结果。

 

示例 1：

输入：nums = [1,2,3,4,5]
输出：[1,2,4,5,3]
解释：
i=1, nums[i] = 2, 两相邻元素平均值为 (1+4) / 2 = 2.5
i=2, nums[i] = 4, 两相邻元素平均值为 (2+5) / 2 = 3.5
i=3, nums[i] = 5, 两相邻元素平均值为 (4+3) / 2 = 3.5
示例 2：

输入：nums = [6,2,0,9,7]
输出：[9,7,6,2,0]
解释：
i=1, nums[i] = 7, 两相邻元素平均值为 (9+6) / 2 = 7.5
i=2, nums[i] = 6, 两相邻元素平均值为 (7+2) / 2 = 4.5
i=3, nums[i] = 2, 两相邻元素平均值为 (6+0) / 2 = 3
 

提示：

3 <= nums.length <= 105
0 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-with-elements-not-equal-to-average-of-neighbors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i, j, size = nums.size();
        vector<int> ans(size);

        sort(nums.begin(), nums.end());

        for (i = 0, j = 0; i < (size + 1) / 2; ++i, j += 2) {
            ans[j] = nums[i];
        }

        for (j = 1; i < size; ++i, j += 2) {
            ans[j] = nums[i];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    vector<int> actual = o.rearrangeArray(nums);
    vector<int> expected = { 1,4,2,5,3 };
    check.checkIntVector(expected, actual);

    nums = { 6,2,0,9,7 };
    actual = o.rearrangeArray(nums);
    expected = { 0,7,2,9,6 };
    check.checkIntVector(expected, actual);

    nums = { 3,2,1 };
    actual = o.rearrangeArray(nums);
    expected = { 1,3,2 };
    check.checkIntVector(expected, actual);

    nums = { 3,2,1,0 };
    actual = o.rearrangeArray(nums);
    expected = { 0,2,1,3 };
    check.checkIntVector(expected, actual);

    nums = { 3,2,1,4,5,6 };
    actual = o.rearrangeArray(nums);
    expected = { 1,4,2,5,3,6 };
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
