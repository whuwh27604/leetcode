/* 最长递增子序列的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> d, count;

        for (int num : nums) {
            int row = binarySearchRow(d, num);
            int cnt = 1;

            if (row > 0) {
                int column = binarySearchColumn(d[row - 1], num);
                cnt = count[row - 1].back() - count[row - 1][column];
            }

            if (row == d.size()) {
                d.push_back({ num });
                count.push_back({ 0,cnt });
            }
            else {
                d[row].push_back(num);
                count[row].push_back(count[row].back() + cnt);
            }
        }

        return count.back().back();
    }

    int binarySearchRow(vector<vector<int>>& d, int target) {
        int left = 0, right = d.size();

        while (left < right) {
            int middle = (left + right) / 2;

            if (d[middle].back() >= target) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }

    int binarySearchColumn(vector<int>& row, int target) {
        int left = 0, right = row.size();

        while (left < right) {
            int middle = (left + right) / 2;

            if (row[middle] < target) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,5,4,7 };
    check.checkInt(2, o.findNumberOfLIS(nums));

    nums = { 2,2,2,2,2 };
    check.checkInt(5, o.findNumberOfLIS(nums));

    nums = { 1,2,3,4 };
    check.checkInt(1, o.findNumberOfLIS(nums));

    nums = { 37,31,26,40,13,15,18,34,45,19,11,21,1,29,12,38,44,25,8,36,5,24,16,14,39,22,32,47,33,2,42,4,46,30,50,6,27,3,20,7,35,49,28,43,17,10,41,9,23,48 };
    check.checkInt(36, o.findNumberOfLIS(nums));
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
