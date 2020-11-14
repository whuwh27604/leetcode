/* 外观数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
解释：这是一个基本样例。
示例 2:

输入: 4
输出: "1211"
解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 = 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "../check/CheckResult.h"

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        vector<int> serial = { 1 };
        for (int i = 1; i < n; i++) {
            serial = getNext(serial);
        }

        return toString(serial);
    }

    vector<int> getNext(vector<int> input) {
        int lastNumber = input[0];
        int numberCount = 1;
        vector<int> output;
        for (unsigned int i = 1; i < input.size(); i++) {
            int number = input[i];
            if (number == lastNumber) {
                numberCount++;
            }
            else {
                output.push_back(numberCount);
                output.push_back(lastNumber);
                lastNumber = number;
                numberCount = 1;
            }
        }

        output.push_back(numberCount);
        output.push_back(lastNumber);

        return output;
    }

    string toString(vector<int>& serial) {
        string output;
        for (unsigned int i = 0; i < serial.size(); i++) {
            string s = to_string(serial[i]);
            output.append(s);
        }
        return output;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("1", o.countAndSay(1));
    check.checkString("11", o.countAndSay(2));
    check.checkString("21", o.countAndSay(3));
    check.checkString("1211", o.countAndSay(4));
    check.checkString("111221", o.countAndSay(5));
    check.checkString("312211", o.countAndSay(6));
    check.checkString("", o.countAndSay(0));
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
