/* 组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return combine(n, 1, k);
    }

    vector<vector<int>> combine(int n, int start, int k) {
        vector<vector<int>> allCombines;

        if (k == 1) {
            for (int i = start; i <= n; i++) {
                allCombines.push_back({ i });
            }
            return allCombines;
        }

        if (n - start + 1 == k) {
            allCombines.push_back(vector<int>(k, 0));
            for (int i = 0; i < k; i++) {
                allCombines[0][i] = start + i;
            }
            return allCombines;
        }

        vector<vector<int>> combines1 = combine(n, start + 1, k - 1);
        for (vector<int>& one : combines1) {
            allCombines.push_back({ start });
            allCombines.back().insert(allCombines.back().end(), one.begin(), one.end());
        }

        vector<vector<int>> combines2 = combine(n, start + 1, k);
        for (vector<int>& one : combines2) {
            allCombines.push_back(one);
        }

        return allCombines;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> actual = o.combine(4, 2);
    vector<vector<int>> expected = { {1,2},{1,3},{1,4},{2,3},{2,4},{3,4} };
    check.checkIntVectorVector(expected, actual);

    actual = o.combine(1, 1);
    expected = { {1} };
    check.checkIntVectorVector(expected, actual);

    actual = o.combine(2, 1);
    expected = { {1},{2} };
    check.checkIntVectorVector(expected, actual);

    actual = o.combine(2, 2);
    expected = { {1,2} };
    check.checkIntVectorVector(expected, actual);

    actual = o.combine(3, 1);
    expected = { {1},{2},{3} };
    check.checkIntVectorVector(expected, actual);

    actual = o.combine(3, 2);
    expected = { {1,2},{1,3},{2,3} };
    check.checkIntVectorVector(expected, actual);

    actual = o.combine(3, 3);
    expected = { {1,2,3} };
    check.checkIntVectorVector(expected, actual);
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
