/* 最大相等频率.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回该前缀的长度：

从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。
如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。

 

示例 1：

输入：nums = [2,2,1,1,5,3,3,5]
输出：7
解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到 [2,2,1,1,3,3]，里面每个数字都出现了两次。
示例 2：

输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
输出：13
 

提示：

2 <= nums.length <= 105
1 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-equal-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> counts;
        int len = 0, longestPrefix = 0, maxFreq = 0, maxFreqFreq = 0;

        for (int num : nums) {
            ++counts[num];
            ++len;
            int freq = counts[num];

            if (freq > maxFreq) {
                maxFreq = freq;
                maxFreqFreq = 1;
            }
            else if (freq == maxFreq) {
                maxFreqFreq += 1;
            }

            // 三种情况：1、ABCD； 2、AAABBBCCCD； 3、AAABBBCCCDDDD（包括AAAA这种特例）
            if ((maxFreq == 1)
                || (maxFreq * maxFreqFreq + 1 == len)
                || ((maxFreq - 1) * counts.size() + 1 == len && maxFreqFreq == 1)) {
                longestPrefix = len;
            }
        }

        return longestPrefix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,2,1,1,5,3,3,5 };
    check.checkInt(7, o.maxEqualFreq(nums));

    nums = { 1,1,1,2,2,2,3,3,3,4,4,4,5 };
    check.checkInt(13, o.maxEqualFreq(nums));

    nums = { 10,2,8,9,3,8,1,5,2,3,7,6 };
    check.checkInt(8, o.maxEqualFreq(nums));

    nums = { 2,3,3 };
    check.checkInt(3, o.maxEqualFreq(nums));

    nums = { 1,1,1,2,2,2 };
    check.checkInt(5, o.maxEqualFreq(nums));

    nums = { 1,1 };
    check.checkInt(2, o.maxEqualFreq(nums));

    nums = { 1,2 };
    check.checkInt(2, o.maxEqualFreq(nums));

    nums = { 1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,42,21,45,27,78,39,78,24,47,60,22,33,45,18,56,91,93,66,79,65,43,7,57,63,74,25,11,14,100,95,19,3,22,18,94,52,91,33,95,16,93,63,65,8,88,51,47,7,51,77,36,48,89,72,81,75,13,69,9,31,16,38,34,76,7,82,10,90,64,28,22,99,40,88,27,94,85,43,75,95,86,82,46,9,74,67,51,93,97,35,2,49 };
    check.checkInt(7, o.maxEqualFreq(nums));
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
