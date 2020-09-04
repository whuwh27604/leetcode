/* 三角形最小路径和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

 

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

通过次数63,023提交次数97,120

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /* dp[i][j] = min(dp[i-1][j-1], dp[i-1][j])+tri[i][j]，可以从下往上反推，直接得到结果 */
        int i, j, height = triangle.size();
        if (height == 0) {
            return 0;
        }

        for (i = height - 2; i >= 0; i--) {
            for (j = 0; j < (int)triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> triangle = {};
    check.checkInt(0, o.minimumTotal(triangle));

    triangle = { {1} };
    check.checkInt(1, o.minimumTotal(triangle));

    triangle = { {1},{2,3} };
    check.checkInt(3, o.minimumTotal(triangle));

    triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
    check.checkInt(11, o.minimumTotal(triangle));

    triangle = { {2},{3,4},{6,5,7},{4,1,8,3},{9,9,9,0,0} };
    check.checkInt(16, o.minimumTotal(triangle));
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
