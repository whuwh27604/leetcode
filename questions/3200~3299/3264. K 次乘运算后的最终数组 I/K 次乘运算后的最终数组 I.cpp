/* K 次乘运算后的最终数组 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，一个整数 k  和一个整数 multiplier 。

你需要对 nums 执行 k 次操作，每次操作中：

找到 nums 中的 最小 值 x ，如果存在多个最小值，选择最 前面 的一个。
将 x 替换为 x * multiplier 。
请你返回执行完 k 次乘运算之后，最终的 nums 数组。



示例 1：

输入：nums = [2,1,3,5,6], k = 5, multiplier = 2

输出：[8,4,6,5,6]

解释：

操作	结果
1 次操作后	[2, 2, 3, 5, 6]
2 次操作后	[4, 2, 3, 5, 6]
3 次操作后	[4, 4, 3, 5, 6]
4 次操作后	[4, 4, 6, 5, 6]
5 次操作后	[8, 4, 6, 5, 6]
示例 2：

输入：nums = [1,2], k = 3, multiplier = 4

输出：[16,8]

解释：

操作	结果
1 次操作后	[4, 2]
2 次操作后	[4, 8]
3 次操作后	[16, 8]


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int val;
    int idx;

    Node() : val(0), idx(0) {}
    Node(int v, int i) : val(v), idx(i) {}

    bool operator<(const Node& o) const {
        return val == o.val ? idx < o.idx : val < o.val;
    }
};

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        set<Node> nodes;
        int size = (int)nums.size();
        vector<int> ans(size);

        for (int i = 0; i < size; ++i) {
            nodes.insert(Node(nums[i], i));
        }

        for (int i = 0; i < k; ++i) {
            int val = nodes.begin()->val, idx = nodes.begin()->idx;
            nodes.erase(nodes.begin());
            nodes.insert(Node(val * multiplier, idx));
        }

        for (auto& node : nodes) {
            ans[node.idx] = node.val;
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,1,3,5,6 };
    vector<int> actual = o.getFinalState(nums, 5, 2);
    vector<int> expected = { 8,4,6,5,6 };
    check.checkIntVector(expected, actual);

    nums = { 1,2 };
    actual = o.getFinalState(nums, 3, 4);
    expected = { 16,8 };
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
