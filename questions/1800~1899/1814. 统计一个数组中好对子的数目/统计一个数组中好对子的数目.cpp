/* 统计一个数组中好对子的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums ，数组中只包含非负整数。定义 rev(x) 的值为将整数 x 各个数字位反转得到的结果。比方说 rev(123) = 321 ， rev(120) = 21 。我们称满足下面条件的下标对 (i, j) 是 好的 ：

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
请你返回好下标对的数目。由于结果可能会很大，请将结果对 109 + 7 取余 后返回。

 

示例 1：

输入：nums = [42,11,1,97]
输出：2
解释：两个坐标对为：
 - (0,3)：42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121 。
 - (1,2)：11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12 。
示例 2：

输入：nums = [13,10,35,24,76]
输出：4
 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-nice-pairs-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, int> counts;

        for (int num : nums) {
            string s = to_string(num);
            reverse(s.begin(), s.end());
            int rnum = stoi(s);
            ++counts[num - rnum];
        }

        for (auto iter = counts.begin(); iter != counts.end(); ++iter) {
            count += (((long long)iter->second - 1) * iter->second / 2);
        }

        return (int)(count % 1000000007);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 42,11,1,97 };
    check.checkInt(2, o.countNicePairs(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,110,111,112,113,114,115,116,117,118,119,120 };
    check.checkInt(56, o.countNicePairs(nums));

    nums = { 13,10,35,24,76 };
    check.checkInt(4, o.countNicePairs(nums));
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
