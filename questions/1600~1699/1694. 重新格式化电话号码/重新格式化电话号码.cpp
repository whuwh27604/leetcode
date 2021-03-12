/* 重新格式化电话号码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串形式的电话号码 number 。number 由数字、空格 ' '、和破折号 '-' 组成。

请你按下述方式重新格式化电话号码。

首先，删除 所有的空格和破折号。
其次，将数组从左到右 每 3 个一组 分块，直到 剩下 4 个或更少数字。剩下的数字将按下述规定再分块：
2 个数字：单个含 2 个数字的块。
3 个数字：单个含 3 个数字的块。
4 个数字：两个分别含 2 个数字的块。
最后用破折号将这些块连接起来。注意，重新格式化过程中 不应该 生成仅含 1 个数字的块，并且 最多 生成两个含 2 个数字的块。

返回格式化后的电话号码。

 

示例 1：

输入：number = "1-23-45 6"
输出："123-456"
解释：数字是 "123456"
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
连接这些块后得到 "123-456" 。
示例 2：

输入：number = "123 4-567"
输出："123-45-67"
解释：数字是 "1234567".
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
连接这些块后得到 "123-45-67" 。
示例 3：

输入：number = "123 4-5678"
输出："123-456-78"
解释：数字是 "12345678" 。
步骤 1：第 1 个块 "123" 。
步骤 2：第 2 个块 "456" 。
步骤 3：剩下 2 个数字，将它们放入单个含 2 个数字的块。第 3 个块是 "78" 。
连接这些块后得到 "123-456-78" 。
示例 4：

输入：number = "12"
输出："12"
示例 5：

输入：number = "--17-5 229 35-39475 "
输出："175-229-353-94-75"
 

提示：

2 <= number.length <= 100
number 由数字和字符 '-' 及 ' ' 组成。
number 中至少含 2 个数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reformat-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string reformated;
        int count = 0;

        for (char c : number) {
            if (c < '0' || c > '9') {
                continue;
            }

            if (count == 3) {
                count = 0;
                reformated += '-';
            }

            ++count;
            reformated += c;
        }

        if (count == 1) {
            swap(reformated[reformated.size() - 2], reformated[reformated.size() - 3]);
        }

        return reformated;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("123-456", o.reformatNumber("1-23-45 6"));
    check.checkString("123-45-67", o.reformatNumber("123 4-567"));
    check.checkString("123-456-78", o.reformatNumber("123 4-5678"));
    check.checkString("12", o.reformatNumber("12"));
    check.checkString("175-229-353-94-75", o.reformatNumber("--17-5 229 35-39475 "));
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
