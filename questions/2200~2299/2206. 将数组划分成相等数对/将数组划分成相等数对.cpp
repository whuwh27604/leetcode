/* 将数组划分成相等数对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，它包含 2 * n 个整数。

你需要将 nums 划分成 n 个数对，满足：

每个元素 只属于一个 数对。
同一数对中的元素 相等 。
如果可以将 nums 划分成 n 个数对，请你返回 true ，否则返回 false 。

 

示例 1：

输入：nums = [3,2,3,2,2,2]
输出：true
解释：
nums 中总共有 6 个元素，所以它们应该被划分成 6 / 2 = 3 个数对。
nums 可以划分成 (2, 2) ，(3, 3) 和 (2, 2) ，满足所有要求。
示例 2：

输入：nums = [1,2,3,4]
输出：false
解释：
无法将 nums 划分成 4 / 2 = 2 个数对且满足所有要求。
 

提示：

nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-array-into-equal-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counts;

        for (int num : nums) {
            ++counts[num];
        }

        for (auto& count : counts) {
            if ((count.second % 2) == 1) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,2,3,2,2,2 };
    check.checkBool(true, o.divideArray(nums));

    nums = { 1,2,3,4 };
    check.checkBool(false, o.divideArray(nums));
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
