/* 更新数组后处理求和查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的数组 nums1 和 nums2 ，和一个二维数组 queries 表示一些操作。总共有 3 种类型的操作：

操作类型 1 为 queries[i] = [1, l, r] 。你需要将 nums1 从下标 l 到下标 r 的所有 0 反转成 1 或将 1 反转成 0 。l 和 r 下标都从 0 开始。
操作类型 2 为 queries[i] = [2, p, 0] 。对于 0 <= i < n 中的所有下标，令 nums2[i] = nums2[i] + nums1[i] * p 。
操作类型 3 为 queries[i] = [3, 0, 0] 。求 nums2 中所有元素的和。
请你返回一个数组，包含所有第三种操作类型的答案。



示例 1：

输入：nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
输出：[3]
解释：第一个操作后 nums1 变为 [1,1,1] 。第二个操作后，nums2 变成 [1,1,1] ，所以第三个操作的答案为 3 。所以返回 [3] 。
示例 2：

输入：nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
输出：[5]
解释：第一个操作后，nums2 保持不变为 [5] ，所以第二个操作的答案是 5 。所以返回 [5] 。


提示：

1 <= nums1.length,nums2.length <= 105
nums1.length = nums2.length
1 <= queries.length <= 105
queries[i].length = 3
0 <= l <= r <= nums1.length - 1
0 <= p <= 106
0 <= nums1[i] <= 1
0 <= nums2[i] <= 109
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Node {
public:
    int start;
    int end;
    int value;  // 区间和
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

    int query(int start, int end) {  // 区间查询，这里是求和操作
        return query(root, start, end);
    }

    void update(int start, int end) {  // 区间更新，这里是flip操作
        return update(root, start, end);
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
            node->value = (node->end - node->start + 1) - node->value;  // 更新当前区间的value，反转操作使区间和变为区间长度减去当前的区间和
            node->lazy ^= 1;  // 标记lazy，暂不往下传递
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

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> ans;
        long long sum = accumulate(nums2.begin(), nums2.end(), (long long)0);
        int size = nums1.size();
        SegmentTree tree(nums1);

        for (auto& query : queries) {
            if (query[0] == 1) {
                tree.update(query[1], query[2]);
            }
            else if (query[0] == 2) {
                sum += (long long)query[1] * tree.query(0, size - 1);
            }
            else {
                ans.push_back(sum);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,0,1 };
    vector<int> nums2 = { 0,0,0 };
    vector<vector<int>> queries = { {1,1,1},{2,1,0},{3,0,0} };
    vector<long long> actual = o.handleQuery(nums1, nums2, queries);
    vector<long long> expected = { 3 };
    check.checkLongLongVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 5 };
    queries = { {2,0,0},{3,0,0} };
    actual = o.handleQuery(nums1, nums2, queries);
    expected = { 5 };
    check.checkLongLongVector(expected, actual);

    nums1 = getIntVector("./testcase1_nums1.txt");
    nums2 = getIntVector("./testcase1_nums2.txt");
    queries = getIntVectorVector("./testcase1_queries.txt");
    actual = o.handleQuery(nums1, nums2, queries);
    expected = getLongLongVector("./testcase1_expected.txt");
    check.checkLongLongVector(expected, actual);
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
