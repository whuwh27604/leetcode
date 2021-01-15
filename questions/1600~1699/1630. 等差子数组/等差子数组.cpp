/* 等差子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个数列由至少两个元素组成，且每两个连续元素之间的差值都相同，那么这个序列就是 等差数列 。更正式地，数列 s 是等差数列，只需要满足：对于每个有效的 i ， s[i+1] - s[i] == s[1] - s[0] 都成立。

例如，下面这些都是 等差数列 ：

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
下面的数列 不是等差数列 ：

1, 1, 2, 5, 7
给你一个由 n 个整数组成的数组 nums，和两个由 m 个整数组成的数组 l 和 r，后两个数组表示 m 组范围查询，其中第 i 个查询对应范围 [l[i], r[i]] 。所有数组的下标都是 从 0 开始 的。

返回 boolean 元素构成的答案列表 answer 。如果子数组 nums[l[i]], nums[l[i]+1], ... , nums[r[i]] 可以 重新排列 形成 等差数列 ，answer[i] 的值就是 true；否则answer[i] 的值就是 false 。

 

示例 1：

输入：nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
输出：[true,false,true]
解释：
第 0 个查询，对应子数组 [4,6,5] 。可以重新排列为等差数列 [6,5,4] 。
第 1 个查询，对应子数组 [4,6,5,9] 。无法重新排列形成等差数列。
第 2 个查询，对应子数组 [5,9,3,7] 。可以重新排列为等差数列 [3,5,7,9] 。
示例 2：

输入：nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
输出：[false,true,false,false,true,true]
 

提示：

n == nums.length
m == l.length
m == r.length
2 <= n <= 500
1 <= m <= 500
0 <= l[i] < r[i] < n
-105 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());

        for (unsigned int i = 0; i < l.size(); ++i) {
            ans[i] = checkArithmeticSubarrs(nums, l[i], r[i]);
        }

        return ans;
    }

    bool checkArithmeticSubarrs(vector<int>& nums, int left, int right) {
        int maxNum = INT_MIN, minNum = INT_MAX;

        getMaxMin(nums, left, right, maxNum, minNum);

        if (maxNum == minNum) {
            return true;
        }

        if ((maxNum - minNum) % (right - left) != 0) {
            return false;
        }

        return check(nums, left, right, minNum, (maxNum - minNum) / (right - left));
    }

    void getMaxMin(vector<int>& nums, int left, int right, int& maxNum, int& minNum) {
        for (int i = left; i <= right; ++i) {
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
        }
    }

    bool check(vector<int>& nums, int left, int right, int base, int diff) {
        int size = right - left + 1;
        vector<int> subarrNums(size, 0);

        for (int i = left; i <= right; ++i) {
            int difference = nums[i] - base;
            if (difference % diff != 0) {
                return false;
            }

            int index = difference / diff;
            if (index >= size || subarrNums[index] == 1) {
                return false;
            }

            subarrNums[index] = 1;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,6,5,9,3,7 };
    vector<int> l = { 0,0,2 };
    vector<int> r = { 2,3,5 };
    vector<bool> actual = o.checkArithmeticSubarrays(nums, l, r);
    vector<bool> expected = { true,false,true };
    check.checkBoolVector(expected, actual);

    nums = { -12,-9,-3,-12,-6,15,20,-25,-20,-15,-10 };
    l = { 0,1,6,4,8,7 };
    r = { 4,4,9,7,9,10 };
    actual = o.checkArithmeticSubarrays(nums, l, r);
    expected = { false,true,false,false,true,true };
    check.checkBoolVector(expected, actual);

    nums = { 3,6 };
    l = { 0 };
    r = { 1 };
    actual = o.checkArithmeticSubarrays(nums, l, r);
    expected = { true };
    check.checkBoolVector(expected, actual);
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
