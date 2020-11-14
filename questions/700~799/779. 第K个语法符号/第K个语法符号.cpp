/* 第K个语法符号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）


例子:

输入: N = 1, K = 1
输出: 0

输入: N = 2, K = 1
输出: 0

输入: N = 2, K = 2
输出: 1

输入: N = 4, K = 5
输出: 1

解释:
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001

注意：

N 的范围 [1, 30].
K 的范围 [1, 2^(N-1)].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-th-symbol-in-grammar
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        stack<int> oneOrTwo;

        // 第N行的第K个数由N-1行的第(K+1)/2个数变来。如果K是奇数，变化后取第一个数；如果K是偶数，变化后取第二个数
        while (K != 1) {
            oneOrTwo.push(K % 2 == 1 ? 1 : 2);
            K = (K + 1) / 2;
        }

        int num = 0;  // 第一行的数为0
        while (!oneOrTwo.empty()) {
            if (oneOrTwo.top() == 2) {  // 如果取第一个数，则num不变；如果取第二个数，则1变为0，0变为1
                num = (num + 1) % 2;
            }

            oneOrTwo.pop();
        }

        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.kthGrammar(1, 1));
    check.checkInt(0, o.kthGrammar(2, 1));
    check.checkInt(1, o.kthGrammar(2, 2));
    check.checkInt(0, o.kthGrammar(3, 1));
    check.checkInt(1, o.kthGrammar(3, 2));
    check.checkInt(1, o.kthGrammar(3, 3));
    check.checkInt(0, o.kthGrammar(3, 4));
    check.checkInt(0, o.kthGrammar(4, 1));
    check.checkInt(1, o.kthGrammar(4, 2));
    check.checkInt(1, o.kthGrammar(4, 3));
    check.checkInt(0, o.kthGrammar(4, 4));
    check.checkInt(1, o.kthGrammar(4, 5));
    check.checkInt(0, o.kthGrammar(4, 6));
    check.checkInt(0, o.kthGrammar(4, 7));
    check.checkInt(1, o.kthGrammar(4, 8));
    check.checkInt(0, o.kthGrammar(30, 1));
    check.checkInt(1, o.kthGrammar(30, 9));
    check.checkInt(0, o.kthGrammar(30, 10));
    check.checkInt(1, o.kthGrammar(30, 99));
    check.checkInt(0, o.kthGrammar(30, 100));
    check.checkInt(1, o.kthGrammar(30, 999));
    check.checkInt(0, o.kthGrammar(30, 1000));
    check.checkInt(1, o.kthGrammar(30, 9876));
    check.checkInt(0, o.kthGrammar(30, 10000));
    check.checkInt(1, o.kthGrammar(30, 98765));
    check.checkInt(0, o.kthGrammar(30, 100000));
    check.checkInt(0, o.kthGrammar(30, 987654));
    check.checkInt(0, o.kthGrammar(30, 1000000));
    check.checkInt(1, o.kthGrammar(30, 9876543));
    check.checkInt(0, o.kthGrammar(30, 10000000));
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
