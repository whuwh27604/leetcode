/* 最简分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

 

示例 1：

输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
示例 2：

输入：n = 3
输出：["1/2","1/3","2/3"]
示例 3：

输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
示例 4：

输入：n = 1
输出：[]
 

提示：

1 <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplified-fractions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> fractions;
        int numerator, denominator;

        for (denominator = 2; denominator <= n; ++denominator) {
            for (numerator = 1; numerator < denominator; ++numerator) {
                if (gcd(numerator, denominator) == 1) {
                    fractions.push_back(to_string(numerator) + '/' + to_string(denominator));
                }
            }
        }

        return fractions;
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.simplifiedFractions(2);
    vector<string> expected = { "1/2" };
    check.checkStringVector(expected, actual);

    actual = o.simplifiedFractions(1);
    expected = {  };
    check.checkStringVector(expected, actual);

    actual = o.simplifiedFractions(3);
    expected = { "1/2","1/3","2/3" };
    check.checkStringVector(expected, actual);

    actual = o.simplifiedFractions(4);
    expected = { "1/2","1/3","2/3","1/4","3/4", };
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
