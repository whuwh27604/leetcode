/* 从相邻元素对还原数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
存在一个由 n 个不同元素组成的整数数组 nums ，但你已经记不清具体内容。好在你还记得 nums 中的每一对相邻元素。

给你一个二维整数数组 adjacentPairs ，大小为 n - 1 ，其中每个 adjacentPairs[i] = [ui, vi] 表示元素 ui 和 vi 在 nums 中相邻。

题目数据保证所有由元素 nums[i] 和 nums[i+1] 组成的相邻元素对都存在于 adjacentPairs 中，存在形式可能是 [nums[i], nums[i+1]] ，也可能是 [nums[i+1], nums[i]] 。这些相邻元素对可以 按任意顺序 出现。

返回 原始数组 nums 。如果存在多种解答，返回 其中任意一个 即可。

 

示例 1：

输入：adjacentPairs = [[2,1],[3,4],[3,2]]
输出：[1,2,3,4]
解释：数组的所有相邻元素对都在 adjacentPairs 中。
特别要注意的是，adjacentPairs[i] 只表示两个元素相邻，并不保证其 左-右 顺序。
示例 2：

输入：adjacentPairs = [[4,-2],[1,4],[-3,1]]
输出：[-2,4,1,-3]
解释：数组中可能存在负数。
另一种解答是 [-3,1,4,-2] ，也会被视作正确答案。
示例 3：

输入：adjacentPairs = [[100000,-100000]]
输出：[100000,-100000]
 

提示：

nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 105
-105 <= nums[i], ui, vi <= 105
题目数据保证存在一些以 adjacentPairs 作为元素对的数组 nums

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacencies;
        getAdjacencies(adjacentPairs, adjacencies);

        vector<int> restored(adjacencies.size());
        int index = 0, prev, current = INT_MIN, next = getHead(adjacencies);

        do {
            prev = current;
            current = next;
            restored[index++] = current;
            next = INT_MAX;

            for (int num : adjacencies[current]) {
                if (num != prev) {
                    next = num;
                    break;
                }
            }
        } while (next != INT_MAX);

        return restored;
    }

    void getAdjacencies(vector<vector<int>>& adjacentPairs, unordered_map<int, vector<int>>& adjacencies) {
        for (auto& adjacentPair : adjacentPairs) {
            adjacencies[adjacentPair[0]].push_back(adjacentPair[1]);
            adjacencies[adjacentPair[1]].push_back(adjacentPair[0]);
        }
    }

    int getHead(unordered_map<int, vector<int>>& adjacencies) {
        auto iter = adjacencies.begin();

        while (iter->second.size() == 2) {
            ++iter;
        }

        return iter->first;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> adjacentPairs = { {2,1},{3,4},{3,2} };
    vector<int> actual = o.restoreArray(adjacentPairs);
    vector<int> expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    adjacentPairs = { {4,-2},{1,4},{-3,1} };
    actual = o.restoreArray(adjacentPairs);
    expected = { -2,4,1,-3 };
    check.checkIntVector(expected, actual);

    adjacentPairs = { {100000,-100000} };
    actual = o.restoreArray(adjacentPairs);
    expected = { 100000,-100000 };
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
