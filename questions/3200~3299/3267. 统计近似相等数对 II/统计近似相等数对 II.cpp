/* 统计近似相等数对 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
注意：在这个问题中，操作次数增加为至多 两次 。

给你一个正整数数组 nums 。

如果我们执行以下操作 至多两次 可以让两个整数 x 和 y 相等，那么我们称这个数对是 近似相等 的：

选择 x 或者 y  之一，将这个数字中的两个数位交换。
请你返回 nums 中，下标 i 和 j 满足 i < j 且 nums[i] 和 nums[j] 近似相等 的数对数目。

注意 ，执行操作后得到的整数可以有前导 0 。



示例 1：

输入：nums = [1023,2310,2130,213]

输出：4

解释：

近似相等数对包括：

1023 和 2310 。交换 1023 中数位 1 和 2 ，然后交换数位 0 和 3 ，得到 2310 。
1023 和 213 。交换 1023 中数位 1 和 0 ，然后交换数位 1 和 2 ，得到 0213 ，也就是 213 。
2310 和 213 。交换 2310 中数位 2 和 0 ，然后交换数位 3 和 2 ，得到 0213 ，也就是 213 。
2310 和 2130 。交换 2310 中数位 3 和 1 ，得到 2130 。
示例 2：

输入：nums = [1,10,100]

输出：3

解释：

近似相等数对包括：

1 和 10 。交换 10 中数位 1 和 0 ，得到 01 ，也就是 1 。
1 和 100 。交换 100 中数位 1 和从左往右的第二个 0 ，得到 001 ，也就是 1 。
10 和 100 。交换 100 中数位 1 和从左往右的第一个 0 ，得到 010 ，也就是 10 。


提示：

2 <= nums.length <= 5000
1 <= nums[i] < 107
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        int oneCnt = 0, pairs = 0;
        unordered_map<int, int> numbers;
        unordered_set<int> ones = { 1,10,100,1000,10000,100000,1000000,10000000 };

        for (int num : nums) {
            if (ones.count(num) != 0) {
                ++oneCnt;
            }
            else {
                ++numbers[num];
            }
        }

        for (auto& kv : numbers) {
            int num = kv.first, cnt = kv.second;
            pairs += cnt * (cnt - 1);

            unordered_set<int> swap1, swap2, total;
            swapDigit(num, swap1, total, true);

            for (int num1 : swap1) {
                swapDigit(num1, swap2, total, false);
            }

            for (int swapped : total) {
                if (swapped != num && numbers.count(swapped) != 0) {
                    pairs += cnt * numbers[swapped];
                }
            }
        }

        return pairs / 2 + oneCnt * (oneCnt - 1) / 2;
    }

    void swapDigit(int num, unordered_set<int>& swapped, unordered_set<int>& total, bool save) {
        int maxBit = 1000000;

        for (int bit1 = 1; bit1 <= maxBit / 10; bit1 *= 10) {
            int d1 = num / bit1 % 10;

            for (int bit2 = bit1 * 10; bit2 <= maxBit; bit2 *= 10) {
                int d2 = num / bit2 % 10;
                int tmp = num - d1 * bit1 - d2 * bit2 + d1 * bit2 + d2 * bit1;
                total.insert(tmp);
                if (save) {
                    swapped.insert(tmp);
                }
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1023,2310,2130,213 };
    check.checkInt(4, o.countPairs(nums));

    nums = { 1,10,100 };
    check.checkInt(3, o.countPairs(nums));

    nums = { 3,3,20,3,3,13,13,13,3,3,12,8,3,3,3,3,4 };
    check.checkInt(48, o.countPairs(nums));

    nums = getIntVector("./testcase1.txt");
    check.checkInt(488678, o.countPairs(nums));
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
