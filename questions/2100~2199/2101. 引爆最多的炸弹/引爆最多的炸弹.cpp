/* 引爆最多的炸弹.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个炸弹列表。一个炸弹的 爆炸范围 定义为以炸弹为圆心的一个圆。

炸弹用一个下标从 0 开始的二维整数数组 bombs 表示，其中 bombs[i] = [xi, yi, ri] 。xi 和 yi 表示第 i 个炸弹的 X 和 Y 坐标，ri 表示爆炸范围的 半径 。

你需要选择引爆 一个 炸弹。当这个炸弹被引爆时，所有 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。

给你数组 bombs ，请你返回在引爆 一个 炸弹的前提下，最多 能引爆的炸弹数目。

 

示例 1：



输入：bombs = [[2,1,3],[6,1,4]]
输出：2
解释：
上图展示了 2 个炸弹的位置和爆炸范围。
如果我们引爆左边的炸弹，右边的炸弹不会被影响。
但如果我们引爆右边的炸弹，两个炸弹都会爆炸。
所以最多能引爆的炸弹数目是 max(1, 2) = 2 。
示例 2：



输入：bombs = [[1,1,5],[10,10,5]]
输出：1
解释：
引爆任意一个炸弹都不会引爆另一个炸弹。所以最多能引爆的炸弹数目为 1 。
示例 3：



输入：bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
输出：5
解释：
最佳引爆炸弹为炸弹 0 ，因为：
- 炸弹 0 引爆炸弹 1 和 2 。红色圆表示炸弹 0 的爆炸范围。
- 炸弹 2 引爆炸弹 3 。蓝色圆表示炸弹 2 的爆炸范围。
- 炸弹 3 引爆炸弹 4 。绿色圆表示炸弹 3 的爆炸范围。
所以总共有 5 个炸弹被引爆。
 

提示：

1 <= bombs.length <= 100
bombs[i].length == 3
1 <= xi, yi, ri <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detonate-the-maximum-bombs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int i, size = bombs.size(), maxDetonation = 0;
        vector<vector<int>> adjs(size);

        getAdjs(bombs, adjs);

        for (i = 0; i < size; ++i) {
            maxDetonation = max(maxDetonation, bfs(i, size, adjs));
        }

        return maxDetonation;
    }

    void getAdjs(vector<vector<int>>& bombs, vector<vector<int>>& adjs) {
        int i, j, size = bombs.size();

        for (i = 0; i < size; ++i) {
            long long squareR = bombs[i][2];
            squareR *= squareR;

            for (j = 0; j < size; ++j) {
                if (i != j) {
                    long long x = (long long)bombs[i][0] - bombs[j][0], y = (long long)bombs[i][1] - bombs[j][1];

                    if (x * x + y * y <= squareR) {  // i爆炸会引爆j，即从i到j可达
                        adjs[i].push_back(j);
                    }
                }
            }
        }
    }

    int bfs(int root, int size, vector<vector<int>>& adjs) {
        int count = 1;
        vector<bool> visited(size, false);
        visited[root] = true;

        queue<int> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (int next : adjs[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    ++count;
                    nodes.push(next);
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> bombs = {{2,1,3},{6,1,4}};
    check.checkInt(2,o.maximumDetonation(bombs));

    bombs = {{1,1,5},{10,10,5}};
    check.checkInt(1,o.maximumDetonation(bombs));

    bombs = { {1,1,100000} };
    check.checkInt(1, o.maximumDetonation(bombs));

    bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    check.checkInt(5,o.maximumDetonation(bombs));

    bombs = {{54,95,4},{99,46,3},{29,21,3},{96,72,8},{49,43,3},{11,20,3},{2,57,1},{69,51,7},{97,1,10},{85,45,2},{38,47,1},{83,75,3},{65,59,3},{33,4,1},{32,10,2},{20,97,8},{35,37,3}};
    check.checkInt(1,o.maximumDetonation(bombs));

    bombs = {{855,82,158},{17,719,430},{90,756,164},{376,17,340},{691,636,152},{565,776,5},{464,154,271},{53,361,162},{278,609,82},{202,927,219},{542,865,377},{330,402,270},{720,199,10},{986,697,443},{471,296,69},{393,81,404},{127,405,177}};
    check.checkInt(9,o.maximumDetonation(bombs));
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
