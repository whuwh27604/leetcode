/* 下一个更大元素 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

 

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
 

提示：

nums1和nums2中所有元素是唯一的。
nums1和nums2 的数组大小都不超过1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> largerMap;
        nextLargerMap(nums2, largerMap);

        vector<int> largerNums;
        largerNums.reserve(nums1.size());

        for (unsigned int i = 0; i < nums1.size(); i++) {
            largerNums.push_back(largerMap[nums1[i]]);
        }

        return largerNums;
    }

    void nextLargerMap(vector<int>& nums, unordered_map<int, int>& largerMap) {
        stack<int> lessStack;
        int leastNum;

        for (unsigned int i = 0; i < nums.size(); i++) {
            if (lessStack.empty()) {
                lessStack.push(nums[i]);
                continue;
            }

            leastNum = lessStack.top();
            while (nums[i] > leastNum) {
                largerMap[leastNum] = nums[i];
                lessStack.pop();
                if (lessStack.empty()) {
                    break;
                }
                leastNum = lessStack.top();
            }
            lessStack.push(nums[i]);
        }

        while (!lessStack.empty()) {
            leastNum = lessStack.top();
            lessStack.pop();
            largerMap[leastNum] = -1;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };
    vector<int> actual = o.nextGreaterElement(nums1, nums2);
    vector<int> expected = { -1,3,-1 };
    check.checkIntVector(expected, actual);

    nums1 = { 2,4 };
    nums2 = { 1,2,3,4 };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = { 3,-1 };
    check.checkIntVector(expected, actual);

    nums1 = {  };
    nums2 = { 1,2,3,4 };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums1 = {  };
    nums2 = {  };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 1 };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 1,2 };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 2,1 };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    nums1 = { 1,2,3,4,5 };
    nums2 = { 5,4,3,2,1 };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = { -1,-1,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    nums1 = { 1,2,3,4,5 };
    nums2 = { 5,4,3,2,1,6 };
    actual = o.nextGreaterElement(nums1, nums2);
    expected = { 6,6,6,6,6 };
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
