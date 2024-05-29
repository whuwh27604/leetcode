/* 不包含相邻元素的子序列的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个二维数组 queries，其中 queries[i] = [posi, xi]。

对于每个查询 i，首先将 nums[posi] 设置为 xi，然后计算查询 i 的答案，该答案为 nums 中 不包含相邻元素 的子序列的 最大 和。

返回所有查询的答案之和。

由于最终答案可能非常大，返回其对 109 + 7 取余 的结果。

子序列 是指从另一个数组中删除一些或不删除元素而不改变剩余元素顺序得到的数组。



示例 1：

输入：nums = [3,5,9], queries = [[1,-2],[0,-3]]

输出：21

解释：
执行第 1 个查询后，nums = [3,-2,9]，不包含相邻元素的子序列的最大和为 3 + 9 = 12。
执行第 2 个查询后，nums = [-3,-2,9]，不包含相邻元素的子序列的最大和为 9 。

示例 2：

输入：nums = [0,-1], queries = [[0,-5]]

输出：0

解释：
执行第 1 个查询后，nums = [-5,-1]，不包含相邻元素的子序列的最大和为 0（选择空子序列）。



提示：

1 <= nums.length <= 5 * 104
-105 <= nums[i] <= 105
1 <= queries.length <= 5 * 104
queries[i] == [posi, xi]
0 <= posi <= nums.length - 1
-105 <= xi <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Node {  // 一个节点维护区间[start, end]分别在 (s,e)、(s,e]、[s,e)、[s,e] 4种情况下的最大和
public:
    int start;
    int end;
    long long s0e0;
    long long s0e1;
    long long s1e0;
    long long s1e1;
    Node* left;
    Node* right;

    Node(int s, int e) : start(s), end(e), s0e0(0), s0e1(0), s1e0(0), s1e1(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        root = create(0, (int)nums.size() - 1, nums);
    }

    void update(int index, int value) {  // 单点更新
        update(root, index, value);
    }

    long long query() {  // 查询整个区间的最大和，就是root节点的值
        return max({ root->s0e0, root->s0e1, root->s1e0, root->s1e1 });
    }

private:
    Node* root;

    Node* create(int start, int end, vector<int>& nums) {
        Node* node = new Node(start, end);
        if (start == end) {  // 已经是叶子节点，更新值
            update(node, nums[end]);
        }
        else {  // 非叶子节点，先创建左右子节点，再合并
            int mid = (start + end) / 2;
            node->left = create(start, mid, nums);
            node->right = create(mid + 1, end, nums);
            merge(node);
        }

        return node;
    }

    void update(Node* node, int index, int value) {  // 单点更新
        if (node->start == node->end) {  // 找到该节点，更新值
            update(node, value);
        }
        else {  // 在左右子树查找该节点
            if (node->right->start <= index) {
                update(node->right, index, value);
            }
            else {
                update(node->left, index, value);
            }

            merge(node);  // 更新完成后刷新父区间
        }
    }

    void update(Node* node, int value) {
        node->s1e1 = value;  // 单点的时候，只有[s,e]取value，(s,e)、(s,e]、[s,e)都取0
    }

    void merge(Node* node) {  // 根据子区间的4种情况，合并父区间的结果
        Node* left = node->left;
        Node* right = node->right;

        node->s0e0 = max({ left->s0e0 + right->s0e0, left->s0e0 + right->s1e0, left->s0e1 + right->s0e0 });
        node->s0e1 = max({ left->s0e0 + right->s0e1, left->s0e0 + right->s1e1, left->s0e1 + right->s0e1 });
        node->s1e0 = max({ left->s1e0 + right->s0e0, left->s1e0 + right->s1e0, left->s1e1 + right->s0e0 });
        node->s1e1 = max({ left->s1e0 + right->s0e1, left->s1e0 + right->s1e1, left->s1e1 + right->s0e1 });
    }
};

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree tree(nums);
        long long sum = 0;

        for (auto& query : queries) {
            tree.update(query[0], query[1]);
            sum += tree.query();
        }

        return (int)(sum % 1000000007);
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<int> nums = { 3,5,9 };
    vector<vector<int>> queries = { {1,-2},{0,-3} };
    check.checkInt(21, o.maximumSumSubsequence(nums, queries));

    nums = { 0,-1 };
    queries = { {0,-5} };
    check.checkInt(0, o.maximumSumSubsequence(nums, queries));
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
