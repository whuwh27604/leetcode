/* 每个查询的最大异或值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 有序 数组 nums ，它由 n 个非负整数组成，同时给你一个整数 maximumBit 。你需要执行以下查询 n 次：

找到一个非负整数 k < 2maximumBit ，使得 nums[0] XOR nums[1] XOR ... XOR nums[nums.length-1] XOR k 的结果 最大化 。k 是第 i 个查询的答案。
从当前数组 nums 删除 最后 一个元素。
请你返回一个数组 answer ，其中 answer[i]是第 i 个查询的结果。

 

示例 1：

输入：nums = [0,1,1,3], maximumBit = 2
输出：[0,3,2,3]
解释：查询的答案如下：
第一个查询：nums = [0,1,1,3]，k = 0，因为 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3 。
第二个查询：nums = [0,1,1]，k = 3，因为 0 XOR 1 XOR 1 XOR 3 = 3 。
第三个查询：nums = [0,1]，k = 2，因为 0 XOR 1 XOR 2 = 3 。
第四个查询：nums = [0]，k = 3，因为 0 XOR 3 = 3 。
示例 2：

输入：nums = [2,3,4,7], maximumBit = 3
输出：[5,2,6,5]
解释：查询的答案如下：
第一个查询：nums = [2,3,4,7]，k = 5，因为 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7。
第二个查询：nums = [2,3,4]，k = 2，因为 2 XOR 3 XOR 4 XOR 2 = 7 。
第三个查询：nums = [2,3]，k = 6，因为 2 XOR 3 XOR 6 = 7 。
第四个查询：nums = [2]，k = 5，因为 2 XOR 5 = 7 。
示例 3：

输入：nums = [0,1,2,2,5,7], maximumBit = 3
输出：[4,3,6,4,6,7]
 

提示：

nums.length == n
1 <= n <= 105
1 <= maximumBit <= 20
0 <= nums[i] < 2maximumBit
nums​​​ 中的数字已经按 升序 排好序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-for-each-query
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int i, size = nums.size(), maxNum = (1 << maximumBit) - 1, xorSum = 0;
        vector<int> ans(size);

        for (i = 0; i < size; ++i) {
            xorSum ^= nums[i];
        }

        for (i = 0; i < size; ++i) {
            ans[i] = xorSum ^ maxNum;
            xorSum ^= nums[size - 1 - i];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 0,1,1,3 };
    vector<int> actual = o.getMaximumXor(nums, 2);
    vector<int> expected = { 0,3,2,3 };
    check.checkIntVector(expected, actual);

    nums = { 2,3,4,7 };
    actual = o.getMaximumXor(nums, 3);
    expected = { 5,2,6,5 };
    check.checkIntVector(expected, actual);

    nums = { 0,1,2,2,5,7 };
    actual = o.getMaximumXor(nums, 3);
    expected = { 4,3,6,4,6,7 };
    check.checkIntVector(expected, actual);

    nums = { 0 };
    actual = o.getMaximumXor(nums, 5);
    expected = { 31 };
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
