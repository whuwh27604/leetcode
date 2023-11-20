/* 平衡子序列的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

nums 一个长度为 k 的 子序列 指的是选出 k 个 下标 i0 < i1 < ... < ik-1 ，如果这个子序列满足以下条件，我们说它是 平衡的 ：

对于范围 [1, k - 1] 内的所有 j ，nums[ij] - nums[ij-1] >= ij - ij-1 都成立。
nums 长度为 1 的 子序列 是平衡的。

请你返回一个整数，表示 nums 平衡 子序列里面的 最大元素和 。

一个数组的 子序列 指的是从原数组中删除一些元素（也可能一个元素也不删除）后，剩余元素保持相对顺序得到的 非空 新数组。



示例 1：

输入：nums = [3,3,5,6]
输出：14
解释：这个例子中，选择子序列 [3,5,6] ，下标为 0 ，2 和 3 的元素被选中。
nums[2] - nums[0] >= 2 - 0 。
nums[3] - nums[2] >= 3 - 2 。
所以，这是一个平衡子序列，且它的和是所有平衡子序列里最大的。
包含下标 1 ，2 和 3 的子序列也是一个平衡的子序列。
最大平衡子序列和为 14 。
示例 2：

输入：nums = [5,-1,-3,8]
输出：13
解释：这个例子中，选择子序列 [5,8] ，下标为 0 和 3 的元素被选中。
nums[3] - nums[0] >= 3 - 0 。
所以，这是一个平衡子序列，且它的和是所有平衡子序列里最大的。
最大平衡子序列和为 13 。
示例 3：

输入：nums = [-2,-1]
输出：-1
解释：这个例子中，选择子序列 [-1] 。
这是一个平衡子序列，而且它的和是 nums 所有平衡子序列里最大的。


提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, LLONG_MIN);  // BIT数据部分不使用索引0
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, long long value) {
        index += 1;  // BIT使用者的数组索引和tree索引偏差1

        while (index <= size) {
            tree[index] = max(tree[index], value);  // 维护区间最大值
            index += lowbit(index);
        }
    }

    long long query(int index) {
        index += 1;  // BIT使用者的数组索引和tree索引偏差1
        long long value = LLONG_MIN;

        while (index != 0) {
            value = max(value, tree[index]);  // 查询区间最大值
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<long long> tree;
};

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int size = nums.size();

        set<int> keys;
        for (int i = 0; i < size; ++i) {
            keys.insert(nums[i] - i);
        }

        int index = 0;
        unordered_map<int, int> keyIndices;
        for (int key : keys) {
            keyIndices[key] = index++;
        }

        vector<long long> dp(size);  // dp[i]表示以nums[i]为结尾的子序列的最大和
        BIT bit(keys.size());  // bit维护所有key小于等于当前key的dp最大值
        long long ans = LLONG_MIN;

        for (int i = 0; i < size; ++i) {
            dp[i] = nums[i];
            int key = nums[i] - i;
            int index = keyIndices[key];  // 将key映射到数组索引
            long long prev = bit.query(index);  // 查询所有key小于等于当前key的最大dp
            if (prev > 0) {  // 如果前面的dp大于0，说明可以将nums[i]加入前一个子序列形成新的最大子序列
                dp[i] += prev;
            }
            bit.update(index, dp[i]);  // 更新bit维护的最大值
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,3,5,6 };
    check.checkLongLong(14, o.maxBalancedSubsequenceSum(nums));

    nums = { 5,-1,-3,8 };
    check.checkLongLong(13, o.maxBalancedSubsequenceSum(nums));

    nums = { -2,-1 };
    check.checkLongLong(-1, o.maxBalancedSubsequenceSum(nums));

    nums = { -5 };
    check.checkLongLong(-5, o.maxBalancedSubsequenceSum(nums));

    nums = { 3,3,5,6,-2,-1,5,-1,-3,8,3,3,5,6,-2,-1,5,-1,-3,8 };
    check.checkLongLong(14, o.maxBalancedSubsequenceSum(nums));
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
