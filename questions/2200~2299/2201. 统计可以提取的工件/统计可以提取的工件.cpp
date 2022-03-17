/* 统计可以提取的工件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
存在一个 n x n 大小、下标从 0 开始的网格，网格中埋着一些工件。给你一个整数 n 和一个下标从 0 开始的二维整数数组 artifacts ，artifacts 描述了矩形工件的位置，其中 artifacts[i] = [r1i, c1i, r2i, c2i] 表示第 i 个工件在子网格中的填埋情况：

(r1i, c1i) 是第 i 个工件 左上 单元格的坐标，且
(r2i, c2i) 是第 i 个工件 右下 单元格的坐标。
你将会挖掘网格中的一些单元格，并清除其中的填埋物。如果单元格中埋着工件的一部分，那么该工件这一部分将会裸露出来。如果一个工件的所有部分都都裸露出来，你就可以提取该工件。

给你一个下标从 0 开始的二维整数数组 dig ，其中 dig[i] = [ri, ci] 表示你将会挖掘单元格 (ri, ci) ，返回你可以提取的工件数目。

生成的测试用例满足：

不存在重叠的两个工件。
每个工件最多只覆盖 4 个单元格。
dig 中的元素互不相同。
 

示例 1：


输入：n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1]]
输出：1
解释：
不同颜色表示不同的工件。挖掘的单元格用 'D' 在网格中进行标记。
有 1 个工件可以提取，即红色工件。
蓝色工件在单元格 (1,1) 的部分尚未裸露出来，所以无法提取该工件。
因此，返回 1 。
示例 2：


输入：n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1],[1,1]]
输出：2
解释：红色工件和蓝色工件的所有部分都裸露出来（用 'D' 标记），都可以提取。因此，返回 2 。
 

提示：

1 <= n <= 1000
1 <= artifacts.length, dig.length <= min(n2, 105)
artifacts[i].length == 4
dig[i].length == 2
0 <= r1i, c1i, r2i, c2i, ri, ci <= n - 1
r1i <= r2i
c1i <= c2i
不存在重叠的两个工件
每个工件 最多 只覆盖 4 个单元格
dig 中的元素互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-artifacts-that-can-be-extracted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int count = 0;

        for (auto& d : dig) {
            grid[d[0]][d[1]] = 1;
        }

        for (auto& artifact : artifacts) {
            if (check(grid, artifact)) {
                ++count;
            }
        }

        return count;
    }

    bool check(vector<vector<int>>& grid, vector<int>& artifact) {
        for (int r = artifact[0]; r <= artifact[2]; ++r) {
            for (int c = artifact[1]; c <= artifact[3]; ++c) {
                if (grid[r][c] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> artifacts = { {0,0,0,0},{0,1,1,1} };
    vector<vector<int>> dig = { {0,0},{0,1} };
    check.checkInt(1, o.digArtifacts(2, artifacts, dig));

    artifacts = { {0,0,0,0},{0,1,1,1} };
    dig = { {0,0},{0,1},{1,1} };
    check.checkInt(2, o.digArtifacts(2, artifacts, dig));

    artifacts = { {0,2,0,5},{0,1,1,1},{3,0,3,3},{4,4,4,4},{2,1,2,4} };
    dig = { {0,2},{0,3},{0,4},{2,0},{2,1},{2,2},{2,5},{3,0},{3,1},{3,3},{3,4},{4,0},{4,3},{4,5},{5,0},{5,1},{5,2},{5,4},{5,5},{1,2},{1,3},{3,2} };
    check.checkInt(1, o.digArtifacts(6, artifacts, dig));

    artifacts = { {3,1,4,1},{1,1,2,2},{1,0,2,0},{4,3,4,4},{0,3,1,4},{2,3,3,4} };
    dig = { {0,0},{2,1},{2,0},{2,3},{4,3},{2,4},{4,1},{0,2},{4,0},{3,1},{1,2},{1,3},{3,2} };
    check.checkInt(1, o.digArtifacts(5, artifacts, dig));
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
