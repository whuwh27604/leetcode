/* 至少在两个数组中出现的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 不同 数组，且由 至少 在 两个 数组中出现的所有值组成。数组中的元素可以按 任意 顺序排列。
 

示例 1：

输入：nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
输出：[3,2]
解释：至少在两个数组中出现的所有值为：
- 3 ，在全部三个数组中都出现过。
- 2 ，在数组 nums1 和 nums2 中出现过。
示例 2：

输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
输出：[2,3,1]
解释：至少在两个数组中出现的所有值为：
- 2 ，在数组 nums2 和 nums3 中出现过。
- 3 ，在数组 nums1 和 nums2 中出现过。
- 1 ，在数组 nums1 和 nums3 中出现过。
示例 3：

输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
输出：[]
解释：不存在至少在两个数组中出现的值。
 

提示：

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-out-of-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> all(101, 0);
        vector<int> ans;

        for (int num : nums1) {
            all[num] = 1;
        }

        for (int num : nums2) {
            if (all[num] == 1) {
                all[num] = -1;
                ans.push_back(num);
            }
            else if (all[num] == 0) {
                all[num] = 2;
            }
        }

        for (int num : nums3) {
            if (all[num] == 1 || all[num] == 2) {
                all[num] = -1;
                ans.push_back(num);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,1,3,2 };
    vector<int> nums2 = { 2,3 };
    vector<int> nums3 = { 3 };
    vector<int> actual = o.twoOutOfThree(nums1, nums2, nums3);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    nums1 = { 3,1 };
    nums2 = { 2,3 };
    nums3 = { 1,2 };
    actual = o.twoOutOfThree(nums1, nums2, nums3);
    expected = { 3,1,2 };
    check.checkIntVector(expected, actual);

    nums1 = { 1,2,2 };
    nums2 = { 4,3,3 };
    nums3 = { 5 };
    actual = o.twoOutOfThree(nums1, nums2, nums3);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums1 = { 7,2,3,8,7,14,11,7,6 };
    nums2 = { 3,8,14,14,4 };
    nums3 = { 14,7,11,8 };
    actual = o.twoOutOfThree(nums1, nums2, nums3);
    expected = { 3,8,14,7,11 };
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
