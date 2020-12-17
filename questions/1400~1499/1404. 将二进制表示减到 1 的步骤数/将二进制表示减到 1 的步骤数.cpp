/* 将二进制表示减到 1 的步骤数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个以二进制形式表示的数字 s 。请你返回按下述规则将其减少到 1 所需要的步骤数：

如果当前数字为偶数，则将其除以 2 。

如果当前数字为奇数，则将其加上 1 。

题目保证你总是可以按上述规则将测试用例变为 1 。

 

示例 1：

输入：s = "1101"
输出：6
解释："1101" 表示十进制数 13 。
Step 1) 13 是奇数，加 1 得到 14 
Step 2) 14 是偶数，除 2 得到 7
Step 3) 7  是奇数，加 1 得到 8
Step 4) 8  是偶数，除 2 得到 4 
Step 5) 4  是偶数，除 2 得到 2 
Step 6) 2  是偶数，除 2 得到 1 
示例 2：

输入：s = "10"
输出：1
解释："10" 表示十进制数 2 。
Step 1) 2 是偶数，除 2 得到 1
示例 3：

输入：s = "1"
输出：0
 

提示：

1 <= s.length <= 500
s 由字符 '0' 或 '1' 组成。
s[0] == '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int i, size = s.size(), steps = size - 1, add = 0;

        for (i = size - 1; i > 0; --i) {
            if (s[i] == '0') {
                steps += add;
            }
            else {
                if (add == 0) {
                    steps += 1;
                    add = 1;
                }
            }
        }

        return add == 0 ? steps : steps + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.numSteps("1101"));
    check.checkInt(1, o.numSteps("10"));
    check.checkInt(0, o.numSteps("1"));
    check.checkInt(24, o.numSteps("1011011101111011111"));
    check.checkInt(25, o.numSteps("10110111011110111110"));
    check.checkInt(31, o.numSteps("110111001111000111110000"));
    check.checkInt(34, o.numSteps("110111001111000111110001"));
    check.checkInt(13, o.numSteps("111111111111"));
    check.checkInt(13, o.numSteps("111111111110"));
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
