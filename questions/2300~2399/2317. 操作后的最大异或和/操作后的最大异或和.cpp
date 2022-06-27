/* 操作后的最大异或和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。一次操作中，选择 任意 非负整数 x 和一个下标 i ，更新 nums[i] 为 nums[i] AND (nums[i] XOR x) 。

注意，AND 是逐位与运算，XOR 是逐位异或运算。

请你执行 任意次 更新操作，并返回 nums 中所有元素 最大 逐位异或和。

 

示例 1：

输入：nums = [3,2,4,6]
输出：7
解释：选择 x = 4 和 i = 3 进行操作，num[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2 。
现在，nums = [3, 2, 4, 2] 且所有元素逐位异或得到 3 XOR 2 XOR 4 XOR 2 = 7 。
可知 7 是能得到的最大逐位异或和。
注意，其他操作可能也能得到逐位异或和 7 。
示例 2：

输入：nums = [1,2,3,9,2]
输出：11
解释：执行 0 次操作。
所有元素的逐位异或和为 1 XOR 2 XOR 3 XOR 9 XOR 2 = 11 。
可知 11 是能得到的最大逐位异或和。
 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 108

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-xor-after-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;

        /* 1、num ^ x 可以得到任何数
           2、(num ^ x) & num 可以得到任意小于等于num的数
           3、要使nums[0] ^ nums[1] ^ ... ^ nums[i - 1]最大，那么某一位上有1就可以保存下来，全部数字在该位上都是0，则结果只能是0
           4、以上等价于nums[0] | nums[1] | ... | nums[i - 1]
        */
        for (int num : nums) {
            ans |= num;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,2,4,6 };
    check.checkInt(7, o.maximumXOR(nums));

    nums = { 1,2,3,9,2 };
    check.checkInt(11, o.maximumXOR(nums));
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
