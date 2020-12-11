/* 完美数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。

给定一个 整数 n， 如果他是完美数，返回 True，否则返回 False

 

示例：

输入: 28
输出: True
解释: 28 = 1 + 2 + 4 + 7 + 14
 

提示：

输入的数字 n 不会超过 100,000,000. (1e8)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 5) {
            return false;
        }

        vector<int> factors;
        int root = (int)sqrt(num);
        factors.reserve(2 * root);
        factors.push_back(1);

        for (int i = 2; i <= root; i++) {
            int quotient = (num / i);
            if ((quotient * i) != num) {
                continue;
            }

            factors.push_back(i);
            if (quotient != i) {
                factors.push_back(quotient);
            }
        }

        int sum = 0;
        for (unsigned int i = 0; i < factors.size(); i++) {
            sum += factors[i];
        }

        return (sum == num);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.checkPerfectNumber(28));
    check.checkBool(false, o.checkPerfectNumber(1));
    check.checkBool(false, o.checkPerfectNumber(2));
    check.checkBool(false, o.checkPerfectNumber(3));
    check.checkBool(false, o.checkPerfectNumber(4));
    check.checkBool(false, o.checkPerfectNumber(5));
    check.checkBool(true, o.checkPerfectNumber(6));
    check.checkBool(false, o.checkPerfectNumber(7));
    check.checkBool(false, o.checkPerfectNumber(8));
    check.checkBool(false, o.checkPerfectNumber(9));
    check.checkBool(false, o.checkPerfectNumber(10));
    check.checkBool(false, o.checkPerfectNumber(11));
    check.checkBool(false, o.checkPerfectNumber(12));
    check.checkBool(false, o.checkPerfectNumber(15));
    check.checkBool(false, o.checkPerfectNumber(16));
    check.checkBool(false, o.checkPerfectNumber(17));
    check.checkBool(false, o.checkPerfectNumber(18));
    check.checkBool(false, o.checkPerfectNumber(19));
    check.checkBool(false, o.checkPerfectNumber(20));
    check.checkBool(false, o.checkPerfectNumber(21));
    check.checkBool(false, o.checkPerfectNumber(22));
    check.checkBool(false, o.checkPerfectNumber(23));
    check.checkBool(false, o.checkPerfectNumber(24));
    check.checkBool(false, o.checkPerfectNumber(25));
    check.checkBool(false, o.checkPerfectNumber(26));
    check.checkBool(false, o.checkPerfectNumber(27));
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
