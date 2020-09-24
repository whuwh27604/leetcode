/* 摆动序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:

输入: [1,7,4,9,2,5]
输出: 6
解释: 整个序列均为摆动序列。
示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
示例 3:

输入: [1,2,3,4,5,6,7,8,9]
输出: 2
进阶:
你能否用 O(n) 时间复杂度完成此题?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wiggle-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return size;
        }

        bool ascending = true;
        int prev = nums[0], current = 1;

        while ((current < size) && (nums[current] == prev)) {
            current++;
        }

        if (current == size) {
            return 1;
        }
        if (nums[current] < prev) {
            ascending = false;
        }
        prev = nums[current];
        int count = 2;

        for (current += 1; current < size; current++) {
            int num = nums[current];
            if ((num > prev) && !ascending) {
                count++;
                ascending = true;
            }
            else if ((num < prev) && ascending) {
                count++;
                ascending = false;
            }

            prev = num;
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkInt(0, o.wiggleMaxLength(nums));

    nums = { 1 };
    check.checkInt(1, o.wiggleMaxLength(nums));

    nums = { 1,1 };
    check.checkInt(1, o.wiggleMaxLength(nums));

    nums = { 1,1,1,2 };
    check.checkInt(2, o.wiggleMaxLength(nums));

    nums = { 1,1,1,0 };
    check.checkInt(2, o.wiggleMaxLength(nums));

    nums = { 1,7,4,9,2,5 };
    check.checkInt(6, o.wiggleMaxLength(nums));

    nums = { 1,17,5,10,13,15,10,5,16,8 };
    check.checkInt(7, o.wiggleMaxLength(nums));

    nums = { 1,2,3,4,5,6,7,8,9 };
    check.checkInt(2, o.wiggleMaxLength(nums));
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
