/* K 次乘运算后的最终数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，一个整数 k  和一个整数 multiplier 。

你需要对 nums 执行 k 次操作，每次操作中：

找到 nums 中的 最小 值 x ，如果存在多个最小值，选择最 前面 的一个。
将 x 替换为 x * multiplier 。
k 次操作以后，你需要将 nums 中每一个数值对 109 + 7 取余。

请你返回执行完 k 次乘运算以及取余运算之后，最终的 nums 数组。



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
取余操作后	[8, 4, 6, 5, 6]
示例 2：

输入：nums = [100000,2000], k = 2, multiplier = 1000000

输出：[999999307,999999993]

解释：

操作	结果
1 次操作后	[100000, 2000000000]
2 次操作后	[100000000000, 2000000000]
取余操作后	[999999307, 999999993]


提示：

1 <= nums.length <= 104
1 <= nums[i] <= 109
1 <= k <= 109
1 <= multiplier <= 106
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Node {
public:
    long long val;
    int idx;

    Node() : val(0), idx(0) {}
    Node(long long v, int i) : val(v), idx(i) {}

    bool operator<(const Node& o) const {
        return val == o.val ? idx < o.idx : val < o.val;
    }
};

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }

        set<Node> nodes;
        int size = (int)nums.size();
        vector<int> ans(size);

        for (int i = 0; i < size; ++i) {
            nodes.insert(Node(nums[i], i));
        }

        long long maxVal = nodes.rbegin()->val;
        int maxIdx = nodes.rbegin()->idx;

        while (!(nodes.begin()->val == maxVal && nodes.begin()->idx == maxIdx) && k != 0) {
            long long val = nodes.begin()->val;
            int idx = nodes.begin()->idx;
            nodes.erase(nodes.begin());
            nodes.insert(Node(val * multiplier, idx));
            --k;
        }

        int rem = k % size, times = k / size, cnt = 0, mod = 1000000007;

        for (auto& node : nodes) {
            ans[node.idx] = node.val % mod * fastPower(multiplier, cnt < rem ? times + 1 : times, mod) % mod;
            ++cnt;
        }

        return ans;
    }

    long long fastPower(long long x, int n, long long mod) {
        long long ans = 1;

        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }

            x = x * x % mod;
            n >>= 1;
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

    nums = { 100000,2000 };
    actual = o.getFinalState(nums, 2, 1000000);
    expected = { 999999307,999999993 };
    check.checkIntVector(expected, actual);

    nums = { 66307295,441787703,589039035,322281864 };
    actual = o.getFinalState(nums, 900900704, 641725);
    expected = { 664480092,763599523,886046925,47878852 };
    check.checkIntVector(expected, actual);

    nums = getIntVector("./testcase1.txt");
    actual = o.getFinalState(nums, 1000000000, 1);
    expected = nums;
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
