/* 求众数 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

 

示例 1：

输入：[3,2,3]
输出：[3]
示例 2：

输入：nums = [1]
输出：[1]
示例 3：

输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
 

提示：

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        pairing(nums, candidate1, candidate2);

        pair<int, int> count = counting(nums, candidate1, candidate2);

        vector<int> majorityElements;
        if (count.first > (int)(nums.size() / 3)) {
            majorityElements.push_back(candidate1);
        }

        if (count.second > (int)(nums.size() / 3)) {
            majorityElements.push_back(candidate2);
        }

        return majorityElements;
    }

    void pairing(vector<int>& nums, int& candidate1, int& candidate2) {
        int count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                ++count1;
            }
            else if (num == candidate2) {
                ++count2;
            }
            else {
                if (count1 == 0) {
                    candidate1 = num;
                    count1 = 1;
                }
                else if (count2 == 0) {
                    candidate2 = num;
                    count2 = 1;
                }
                else {
                    --count1;
                    --count2;
                }
            }
        }
    }

    pair<int, int> counting(vector<int>& nums, int& candidate1, int& candidate2) {
        int count1 = 0, count2 = 0;

        for (int num : nums) {
            if (num == candidate1) {
                ++count1;
            }
            else if (num == candidate2) {
                ++count2;
            }
        }

        return { count1, count2 };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3 };
    vector<int> actual = o.majorityElement(nums);
    vector<int> expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 3,2,3 };
    actual = o.majorityElement(nums);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    nums = { 3,3,3 };
    actual = o.majorityElement(nums);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.majorityElement(nums);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,3,3,2,2,2 };
    actual = o.majorityElement(nums);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    nums = { 6,6,6,7,7 };
    actual = o.majorityElement(nums);
    expected = { 6,7 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,2,2,3,3,4,1,1,2,2,3,3,4,4,4,4,4,4,4,4 };
    actual = o.majorityElement(nums);
    expected = { 4 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,12,19,31,1,15,2,3,3,2,2,2 };
    actual = o.majorityElement(nums);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 3,3,3,12,3,31,3,3,2,3,3,3,2,3,2 };
    actual = o.majorityElement(nums);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    nums = { 3,2,3,5,10,10,10,5,9,4,3,3,3,3,3 };
    actual = o.majorityElement(nums);
    expected = { 3 };
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
