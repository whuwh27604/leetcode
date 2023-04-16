/* 等值距离和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。现有一个长度等于 nums.length 的数组 arr 。对于满足 nums[j] == nums[i] 且 j != i 的所有 j ，arr[i] 等于所有 |i - j| 之和。如果不存在这样的 j ，则令 arr[i] 等于 0 。

返回数组 arr 。



示例 1：

输入：nums = [1,3,1,1,2]
输出：[5,0,3,4,0]
解释：
i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] = |0 - 2| + |0 - 3| = 5 。
i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] = |2 - 0| + |2 - 3| = 3 。
i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] = |3 - 0| + |3 - 2| = 4 。
i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。
示例 2：

输入：nums = [0,5,3]
输出：[0,0,0]
解释：因为 nums 中的元素互不相同，对于所有 i ，都有 arr[i] = 0 。


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, vector<long long>> numSums;
        unordered_map<int, int> numCount;
        vector<long long> arr(size, 0);

        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            if (numSums.count(num) == 0) {
                numSums[num] = { 0,i };
            }
            else {
                numSums[num].push_back(numSums[num].back() + i);
            }
        }

        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            int count = numCount[num]++;
            vector<long long>& sums = numSums[num];
            arr[i] = i * (long long)count - sums[count] + sums.back() - sums[count + 1] - i * ((long long)sums.size() - count - 2);
        }

        return arr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,1,1,2 };
    vector<long long> actual = o.distance(nums);
    vector<long long> expected = { 5,0,3,4,0 };
    check.checkLongLongVector(expected, actual);

    nums = { 0,5,3 };
    actual = o.distance(nums);
    expected = { 0,0,0 };
    check.checkLongLongVector(expected, actual);
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
