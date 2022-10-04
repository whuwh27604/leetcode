/* 满足不等式的数对数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两个数组的大小都为 n ，同时给你一个整数 diff ，统计满足以下条件的 数对 (i, j) ：

0 <= i < j <= n - 1 且
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
请你返回满足条件的 数对数目 。

 

示例 1：

输入：nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
输出：3
解释：
总共有 3 个满足条件的数对：
1. i = 0, j = 1：3 - 2 <= 2 - 2 + 1 。因为 i < j 且 1 <= 1 ，这个数对满足条件。
2. i = 0, j = 2：3 - 5 <= 2 - 1 + 1 。因为 i < j 且 -2 <= 2 ，这个数对满足条件。
3. i = 1, j = 2：2 - 5 <= 2 - 1 + 1 。因为 i < j 且 -3 <= 2 ，这个数对满足条件。
所以，我们返回 3 。
示例 2：

输入：nums1 = [3,-1], nums2 = [-2,2], diff = -1
输出：0
解释：
没有满足条件的任何数对，所以我们返回 0 。
 

提示：

n == nums1.length == nums2.length
2 <= n <= 105
-104 <= nums1[i], nums2[i] <= 104
-104 <= diff <= 104

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-pairs-satisfying-inequality
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long sum = 0;
        int size = nums1.size(), i, j = size - 1;
        vector<pair<int, int>> diffIndices(size);
        BIT bit(size + 1);

        for (i = 0; i < size; ++i) {
            diffIndices[i] = { nums1[i] - nums2[i],i };
        }

        sort(diffIndices.begin(), diffIndices.end());

        for (i = size - 1; i >= 0; --i) {
            for (; j >= 0 && diffIndices[j].first >= diffIndices[i].first - diff; --j) {
                bit.update(diffIndices[j].second + 1, 1);
            }

            sum += ((long long)bit.query(size) - bit.query(diffIndices[i].second + 1));
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 3,2,5 };
    vector<int> nums2 = { 2,2,1 };
    check.checkLongLong(3, o.numberOfPairs(nums1, nums2, 1));

    nums1 = { 3,-1 };
    nums2 = { -2,2 };
    check.checkLongLong(0, o.numberOfPairs(nums1, nums2, -1));

    nums1 = { -4,-4,4,-1,-2,5 };
    nums2 = { -2,2,-1,4,4,3 };
    check.checkLongLong(9, o.numberOfPairs(nums1, nums2, 1));

    nums1 = { 1,2,3,4,5 };
    nums2 = { 6,7,8,9,10 };
    check.checkLongLong(10, o.numberOfPairs(nums1, nums2, 0));
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
