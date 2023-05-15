/* 老人的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 details 。details 中每个元素都是一位乘客的信息，信息用长度为 15 的字符串表示，表示方式如下：

前十个字符是乘客的手机号码。
接下来的一个字符是乘客的性别。
接下来两个字符是乘客的年龄。
最后两个字符是乘客的座位号。
请你返回乘客中年龄 严格大于 60 岁 的人数。



示例 1：

输入：details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
输出：2
解释：下标为 0 ，1 和 2 的乘客年龄分别为 75 ，92 和 40 。所以有 2 人年龄大于 60 岁。
示例 2：

输入：details = ["1313579440F2036","2921522980M5644"]
输出：0
解释：没有乘客的年龄大于 60 岁。


提示：

1 <= details.length <= 100
details[i].length == 15
details[i] 中的数字只包含 '0' 到 '9' 。
details[i][10] 是 'M' ，'F' 或者 'O' 之一。
所有乘客的手机号码和座位号互不相同。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for (string& detail : details) {
            if (detail[11] > '6' || (detail[11] == '6' && detail[12] > '0')) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> details = { "7868190130M7522","5303914400F9211","9273338290F4010" };
    check.checkInt(2, o.countSeniors(details));

    details = { "1313579440F2036","2921522980M5644" };
    check.checkInt(0, o.countSeniors(details));
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
