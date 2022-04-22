/* 铺瓷砖.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你是一位施工队的工长，根据设计师的要求准备为一套设计风格独特的房子进行室内装修。

房子的客厅大小为 n x m，为保持极简的风格，需要使用尽可能少的 正方形 瓷砖来铺盖地面。

假设正方形瓷砖的规格不限，边长都是整数。

请你帮设计师计算一下，最少需要用到多少块方形瓷砖？

 

示例 1：



输入：n = 2, m = 3
输出：3
解释：3 块地砖就可以铺满卧室。
     2 块 1x1 地砖
     1 块 2x2 地砖
示例 2：



输入：n = 5, m = 8
输出：5
示例 3：



输入：n = 11, m = 13
输出：6
 

提示：

1 <= n <= 13
1 <= m <= 13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tiling-a-rectangle-with-the-fewest-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int tilingRectangle(int n, int m) {
        vector<vector<int>> rectangle(n, vector<int>(m, 0));
        int minSquares = n * m;

        DFS(rectangle, 0, minSquares);

        return minSquares;
    }

    void DFS(vector<vector<int>>& rectangle, int squares, int& minSquares) {
        if (squares == minSquares) {
            return;  // 已经不可能比minSquares更小，直接返回
        }

        int r = 0, c = 0;
        if (!findSquare(rectangle, r, c)) {
            minSquares = squares;  // rectangle已经全部贴满瓷砖，更新minSquares
            return;
        }

        int maxSize = getMaxSize(rectangle, r, c);  // 以[r, c]为左上顶点的最大正方形

        for (int size = maxSize; size > 0; --size) {  // 按照从大到小的顺序尝试，一般情况下用大的更有可能先贴满
            tiling(rectangle, r, c, size, 1);
            DFS(rectangle, squares + 1, minSquares);
            tiling(rectangle, r, c, size, 0);  // 回溯
        }
    }

    bool findSquare(vector<vector<int>>& rectangle, int& r, int& c) {
        for (r = 0; r < (int)rectangle.size(); ++r) {
            for (c = 0; c < (int)rectangle[0].size(); ++c) {
                if (rectangle[r][c] == 0) {
                    return true;
                }
            }
        }

        return false;
    }

    int getMaxSize(vector<vector<int>>& rectangle, int& r, int& c) {
        int size = 1, maxR = r + 1, maxC = c + 1, n = rectangle.size(), m = rectangle[0].size();

        while (maxR < n && maxC < m) {
            for (int i = r; i <= maxR; ++i) {
                if (rectangle[i][maxC] == 1) {
                    return size;
                }
            }

            for (int j = c; j <= maxC; ++j) {
                if (rectangle[maxR][j] == 1) {
                    return size;
                }
            }

            ++size, ++maxR, ++maxC;
        }

        return size;
    }

    void tiling(vector<vector<int>>& rectangle, int& r, int& c, int size, int what) {
        for (int i = r; i < r + size; ++i) {
            for (int j = c; j < c + size; ++j) {
                rectangle[i][j] = what;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.tilingRectangle(2, 3));
    check.checkInt(5, o.tilingRectangle(5, 8));
    check.checkInt(6, o.tilingRectangle(11, 13));
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
