/* 组合总和 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        DFS(0, n, k, {}, combinations);

        return combinations;
    }

    void DFS(int current, int target, int k, vector<int> combination, vector<vector<int>>& combinations) {
        if ((target == 0) && (combination.size() == k)) {
            combinations.push_back(combination);
            return;
        }

        if ((int)combination.size() >= k) {
            return;
        }

        for (int num = current + 1; num <= 9; num++) {
            if (target < num) {
                break;
            }

            vector<int> tmp = combination;
            tmp.push_back(num);
            DFS(num, target - num, k, tmp, combinations);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> actual = o.combinationSum3(3, 7);
    vector<vector<int>> expected = { {1,2,4} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(3, 9);
    expected = { {1,2,6},{1,3,5},{2,3,4} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(1, 0);
    expected = {  };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(1, 1);
    expected = { {1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(1, 5);
    expected = { {5} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(3, 5);
    expected = {  };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(2, 10);
    expected = { {1,9},{2,8},{3,7},{4,6} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(8, 45);
    expected = {  };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(9, 45);
    expected = { {1,2,3,4,5,6,7,8,9} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    actual = o.combinationSum3(9, 46);
    expected = {  };
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
