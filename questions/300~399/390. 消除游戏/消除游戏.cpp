/* 消除游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个从1 到 n 排序的整数列表。
首先，从左到右，从第一个数字开始，每隔一个数字进行删除，直到列表的末尾。
第二步，在剩下的数字中，从右到左，从倒数第一个数字开始，每隔一个数字进行删除，直到列表开头。
我们不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
返回长度为 n 的列表中，最后剩下的数字。

示例：

输入:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

输出:
6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/elimination-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        /* 考虑s1=1,2,..i和s2=1,2,...i,i+1,i+2,...i*2，s2经过第一轮删除后，就刚好等于s1每个数*2，所以接下来删除数字的位置是一样的，
           只是s1从前往后删，s2此时要从后往前删。所以最终s1剩下x的话，s2会剩下2*(i-x+1)。即dp[2*i]=2*(i-dp[i]+1)
           再考虑s1=1,2,...i,i+1,i+2,...i*2和s2=1,2,...i,i+1,i+2,...i*2,i*2+1，经过第一轮删除后，s1和s2剩下的数相同，所以dp[2*i+1]=dp[2*i] */
        if (n < 3) {
            return n;
        }

        if ((n % 2) == 1) {
            return lastRemaining(n - 1);
        }
        else {
            int i = n / 2;
            return 2 * (i - lastRemaining(i) + 1);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.lastRemaining(1));
    check.checkInt(8, o.lastRemaining(10));
    check.checkInt(54, o.lastRemaining(100));
    check.checkInt(510, o.lastRemaining(1000));
    check.checkInt(5974, o.lastRemaining(10000));
    check.checkInt(55286, o.lastRemaining(100000));
    check.checkInt(481110, o.lastRemaining(1000000));
    check.checkInt(6150102, o.lastRemaining(10000000));
    check.checkInt(32896342, o.lastRemaining(100000000));
    check.checkInt(534765398, o.lastRemaining(1000000000));
    check.checkInt(1073741824, o.lastRemaining(INT_MAX));
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
