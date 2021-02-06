/* 分割平衡字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。

给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。

返回可以通过分割得到的平衡字符串的最大数量。

 

示例 1：

输入：s = "RLRRLLRLRL"
输出：4
解释：s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。
示例 2：

输入：s = "RLLLLRRRLR"
输出：3
解释：s 可以分割为 "RL", "LLLRRR", "LR", 每个子字符串中都包含相同数量的 'L' 和 'R'。
示例 3：

输入：s = "LLLLRRRR"
输出：1
解释：s 只能保持原样 "LLLLRRRR".
 

提示：

1 <= s.length <= 1000
s[i] = 'L' 或 'R'
分割得到的每个字符串都必须是平衡字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-a-string-in-balanced-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int countL = 0, countR = 0, balanced = 0;

        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                countL++;
            }
            else {
                countR++;
            }

            if (countL == countR) {
                balanced++;
            }
        }

        return balanced;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(4, o.balancedStringSplit("RLRRLLRLRL"));
    check.checkInt(3, o.balancedStringSplit("RLLLLRRRLR"));
    check.checkInt(1, o.balancedStringSplit("LLLLRRRR"));
    check.checkInt(1, o.balancedStringSplit("LR"));
    check.checkInt(6, o.balancedStringSplit("LRLRLRLRLRLR"));
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
