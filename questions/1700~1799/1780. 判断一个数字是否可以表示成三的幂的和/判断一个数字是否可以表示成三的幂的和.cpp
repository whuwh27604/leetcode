/* 判断一个数字是否可以表示成三的幂的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，如果你可以将 n 表示成若干个不同的三的幂之和，请你返回 true ，否则请返回 false 。

对于一个整数 y ，如果存在整数 x 满足 y == 3x ，我们称这个整数 y 是三的幂。

 

示例 1：

输入：n = 12
输出：true
解释：12 = 31 + 32
示例 2：

输入：n = 91
输出：true
解释：91 = 30 + 32 + 34
示例 3：

输入：n = 21
输出：false
 

提示：

1 <= n <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-number-is-a-sum-of-powers-of-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers = { 1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969 };

        for (int i = powers.size() - 1; i >= 0; --i) {
            if (n >= powers[i]) {
                n -= powers[i];
            }
        }

        return n == 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.checkPowersOfThree(12));
    check.checkBool(true, o.checkPowersOfThree(91));
    check.checkBool(false, o.checkPowersOfThree(21));
    check.checkBool(true, o.checkPowersOfThree(4782969));
    check.checkBool(true, o.checkPowersOfThree(7174453));
    check.checkBool(false, o.checkPowersOfThree(7174454));
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
