/* 连续数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。

 

示例 1:

输入: [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
示例 2:

输入: [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 

注意: 给定的二进制数组的长度不会超过50000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contiguous-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i, size = nums.size(), diff = size, maxLen = 0;
        vector<int> diffIndices(2 * size + 1, -2);
        diffIndices[size] = -1;

        for (i = 0; i < size; ++i) {
            nums[i] == 0 ? --diff : ++diff;

            if (diffIndices[diff] == -2) {
                diffIndices[diff] = i;
            }
            else {
                maxLen = max(maxLen, i - diffIndices[diff]);  // 每一次diff相等时，说明在(index, i]这个区间内0,1个数相等
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 0,1 };
    check.checkInt(2, o.findMaxLength(nums));

    nums = { 0,1,0 };
    check.checkInt(2, o.findMaxLength(nums));

    nums = { 0,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1 };
    check.checkInt(16, o.findMaxLength(nums));

    nums = {  };
    check.checkInt(0, o.findMaxLength(nums));

    nums = { 1 };
    check.checkInt(0, o.findMaxLength(nums));
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
