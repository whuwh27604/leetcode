/* 跳跃游戏 VII.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二进制字符串 s 和两个整数 minJump 和 maxJump 。一开始，你在下标 0 处，且该位置的值一定为 '0' 。当同时满足如下条件时，你可以从下标 i 移动到下标 j 处：

i + minJump <= j <= min(i + maxJump, s.length - 1) 且
s[j] == '0'.
如果你可以到达 s 的下标 s.length - 1 处，请你返回 true ，否则返回 false 。

 

示例 1：

输入：s = "011010", minJump = 2, maxJump = 3
输出：true
解释：
第一步，从下标 0 移动到下标 3 。
第二步，从下标 3 移动到下标 5 。
示例 2：

输入：s = "01101110", minJump = 2, maxJump = 3
输出：false
 

提示：

2 <= s.length <= 105
s[i] 要么是 '0' ，要么是 '1'
s[0] == '0'
1 <= minJump <= maxJump < s.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-vii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int i, j, size = s.size(), end = maxJump + 1;

        for (i = minJump; i <= maxJump && i < size; ++i) {
            if (s[i] == '0') {
                s[i] = '2';
            }
        }

        for (i = minJump; i < size; ++i) {
            if (s[i] == '0' || s[i] == '1') {
                continue;
            }

            for (j = max(end, i + minJump); j <= i + maxJump && j < size; ++j) {
                if (s[j] == '0') {
                    s[j] = '2';
                }
            }

            end = j;
        }

        return s.back() == '2';
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.canReach("011010", 2, 3));
    check.checkBool(false, o.canReach("01101110", 2, 3));
    check.checkBool(false, o.canReach("01", 1, 3));
    check.checkBool(false, o.canReach("011100110101011011011110", 4, 5));
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
