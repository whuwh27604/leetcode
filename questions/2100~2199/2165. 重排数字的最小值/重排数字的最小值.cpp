/* 重排数字的最小值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 num 。重排 num 中的各位数字，使其值 最小化 且不含 任何 前导零。

返回不含前导零且值最小的重排数字。

注意，重排各位数字后，num 的符号不会改变。

 

示例 1：

输入：num = 310
输出：103
解释：310 中各位数字的可行排列有：013、031、103、130、301、310 。
不含任何前导零且值最小的重排数字是 103 。
示例 2：

输入：num = -7605
输出：-7650
解释：-7605 中各位数字的部分可行排列为：-7650、-6705、-5076、-0567。
不含任何前导零且值最小的重排数字是 -7650 。
 

提示：

-1015 <= num <= 1015

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-value-of-the-rearranged-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;
        }
        else if (num > 0) {
            return smallestPositive(num);
        }
        else {
            return smallestNegative(num);
        }
    }

    long long smallestPositive(long long num) {
        string number = to_string(num);
        int i, j = 0, k, size = number.size();
        string smallest(size, 0);

        sort(number.begin(), number.end());

        for (i = 0; i < size && number[i] == '0'; ++i) {}

        smallest[j++] = number[i];

        for (k = 0; k < i; ++k) {
            smallest[j++] = '0';
        }

        for (++i; i < size; ++i) {
            smallest[j++] = number[i];
        }

        return stoll(smallest);
    }

    long long smallestNegative(long long num) {
        num = -num;
        string number = to_string(num);
        int i, j = 0, size = number.size();
        string smallest(size, 0);

        sort(number.begin(), number.end());

        for (i = size - 1; i >= 0; --i) {
            smallest[j++] = number[i];
        }

        return -stoll(smallest);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(103, o.smallestNumber(310));
    check.checkLongLong(-7650, o.smallestNumber(-7605));
    check.checkLongLong(0, o.smallestNumber(0));
    check.checkLongLong(1, o.smallestNumber(1));
    check.checkLongLong(-5, o.smallestNumber(-5));
    check.checkLongLong(1000223, o.smallestNumber(1020203));
    check.checkLongLong(-98760000, o.smallestNumber(-90807006));
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
