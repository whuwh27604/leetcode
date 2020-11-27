/* Fizz Buzz.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fizz-buzz
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> fizzBuzzNums;
        string fizz = "Fizz";
        string buzz = "Buzz";
        string fibu = "FizzBuzz";
        for (int i = 1; i <= n; i++) {
            if ((i / 3 / 5 * 3 * 5) == i) {
                fizzBuzzNums.push_back(fibu);
            }
            else {
                if ((i / 3 * 3) == i) {
                    fizzBuzzNums.push_back(fizz);
                }
                else if ((i / 5 * 5) == i) {
                    fizzBuzzNums.push_back(buzz);
                }
                else {
                    fizzBuzzNums.push_back(to_string(i));
                }
            }
        }

        return fizzBuzzNums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> expected = { "1" };
    vector<string> actual = o.fizzBuzz(1);
    check.checkStringVector(expected, actual);

    expected = { "1","2" };
    actual = o.fizzBuzz(2);
    check.checkStringVector(expected, actual);

    expected = { "1","2","Fizz" };
    actual = o.fizzBuzz(3);
    check.checkStringVector(expected, actual);

    expected = { "1","2","Fizz","4" };
    actual = o.fizzBuzz(4);
    check.checkStringVector(expected, actual);

    expected = { "1","2","Fizz","4","Buzz" };
    actual = o.fizzBuzz(5);
    check.checkStringVector(expected, actual);

    expected = { "1","2","Fizz","4","Buzz","Fizz","7" };
    actual = o.fizzBuzz(7);
    check.checkStringVector(expected, actual);

    expected = { "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz" };
    actual = o.fizzBuzz(15);
    check.checkStringVector(expected, actual);

    expected = { "1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz","16" };
    actual = o.fizzBuzz(16);
    check.checkStringVector(expected, actual);
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
