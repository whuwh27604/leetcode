/* 正方形数组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数数组 A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。

返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。

 

示例 1：

输入：[1,17,8]
输出：2
解释：
[1,8,17] 和 [17,8,1] 都是有效的排列。
示例 2：

输入：[2,2,2]
输出：1
 

提示：

1 <= A.length <= 12
0 <= A[i] <= 1e9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-squareful-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int i, size = nums.size(), prev = -1, perms = 0;
        vector<vector<int>> adjs(size);
        vector<bool> visited(size, false);

        sort(nums.begin(), nums.end());
        getAdjs(nums, adjs);

        for (i = 0; i < size; ++i) {
            if (nums[i] != prev) {
                prev = nums[i];
                DFS(nums, adjs, visited, i, 1, perms);
            }
        }

        return perms;
    }

    void getAdjs(vector<int>& nums, vector<vector<int>>& adjs) {
        int i, j, size = nums.size();

        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                if (j != i) {
                    int sum = nums[i] + nums[j], root = (int)sqrt(sum);

                    if (root * root == sum) {
                        adjs[i].push_back(j);
                    }
                }
            }
        }
    }

    void DFS(vector<int>& nums, vector<vector<int>>& adjs, vector<bool>& visited, int node, int depth, int& perms) {
        visited[node] = true;

        if (depth == adjs.size()) {
            ++perms;
        }
        else {
            int prev = -1;

            for (int next : adjs[node]) {
                if (!visited[next] && nums[next] != prev) {
                    prev = nums[next];
                    DFS(nums, adjs, visited, next, depth + 1, perms);
                }
            }
        }

        visited[node] = false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,17,8 };
    check.checkInt(2, o.numSquarefulPerms(nums));

    nums = { 2,2,2 };
    check.checkInt(1, o.numSquarefulPerms(nums));

    nums = { 0,0,0,1,1,1 };
    check.checkInt(4, o.numSquarefulPerms(nums));

    nums = { 2,3,1 };
    check.checkInt(0, o.numSquarefulPerms(nums));
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
