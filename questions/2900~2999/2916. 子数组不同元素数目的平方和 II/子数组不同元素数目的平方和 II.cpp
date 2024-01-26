/* 子数组不同元素数目的平方和 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

定义 nums 一个子数组的 不同计数 值如下：

令 nums[i..j] 表示 nums 中所有下标在 i 到 j 范围内的元素构成的子数组（满足 0 <= i <= j < nums.length ），那么我们称子数组 nums[i..j] 中不同值的数目为 nums[i..j] 的不同计数。
请你返回 nums 中所有子数组的 不同计数 的 平方 和。

由于答案可能会很大，请你将它对 109 + 7 取余 后返回。

子数组指的是一个数组里面一段连续 非空 的元素序列。



示例 1：

输入：nums = [1,2,1]
输出：15
解释：六个子数组分别为：
[1]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[1]: 1 个互不相同的元素。
[1,2]: 2 个互不相同的元素。
[2,1]: 2 个互不相同的元素。
[1,2,1]: 2 个互不相同的元素。
所有不同计数的平方和为 12 + 12 + 12 + 22 + 22 + 22 = 15 。
示例 2：

输入：nums = [2,2]
输出：3
解释：三个子数组分别为：
[2]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[2,2]: 1 个互不相同的元素。
所有不同计数的平方和为 12 + 12 + 12 = 3 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
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
    int sqrSum;
    int lazy;  // lazy标记设计为当前节点的value更新完毕，暂时没有传递到子节点，记录下更新的值。当有需要的时候，再传递更新值到子节点。
    Node* left;
    Node* right;

    Node(int s, int e) : start(s), end(e), sum(0), sqrSum(0), lazy(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    SegmentTree(int size_) {  // 线段树的底层数组记录的是：当遍历到nums[i]时，以 i - 1 为右端点的所有子数组的不同计数x
        size = size_;
        root = create(0, size - 1);
    }

    int querySum(int start, int end) {  // 查询区间[start, end]内x的sum
        return querySum(root, start, end);
    }

    int querySqrSum(int start, int end) {  // 查询区间[start, end]内x的square sum
        return querySqrSum(root, start, end);
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

    int querySqrSum(Node* node, int start, int end) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，求和操作返回0
            return 0;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是查询区间的子集，返回当前区间的值
            return node->sqrSum;
        }

        pushDown(node);  // 如果有必要，先将lazy标记往下传

        return (querySqrSum(node->left, start, end) + querySqrSum(node->right, start, end)) % mod;  // 当前区间和查询区间有交集，递归查询左右子树，并求和
    }

    void update(Node* node, int start, int end, int add) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集，直接返回
            return;
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是更新区间的子集
            long long len = (long long)node->end - node->start + 1;
            node->sqrSum = (node->sqrSum + (long long)2 * add * node->sum + len * add * add) % mod;
            node->sum = (node->sum + len * add) % mod;
            node->lazy += add;  // 标记lazy，暂不往下传递
            return;
        }

        pushDown(node);  // 当前区间和更新区间有交集，没办法了，lazy标记往下传，把以前积攒的更新处理掉
        update(node->left, start, end, add);
        update(node->right, start, end, add);
        node->sum = (node->left->sum + node->right->sum) % mod;
        node->sqrSum = (node->left->sqrSum + node->right->sqrSum) % mod;
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
    int sumCounts(vector<int>& nums) {
        int size = nums.size(), sqrSum = 1;
        SegmentTree tree(size);
        tree.update(0, 0, 1);
        vector<int> lastIndex(100001, -1);
        lastIndex[nums[0]] = 0;

        for (int i = 1; i < size; ++i) {
            int num = nums[i];
            int last = lastIndex[num];
            if (last != -1) {
                // 对于区间[0, last]内的 j ，子数组nums[j, i]的不同计数等于子数组nums[j, i - 1]的不同计数
                sqrSum = (sqrSum + tree.querySqrSum(0, last)) % mod;
            }
            // 对于区间[last + 1, i - 1]内的 j ，子数组nums[j, i]的不同计数x等于子数组nums[j, i - 1]的不同计数x' + 1
            // 对于新增的子数组nums[i, i]，x也会增加1
            tree.update(last + 1, i, 1);
            sqrSum = (sqrSum + tree.querySqrSum(last + 1, i)) % mod;

            // 现在对右端点nums[i]的计算已经完成，将tree的含义更新到nums[i]：区间[0, last]不变，区间[last + 1, i]都会增加1，上面已经处理过了
            lastIndex[num] = i;
        }

        return sqrSum;
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<int> nums = { 1,2,1 };
    check.checkInt(15, o.sumCounts(nums));

    nums = { 2,2 };
    check.checkInt(3, o.sumCounts(nums));

    nums = { 1 };
    check.checkInt(1, o.sumCounts(nums));

    nums = { 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
    check.checkInt(2030, o.sumCounts(nums));
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
