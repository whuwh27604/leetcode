/* 移除最多的同行或同列石头.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们将石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。

每次 move 操作都会移除一块所在行或者列上有其他石头存在的石头。

请你设计一个算法，计算最多能执行多少次 move 操作？

 

示例 1：

输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
输出：5
示例 2：

输入：stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
输出：3
示例 3：

输入：stones = [[0,0]]
输出：0
 

提示：

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int* parents = new int[20000];
        init(stones, parents);

        for (vector<int>& stone : stones) {
            unionSet(stone, parents);
        }

        unordered_set<int> parentsSet;
        for (vector<int>& stone : stones) {  // 把所有parent刷到最新，看看有几个集合
            int parent = findParent(stone[0], parents);
            parentsSet.insert(parent);
        }

        delete[] parents;
        return stones.size() - parentsSet.size();
    }

    void init(vector<vector<int>>& stones, int* parents) {
        for (vector<int>& stone : stones) {
            parents[stone[0]] = stone[0];  // 初始化每个点的parent为自己
            parents[stone[1] + 10000] = stone[1] + 10000;
        }
    }

    int findParent(int index, int* parents) {
        if (index != parents[index]) {
            parents[index] = findParent(parents[index], parents);
        }

        return parents[index];
    }

    void unionSet(vector<int>& stone, int* parents) {
        int parentX = findParent(stone[0], parents), parentY = findParent(stone[1] + 10000, parents);
        parents[parentX] = parentY;  // 合并x,y坐标的两个集合
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> stones = { {0,0} };
    check.checkInt(0, o.removeStones(stones));

    stones = { {0,0},{0,2},{1,1},{2,0},{2,2} };
    check.checkInt(3, o.removeStones(stones));

    stones = { {0,0},{0,1},{1,0},{1,2},{2,1},{2,2} };
    check.checkInt(5, o.removeStones(stones));

    stones = { {1,2},{1,3},{3,3},{3,1},{2,1},{1,0} };
    check.checkInt(5, o.removeStones(stones));
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
