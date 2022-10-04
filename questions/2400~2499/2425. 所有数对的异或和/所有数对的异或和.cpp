/* 所有数对的异或和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的数组 nums1 和 nums2 ，两个数组都只包含非负整数。请你求出另外一个数组 nums3 ，包含 nums1 和 nums2 中 所有数对 的异或和（nums1 中每个整数都跟 nums2 中每个整数 恰好 匹配一次）。

请你返回 nums3 中所有整数的 异或和 。

 

示例 1：

输入：nums1 = [2,1,3], nums2 = [10,2,5,0]
输出：13
解释：
一个可能的 nums3 数组是 [8,0,7,2,11,3,4,1,9,1,6,3] 。
所有这些数字的异或和是 13 ，所以我们返回 13 。
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：0
解释：
所有数对异或和的结果分别为 nums1[0] ^ nums2[0] ，nums1[0] ^ nums2[1] ，nums1[1] ^ nums2[0] 和 nums1[1] ^ nums2[1] 。
所以，一个可能的 nums3 数组是 [2,5,1,6] 。
2 ^ 5 ^ 1 ^ 6 = 0 ，所以我们返回 0 。
 

提示：

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[j] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/bitwise-xor-of-all-pairings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorSum = 0;

        if ((nums1.size() & 1) == 1) {
            for (int num : nums2) {
                xorSum ^= num;
            }
        }

        if ((nums2.size() & 1) == 1) {
            for (int num : nums1) {
                xorSum ^= num;
            }
        }

        return xorSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 2,1,3 };
    vector<int> nums2 = { 10,2,5,0 };
    check.checkInt(13, o.xorAllNums(nums1, nums2));

    nums1 = { 1,2 };
    nums2 = { 3,4 };
    check.checkInt(0, o.xorAllNums(nums1, nums2));
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
