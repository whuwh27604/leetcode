/* 区间和的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

说明:
最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。

示例:

输入: nums = [-2,5,-1], lower = -2, upper = 2,
输出: 3
解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-range-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        vector<long long> preSum(size + 1, 0);
        getPreSum(nums, preSum);

        set<long long> allSums;
        sortSums(preSum, allSums, lower, upper);

        unordered_map<long long, int> values;
        discretization(allSums, values);

        return countSumInRange(preSum, values, lower, upper);
    }

    void getPreSum(vector<int>& nums, vector<long long>& preSum) {
        for (unsigned int i = 0; i < nums.size(); ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }

    void sortSums(vector<long long>& preSum, set<long long>& allSums, int lower, int upper) {
        for (long long sum : preSum) {
            allSums.insert(sum);
            allSums.insert(sum - lower);
            allSums.insert(sum - upper);
        }
    }

    void discretization(set<long long>& allSums, unordered_map<long long, int>& values) {
        int index = 0;

        for (long long sum : allSums) {
            values[sum] = index++;
        }
    }

    int countSumInRange(vector<long long>& preSum, unordered_map<long long, int>& values, int lower, int upper) {
        BIT bit(values.size());
        int sumInRange = 0;

        for (long long sum : preSum) {
            int left = values[sum - upper], right = values[sum - lower];
            sumInRange += bit.query(right + 1) - bit.query(left);
            bit.update(values[sum] + 1, 1);
        }

        return sumInRange;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { -2,5,-1 };
    check.checkInt(3, o.countRangeSum(nums, -2, 2));

    nums = { -2147483647,0,-2147483647,2147483647 };
    check.checkInt(3, o.countRangeSum(nums, -564, 3864));

    nums = {  };
    check.checkInt(0, o.countRangeSum(nums, -564, 3864));

    nums = { 1 };
    check.checkInt(1, o.countRangeSum(nums, 1, 2));

    nums = { 1 };
    check.checkInt(0, o.countRangeSum(nums, 2, 3));

    nums = { 1,2,3,4 };
    check.checkInt(4, o.countRangeSum(nums, 3, 5));

    nums = { 1,2,3,4,5 };
    check.checkInt(2, o.countRangeSum(nums, 5, 5));

    nums = { -5,-4,-3,-2,-1,0,1,2,3,4,5 };
    check.checkInt(34, o.countRangeSum(nums, -5, 5));
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
