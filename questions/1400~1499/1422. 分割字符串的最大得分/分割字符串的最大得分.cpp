/* 分割字符串的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。

「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。

 

示例 1：

输入：s = "011101"
输出：5
解释：
将字符串 s 划分为两个非空子字符串的可行方案有：
左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5
左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4
左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3
左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2
左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3
示例 2：

输入：s = "00111"
输出：5
解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5
示例 3：

输入：s = "1111"
输出：3
 

提示：

2 <= s.length <= 500
字符串 s 仅由字符 '0' 和 '1' 组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int i, len = s.size(), totalOnes = 0;
        for (i = 0; i < len; i++) {
            if (s[i] == '1') {
                totalOnes++;
            }
        }

        int leftZeros = 0, leftOnes = 0, maximumScore = 0;
        for (i = 0; i < len - 1; i++) {
            if (s[i] == '0') {
                leftZeros++;
            }
            else {
                leftOnes++;
            }

            int rightOnes = totalOnes - leftOnes;
            int score = leftZeros + rightOnes;
            if (score > maximumScore) {
                maximumScore = score;
            }
        }

        return maximumScore;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(5, o.maxScore("011101"));
    check.checkInt(5, o.maxScore("00111"));
    check.checkInt(3, o.maxScore("1111"));
    check.checkInt(1, o.maxScore("00"));
    check.checkInt(2, o.maxScore("01"));
    check.checkInt(0, o.maxScore("10"));
    check.checkInt(1, o.maxScore("11"));
    check.checkInt(10, o.maxScore("11101010101000011"));
    check.checkInt(5, o.maxScore("1011011"));
    check.checkInt(4, o.maxScore("111110"));
    check.checkInt(3, o.maxScore("11110000"));
    check.checkInt(1, o.maxScore("1100"));
    check.checkInt(2, o.maxScore("010"));
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
