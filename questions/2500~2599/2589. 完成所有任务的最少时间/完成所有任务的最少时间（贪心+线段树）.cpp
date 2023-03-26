// 完成所有任务的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int start;
    int end;
    int value;
    int lazy;  // lazy标记设计为当前节点的value更新完毕，暂时没有传递到子节点，记录下更新的值。当有需要的时候，再传递更新值到子节点。
    Node* left;
    Node* right;

    Node() : start(0), end(0), value(0), lazy(0), left(NULL), right(NULL) {}
    Node(int s, int e) : start(s), end(e), value(0), lazy(0), left(NULL), right(NULL) {}
    Node(int s, int e, int v) : start(s), end(e), value(v), lazy(0), left(NULL), right(NULL) {}
    Node(int s, int e, int v, bool _lazy, Node* l, Node* r) : start(s), end(e), value(v), lazy(_lazy), left(l), right(r) {}
};

class SegmentTree {
public:
    SegmentTree(int size_) {
        size = size_;
        root = create(0, size - 1);
    }

    int query(int start, int end) {  // 区间查询，这里是求区间内1的个数
        return query(root, start, end);
    }

    void update(int start, int end) {  // 区间更新，这里是将区间内的0全部更新为1
        return update(root, start, end);
    }

    int getIdleIndex(int idle, int end) {  // 查询index的位置，使得[index, end]范围内有idle个0
        if (end != size - 1) {
            idle += (size - 1 - end + query(end + 1, size - 1));
        }

        Node* node = root;
        while (node->end - node->start + 1 - node->value != idle) {
            pushDown(node);
            if (node->right->end - node->right->start + 1 - node->right->value >= idle) {
                node = node->right;
            }
            else {
                idle -= node->right->end - node->right->start + 1 - node->right->value;
                node = node->left;
            }
        }

        return node->start;
    }

private:
    Node* root;
    int size;

    Node* create(int start, int end) {
        Node* node = new Node(start, end);
        if (start == end) {
            node->value = 0;
        }
        else {
            int mid = (start + end) / 2;
            Node* left = create(start, mid);
            Node* right = create(mid + 1, end);
            node->left = left;
            node->right = right;
            node->value = left->value + right->value;  // 线段树求和操作，也可以是求最大值、最小值等
        }

        return node;
    }

    int query(Node* node, int start, int end) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，求和操作返回0
            return 0;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是查询区间的子集，返回当前区间的值
            return node->value;
        }

        pushDown(node);  // 如果有必要，先将lazy标记往下传

        return query(node->left, start, end) + query(node->right, start, end);  // 当前区间和查询区间有交集，递归查询左右子树，并求和
    }

    void update(Node* node, int start, int end) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，直接返回
            return;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是更新区间的子集
            node->value = node->end - node->start + 1;  // 更新当前区间的value，全部更新为1后value为区间长度
            node->lazy = 1;  // 标记lazy，暂不往下传递
            return;
        }

        pushDown(node);  // 当前区间和更新区间有交集，没办法了，lazy标记往下传，把以前积攒的更新处理掉
        update(node->left, start, end);
        update(node->right, start, end);
        node->value = node->left->value + node->right->value;
    }

    void pushDown(Node* node) {  // 将lazy标记传递给左右子树
        if (node->lazy != 0) {
            update(node->left, node->left->start, node->left->end);
            update(node->right, node->right->start, node->right->end);
            node->lazy = 0;  // 传递下去以后，自己的lazy标记被清除
        }
    }
};

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int maxTime = 2000, minTime = 0;
        SegmentTree tree(maxTime + 1);

        sort(tasks.begin(), tasks.end(), vectorCompare);

        for (auto& task : tasks) {
            int busy = tree.query(task[0], task[1]);
            if (busy < task[2]) {
                int idle = task[2] - busy;
                minTime += idle;
                tree.update(tree.getIdleIndex(idle, task[1]), task[1]);
            }
        }

        return minTime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> tasks = { {2,3,1},{4,5,1},{1,5,2} };
    check.checkInt(2, o.findMinimumTime(tasks));

    tasks = { {1,3,2},{2,5,3},{5,6,2} };
    check.checkInt(4, o.findMinimumTime(tasks));
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
