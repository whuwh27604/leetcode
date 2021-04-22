/* 下降路径最小和  II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数方阵 arr ，定义「非零偏移下降路径」为：从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。

请你返回非零偏移下降路径数字和的最小值。

 

示例 1：

输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
输出：13
解释：
所有非零偏移下降路径包括：
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。
 

提示：

1 <= arr.length == arr[i].length <= 200
-99 <= arr[i][j] <= 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-falling-path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int i, j, size = arr.size(), min1st = 0, min2nd = 0;
        vector<int> dp(size, 0);

        for (i = 0; i < size; ++i) {
            vector<int> tmpDp(size);
            int tmpMin1st = INT_MAX, tmpMin2nd = INT_MAX;

            for (j = 0; j < size; ++j) {
                tmpDp[j] = arr[i][j] + (dp[j] == min1st ? min2nd : min1st);

                if (tmpDp[j] < tmpMin1st) {
                    tmpMin2nd = tmpMin1st;
                    tmpMin1st = tmpDp[j];
                }
                else if (tmpDp[j] < tmpMin2nd) {
                    tmpMin2nd = tmpDp[j];
                }
            }

            dp = tmpDp;
            min1st = tmpMin1st;
            min2nd = tmpMin2nd;
        }

        return min1st;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> arr = { {1,2,3},{4,5,6},{7,8,9} };
    check.checkInt(13, o.minFallingPathSum(arr));

    arr = { {1,2,3} };
    check.checkInt(1, o.minFallingPathSum(arr));

    arr = { {0,10,10},{0,0,1},{10,0,10} };
    check.checkInt(1, o.minFallingPathSum(arr));

    arr = { {1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10} };
    check.checkInt(15, o.minFallingPathSum(arr));

    arr = { {1,2,3,4,5,6,7,8,9,10},{10,9,8,7,6,5,4,3,2,1},{1,2,3,4,5,6,7,8,9,10},{10,9,8,7,6,5,4,3,2,1},{1,2,3,4,5,6,7,8,9,10},{10,9,8,7,6,5,4,3,2,1},{1,2,3,4,5,6,7,8,9,10},{10,9,8,7,6,5,4,3,2,1},{1,2,3,4,5,6,7,8,9,10},{10,9,8,7,6,5,4,3,2,1} };
    check.checkInt(10, o.minFallingPathSum(arr));
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
