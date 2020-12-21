/* 对角线遍历 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个列表 nums ，里面每一个元素都是一个整数列表。请你依照下面各图的规则，按顺序返回 nums 中对角线上的整数。

 

示例 1：



输入：nums = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,4,2,7,5,3,8,6,9]
示例 2：



输入：nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
输出：[1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
示例 3：

输入：nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
输出：[1,4,2,5,3,8,6,9,7,10,11]
示例 4：

输入：nums = [[1,2,3,4,5,6]]
输出：[1,2,3,4,5,6]
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i].length <= 10^5
1 <= nums[i][j] <= 10^9
nums 中最多有 10^5 个数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxColumn = findMaxColumn(nums);

        vector<vector<int>> diagonalNums((int)nums.size() + maxColumn, vector<int>{});        
        classify(nums, diagonalNums);

        vector<int> ans;
        output(diagonalNums, ans);

        return ans;
    }

    int findMaxColumn(vector<vector<int>>& nums) {
        int maxColumn = 0;

        for (auto& row : nums) {
            maxColumn = max(maxColumn, (int)row.size());
        }

        return maxColumn;
    }

    void classify(vector<vector<int>>& nums, vector<vector<int>>& diagonalNums) {
        int i, j, row = nums.size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < (int)nums[i].size(); ++j) {
                diagonalNums[i + j].push_back(nums[i][j]);
            }
        }
    }

    void output(vector<vector<int>>& diagonalNums, vector<int>& ans) {
        for (auto& row : diagonalNums) {
            for (int i = row.size() - 1; i >= 0; --i) {
                ans.push_back(row[i]);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> nums = { {1,2,3},{4,5,6},{7,8,9} };
    vector<int> actual = o.findDiagonalOrder(nums);
    vector<int> expected = { 1,4,2,7,5,3,8,6,9 };
    check.checkIntVector(expected, actual);

    nums = { {1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16} };
    actual = o.findDiagonalOrder(nums);
    expected = { 1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16 };
    check.checkIntVector(expected, actual);

    nums = { {1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16} };
    actual = o.findDiagonalOrder(nums);
    expected = { 1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16 };
    check.checkIntVector(expected, actual);

    nums = { {1,2,3,4,5,6} };
    actual = o.findDiagonalOrder(nums);
    expected = { 1,2,3,4,5,6 };
    check.checkIntVector(expected, actual);

    nums = { {1},{2},{3},{4},{5},{6} };
    actual = o.findDiagonalOrder(nums);
    expected = { 1,2,3,4,5,6 };
    check.checkIntVector(expected, actual);

    nums = { {1} };
    actual = o.findDiagonalOrder(nums);
    expected = { 1 };
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
