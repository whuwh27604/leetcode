/* 两个数组的交集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashedNums1, hashedNums2;
        vector<int> intersectionNums;

        for (int num : nums1) {
            hashedNums1.insert(num);
        }

        for (int num : nums2) {
            if (hashedNums2.count(num) == 0 && hashedNums1.count(num) != 0) {
                intersectionNums.push_back(num);
            }

            hashedNums2.insert(num);
        }

        return intersectionNums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };
    vector<int> actual = o.intersection(nums1, nums2);
    vector<int> expected = { 4,9 };
    check.checkIntVectorRandomOrder(expected, actual);

    nums1 = { 1,2,2,1 };
    nums2 = { 2,2 };
    actual = o.intersection(nums1, nums2);
    expected = { 2 };
    check.checkIntVectorRandomOrder(expected, actual);

    nums1 = {  };
    nums2 = { 2,2 };
    actual = o.intersection(nums1, nums2);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);

    nums1 = { 1 };
    nums2 = { 2 };
    actual = o.intersection(nums1, nums2);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);

    nums1 = { 1 };
    nums2 = { 1,1,1 };
    actual = o.intersection(nums1, nums2);
    expected = { 1 };
    check.checkIntVectorRandomOrder(expected, actual);

    nums1 = { 1,2,3,4,5 };
    nums2 = { 1,2,3,4,5 };
    actual = o.intersection(nums1, nums2);
    expected = { 1,2,3,4,5 };
    check.checkIntVectorRandomOrder(expected, actual);

    nums1 = { 6,5,4,3,2,1 };
    nums2 = { 1,2,3,4,5,6 };
    actual = o.intersection(nums1, nums2);
    expected = { 1,2,3,4,5,6 };
    check.checkIntVectorRandomOrder(expected, actual);
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
