/* 循环轮转矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的整数矩阵 grid​​​ ，其中 m 和 n 都是 偶数 ；另给你一个整数 k 。

矩阵由若干层组成，如下图所示，每种颜色代表一层：



矩阵的循环轮转是通过分别循环轮转矩阵中的每一层完成的。在对某一层进行一次循环旋转操作时，层中的每一个元素将会取代其 逆时针 方向的相邻元素。轮转示例如下：


返回执行 k 次循环轮转操作后的矩阵。

 

示例 1：


输入：grid = [[40,10],[30,20]], k = 1
输出：[[10,20],[40,30]]
解释：上图展示了矩阵在执行循环轮转操作时每一步的状态。
示例 2：


输入：grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
输出：[[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
解释：上图展示了矩阵在执行循环轮转操作时每一步的状态。
 

提示：

m == grid.length
n == grid[i].length
2 <= m, n <= 50
m 和 n 都是 偶数
1 <= grid[i][j] <= 5000
1 <= k <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cyclically-rotating-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int i, j, m = grid.size(), n = grid[0].size();
        int i1 = 0, j1 = 0, i2 = 0, j2 = n - 1, i3 = m - 1, j3 = 0, i4 = m - 1, j4 = n - 1;

        while (i1 < i3 && j1 < j2) {
            deque<int> nums;

            for (i = i1; i <= i3; ++i) {
                nums.push_back(grid[i][j1]);
            }

            for (j = j1 + 1; j < j2; ++j) {
                nums.push_back(grid[i3][j]);
            }

            for (i = i4; i >= i2; --i) {
                nums.push_back(grid[i][j4]);
            }

            for (j = j2 - 1; j > j1; --j) {
                nums.push_back(grid[i2][j]);
            }

            int len = 2 * (i3 - i1 + 1) + 2 * (j4 - j3 - 1);
            rotate(nums, k % len);
            
            for (i = i1; i <= i3; ++i) {
                grid[i][j1] = nums.front();
                nums.pop_front();
            }

            for (j = j1 + 1; j < j2; ++j) {
                grid[i3][j] = nums.front();
                nums.pop_front();
            }

            for (i = i4; i >= i2; --i) {
                grid[i][j4] = nums.front();
                nums.pop_front();
            }

            for (j = j2 - 1; j > j1; --j) {
                grid[i2][j] = nums.front();
                nums.pop_front();
            }

            ++i1, ++j1;
            ++i2, --j2;
            --i3, ++j3;
            --i4, --j4;
        }

        return grid;
    }

    void rotate(deque<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            nums.push_front(nums.back());
            nums.pop_back();
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {40,10},{30,20} };
    vector<vector<int>> actual = o.rotateGrid(grid, 1);
    vector<vector<int>> expected = { {10,20},{40,30} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
    actual = o.rotateGrid(grid, 2);
    expected = { {3,4,8,12},{2,11,10,16},{1,7,6,15},{5,9,13,14} };
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
