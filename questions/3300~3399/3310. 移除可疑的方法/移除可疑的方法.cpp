/* 移除可疑的方法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在维护一个项目，该项目有 n 个方法，编号从 0 到 n - 1。

给你两个整数 n 和 k，以及一个二维整数数组 invocations，其中 invocations[i] = [ai, bi] 表示方法 ai 调用了方法 bi。

已知如果方法 k 存在一个已知的 bug。那么方法 k 以及它直接或间接调用的任何方法都被视为 可疑方法 ，我们需要从项目中移除这些方法。

只有当一组方法没有被这组之外的任何方法调用时，这组方法才能被移除。

返回一个数组，包含移除所有 可疑方法 后剩下的所有方法。你可以以任意顺序返回答案。如果无法移除 所有 可疑方法，则 不 移除任何方法。



示例 1:

输入: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]

输出: [0,1,2,3]

解释:



方法 2 和方法 1 是可疑方法，但它们分别直接被方法 3 和方法 0 调用。由于方法 3 和方法 0 不是可疑方法，我们无法移除任何方法，故返回所有方法。

示例 2:

输入: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]

输出: [3,4]

解释:



方法 0、方法 1 和方法 2 是可疑方法，且没有被任何其他方法直接调用。我们可以移除它们。

示例 3:

输入: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]

输出: []

解释:



所有方法都是可疑方法。我们可以移除它们。



提示:

1 <= n <= 105
0 <= k <= n - 1
0 <= invocations.length <= 2 * 105
invocations[i] == [ai, bi]
0 <= ai, bi <= n - 1
ai != bi
invocations[i] != invocations[j]
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjs(n);
        getAdjs(invocations, adjs);

        vector<bool> isSuspicious(n, false);
        getSuspicious(n, k, adjs, isSuspicious);

        vector<int> remainings;
        if (callSuspicious(n, adjs, isSuspicious)) {
            for (int i = 0; i < n; ++i) {
                remainings.push_back(i);
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (!isSuspicious[i]) {
                    remainings.push_back(i);
                }
            }
        }

        return remainings;
    }

    void getAdjs(vector<vector<int>>& invocations, vector<vector<int>>& adjs) {
        for (auto& invocation : invocations) {
            adjs[invocation[0]].push_back(invocation[1]);
        }
    }

    void getSuspicious(int n, int k, vector<vector<int>>& adjs, vector<bool>& isSuspicious) {
        isSuspicious[k] = true;
        vector<bool> visited(n, false);
        visited[k] = true;
        queue<int> nodes;
        nodes.push(k);

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (int next : adjs[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    nodes.push(next);
                    isSuspicious[next] = true;
                }
            }
        }
    }

    bool callSuspicious(int n, vector<vector<int>>& adjs, vector<bool>& isSuspicious) {
        vector<bool> visited(n, false);
        queue<int> nodes;

        for (int node = 0; node < n; ++node) {
            if (!isSuspicious[node]) {
                nodes.push(node);
                visited[node] = true;
            }
        }

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (int next : adjs[node]) {
                if (isSuspicious[next]) {
                    return true;
                }

                if (!visited[next]) {
                    visited[next] = true;
                    nodes.push(next);
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> invocations = { {1,2},{0,1},{3,2} };
    vector<int> actual = o.remainingMethods(4, 1, invocations);
    vector<int> expected = { 0,1,2,3 };
    check.checkIntVectorRandomOrder(expected, actual);

    invocations = { {1,2},{0,2},{0,1},{3,4} };
    actual = o.remainingMethods(5, 0, invocations);
    expected = { 3,4 };
    check.checkIntVectorRandomOrder(expected, actual);

    invocations = { {1,2},{0,1},{2,0} };
    actual = o.remainingMethods(3, 2, invocations);
    expected = {  };
    check.checkIntVectorRandomOrder(expected, actual);

    invocations = { {2,0} };
    actual = o.remainingMethods(3, 0, invocations);
    expected = { 0,1,2 };
    check.checkIntVectorRandomOrder(expected, actual);
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
