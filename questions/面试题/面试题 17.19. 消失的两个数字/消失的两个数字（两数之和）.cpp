/* 消失的两个数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？

以任意顺序返回这两个数字均可。

示例 1:

输入: [1]
输出: [2,3]
示例 2:

输入: [2,3]
输出: [1,4]
提示：

nums.length <= 30000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/missing-two-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        int sum = (n + 1) * n / 2 - accumulate(nums.begin(), nums.end(), 0);  // 两数之和
        int half = sum / 2;  // 一个数在区间[1, half]， 一个数在区间[half + 1, n]

        return { getMissing(nums, 1, half), getMissing(nums, half + 1, n) };
    }

    int getMissing(vector<int>& nums, int start, int end) {
        int sum = 0;

        for (int num : nums) {
            if (num >= start && num <= end) {
                sum += num;
            }
        }

        return (start + end) * (end - start + 1) / 2 - sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1 };
    vector<int> actual = o.missingTwo(nums);
    vector<int> expected = { 2,3 };
    check.checkIntVector(expected, actual);

    nums = { 2,3 };
    actual = o.missingTwo(nums);
    expected = { 1,4 };
    check.checkIntVector(expected, actual);

    nums = getIntVector("./testcase1.txt");
    actual = o.missingTwo(nums);
    expected = { 12051,28099 };
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
