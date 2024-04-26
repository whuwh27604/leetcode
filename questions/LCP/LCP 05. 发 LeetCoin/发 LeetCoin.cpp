/* 发 LeetCoin.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣决定给一个刷题团队发LeetCoin作为奖励。同时，为了监控给大家发了多少LeetCoin，力扣有时候也会进行查询。



该刷题团队的管理模式可以用一棵树表示：

团队只有一个负责人，编号为1。除了该负责人外，每个人有且仅有一个领导（负责人没有领导）；
不存在循环管理的情况，如A管理B，B管理C，C管理A。


力扣想进行的操作有以下三种：

给团队的一个成员（也可以是负责人）发一定数量的LeetCoin；
给团队的一个成员（也可以是负责人），以及他/她管理的所有人（即他/她的下属、他/她下属的下属，……），发一定数量的LeetCoin；
查询某一个成员（也可以是负责人），以及他/她管理的所有人被发到的LeetCoin之和。


输入：

N表示团队成员的个数（编号为1～N，负责人为1）；
leadership是大小为(N - 1) * 2的二维数组，其中每个元素[a, b]代表b是a的下属；
operations是一个长度为Q的二维数组，代表以时间排序的操作，格式如下：
operations[i][0] = 1: 代表第一种操作，operations[i][1]代表成员的编号，operations[i][2]代表LeetCoin的数量；
operations[i][0] = 2: 代表第二种操作，operations[i][1]代表成员的编号，operations[i][2]代表LeetCoin的数量；
operations[i][0] = 3: 代表第三种操作，operations[i][1]代表成员的编号；
输出：

返回一个数组，数组里是每次查询的返回值（发LeetCoin的操作不需要任何返回值）。由于发的LeetCoin很多，请把每次查询的结果模1e9+7 (1000000007)。



示例 1：

输入：N = 6, leadership = [[1, 2], [1, 6], [2, 3], [2, 5], [1, 4]], operations = [[1, 1, 500], [2, 2, 50], [3, 1], [2, 6, 15], [3, 1]]
输出：[650, 665]
解释：团队的管理关系见下图。
第一次查询时，每个成员得到的LeetCoin的数量分别为（按编号顺序）：500, 50, 50, 0, 50, 0;
第二次查询时，每个成员得到的LeetCoin的数量分别为（按编号顺序）：500, 50, 50, 0, 50, 15.




限制：

1 <= N <= 50000
1 <= Q <= 50000
operations[i][0] != 3 时，1 <= operations[i][2] <= 5000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

int mod = 1000000007;

class Node {
public:
    int start;
    int end;
    int sum;
    int lazy;  // lazy标记设计为当前节点的value更新完毕，暂时没有传递到子节点，记录下更新的值。当有需要的时候，再传递更新值到子节点。
    Node* left;
    Node* right;

    Node(int s, int e) : start(s), end(e), sum(0), lazy(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    SegmentTree(int size_) {
        size = size_;
        root = create(0, size - 1);
    }

    int querySum(int start, int end) {  // 查询区间[start, end]内x的sum
        return querySum(root, start, end);
    }

    void update(int start, int end, int add) {  // 区间更新，将区间[start, end]内x的值加add
        return update(root, start, end, add);
    }

private:
    Node* root;
    int size;

    Node* create(int start, int end) {
        Node* node = new Node(start, end);
        if (start != end) {
            int mid = (start + end) / 2;
            node->left = create(start, mid);
            node->right = create(mid + 1, end);
        }

        return node;
    }

    int querySum(Node* node, int start, int end) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，求和操作返回0
            return 0;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是查询区间的子集，返回当前区间的值
            return node->sum;
        }

        pushDown(node);  // 如果有必要，先将lazy标记往下传

        return (querySum(node->left, start, end) + querySum(node->right, start, end)) % mod;  // 当前区间和查询区间有交集，递归查询左右子树，并求和
    }

    void update(Node* node, int start, int end, int add) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，直接返回
            return;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是更新区间的子集
            long long len = (long long)node->end - node->start + 1;
            node->sum = (node->sum + len * add) % mod;
            node->lazy += add;  // 标记lazy，暂不往下传递
            return;
        }

        pushDown(node);  // 当前区间和更新区间有交集，没办法了，lazy标记往下传，把以前积攒的更新处理掉
        update(node->left, start, end, add);
        update(node->right, start, end, add);
        node->sum = (node->left->sum + node->right->sum) % mod;
    }

    void pushDown(Node* node) {  // 将lazy标记传递给左右子树
        if (node->lazy != 0) {
            update(node->left, node->left->start, node->left->end, node->lazy);
            update(node->right, node->right->start, node->right->end, node->lazy);
            node->lazy = 0;  // 传递下去以后，自己的lazy标记被清除
        }
    }
};

class Solution {
public:
	vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
		vector<vector<int>> children(n + 1);
		getChildren(leadership, children);

		vector<int> start(n + 1, 0);
		vector<int> indices(n + 1);
		int index = 0;
		LRD(1, index, children, start, indices);

        SegmentTree tree(n);
        vector<int> ans;

        for (auto& operation : operations) {
            int left = start[operation[1]], right = indices[operation[1]];
            if (operation[0] == 1) {
                tree.update(right, right, operation[2]);
            }
            else if (operation[0] == 2) {
                tree.update(left, right, operation[2]);
            }
            else {
                ans.push_back(tree.querySum(left, right));
            }
        }

        return ans;
	}

	void getChildren(vector<vector<int>>& leadership, vector<vector<int>>& children) {
		for (auto& leader : leadership) {
			int a = leader[0], b = leader[1];
			children[a].push_back(b);
		}
	}

	void LRD(int node, int& index, vector<vector<int>>& children, vector<int>& start, vector<int>& indices) {
		start[node] = index;

		for (int child : children[node]) {
			LRD(child, index, children, start, indices);
		}

		indices[node] = index++;
	}
};

int main()
{
	Solution o;
	CheckResult check;

    vector<vector<int>> leadership = { {1,2},{1,6},{2,3},{2,5},{1,4} };
    vector<vector<int>> operations = { {1,1,500},{2,2,50},{3,1},{2,6,15},{3,1} };
    vector<int> actual = o.bonus(6, leadership, operations);
    vector<int> expected = { 650, 665 };
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
