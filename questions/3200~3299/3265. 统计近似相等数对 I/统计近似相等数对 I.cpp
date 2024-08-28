/* 统计近似相等数对 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums 。

如果我们执行以下操作 至多一次 可以让两个整数 x 和 y 相等，那么我们称这个数对是 近似相等 的：

选择 x 或者 y  之一，将这个数字中的两个数位交换。
请你返回 nums 中，下标 i 和 j 满足 i < j 且 nums[i] 和 nums[j] 近似相等 的数对数目。

注意 ，执行操作后一个整数可以有前导 0 。



示例 1：

输入：nums = [3,12,30,17,21]

输出：2

解释：

近似相等数对包括：

3 和 30 。交换 30 中的数位 3 和 0 ，得到 3 。
12 和 21 。交换12 中的数位 1 和 2 ，得到 21 。
示例 2：

输入：nums = [1,1,1,1,1]

输出：10

解释：

数组中的任意两个元素都是近似相等的。

示例 3：

输入：nums = [123,231]

输出：0

解释：

我们无法通过交换 123 或者 321 中的两个数位得到另一个数。



提示：

2 <= nums.length <= 100
1 <= nums[i] <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int size = (int)nums.size(), pairs = 0;
        vector<string> numbers(size);

        for (int i = 0; i < size; ++i) {
            numbers[i] = toString(nums[i]);
        }

        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] == nums[j] || isAlmostEqual(numbers[i], numbers[j])) {
                    ++pairs;
                }
            }
        }
        
        return pairs;
    }

    bool isAlmostEqual(string& x, string& y) {
        int diff1 = 0, diff2 = 0, cnt = 0;

        for (int i = 0; i < maxBit; ++i) {
            if (x[i] != y[i]) {
                ++cnt;
                diff1 = diff2;
                diff2 = i;
            }
        }

        return cnt == 2 && x[diff1] == y[diff2] && x[diff2] == y[diff1];
    }

    string toString(int n) {
        string s(maxBit, '0');
        int idx = maxBit - 1;

        while (n != 0) {
            s[idx--] = n % 10 + '0';
            n /= 10;
        }

        return s;
    }

    int maxBit = 7;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,12,30,17,21 };
    check.checkInt(2, o.countPairs(nums));

    nums = { 1,1,1,1,1 };
    check.checkInt(10, o.countPairs(nums));

    nums = { 123,231 };
    check.checkInt(0, o.countPairs(nums));

    nums = { 50701,751 };
    check.checkInt(1, o.countPairs(nums));
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
