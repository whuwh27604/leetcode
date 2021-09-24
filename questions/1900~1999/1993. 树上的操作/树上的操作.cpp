/* 树上的操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点的树，编号从 0 到 n - 1 ，以父节点数组 parent 的形式给出，其中 parent[i] 是第 i 个节点的父节点。树的根节点为 0 号节点，所以 parent[0] = -1 ，因为它没有父节点。你想要设计一个数据结构实现树里面对节点的加锁，解锁和升级操作。

数据结构需要支持如下函数：

Lock：指定用户给指定节点 上锁 ，上锁后其他用户将无法给同一节点上锁。只有当节点处于未上锁的状态下，才能进行上锁操作。
Unlock：指定用户给指定节点 解锁 ，只有当指定节点当前正被指定用户锁住时，才能执行该解锁操作。
Upgrade：指定用户给指定节点 上锁 ，并且将该节点的所有子孙节点 解锁 。只有如下 3 个条件 全部 满足时才能执行升级操作：
指定节点当前状态为未上锁。
指定节点至少有一个上锁状态的子孙节点（可以是 任意 用户上锁的）。
指定节点没有任何上锁的祖先节点。
请你实现 LockingTree 类：

LockingTree(int[] parent) 用父节点数组初始化数据结构。
lock(int num, int user) 如果 id 为 user 的用户可以给节点 num 上锁，那么返回 true ，否则返回 false 。如果可以执行此操作，节点 num 会被 id 为 user 的用户 上锁 。
unlock(int num, int user) 如果 id 为 user 的用户可以给节点 num 解锁，那么返回 true ，否则返回 false 。如果可以执行此操作，节点 num 变为 未上锁 状态。
upgrade(int num, int user) 如果 id 为 user 的用户可以给节点 num 升级，那么返回 true ，否则返回 false 。如果可以执行此操作，节点 num 会被 升级 。
 

示例 1：



输入：
["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
[[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], [0, 1]]
输出：
[null, true, false, true, true, true, false]

解释：
LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
lockingTree.lock(2, 2);    // 返回 true ，因为节点 2 未上锁。
                           // 节点 2 被用户 2 上锁。
lockingTree.unlock(2, 3);  // 返回 false ，因为用户 3 无法解锁被用户 2 上锁的节点。
lockingTree.unlock(2, 2);  // 返回 true ，因为节点 2 之前被用户 2 上锁。
                           // 节点 2 现在变为未上锁状态。
lockingTree.lock(4, 5);    // 返回 true ，因为节点 4 未上锁。
                           // 节点 4 被用户 5 上锁。
lockingTree.upgrade(0, 1); // 返回 true ，因为节点 0 未上锁且至少有一个被上锁的子孙节点（节点 4）。
                           // 节点 0 被用户 1 上锁，节点 4 变为未上锁。
lockingTree.lock(0, 1);    // 返回 false ，因为节点 0 已经被上锁了。
 

提示：

n == parent.length
2 <= n <= 2000
对于 i != 0 ，满足 0 <= parent[i] <= n - 1
parent[0] == -1
0 <= num <= n - 1
1 <= user <= 104
parent 表示一棵合法的树。
lock ，unlock 和 upgrade 的调用 总共 不超过 2000 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/operations-on-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int user;
    Node* parent;
    vector<Node*> children;

    Node() : user(-1), parent(NULL) {}
};

class LockingTree {
public:
    LockingTree(vector<int>& parent) {
        int i, size = parent.size();
        nodes.resize(size);

        for (i = 0; i < size; ++i) {
            nodes[i] = new Node;
        }

        for (i = 1; i < size; ++i) {
            nodes[i]->parent = nodes[parent[i]];
            nodes[parent[i]]->children.push_back(nodes[i]);
        }
    }

    bool lock(int num, int user) {
        if (nodes[num]->user != -1) {
            return false;
        }

        nodes[num]->user = user;

        return true;
    }

    bool unlock(int num, int user) {
        if (nodes[num]->user != user) {
            return false;
        }

        nodes[num]->user = -1;

        return true;
    }

    bool upgrade(int num, int user) {
        if (!check(num)) {
            return false;
        }

        DFS4ChildrenUnlock(nodes[num]);
        nodes[num]->user = user;

        return true;
    }

    bool check(int num) {
        if (nodes[num]->user != -1) {
            return false;
        }

        if (!DFS4ChildrenState(nodes[num])) {
            return false;
        }

        Node* node = nodes[num]->parent;

        while (node != NULL) {
            if (node->user != -1) {
                return false;
            }

            node = node->parent;
        }

        return true;
    }

    bool DFS4ChildrenState(Node* node) {  // 任何一个children被锁则返回成功
        if (node->user != -1) {
            return true;
        }

        for (Node* child : node->children) {
            if (DFS4ChildrenState(child)) {
                return true;
            }
        }

        return false;
    }

    void DFS4ChildrenUnlock(Node* node) {  // 解锁所有children节点
        node->user = -1;

        for (Node* child : node->children) {
            DFS4ChildrenUnlock(child);
        }
    }

private:
    vector<Node*> nodes;
};

int main()
{
    CheckResult check;

    vector<int> parent = { -1,0,0,1,1,2,2 };
    LockingTree o1(parent);
    check.checkBool(true, o1.lock(2, 2));
    check.checkBool(false, o1.unlock(2, 3));
    check.checkBool(true, o1.unlock(2, 2));
    check.checkBool(true, o1.lock(4, 5));
    check.checkBool(true, o1.upgrade(0, 1));
    check.checkBool(false, o1.lock(0, 1));
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
