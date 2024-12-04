/* 二叉搜索树染色.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣城，本次试炼主题为「二叉搜索树染色」。

每位勇士面前设有一个二叉搜索树的模型，模型的根节点为 root，树上的各个节点值均不重复。初始时，所有节点均为蓝色。现在按顺序对这棵二叉树进行若干次操作， ops[i] = [type, x, y] 表示第 i 次操作为：

type 等于 0 时，将节点值范围在 [x, y] 的节点均染蓝
type 等于 1 时，将节点值范围在 [x, y] 的节点均染红
请返回完成所有染色后，该二叉树中红色节点的数量。

注意：

题目保证对于每个操作的 x、y 值定出现在二叉搜索树节点中
示例 1：

输入：root = [1,null,2,null,3,null,4,null,5], ops = [[1,2,4],[1,1,3],[0,3,5]]

输出：2

解释： 第 0 次操作，将值为 2、3、4 的节点染红； 第 1 次操作，将值为 1、2、3 的节点染红； 第 2 次操作，将值为 3、4、5 的节点染蓝； 因此，最终值为 1、2 的节点为红色节点，返回数量 2image.png

示例 2：

输入：root = [4,2,7,1,null,5,null,null,null,null,6] ops = [[0,2,2],[1,1,5],[0,4,5],[1,5,7]]

输出：5

解释： 第 0 次操作，将值为 2 的节点染蓝； 第 1 次操作，将值为 1、2、4、5 的节点染红； 第 2 次操作，将值为 4、5 的节点染蓝； 第 3 次操作，将值为 5、6、7 的节点染红； 因此，最终值为 1、2、5、6、7 的节点为红色节点，返回数量 5image.png

提示：

1 <= 二叉树节点数量 <= 10^5
1 <= ops.length <= 10^5
ops[i].length == 3
ops[i][0] 仅为 0 or 1
0 <= ops[i][1] <= ops[i][2] <= 10^9
0 <= 节点值 <= 10^9
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Node {
public:
    int start;
    int end;
    int count;
    int lazy;  // lazy标记设计为当前节点的count更新完毕，暂时没有传递到子节点，记录下更新的值。当有需要的时候，再传递更新值到子节点。
    Node* left;
    Node* right;

    Node(int s, int e) : start(s), end(e), count(0), lazy(-1), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    SegmentTree(int size_) {
        size = size_;
        root = create(0, size - 1);
    }

    int query() {  // 查询整个区间内1的个数
        return query(root, 0, size - 1);
    }

    void update(int start, int end, int val) {  // 区间更新，将区间[start, end]的值设置为val
        return update(root, start, end, val);
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

    int query(Node* node, int start, int end) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，返回0
            return 0;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是查询区间的子集，返回当前区间的值
            return node->count;
        }

        pushDown(node);  // 如果有必要，先将lazy标记往下传

        return query(node->left, start, end) + query(node->right, start, end);  // 当前区间和查询区间有交集，递归查询左右子树，并求和
    }

    void update(Node* node, int start, int end, int val) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，直接返回
            return;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是更新区间的子集
            node->count = (val == 0 ? 0 : node->end - node->start + 1);
            node->lazy = val;  // 标记lazy，暂不往下传递
            return;
        }

        pushDown(node);  // 当前区间和更新区间有交集，没办法了，lazy标记往下传，把以前积攒的更新处理掉
        update(node->left, start, end, val);
        update(node->right, start, end, val);
        node->count = node->left->count + node->right->count;
    }

    void pushDown(Node* node) {  // 将lazy标记传递给左右子树
        if (node->lazy != -1) {
            update(node->left, node->left->start, node->left->end, node->lazy);
            update(node->right, node->right->start, node->right->end, node->lazy);
            node->lazy = -1;  // 传递下去以后，自己的lazy标记被清除
        }
    }
};

class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        unordered_map<int, int> indices;
        int size = value2Indices(root, indices);
        SegmentTree tree(size);

        for (auto& op : ops) {
            tree.update(indices[op[1]], indices[op[2]], op[0]);
        }

        return tree.query();
    }

    int value2Indices(TreeNode* root, unordered_map<int, int>& indices) {
        vector<int> vals;

        DFS(root, vals);
        int size = (int)vals.size();

        for (int i = 0; i < size; ++i) {
            indices[vals[i]] = i;
        }

        return size;
    }

    void DFS(TreeNode* node, vector<int>& vals) {
        if (node->left != NULL) {
            DFS(node->left, vals);
        }

        vals.push_back(node->val);

        if (node->right != NULL) {
            DFS(node->right, vals);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,INT_MIN,2,INT_MIN,3,INT_MIN,4,INT_MIN,5 };
    vector<vector<int>> ops = { {1,2,4},{1,1,3},{0,3,5} };
    check.checkInt(2, o.getNumber(createTree(values), ops));

    values = { 4,2,7,1,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,6 };
    ops = { {0,2,2},{1,1,5},{0,4,5},{1,5,7} };
    check.checkInt(5, o.getNumber(createTree(values), ops));
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
