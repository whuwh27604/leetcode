/* 只有两个键的键盘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
最初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：

Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
Paste (粘贴) : 你可以粘贴你上一次复制的字符。
给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。输出能够打印出 n 个 'A' 的最少操作次数。

示例 1:

输入: 3
输出: 3
解释:
最初, 我们只有一个字符 'A'。
第 1 步, 我们使用 Copy All 操作。
第 2 步, 我们使用 Paste 操作来获得 'AA'。
第 3 步, 我们使用 Paste 操作来获得 'AAA'。
说明:

n 的取值范围是 [1, 1000] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2-keys-keyboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int factor, num = n, count = 0;

        while ((factor = decompose(num)) != 1) {
            count += factor;
            num /= factor;
        }

        return n == 1 ? 0 : count + num;
    }

    int decompose(int n) {
        int root = (int)sqrt(n);

        for (int factor = 2; factor <= root; factor++) {
            if (n % factor == 0) {
                return factor;
            }
        }

        return 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.minSteps(1));
    check.checkInt(2, o.minSteps(2));
    check.checkInt(3, o.minSteps(3));
    check.checkInt(4, o.minSteps(4));
    check.checkInt(5, o.minSteps(5));
    check.checkInt(6, o.minSteps(9));
    check.checkInt(17, o.minSteps(99));
    check.checkInt(14, o.minSteps(100));
    check.checkInt(199, o.minSteps(199));
    check.checkInt(46, o.minSteps(999));
    check.checkInt(21, o.minSteps(1000));
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
