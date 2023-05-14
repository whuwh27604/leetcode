/* 将数组清空.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个包含若干 互不相同 整数的数组 nums ，你需要执行以下操作 直到数组为空 ：

如果数组中第一个元素是当前数组中的 最小值 ，则删除它。
否则，将第一个元素移动到数组的 末尾 。
请你返回需要多少个操作使 nums 为空。



示例 1：

输入：nums = [3,4,-1]
输出：5
Operation	Array
1	[4, -1, 3]
2	[-1, 3, 4]
3	[3, 4]
4	[4]
5	[]


示例 2：

输入：nums = [1,2,4,3]
输出：5
Operation	Array
1	[2, 4, 3]
2	[4, 3]
3	[3, 4]
4	[4]
5	[]


示例 3：

输入：nums = [1,2,3]
输出：3
Operation	Array
1	[2, 3]
2	[3]
3	[]


提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 中的元素 互不相同 。
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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int size = nums.size(), prev = 0;
        long long opers = 0;
        vector<pair<int, int>> numIndices(size);
        BIT tree(size);

        for (int i = 0; i < size; ++i) {
            numIndices[i] = { nums[i],i };
        }

        sort(numIndices.begin(), numIndices.end());

        for (int i = 0; i < size; ++i) {
            int current = numIndices[i].second;
            if (current >= prev) {
                opers += ((long long)current - prev + 1 - tree.query(current + 1) + tree.query(prev));
            }
            else {
                opers += ((long long)size - prev - tree.query(size) + tree.query(prev));
                opers += ((long long)current + 1 - tree.query(current + 1));
            }

            tree.update(current + 1, 1);
            prev = current;
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,4,-1 };
    check.checkLongLong(5, o.countOperationsToEmptyArray(nums));

    nums = { 1,2,4,3 };
    check.checkLongLong(5, o.countOperationsToEmptyArray(nums));

    nums = { 1,2,3 };
    check.checkLongLong(3, o.countOperationsToEmptyArray(nums));
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
