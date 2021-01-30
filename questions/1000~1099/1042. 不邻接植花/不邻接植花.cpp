/* 不邻接植花.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。

paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。

另外，没有花园有 3 条以上的路径可以进入或者离开。

你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。

以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。

 

示例 1：

输入：N = 3, paths = [[1,2],[2,3],[3,1]]
输出：[1,2,3]
示例 2：

输入：N = 4, paths = [[1,2],[3,4]]
输出：[1,2,1,2]
示例 3：

输入：N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
输出：[1,2,3,4]
 

提示：

1 <= N <= 10000
0 <= paths.size <= 20000
不存在花园有 4 条或者更多路径可以进入或离开。
保证存在答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flower-planting-with-no-adjacent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> flowerTypes(N, 0);
        unordered_map<int, vector<int>> gardenAdjs;

        createAdjsTable(paths, gardenAdjs);

        for (int i = 0; i < N; i++) {
            if (flowerTypes[i] != 0) {
                continue;
            }

            auto iter = gardenAdjs.find(i + 1);
            if (iter == gardenAdjs.end()) {
                flowerTypes[i] = 1;
                continue;
            }

            flowerTypes[i] = chooseType(iter->second, flowerTypes);
        }

        return flowerTypes;
    }

    void createAdjsTable(vector<vector<int>>& paths, unordered_map<int, vector<int>>& gardenAdjs) {
        for (unsigned int i = 0; i < paths.size(); i++) {
            auto iter = gardenAdjs.find(paths[i][0]);
            if (iter == gardenAdjs.end()) {
                gardenAdjs[paths[i][0]] = { paths[i][1] };
            }
            else {
                iter->second.push_back(paths[i][1]);
            }

            iter = gardenAdjs.find(paths[i][1]);
            if (iter == gardenAdjs.end()) {
                gardenAdjs[paths[i][1]] = { paths[i][0] };
            }
            else {
                iter->second.push_back(paths[i][0]);
            }
        }
    }

    int chooseType(vector<int>& adjs, vector<int>& flowerTypes) {
        int types[5] = { 0,1,2,3,4 };
        for (unsigned int i = 0; i < adjs.size(); i++) {
            int type = flowerTypes[adjs[i] - 1];
            if (type != 0) {
                types[type] = 0;
            }
        }

        for (int j = 1; j < 5; j++) {
            if (types[j] != 0) {
                return types[j];
            }
        }

        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> paths = { {1,2},{2,3},{3,1} };
    vector<int> actual = o.gardenNoAdj(3, paths);
    vector<int> expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    paths = { {1,2},{3,4} };
    actual = o.gardenNoAdj(4, paths);
    expected = { 1,2,1,2 };
    check.checkIntVector(expected, actual);

    paths = { {1,2},{2,3},{3,4},{4,1},{1,3},{2,4} };
    actual = o.gardenNoAdj(4, paths);
    expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    paths = { {1,2},{2,3},{3,1},{1,2},{2,3},{3,1} };
    actual = o.gardenNoAdj(3, paths);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    paths = {  };
    actual = o.gardenNoAdj(1, paths);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    paths = {  };
    actual = o.gardenNoAdj(2, paths);
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    paths = { {1,2} };
    actual = o.gardenNoAdj(2, paths);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    paths = { {1,2},{2,3},{3,4},{4,1},{1,3},{2,4},{5,6} };
    actual = o.gardenNoAdj(8, paths);
    expected = { 1,2,3,4,1,2,1,1 };
    check.checkIntVector(expected, actual);
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
