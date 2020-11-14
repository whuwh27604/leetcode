/* 神奇字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
神奇的字符串 S 只包含 '1' 和 '2'，并遵守以下规则：

字符串 S 是神奇的，因为串联字符 '1' 和 '2' 的连续出现次数会生成字符串 S 本身。

字符串 S 的前几个元素如下：S = “1221121221221121122 ......”

如果我们将 S 中连续的 1 和 2 进行分组，它将变成：

1 22 11 2 1 22 1 22 11 2 11 22 ......

并且每个组中 '1' 或 '2' 的出现次数分别是：

1 2 2 1 1 2 1 2 2 1 2 2 ......

你可以看到上面的出现次数就是 S 本身。

给定一个整数 N 作为输入，返回神奇字符串 S 中前 N 个数字中的 '1' 的数目。

注意：N 不会超过 100,000。

示例：

输入：6
输出：3
解释：神奇字符串 S 的前 6 个元素是 “12211”，它包含三个 1，因此返回 3。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magical-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n == 0) {
            return 0;
        }

        if (n < 4) {
            return 1;
        }

        char* str = new char[n];
        str[0] = 1;
        str[1] = 2;
        str[2] = 2;

        int fast = 3, slow = 2, count = 1, num = 1;
        while (fast < n) {
            str[fast++] = num;
            count += (num & 1);
            if ((str[slow++] == 2) && (fast < n)) {
                str[fast++] = num;
                count += (num & 1);
            }

            num ^= 0b11;
        }

        delete[] str;
        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.magicalString(0));
    check.checkInt(1, o.magicalString(1));
    check.checkInt(1, o.magicalString(2));
    check.checkInt(1, o.magicalString(3));
    check.checkInt(2, o.magicalString(4));
    check.checkInt(3, o.magicalString(5));
    check.checkInt(3, o.magicalString(6));
    check.checkInt(4, o.magicalString(7));
    check.checkInt(5, o.magicalString(10));
    check.checkInt(49, o.magicalString(100));
    check.checkInt(49972, o.magicalString(100000));
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
