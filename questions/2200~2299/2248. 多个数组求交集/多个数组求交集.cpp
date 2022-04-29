/* 多个数组求交集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 nums ，其中 nums[i] 是由 不同 正整数组成的一个非空数组，按 升序排列 返回一个数组，数组中的每个元素在 nums 所有数组 中都出现过。

 

示例 1：

输入：nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
输出：[3,4]
解释：
nums[0] = [3,1,2,4,5]，nums[1] = [1,2,3,4]，nums[2] = [3,4,5,6]，在 nums 中每个数组中都出现的数字是 3 和 4 ，所以返回 [3,4] 。
示例 2：

输入：nums = [[1,2,3],[4,5,6]]
输出：[]
解释：
不存在同时出现在 nums[0] 和 nums[1] 的整数，所以返回一个空列表 [] 。
 

提示：

1 <= nums.length <= 1000
1 <= sum(nums[i].length) <= 1000
1 <= nums[i][j] <= 1000
nums[i] 中的所有值 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-multiple-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> count(1001, 0), ans;

        for (auto& arr : nums) {
            for (int num : arr) {
                ++count[num];
            }
        }

        for (int i = 1; i < 1001; ++i) {
            if (count[i] == nums.size()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> nums = { {3,1,2,4,5},{1,2,3,4},{3,4,5,6} };
    vector<int> actual = o.intersection(nums);
    vector<int> expected = { 3,4 };
    check.checkIntVector(expected, actual);

    nums = { {1,2,3},{4,5,6} };
    actual = o.intersection(nums);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { {1,2,3,4,5,6} };
    actual = o.intersection(nums);
    expected = { 1,2,3,4,5,6 };
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
