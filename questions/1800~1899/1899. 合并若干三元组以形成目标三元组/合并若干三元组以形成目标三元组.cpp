﻿/* 合并若干三元组以形成目标三元组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
三元组 是一个由三个整数组成的数组。给你一个二维整数数组 triplets ，其中 triplets[i] = [ai, bi, ci] 表示第 i 个 三元组 。同时，给你一个整数数组 target = [x, y, z] ，表示你想要得到的 三元组 。

为了得到 target ，你需要对 triplets 执行下面的操作 任意次（可能 零 次）：

选出两个下标（下标 从 0 开始 计数）i 和 j（i != j），并 更新 triplets[j] 为 [max(ai, aj), max(bi, bj), max(ci, cj)] 。
例如，triplets[i] = [2, 5, 3] 且 triplets[j] = [1, 7, 5]，triplets[j] 将会更新为 [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5] 。
如果通过以上操作我们可以使得目标 三元组 target 成为 triplets 的一个 元素 ，则返回 true ；否则，返回 false 。

 

示例 1：

输入：triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
输出：true
解释：执行下述操作：
- 选择第一个和最后一个三元组 [[2,5,3],[1,8,4],[1,7,5]] 。更新最后一个三元组为 [max(2,1), max(5,7), max(3,5)] = [2,7,5] 。triplets = [[2,5,3],[1,8,4],[2,7,5]]
目标三元组 [2,7,5] 现在是 triplets 的一个元素。
示例 2：

输入：triplets = [[1,3,4],[2,5,8]], target = [2,5,8]
输出：true
解释：目标三元组 [2,5,8] 已经是 triplets 的一个元素。
示例 3：

输入：triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
输出：true
解释：执行下述操作：
- 选择第一个和第三个三元组 [[2,5,3],[2,3,4],[1,2,5],[5,2,3]] 。更新第三个三元组为 [max(2,1), max(5,2), max(3,5)] = [2,5,5] 。triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]] 。
- 选择第三个和第四个三元组 [[2,5,3],[2,3,4],[2,5,5],[5,2,3]] 。更新第四个三元组为 [max(2,5), max(5,2), max(5,3)] = [5,5,5] 。triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]] 。
目标三元组 [5,5,5] 现在是 triplets 的一个元素。
示例 4：

输入：triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
输出：false
解释：无法得到 [3,2,5] ，因为 triplets 不含 2 。
 

提示：

1 <= triplets.length <= 105
triplets[i].length == target.length == 3
1 <= ai, bi, ci, x, y, z <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-triplets-to-form-target-triplet
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> merged = { 0,0,0 };

        for (auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                merged[0] = max(merged[0], triplet[0]);
                merged[1] = max(merged[1], triplet[1]);
                merged[2] = max(merged[2], triplet[2]);
            }
        }

        return merged == target;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> triplets = { {2,5,3},{1,8,4},{1,7,5} };
    vector<int> target = { 2,7,5 };
    check.checkBool(true, o.mergeTriplets(triplets, target));

    triplets = { {1,3,4},{2,5,8} };
    target = { 2,5,8 };
    check.checkBool(true, o.mergeTriplets(triplets, target));

    triplets = { {2,5,3},{2,3,4},{1,2,5},{5,2,3} };
    target = { 5,5,5 };
    check.checkBool(true, o.mergeTriplets(triplets, target));

    triplets = { {3,4,5},{4,5,6} };
    target = { 3,2,5 };
    check.checkBool(false, o.mergeTriplets(triplets, target));
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
