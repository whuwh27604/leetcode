/* 数的平方等于两数乘积的方法数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 nums1 和 nums2 ，请你返回根据以下规则形成的三元组的数目（类型 1 和类型 2 ）：

类型 1：三元组 (i, j, k) ，如果 nums1[i]2 == nums2[j] * nums2[k] 其中 0 <= i < nums1.length 且 0 <= j < k < nums2.length
类型 2：三元组 (i, j, k) ，如果 nums2[i]2 == nums1[j] * nums1[k] 其中 0 <= i < nums2.length 且 0 <= j < k < nums1.length
 

示例 1：

输入：nums1 = [7,4], nums2 = [5,2,8,9]
输出：1
解释：类型 1：(1,1,2), nums1[1]^2 = nums2[1] * nums2[2] (4^2 = 2 * 8)
示例 2：

输入：nums1 = [1,1], nums2 = [1,1,1]
输出：9
解释：所有三元组都符合题目要求，因为 1^2 = 1 * 1
类型 1：(0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2), nums1[i]^2 = nums2[j] * nums2[k]
类型 2：(0,0,1), (1,0,1), (2,0,1), nums2[i]^2 = nums1[j] * nums1[k]
示例 3：

输入：nums1 = [7,7,8,3], nums2 = [1,2,9,7]
输出：2
解释：有两个符合题目要求的三元组
类型 1：(3,0,2), nums1[3]^2 = nums2[0] * nums2[2]
类型 2：(3,0,1), nums2[3]^2 = nums1[0] * nums1[1]
示例 4：

输入：nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
输出：0
解释：不存在符合题目要求的三元组
 

提示：

1 <= nums1.length, nums2.length <= 1000
1 <= nums1[i], nums2[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> nums1Count, nums2Count;

        countNums(nums1, nums1Count);
        countNums(nums2, nums2Count);

        return countTriplets(nums1Count, nums2Count) + countTriplets(nums2Count, nums1Count);
    }

    void countNums(vector<int>& nums, unordered_map<long long, int>& numsCount) {
        for (int num : nums) {
            ++numsCount[num];
        }
    }

    int countTriplets(unordered_map<long long, int>& nums1Count, unordered_map<long long, int>& nums2Count) {
        int triplets = 0;

        for (auto it1 = nums1Count.begin(); it1 != nums1Count.end(); ++it1) {
            long long numI = it1->first, square = numI * numI;

            for (auto it2 = nums2Count.begin(); it2 != nums2Count.end(); ++it2) {
                long long numJ = it2->first, numK = square / numJ;

                if (numJ > numI || numJ * numK != square || nums2Count.count(numK) == 0) {
                    continue;
                }

                if (numJ == numI) {
                    triplets += (it1->second * it2->second * (it2->second - 1) / 2);
                }
                else {
                    triplets += (it1->second * it2->second * nums2Count[numK]);
                }
            }
        }

        return triplets;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 7,4 };
    vector<int> nums2 = { 5,2,8,9 };
    check.checkInt(1, o.numTriplets(nums1, nums2));

    nums1 = { 1,1 };
    nums2 = { 1,1,1 };
    check.checkInt(9, o.numTriplets(nums1, nums2));

    nums1 = { 2,2,2,3,3,3,3,4,4,4,4,4 };
    nums2 = { 2,2,2,3,3,3,3,4,4,4,4,4 };
    check.checkInt(166, o.numTriplets(nums1, nums2));

    nums1 = { 1,1,2,2,2,3,3,3,3,4,4,4,4,4 };
    nums2 = { 1,1,2,2,2,3,3,3,3,4,4,4,4,4 };
    check.checkInt(230, o.numTriplets(nums1, nums2));

    nums1 = { 7,7,8,3 };
    nums2 = { 1,2,9,7 };
    check.checkInt(2, o.numTriplets(nums1, nums2));

    nums1 = { 4,7,9,11,23 };
    nums2 = { 3,5,1024,12,18 };
    check.checkInt(0, o.numTriplets(nums1, nums2));

    nums1 = { 43024,99908 };
    nums2 = { 1864 };
    check.checkInt(0, o.numTriplets(nums1, nums2));
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
