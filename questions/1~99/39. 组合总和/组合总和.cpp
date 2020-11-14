/* 组合总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        DFS(candidates, 0, target, {}, combinations);

        return combinations;
    }

    void DFS(vector<int>& candidates, int index, int target, vector<int> combination, vector<vector<int>>& combinations) {
        if (target == 0) {
            combinations.push_back(combination);
            return;
        }

        for (int i = index; i < (int)candidates.size(); i++) {
            if (target >= candidates[i]) {
                vector<int> tmp = combination;
                tmp.push_back(candidates[i]);
                DFS(candidates, i, target - candidates[i], tmp, combinations);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> candidates = { 2,3,6,7 };
    vector<vector<int>> actual = o.combinationSum(candidates, 7);
    vector<vector<int>> expected = { {2,2,3},{7} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    candidates = { 2,3,5 };
    actual = o.combinationSum(candidates, 8);
    expected = { {2,2,2,2},{2,3,3},{3,5} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    candidates = { 1 };
    actual = o.combinationSum(candidates, 1);
    expected = { {1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    candidates = { 5,4,3,2,1 };
    actual = o.combinationSum(candidates, 5);
    expected = { {5},{4,1},{3,2},{3,1,1},{2,2,1},{2,1,1,1},{1,1,1,1,1} };
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
