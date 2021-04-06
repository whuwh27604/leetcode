/* 序列中不同最大公约数的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由正整数组成的数组 nums 。

数字序列的 最大公约数 定义为序列中所有整数的共有约数中的最大整数。

例如，序列 [4,6,16] 的最大公约数是 2 。
数组的一个 子序列 本质是一个序列，可以通过删除数组中的某些元素（或者不删除）得到。

例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。
计算并返回 nums 的所有 非空 子序列中 不同 最大公约数的 数目 。

 

示例 1：


输入：nums = [6,10,3]
输出：5
解释：上图显示了所有的非空子序列与各自的最大公约数。
不同的最大公约数为 6 、10 、3 、2 和 1 。
示例 2：

输入：nums = [5,15,40,5,6]
输出：7
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 2 * 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-different-subsequences-gcds
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int allSeqGCD = 0, maximum = *max_element(nums.begin(), nums.end());

        vector<bool> allNums(maximum + 1, false);
        getAllNums(nums, allNums);

        for (int seqGCD = 1; seqGCD <= maximum; ++seqGCD) {
            if (isSubsequenceGCD(allNums, seqGCD, maximum)) {
                ++allSeqGCD;
            }
        }

        return allSeqGCD;
    }

    void getAllNums(vector<int>& nums, vector<bool>& allNums) {
        for (int num : nums) {
            allNums[num] = true;
        }
    }

    bool isSubsequenceGCD(vector<bool>& allNums, int seqGCD, int maximum) {
        if (allNums[seqGCD]) {  // 这个seqGCD存在于数组中，那么它肯定是一个答案
            return true;
        }

        int GCD = 0;
        for (int num = seqGCD; num <= maximum; num += seqGCD) {
            if (!allNums[num]) {
                continue;
            }

            if (GCD == 0) {  // 第一个倍数
                GCD = num;
                continue;
            }
            
            GCD = gcd(GCD, num);  // gcd(a,b,c)=gcd(gcd(a,b),c)
            if (GCD == seqGCD) {  // 已经降到了seqGCD，不可能再小了，可以直接返回了
                return true;
            }
        }

        return false;
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 6,10,3 };
    check.checkInt(5, o.countDifferentSubsequenceGCDs(nums));

    nums = { 5,15,40,5,6 };
    check.checkInt(7, o.countDifferentSubsequenceGCDs(nums));

    nums = { 200000 };
    check.checkInt(1, o.countDifferentSubsequenceGCDs(nums));

    nums = { 16,15 };
    check.checkInt(3, o.countDifferentSubsequenceGCDs(nums));
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
