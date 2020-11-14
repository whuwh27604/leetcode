/* 组合总和 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> combinations;
        DFS(candidates, 0, target, {}, combinations);

        return combinations;
    }

    void DFS(vector<int>& candidates, int index, int target, vector<int> combination, vector<vector<int>>& combinations) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }

        int last = 0;
        for (int i = index; i < (int)candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            }

            if (candidates[i] == last) {
                continue;
            }

            last = candidates[i];
            vector<int> tmp = combination;
            tmp.push_back(candidates[i]);
            DFS(candidates, i + 1, target - candidates[i], tmp, combinations);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> candidates = { 10,1,2,7,6,1,5 };
    vector<vector<int>> actual = o.combinationSum2(candidates, 8);
    vector<vector<int>> expected = { {1,1,6},{1,2,5},{2,6},{1,7} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    candidates = { 2,5,2,1,2 };
    actual = o.combinationSum2(candidates, 5);
    expected = { {1,2,2},{5} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    candidates = { 1 };
    actual = o.combinationSum2(candidates, 1);
    expected = { {1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    candidates = { 1 };
    actual = o.combinationSum2(candidates, 2);
    expected = {  };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    candidates = { 1,1,1 };
    actual = o.combinationSum2(candidates, 2);
    expected = { {1,1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);
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
