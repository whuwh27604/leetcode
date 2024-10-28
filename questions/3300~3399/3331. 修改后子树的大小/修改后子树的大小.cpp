/* 修改后子树的大小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点且根节点为编号 0 的树，节点编号为 0 到 n - 1 。这棵树用一个长度为 n 的数组 parent 表示，其中 parent[i] 是第 i 个节点的父亲节点的编号。由于节点 0 是根，parent[0] == -1 。

给你一个长度为 n 的字符串 s ，其中 s[i] 是节点 i 对应的字符。

对于节点编号从 1 到 n - 1 的每个节点 x ，我们 同时 执行以下操作 一次 ：

找到距离节点 x 最近 的祖先节点 y ，且 s[x] == s[y] 。
如果节点 y 不存在，那么不做任何修改。
否则，将节点 x 与它父亲节点之间的边 删除 ，在 x 与 y 之间连接一条边，使 y 变为 x 新的父节点。
请你返回一个长度为 n 的数组 answer ，其中 answer[i] 是 最终 树中，节点 i 为根的子树的 大小 。

一个 子树 subtree 指的是节点 subtree 和它所有的后代节点。



示例 1：

输入：parent = [-1,0,0,1,1,1], s = "abaabc"

输出：[6,3,1,1,1,1]

解释：



节点 3 的父节点从节点 1 变为节点 0 。

示例 2：

输入：parent = [-1,0,4,0,1], s = "abbba"

输出：[5,2,1,1,1]

解释：



以下变化会同时发生：

节点 4 的父节点从节点 1 变为节点 0 。
节点 2 的父节点从节点 4 变为节点 1 。


提示：

n == parent.length == s.length
1 <= n <= 105
对于所有的 i >= 1 ，都有 0 <= parent[i] <= n - 1 。
parent[0] == -1
parent 表示一棵合法的树。
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = (int)s.size();
        vector<vector<int>> adjs(n);
        vector<int> last(26, -1);
        vector<int> subSize(n, 1);

        getAdjs(n, parent, adjs);
        adjust(0, parent, s, adjs, last);
        adjs.clear();
        adjs.resize(n);
        getAdjs(n, parent, adjs);
        getSubSize(0, adjs, subSize);

        return subSize;
    }

    void getAdjs(int n, vector<int>& parent, vector<vector<int>>& adjs) {
        for (int i = 1; i < n; ++i) {
            adjs[parent[i]].push_back(i);
        }
    }

    void adjust(int node, vector<int>& parent, string& s, vector<vector<int>>& adjs, vector<int>& last) {
        int idx = s[node] - 'a';
        if (last[idx] != -1) {
            parent[node] = last[idx];
        }

        int save = last[idx];
        last[idx] = node;

        for (int next : adjs[node]) {
            adjust(next, parent, s, adjs, last);
        }

        last[idx] = save;  // 注意回溯，函数返回之前恢复上一个last[idx]
    }

    int getSubSize(int node, vector<vector<int>>& adjs, vector<int>& subSize) {
        int size = 1;

        for (int next : adjs[node]) {
            size += getSubSize(next, adjs, subSize);
        }

        return subSize[node] = size;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> parent = { -1,0,0,1,1,1 };
    vector<int> actual = o.findSubtreeSizes(parent, "abaabc");
    vector<int> expected = { 6,3,1,1,1,1 };
    check.checkIntVector(expected, actual);

    parent = { -1,0,4,0,1 };
    actual = o.findSubtreeSizes(parent, "abbba");
    expected = { 5,2,1,1,1 };
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
