/* 统计平方和三元组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 平方和三元组 (a,b,c) 指的是满足 a2 + b2 = c2 的 整数 三元组 a，b 和 c 。

给你一个整数 n ，请你返回满足 1 <= a, b, c <= n 的 平方和三元组 的数目。

 

示例 1：

输入：n = 5
输出：2
解释：平方和三元组为 (3,4,5) 和 (4,3,5) 。
示例 2：

输入：n = 10
输出：4
解释：平方和三元组为 (3,4,5)，(4,3,5)，(6,8,10) 和 (8,6,10) 。
 

提示：

1 <= n <= 250

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-square-sum-triples
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int a, b, maxSquare = n * n, triples = 0;
        vector<bool> squares(maxSquare + 1, false);

        for (a = 1; a <= n; ++a) {
            squares[a * a] = true;
        }

        for (a = 2; a < n; ++a) {
            for (b = a + 1; b <= n; ++b) {
                int squareC = a * a + b * b;
                if (squareC > maxSquare) {
                    break;
                }

                if (squares[squareC]) {
                    triples += 2;
                }
            }
        }

        return triples;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.countTriples(1));
    check.checkInt(2, o.countTriples(5));
    check.checkInt(4, o.countTriples(10));
    check.checkInt(40, o.countTriples(50));
    check.checkInt(104, o.countTriples(100));
    check.checkInt(178, o.countTriples(150));
    check.checkInt(254, o.countTriples(200));
    check.checkInt(330, o.countTriples(250));
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
