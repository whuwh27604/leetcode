/* 按位与结果大于零的最长组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对数组 nums 执行 按位与 相当于对数组 nums 中的所有整数执行 按位与 。

例如，对 nums = [1, 5, 3] 来说，按位与等于 1 & 5 & 3 = 1 。
同样，对 nums = [7] 而言，按位与等于 7 。
给你一个正整数数组 candidates 。计算 candidates 中的数字每种组合下 按位与 的结果。 candidates 中的每个数字在每种组合中只能使用 一次 。

返回按位与结果大于 0 的 最长 组合的长度。

 

示例 1：

输入：candidates = [16,17,71,62,12,24,14]
输出：4
解释：组合 [16,17,62,24] 的按位与结果是 16 & 17 & 62 & 24 = 16 > 0 。
组合长度是 4 。
可以证明不存在按位与结果大于 0 且长度大于 4 的组合。
注意，符合长度最大的组合可能不止一种。
例如，组合 [62,12,24,14] 的按位与结果是 62 & 12 & 24 & 14 = 8 > 0 。
示例 2：

输入：candidates = [8,8]
输出：2
解释：最长组合是 [8,8] ，按位与结果 8 & 8 = 8 > 0 。
组合长度是 2 ，所以返回 2 。
 

提示：

1 <= candidates.length <= 105
1 <= candidates[i] <= 107

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(32, 0);

        for (int candidate : candidates) {
            countBits(candidate, count);
        }

        return *max_element(count.begin(), count.end());
    }

    void countBits(int num, vector<int>& count) {
        int index = 0;

        while (num != 0) {
            if ((num & 1) == 1) {
                ++count[index];
            }

            num >>= 1;
            ++index;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> candidates = { 16,17,71,62,12,24,14 };
    check.checkInt(4, o.largestCombination(candidates));

    candidates = { 8,8 };
    check.checkInt(2, o.largestCombination(candidates));
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
