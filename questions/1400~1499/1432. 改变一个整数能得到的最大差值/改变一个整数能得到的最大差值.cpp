/* 改变一个整数能得到的最大差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 num 。你可以对它进行如下步骤恰好 两次 ：

选择一个数字 x (0 <= x <= 9).
选择另一个数字 y (0 <= y <= 9) 。数字 y 可以等于 x 。
将 num 中所有出现 x 的数位都用 y 替换。
得到的新的整数 不能 有前导 0 ，得到的新整数也 不能 是 0 。
令两次对 num 的操作得到的结果分别为 a 和 b 。

请你返回 a 和 b 的 最大差值 。

 

示例 1：

输入：num = 555
输出：888
解释：第一次选择 x = 5 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 5 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 999 和 b = 111 ，最大差值为 888
示例 2：

输入：num = 9
输出：8
解释：第一次选择 x = 9 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 9 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 9 和 b = 1 ，最大差值为 8
示例 3：

输入：num = 123456
输出：820000
示例 4：

输入：num = 10000
输出：80000
示例 5：

输入：num = 9288
输出：8700
 

提示：

1 <= num <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-difference-you-can-get-from-changing-an-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        return toMax(num) - toMin(num);
    }

    int toMax(int num) {
        string s = to_string(num);
        int i, size = s.size();
        char x = 'a', y = '9';

        for (i = 0; i < size; ++i) {
            if (s[i] != '9') {  // 找到第一个不是9的x
                x = s[i];
                break;
            }
        }

        for (; i < size; ++i) {
            if (s[i] == x) {
                s[i] = y;  // 把x替换为9
            }
        }

        return stoi(s);
    }

    int toMin(int num) {
        string s = to_string(num);
        int i = 0, size = s.size();
        char x = 'a', y = 'a';

        if (s[i] != '1') {  // 如果第一位不是1，那么这个数可以被1替换
            x = s[i];
            y = '1';
        }
        else {  // 如果第一位是1，那么往后找即不是1也不是0的数，把它替换为0。不能把1替换为0，因为所有的1都将被替换，这样会出现前导0
            for (i = 1; i < size; ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    x = s[i];
                    y = '0';
                    break;
                }
            }
        }

        for (; i < size; ++i) {
            if (s[i] == x) {
                s[i] = y;
            }
        }

        return stoi(s);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(888, o.maxDiff(555));
    check.checkInt(8, o.maxDiff(9));
    check.checkInt(820000, o.maxDiff(123456));
    check.checkInt(80000, o.maxDiff(10000));
    check.checkInt(8700, o.maxDiff(9288));
    check.checkInt(8, o.maxDiff(1));
    check.checkInt(882, o.maxDiff(112));
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
