/* 通过连接另一个数组的子数组得到一个数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的二维整数数组 groups ，同时给你一个整数数组 nums 。

你是否可以从 nums 中选出 n 个 不相交 的子数组，使得第 i 个子数组与 groups[i] （下标从 0 开始）完全相同，且如果 i > 0 ，那么第 (i-1) 个子数组在 nums 中出现的位置在第 i 个子数组前面。（也就是说，这些子数组在 nums 中出现的顺序需要与 groups 顺序相同）

如果你可以找出这样的 n 个子数组，请你返回 true ，否则返回 false 。

如果不存在下标为 k 的元素 nums[k] 属于不止一个子数组，就称这些子数组是 不相交 的。子数组指的是原数组中连续元素组成的一个序列。

 

示例 1：

输入：groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
输出：true
解释：你可以分别在 nums 中选出第 0 个子数组 [1,-1,0,1,-1,-1,3,-2,0] 和第 1 个子数组 [1,-1,0,1,-1,-1,3,-2,0] 。
这两个子数组是不相交的，因为它们没有任何共同的元素。
示例 2：

输入：groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
输出：false
解释：选择子数组 [1,2,3,4,10,-2] 和 [1,2,3,4,10,-2] 是不正确的，因为它们出现的顺序与 groups 中顺序不同。
[10,-2] 必须出现在 [1,2,3,4] 之前。
示例 3：

输入：groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
输出：false
解释：选择子数组 [7,7,1,2,3,4,7,7] 和 [7,7,1,2,3,4,7,7] 是不正确的，因为它们不是不相交子数组。
它们有一个共同的元素 nums[4] （下标从 0 开始）。
 

提示：

groups.length == n
1 <= n <= 103
1 <= groups[i].length, sum(groups[i].length) <= 103
1 <= nums.length <= 103
-107 <= groups[i][j], nums[k] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/form-array-by-concatenating-subarrays-of-another-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i, j, k = 0, len = groups[0].size(), size = nums.size();

        for (i = 0; i < size; ++i) {
            for (j = 0; j < len && i + j < size; ++j) {
                if (nums[i + j] != groups[k][j]) {
                    break;
                }
            }

            if (j == len) {
                if (++k == groups.size()) {
                    return true;
                }

                i += (len - 1);
                len = groups[k].size();
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> groups = { {1,-1,-1},{3,-2,0} };
    vector<int> nums = { 1,-1,0,1,-1,-1,3,-2,0 };
    check.checkBool(true, o.canChoose(groups, nums));

    groups = { {10,-2},{1,2,3,4} };
    nums = { 1,2,3,4,10,-2 };
    check.checkBool(false, o.canChoose(groups, nums));

    groups = { {1,2,3},{3,4} };
    nums = { 7,7,1,2,3,4,7,7 };
    check.checkBool(false, o.canChoose(groups, nums));

    groups = { {1,2,3} };
    nums = { 1,2 };
    check.checkBool(false, o.canChoose(groups, nums));

    groups = { {1,2} };
    nums = { 1,3,2 };
    check.checkBool(false, o.canChoose(groups, nums));
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
