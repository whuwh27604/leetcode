/* 区域和检索 - 数组不可变.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <iomanip>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sumArray = new int[nums.size() + 1];
        sumArray[0] = 0;
        int sum = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sumArray[i + 1] = sum;
        }
    }

    ~NumArray() {
        delete[] sumArray;
    }

    int sumRange(int i, int j) {
        return (sumArray[j + 1] - sumArray[i]);
    }

    // 空间换时间
    int* sumArray;
};

int main()
{
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray o(nums);
    CheckResult check;
    check.checkInt(1, o.sumRange(0, 2));
    check.checkInt(-1, o.sumRange(2, 5));
    check.checkInt(-3, o.sumRange(0, 5));
    check.checkInt(-2, o.sumRange(0, 0));
    check.checkInt(-1, o.sumRange(5, 5));
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
