/* 子数组中占绝大多数的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个数据结构，有效地找到给定子数组的 多数元素 。

子数组的 多数元素 是在子数组中出现 threshold 次数或次数以上的元素。

实现 MajorityChecker 类:

MajorityChecker(int[] arr) 会用给定的数组 arr 对 MajorityChecker 初始化。
int query(int left, int right, int threshold) 返回子数组中的元素  arr[left...right] 至少出现 threshold 次数，如果不存在这样的元素则返回 -1。
 

示例 1：

输入:
["MajorityChecker", "query", "query", "query"]
[[[1, 1, 2, 2, 1, 1]], [0, 5, 4], [0, 3, 3], [2, 3, 2]]
输出：
[null, 1, -1, 2]

解释：
MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // 返回 1
majorityChecker.query(0,3,3); // 返回 -1
majorityChecker.query(2,3,2); // 返回 2
 

提示：

1 <= arr.length <= 2 * 104
1 <= arr[i] <= 2 * 104
0 <= left <= right < arr.length
threshold <= right - left + 1
2 * threshold > right - left + 1
调用 query 的次数最多为 104

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/online-majority-element-in-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int start;
    int end;
    int majority;  // Boyer-Moore算法选出的可能的众数
    int count;  // 可能众数的得票数
    Node* left;
    Node* right;

    Node(int s, int e) : start(s), end(e), majority(0), count(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        int size = nums.size();
        root = create(0, size - 1, nums);
    }

    pair<int, int> query(int start, int end) {  // 区间查询，这里是在区间上执行Boyer-Moore算法
        return query(root, start, end);
    }

private:
    Node* root;

    Node* create(int start, int end, vector<int>& nums) {
        Node* node = new Node(start, end);
        if (start == end) {
            node->majority = nums[end];
            node->count = 1;
        }
        else {
            int mid = (start + end) / 2;
            Node* left = create(start, mid, nums);
            Node* right = create(mid + 1, end, nums);
            node->left = left;
            node->right = right;
            pair<int, int> result = merge(left->majority, left->count, right->majority, right->count);
            node->majority = result.first;
            node->count = result.second;
        }

        return node;
    }

    pair<int, int> merge(int majority1, int count1, int majority2, int count2) {  // 对合并区间执行Boyer-Moore算法
        int majority = 0, count = 0;

        if (majority1 == majority2) {  // 如果两边的可选majority相同，合并后可选majority肯定还是它，并且count会相加
            majority = majority1;
            count = count1 + count2;
        }
        else {  // 如果两边的可选majority不同，那么合并后只可能是count较大的那一个，并且两边比拼后，只会剩下两个count相减的个数
            if (count1 > count2) {
                majority = majority1;
                count = count1 - count2;
            }
            else {
                majority = majority2;
                count = count2 - count1;
            }
        }

        return { majority,count };
    }

    pair<int, int> query(Node* node, int start, int end) {
        if (node->start > end || node->end < start) {  // 两个区间没有交集
            return { 0,0 };
        }

        if (node->start >= start && node->end <= end) {  // 当前区间是查询区间的子集，返回当前区间的值
            return { node->majority,node->count };
        }

        pair<int, int> left = query(node->left, start, end);
        pair<int, int> right = query(node->right, start, end);

        return merge(left.first, left.second, right.first, right.second);
    }
};

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        tree = new SegmentTree(arr);

        for (int i = 0; i < (int)arr.size(); ++i) {
            numIndices[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        pair<int, int> result = tree->query(left, right);

        return check(left, right, threshold, numIndices[result.first]) ? result.first : -1;
    }

    bool check(int left, int right, int threshold, vector<int>& indices) {  // 找到可能的majority后，校验个数是否满足threshold
        auto iter1 = lower_bound(indices.begin(), indices.end(), left);
        auto iter2 = upper_bound(indices.begin(), indices.end(), right);

        return distance(iter1, iter2) >= threshold;
    }

private:
    SegmentTree* tree;
    unordered_map<int, vector<int>> numIndices;
};

int main()
{
    CheckResult check;

    vector<int> arr = { 1,1,2,2,1,1 };
    MajorityChecker o1(arr);
    check.checkInt(1, o1.query(0, 5, 4));
    check.checkInt(-1, o1.query(0, 3, 3));
    check.checkInt(2, o1.query(2, 3, 2));
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
