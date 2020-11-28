﻿/* 翻转对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

你需要返回给定数组中的重要翻转对的数量。

示例 1:

输入: [1,3,2,3,1]
输出: 2
示例 2:

输入: [2,4,3,5,1]
输出: 3
注意:

给定数组的长度不会超过50000。
输入数组中的所有数字都在32位整数的表示范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <unordered_map>
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
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        set<long long> allNums;
        sortAllNums(nums, allNums);

        unordered_map<long long, int> values;
        discretization(allNums, values);

        int IRPs = 0, size = values.size();
        BIT bit(size);

        for (int num : nums) {
            int index = values[(long long)num * 2];
            IRPs += (bit.query(size) - bit.query(index));
            bit.update(values[num], 1);
        }

        return IRPs;
    }

    void sortAllNums(vector<int>& nums, set<long long>& allNums) {
        for (int num : nums) {
            allNums.insert(num);
            allNums.insert((long long)num * 2);
        }
    }

    void discretization(set<long long>& allNums, unordered_map<long long, int>& values) {
        int index = 0;

        for (long long num : allNums) {
            values[num] = ++index;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,2,3,1 };
    check.checkInt(2, o.reversePairs(nums));

    nums = { 2,4,3,5,1 };
    check.checkInt(3, o.reversePairs(nums));

    nums = {  };
    check.checkInt(0, o.reversePairs(nums));

    nums = { 5 };
    check.checkInt(0, o.reversePairs(nums));

    nums = { 5,2 };
    check.checkInt(1, o.reversePairs(nums));

    nums = { 2147483647,2147483647,2147483647,2147483647,2,4,3,5,1,2147483647,2147483647 };
    check.checkInt(23, o.reversePairs(nums));
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
