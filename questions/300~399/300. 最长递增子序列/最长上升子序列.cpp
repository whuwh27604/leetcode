/* 最长上升子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
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

    void update(int index, int value) {  // 更新位置index的值
        while (index <= size) {
            tree[index] = max(tree[index], value);
            index += lowbit(index);
        }
    }

    int query(int index) {  // 查询区间[1,index]的最大值
        int value = 0;

        while (index != 0) {
            value = max(tree[index], value);
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

// 如果有相同的数，注意索引大的排在前面，这一点非常关键！因为如果先计算了索引小的，会影响后面一个数的正确性；而先计算了后面一个数不会影响前面数的正确性。
bool pairCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first != p2.first ? p1.first < p2.first : p1.second > p2.second;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int index = 1, prev = INT_MIN;
        vector<pair<int, int>> numsIndices;

        for (int num : nums) {
            if (num != prev) {  // 因为必须严格递增，所以连续的相同数没有意义，只保留一个就可以了
                numsIndices.push_back({ num, index++ });
                prev = num;
            }
        }

        sort(numsIndices.begin(), numsIndices.end(), pairCompare);

        BIT bit(numsIndices.size());
        int maxLIS = 0;

        for (auto& numIndex : numsIndices) {
            // 因为numsIndices是递增的，所以每次查询区间1到它前面一个索引的最大LIS，再加上自己就是新的最大LIS。这一步用log(n)复杂度优化了dp每次遍历前面所有LIS的过程
            int LIS = bit.query(numIndex.second - 1) + 1;
            maxLIS = max(maxLIS, LIS);
            bit.update(numIndex.second, LIS);  // 更新最大值受影响的区间
        }

        return maxLIS;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    check.checkInt(4, o.lengthOfLIS(nums));

    nums = { 0,1,0,3,2,3 };
    check.checkInt(4, o.lengthOfLIS(nums));

    nums = { 7,7,7,7,7,7,7 };
    check.checkInt(1, o.lengthOfLIS(nums));

    nums = {  };
    check.checkInt(0, o.lengthOfLIS(nums));

    nums = { 11,12,13,14,15,6,7,8,101,18 };
    check.checkInt(6, o.lengthOfLIS(nums));

    nums = { 3,4,5,6,1,10,7,8 };
    check.checkInt(6, o.lengthOfLIS(nums));

    nums = { 4,10,4,3,8,9 };
    check.checkInt(3, o.lengthOfLIS(nums));

    nums = { 3,5,6,2,5,4,19,5,6,7,12 };
    check.checkInt(6, o.lengthOfLIS(nums));

    nums = { 8,8,7,6,5,4,3,2,2,1 };
    check.checkInt(1, o.lengthOfLIS(nums));

    nums = { 3,6,9,5,10,12,1,2,3 };
    check.checkInt(5, o.lengthOfLIS(nums));

    nums = { 10,11,12,13,1,2,3 };
    check.checkInt(4, o.lengthOfLIS(nums));

    nums = { 11,12,13,14,15,6,7,8,101,18 };
    check.checkInt(6, o.lengthOfLIS(nums));
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
