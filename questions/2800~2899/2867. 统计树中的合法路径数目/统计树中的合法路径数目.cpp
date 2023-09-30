/* 统计树中的合法路径数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点的无向树，节点编号为 1 到 n 。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示节点 ui 和 vi 在树中有一条边。

请你返回树中的 合法路径数目 。

如果在节点 a 到节点 b 之间 恰好有一个 节点的编号是质数，那么我们称路径 (a, b) 是 合法的 。

注意：

路径 (a, b) 指的是一条从节点 a 开始到节点 b 结束的一个节点序列，序列中的节点 互不相同 ，且相邻节点之间在树上有一条边。
路径 (a, b) 和路径 (b, a) 视为 同一条 路径，且只计入答案 一次 。


示例 1：



输入：n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
输出：4
解释：恰好有一个质数编号的节点路径有：
- (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
- (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
- (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
- (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
只有 4 条合法路径。
示例 2：



输入：n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
输出：6
解释：恰好有一个质数编号的节点路径有：
- (1, 2) 因为路径 1 到 2 只包含一个质数 2 。
- (1, 3) 因为路径 1 到 3 只包含一个质数 3 。
- (1, 4) 因为路径 1 到 4 只包含一个质数 2 。
- (1, 6) 因为路径 1 到 6 只包含一个质数 3 。
- (2, 4) 因为路径 2 到 4 只包含一个质数 2 。
- (3, 6) 因为路径 3 到 6 只包含一个质数 3 。
只有 6 条合法路径。


提示：

1 <= n <= 105
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
输入保证 edges 形成一棵合法的树。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

const int maxN = 100000;
vector<int> primes;
vector<bool> isPrimes(maxN + 1, true);

void EulerFilter() {
    isPrimes[0] = isPrimes[1] = false;

    for (int num = 2; num <= maxN; ++num) {
        if (isPrimes[num]) {
            primes.push_back(num);
        }

        for (int prime : primes) {
            int composite = num * prime;
            if (composite > maxN) {
                break;
            }

            isPrimes[composite] = false;

            if (num % prime == 0) {
                break;
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        EulerFilter();
    }
}

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n + 1);
        vector<int> nonPrimesSetSize(n + 1, -1);
        long long paths = 0;

        init();
        getAdjs(edges, adjs);

        for (int node = 1; node <= n; ++node) {
            if (!isPrimes[node]) {
                continue;
            }

            long long totalNonPrimes = 0;

            for (int next : adjs[node]) {
                int nonPrimes = nonPrimesSetSize[next];
                if (nonPrimes == -1) {
                    nonPrimes = countNonPrimes(next, node, adjs);
                    setNonPrimes(next, node, nonPrimes, adjs, nonPrimesSetSize);
                }

                if (nonPrimes != 0) {
                    paths += nonPrimes;  // 从质数节点node到每一个非质数节点都是一个合法路径
                    paths += nonPrimes * totalNonPrimes;  // 当前非质数集合里面的每一个点到前面所有非质数集合的每一个点，都是一个合法路径
                    totalNonPrimes += nonPrimes;
                }
            }
        }

        return paths;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int countNonPrimes(int node, int parent, vector<vector<int>>& adjs) {
        if (isPrimes[node]) {
            return 0;
        }

        int nonPrimes = 1;

        for (int next : adjs[node]) {
            if (next != parent) {
                nonPrimes += countNonPrimes(next, node, adjs);
            }
        }

        return nonPrimes;
    }

    void setNonPrimes(int node, int parent, int nonPrimes, vector<vector<int>>& adjs, vector<int>& nonPrimesSetSize) {
        if (isPrimes[node]) {
            return;
        }

        nonPrimesSetSize[node] = nonPrimes;

        for (int next : adjs[node]) {
            if (next != parent) {
                setNonPrimes(next, node, nonPrimes, adjs, nonPrimesSetSize);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{1,3},{2,4},{2,5} };
    check.checkLongLong(4, o.countPaths(5, edges));

    edges = { {1,2},{1,3},{2,4},{3,5},{3,6} };
    check.checkLongLong(6, o.countPaths(6, edges));

    edges = getIntVectorVector("./testcase1.txt");
    check.checkLongLong(867193536, o.countPaths(100000, edges));
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
