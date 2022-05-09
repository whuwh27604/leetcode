/* 移除指定数字得到的最大结果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个表示某个正整数的字符串 number 和一个字符 digit 。

从 number 中 恰好 移除 一个 等于 digit 的字符后，找出并返回按 十进制 表示 最大 的结果字符串。生成的测试用例满足 digit 在 number 中出现至少一次。

 

示例 1：

输入：number = "123", digit = "3"
输出："12"
解释："123" 中只有一个 '3' ，在移除 '3' 之后，结果为 "12" 。
示例 2：

输入：number = "1231", digit = "1"
输出："231"
解释：可以移除第一个 '1' 得到 "231" 或者移除第二个 '1' 得到 "123" 。
由于 231 > 123 ，返回 "231" 。
示例 3：

输入：number = "551", digit = "5"
输出："51"
解释：可以从 "551" 中移除第一个或者第二个 '5' 。
两种方案的结果都是 "51" 。
 

提示：

2 <= number.length <= 100
number 由数字 '1' 到 '9' 组成
digit 是 '1' 到 '9' 中的一个数字
digit 在 number 中出现至少一次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-digit-from-number-to-maximize-result
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int i, size = number.size(), index = 0;

        // 贪心，如果digit比后面一个字符小，那么应该立即删除它；如果不比后面一个小，那么记录该位置，并删除最后一个digit
        for (i = 0; i < size; ++i) {
            if (number[i] == digit) {
                index = i;

                if (i != size - 1 && number[i] < number[i + 1]) {
                    break;
                }
            }
        }

        return string(number, 0, index) + string(number, index + 1, size - index - 1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("12", o.removeDigit("123", '3'));
    check.checkString("231", o.removeDigit("1231", '1'));
    check.checkString("51", o.removeDigit("551", '5'));
    check.checkString("8", o.removeDigit("98", '9'));
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
