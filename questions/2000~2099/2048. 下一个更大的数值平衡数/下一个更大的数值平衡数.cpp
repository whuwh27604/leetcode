/* 下一个更大的数值平衡数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果整数  x 满足：对于每个数位 d ，这个数位 恰好 在 x 中出现 d 次。那么整数 x 就是一个 数值平衡数 。

给你一个整数 n ，请你返回 严格大于 n 的 最小数值平衡数 。

 

示例 1：

输入：n = 1
输出：22
解释：
22 是一个数值平衡数，因为：
- 数字 2 出现 2 次
这也是严格大于 1 的最小数值平衡数。
示例 2：

输入：n = 1000
输出：1333
解释：
1333 是一个数值平衡数，因为：
- 数字 1 出现 1 次。
- 数字 3 出现 3 次。
这也是严格大于 1000 的最小数值平衡数。
注意，1022 不能作为本输入的答案，因为数字 0 的出现次数超过了 0 。
示例 3：

输入：n = 3000
输出：3133
解释：
3133 是一个数值平衡数，因为：
- 数字 1 出现 1 次。
- 数字 3 出现 3 次。
这也是严格大于 3000 的最小数值平衡数。
 

提示：

0 <= n <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-numerically-balanced-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        int number = n + 1;

        for (; true; ++number) {
            int num = number, digits[10] = { 0 };
            bool check = true;

            while (num != 0) {
                int digit = num % 10;
                if (digit == 0 || digit == 7 || digit == 8 || digit == 9) {
                    check = false;
                    break;
                }

                ++digits[digit];
                num /= 10;
            }

            if (check && (digits[1] == 0 || digits[1] == 1) && (digits[2] == 0 || digits[2] == 2) && (digits[3] == 0 || digits[3] == 3)
                && (digits[4] == 0 || digits[4] == 4) && (digits[5] == 0 || digits[5] == 5) && (digits[6] == 0 || digits[6] == 6)) {
                break;
            }
        }

        return number;
    }
};

int main()
{
    CheckResult check;
    Solution o;
    
    check.checkInt(1, o.nextBeautifulNumber(0));
    check.checkInt(22, o.nextBeautifulNumber(1));
    check.checkInt(122, o.nextBeautifulNumber(100));
    check.checkInt(14444, o.nextBeautifulNumber(4444));
    check.checkInt(1224444, o.nextBeautifulNumber(666666));
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
