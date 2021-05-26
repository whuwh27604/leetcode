/* 摆动排序 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

你可以假设所有输入数组都可以得到满足题目要求的结果。

 

示例 1：

输入：nums = [1,5,1,1,6,4]
输出：[1,6,1,5,1,4]
解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
示例 2：

输入：nums = [1,3,2,2,3,1]
输出：[2,3,1,3,1,2]
 

提示：

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
 

进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wiggle-sort-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int p, q, size = nums.size(), mid = (size - 1) / 2;

        getMedian(nums);

        for (p = 0, q = mid; p < q; ++p, --q) {
            swap(nums, mapping(size, p), mapping(size, q));
        }

        for (p = mid + 1, q = size - 1; p < q; ++p, --q) {
            swap(nums, mapping(size, p), mapping(size, q));
        }
    }

    // three-way partition, O(n)-average time, O(1)-space
    void getMedian(vector<int>& nums) {
        int size = nums.size(), start = 0, end = size - 1, median = (size - 1) / 2;

        while (true) {
            // [start, p) < pivot, [p, q) == pivot, [q, i) > pivot
            int pivot = nums[mapping(size, end)], p = start, q = p;

            for (int i = start; i < end; ++i) {
                if (nums[mapping(size, i)] <= pivot) {
                    swap(nums, mapping(size, q++), mapping(size, i));

                    if (nums[mapping(size, q - 1)] < pivot) {
                        swap(nums, mapping(size, p++), mapping(size, q - 1));
                    }
                }
            }

            swap(nums, mapping(size, q++), mapping(size, end));

            if (median < p - start) {
                end = p - 1;
            }
            else if (median < q - start) {
                return;
            }
            else {
                median -= q - start;
                start = q;
            }
        }
    }

    int mapping(int size, int index) {
        return index <= (size - 1) / 2 ? index * 2 : (index - (size + 1) / 2) * 2 + 1;
    }

    void swap(vector<int>& nums, int p, int q) {
        int tmp = nums[p];
        nums[p] = nums[q];
        nums[q] = tmp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,5,1,1,6,4 };
    o.wiggleSort(nums);
    vector<int> expected = { 1,5,1,6,1,4 };
    check.checkIntVector(expected, nums);

    nums = { 1,3,2,2,3,1 };
    o.wiggleSort(nums);
    expected = { 2,3,1,3,1,2 };
    check.checkIntVector(expected, nums);

    nums = { 3,1 };
    o.wiggleSort(nums);
    expected = { 1,3 };
    check.checkIntVector(expected, nums);
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
