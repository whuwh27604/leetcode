/* 区域和检索 - 数组可修改.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

示例:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
说明:

数组仅可以在 update 函数下进行修改。
你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-mutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);
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

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();
        bit = new BIT(size);
        data = nums;

        for (int i = 0; i < size; ++i) {
            bit->update(i + 1, nums[i]);
        }
    }

    void update(int i, int val) {
        bit->update(i + 1, val - data[i]);
        data[i] = val;
    }

    int sumRange(int i, int j) {
        return bit->query(j + 1) - bit->query(i);
    }

private:
    BIT *bit;
    vector<int> data;
};

int main()
{
    CheckResult check;

    vector<int> nums = { 1,3,5 };
    NumArray o1(nums);
    check.checkInt(9, o1.sumRange(0, 2));
    o1.update(1, 2);
    check.checkInt(8, o1.sumRange(0, 2));

    nums = { 1 };
    NumArray o2(nums);
    check.checkInt(1, o2.sumRange(0, 0));
    o2.update(0, 2);
    check.checkInt(2, o2.sumRange(0, 0));
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
