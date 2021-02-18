/* 6 和 9 组成的最大数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由数字 6 和 9 组成的正整数 num。

你最多只能翻转一位数字，将 6 变成 9，或者把 9 变成 6 。

请返回你可以得到的最大数字。

 

示例 1：

输入：num = 9669
输出：9969
解释：
改变第一位数字可以得到 6669 。
改变第二位数字可以得到 9969 。
改变第三位数字可以得到 9699 。
改变第四位数字可以得到 9666 。
其中最大的数字是 9969 。
示例 2：

输入：num = 9996
输出：9999
解释：将最后一位从 6 变到 9，其结果 9999 是最大的数。
示例 3：

输入：num = 9999
输出：9999
解释：无需改变就已经是最大的数字了。
 

提示：

1 <= num <= 10^4
num 每一位上的数字都是 6 或者 9 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-69-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <sstream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        string::size_type position = s.find("6");
        if (position != s.npos) {
            s.replace(position, 1, "9");
        }

        stringstream ss;
        ss << s;
        int maxNumber;
        ss >> maxNumber;
        return maxNumber;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(9969, o.maximum69Number(9669));
    check.checkInt(9999, o.maximum69Number(9996));
    check.checkInt(9999, o.maximum69Number(9999));
    check.checkInt(9, o.maximum69Number(9));
    check.checkInt(9, o.maximum69Number(6));
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
