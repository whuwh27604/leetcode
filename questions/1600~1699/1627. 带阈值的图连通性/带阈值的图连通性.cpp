/* 带阈值的图连通性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 座城市，编号从 1 到 n 。编号为 x 和 y 的两座城市直接连通的前提是： x 和 y 的公因数中，至少有一个 严格大于 某个阈值 threshold 。更正式地说，如果存在整数 z ，且满足以下所有条件，则编号 x 和 y 的城市之间有一条道路：

x % z == 0
y % z == 0
z > threshold
给你两个整数 n 和 threshold ，以及一个待查询数组，请你判断每个查询 queries[i] = [ai, bi] 指向的城市 ai 和 bi 是否连通（即，它们之间是否存在一条路径）。

返回数组 answer ，其中answer.length == queries.length 。如果第 i 个查询中指向的城市 ai 和 bi 连通，则 answer[i] 为 true ；如果不连通，则 answer[i] 为 false 。

 

示例 1：



 

输入：n = 6, threshold = 2, queries = [[1,4],[2,5],[3,6]]
输出：[false,false,true]
解释：每个数的因数如下：
1:   1
2:   1, 2
3:   1, 3
4:   1, 2, 4
5:   1, 5
6:   1, 2, 3, 6
所有大于阈值的的因数已经加粗标识，只有城市 3 和 6 共享公约数 3 ，因此结果是：
[1,4]   1 与 4 不连通
[2,5]   2 与 5 不连通
[3,6]   3 与 6 连通，存在路径 3--6
示例 2：



 

输入：n = 6, threshold = 0, queries = [[4,5],[3,4],[3,2],[2,6],[1,3]]
输出：[true,true,true,true,true]
解释：每个数的因数与上一个例子相同。但是，由于阈值为 0 ，所有的因数都大于阈值。因为所有的数字共享公因数 1 ，所以所有的城市都互相连通。
示例 3：



 

输入：n = 5, threshold = 1, queries = [[4,5],[4,5],[3,2],[2,3],[3,4]]
输出：[false,false,false,false,false]
解释：只有城市 2 和 4 共享的公约数 2 严格大于阈值 1 ，所以只有这两座城市是连通的。
注意，同一对节点 [x, y] 可以有多个查询，并且查询 [x，y] 等同于查询 [y，x] 。
 

提示：

2 <= n <= 104
0 <= threshold <= n
1 <= queries.length <= 105
queries[i].length == 2
1 <= ai, bi <= cities
ai != bi

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/graph-connectivity-with-threshold
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);
        sizes.resize(size, 1);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);  // 路径压缩，父节点设置为根节点
        }

        return parents[x];
    }

    void merge(int x, int y) {
        int parentX = find(x), parentY = find(y);

        if (parentX != parentY) {
            if (sizes[parentX] < sizes[parentY]) {
                swap(parentX, parentY);
            }

            parents[parentY] = parentX;  // 把小的集合合并到大的
            sizes[parentX] += sizes[parentY];
        }
    }

private:
    vector<int> parents;
    vector<int> sizes;
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int i, size = queries.size();
        DSU dsu(n + 1);
        vector<bool> ans(size, true);

        if (threshold != 0) {
            for (int num = threshold + 1; num <= n / 2; ++num) {
                for (int multi = num + num; multi <= n; multi += num) {
                    dsu.merge(num, multi);
                }
            }

            for (i = 0; i < size; ++i) {
                ans[i] = (dsu.find(queries[i][0]) == dsu.find(queries[i][1]));
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {1,4},{2,5},{3,6} };
    vector<bool> actual = o.areConnected(6, 2, queries);
    vector<bool> expected = { false,false,true };
    check.checkBoolVector(expected, actual);

    queries = { {4,5},{3,4},{3,2},{2,6},{1,3} };
    actual = o.areConnected(6, 0, queries);
    expected = { true,true,true,true,true };
    check.checkBoolVector(expected, actual);

    queries = { {4,5},{4,5},{3,2},{2,3},{3,4} };
    actual = o.areConnected(5, 1, queries);
    expected = { false,false,false,false,false };
    check.checkBoolVector(expected, actual);

    queries = { {6,8},{6,9},{8,9} };
    actual = o.areConnected(9, 1, queries);
    expected = { true,true,true };
    check.checkBoolVector(expected, actual);

    queries = { {6,8},{6,9},{8,9} };
    actual = o.areConnected(10000, 1, queries);
    expected = { true,true,true };
    check.checkBoolVector(expected, actual);
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
