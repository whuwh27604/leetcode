/* 找到所有数组中消失的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 把出现的数对应位置上的数置为负数，再扫描一遍，仍然为正数的就是缺失的数。时间复杂度为O(2n)
        for (unsigned int i = 0; i < nums.size(); i++) {
            int index = (abs(nums[i]) - 1);
            if (nums[index] > 0) {
                nums[index] = (0 - nums[index]);
            }            
        }

        vector<int> disappearedNumbers;
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                disappearedNumbers.push_back(i + 1);
            }
        }

        return disappearedNumbers;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,3,2,7,8,2,3,1 };
    vector<int> actual = o.findDisappearedNumbers(nums);
    vector<int> expected = { 5,6 };
    check.checkIntVector(expected, actual);

    nums = { 3,3,2,1,4,5,6,4 };
    actual = o.findDisappearedNumbers(nums);
    expected = { 7,8 };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.findDisappearedNumbers(nums);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,1,1,1,1,1 };
    actual = o.findDisappearedNumbers(nums);
    expected = { 2,3,4,5,6,7,8 };
    check.checkIntVector(expected, actual);

    nums = { 3,3,2,5,4,5,6,4 };
    actual = o.findDisappearedNumbers(nums);
    expected = { 1,7,8 };
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
