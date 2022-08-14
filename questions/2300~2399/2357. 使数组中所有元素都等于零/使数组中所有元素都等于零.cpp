/* 使数组中所有元素都等于零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个非负整数数组 nums 。在一步操作中，你必须：

选出一个正整数 x ，x 需要小于或等于 nums 中 最小 的 非零 元素。
nums 中的每个正整数都减去 x。
返回使 nums 中所有元素都等于 0 需要的 最少 操作数。

 

示例 1：

输入：nums = [1,5,0,3,5]
输出：3
解释：
第一步操作：选出 x = 1 ，之后 nums = [0,4,0,2,4] 。
第二步操作：选出 x = 2 ，之后 nums = [0,2,0,0,2] 。
第三步操作：选出 x = 2 ，之后 nums = [0,0,0,0,0] 。
示例 2：

输入：nums = [0]
输出：0
解释：nums 中的每个元素都已经是 0 ，所以不需要执行任何操作。
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int num : nums) {
            numbers.insert(num);
        }

        numbers.erase(0);

        return numbers.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,5,0,3,5 };
    check.checkInt(3, o.minimumOperations(nums));

    nums = { 0 };
    check.checkInt(0, o.minimumOperations(nums));
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
