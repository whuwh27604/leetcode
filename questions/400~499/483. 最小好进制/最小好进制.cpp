/* 最小好进制.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对于给定的整数 n, 如果n的k（k>=2）进制数的所有数位全为1，则称 k（k>=2）是 n 的一个好进制。

以字符串的形式给出 n, 以字符串的形式返回 n 的最小好进制。

 

示例 1：

输入："13"
输出："3"
解释：13 的 3 进制是 111。
示例 2：

输入："4681"
输出："8"
解释：4681 的 8 进制是 11111。
示例 3：

输入："1000000000000000000"
输出："999999999999999999"
解释：1000000000000000000 的 999999999999999999 进制是 11。
 

提示：

n的取值范围是 [3, 10^18]。
输入总是有效且没有前导 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-good-base
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        int maxPower = (int)floor(log(num) / log(2));

        for (int power = maxPower; power > 1; --power) {
            int k = (int)pow(num, 1.0 / power);
            long long multi = 1, sum = 1;

            for (int i = 0; i < power; ++i) {
                multi *= k;
                sum += multi;
            }

            if (sum == num) {
                return to_string(k);
            }
        }

        return to_string(num - 1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("3", o.smallestGoodBase("13"));
    check.checkString("8", o.smallestGoodBase("4681"));
    check.checkString("999999999999999999", o.smallestGoodBase("1000000000000000000"));
    check.checkString("999999999999999998", o.smallestGoodBase("999999999999999999"));
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
