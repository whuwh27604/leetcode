/* 不可能得到的最短骰子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 rolls 和一个整数 k 。你扔一个 k 面的骰子 n 次，骰子的每个面分别是 1 到 k ，其中第 i 次扔得到的数字是 rolls[i] 。

请你返回 无法 从 rolls 中得到的 最短 骰子子序列的长度。

扔一个 k 面的骰子 len 次得到的是一个长度为 len 的 骰子子序列 。

注意 ，子序列只需要保持在原数组中的顺序，不需要连续。

 

示例 1：

输入：rolls = [4,2,1,2,3,3,2,4,1], k = 4
输出：3
解释：所有长度为 1 的骰子子序列 [1] ，[2] ，[3] ，[4] 都可以从原数组中得到。
所有长度为 2 的骰子子序列 [1, 1] ，[1, 2] ，... ，[4, 4] 都可以从原数组中得到。
子序列 [1, 4, 2] 无法从原数组中得到，所以我们返回 3 。
还有别的子序列也无法从原数组中得到。
示例 2：

输入：rolls = [1,1,2,2], k = 2
输出：2
解释：所有长度为 1 的子序列 [1] ，[2] 都可以从原数组中得到。
子序列 [2, 1] 无法从原数组中得到，所以我们返回 2 。
还有别的子序列也无法从原数组中得到，但 [2, 1] 是最短的子序列。
示例 3：

输入：rolls = [1,1,3,2,2,2,3,3], k = 4
输出：1
解释：子序列 [4] 无法从原数组中得到，所以我们返回 1 。
还有别的子序列也无法从原数组中得到，但 [4] 是最短的子序列。
 

提示：

n == rolls.length
1 <= n <= 105
1 <= rolls[i] <= k <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shortest-impossible-sequence-of-rolls
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int minSeq = 1, count = 0;
        vector<bool> exist(k + 1, false);

        for (int roll : rolls) {
            if (!exist[roll]) {
                exist[roll] = true;

                if (++count == k) {
                    ++minSeq;
                    count = 0;
                    exist = vector<bool>(k + 1, false);
                }
            }
        }

        return minSeq;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rolls = { 4,2,1,2,3,3,2,4,1 };
    check.checkInt(3, o.shortestSequence(rolls, 4));

    rolls = { 1,1,2,2 };
    check.checkInt(2, o.shortestSequence(rolls, 2));

    rolls = { 1,1,3,2,2,2,3,3 };
    check.checkInt(1, o.shortestSequence(rolls, 4));
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
