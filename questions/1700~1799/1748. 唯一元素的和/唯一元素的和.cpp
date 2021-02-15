/* 唯一元素的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。

请你返回 nums 中唯一元素的 和 。

 

示例 1：

输入：nums = [1,2,3,2]
输出：4
解释：唯一元素为 [1,3] ，和为 4 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：0
解释：没有唯一元素，和为 0 。
示例 3 ：

输入：nums = [1,2,3,4,5]
输出：15
解释：唯一元素为 [1,2,3,4,5] ，和为 15 。
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-unique-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> numsCount(101, 0);
        int sum = 0;

        for (int num : nums) {
            ++numsCount[num];
        }

        for (int i = 1; i < 101; ++i) {
            if (numsCount[i] == 1) {
                sum += i;
            }
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,2 };
    check.checkInt(4, o.sumOfUnique(nums));

    nums = { 1,1,1,1,1 };
    check.checkInt(0, o.sumOfUnique(nums));

    nums = { 1,2,3,4,5 };
    check.checkInt(15, o.sumOfUnique(nums));

    nums = { 5 };
    check.checkInt(5, o.sumOfUnique(nums));
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
