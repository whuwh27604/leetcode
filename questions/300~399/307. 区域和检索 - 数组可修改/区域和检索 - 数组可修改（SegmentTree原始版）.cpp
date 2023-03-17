/* 区域和检索 - 数组可修改.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）


示例 1：

输入：
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
输出：
[null, 9, null, 8]

解释：
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8


提示：

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
调用 update 和 sumRange 方法次数不大于 3 * 104
*/

#include <iostream>
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
    SegmentTree(vector<int>& nums) {
        int size = nums.size();
        root = create(0, size - 1, nums);
    }

    int query(int index) {  // 单点查询
        return query(root, index);
    }

    int query(int start, int end) {  // 区间查询，这里是求和操作
        return query(root, start, end);
    }

    void update(int index, int value) {  // 单点更新，根据实际需要value可以设计为更新后的值，也可以是当前值的增量等。求和操作使用增量
        return update(root, index, value);
    }

    void update(int start, int end, int value) {  // 区间更新
        return update(root, start, end, value);
    }

private:
    Node* root;

    Node* create(int start, int end, vector<int>& nums) {
        Node* node = new Node(start, end);
        if (start == end) {
            node->value = nums[end];
        }
        else {
            int mid = (start + end) / 2;
            Node* left = create(start, mid, nums);
            Node* right = create(mid + 1, end, nums);
            node->left = left;
            node->right = right;
            node->value = left->value + right->value;  // 线段树求和操作，也可以是求最大值、最小值等
        }

        return node;
    }

    int query(Node* node, int index) {
        if (node->start == node->end) {
            return node->value;
        }

        if (index <= (node->start + node->end) / 2) {
            return query(node->left, index);
        }

        return query(node->right, index);
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

    void update(Node* node, int index, int value) {
        if (node->start == index && node->end == index) {
            node->value += value;  // 求和操作value设计为增量
        }
        else {
            int mid = (node->start + node->end) / 2;
            if (index <= mid) {  // 在左子树
                update(node->left, index, value);
            }
            else {  // 在右子树
                update(node->right, index, value);
            }

            node->value = node->left->value + node->right->value;  // 更新完叶子节点后，同步更新该叶子节点的所有祖先
        }
    }

    void update(Node* node, int start, int end, int value) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，直接返回
            return;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是更新区间的子集
            node->value += ((node->end - node->start + 1) * value);  // 更新当前区间的value，求和操作意味着需要增加[start, end] * value
            node->lazy += value;  // 标记lazy，暂不往下传递
            return;
        }

        pushDown(node);  // 当前区间和更新区间有交集，没办法了，lazy标记往下传，把以前积攒的更新处理掉
        update(node->left, start, end, value);
        update(node->right, start, end, value);
        node->value = node->left->value + node->right->value;
    }

    void pushDown(Node* node) {  // 将lazy标记传递给左右子树
        if (node->lazy != 0) {
            update(node->left, node->left->start, node->left->end, node->lazy);
            update(node->right, node->right->start, node->right->end, node->lazy);
            node->lazy = 0;  // 传递下去以后，自己的lazy标记被清除
        }
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums);
    }

    void update(int index, int val) {
        tree->update(index, val - tree->query(index));
    }

    int sumRange(int left, int right) {
        return tree->query(left, right);
    }

private:
    SegmentTree* tree;
};

int main()
{
    CheckResult check;

    vector<int> nums = { 1,3,5 };
    NumArray o1(nums);
    check.checkInt(9, o1.sumRange(0, 2));
    o1.update(1, 2);
    check.checkInt(8, o1.sumRange(0, 2));
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
