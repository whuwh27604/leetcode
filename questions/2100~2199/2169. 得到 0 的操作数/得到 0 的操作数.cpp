/* 得到 0 的操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 非负 整数 num1 和 num2 。

每一步 操作 中，如果 num1 >= num2 ，你必须用 num1 减 num2 ；否则，你必须用 num2 减 num1 。

例如，num1 = 5 且 num2 = 4 ，应该用 num1 减 num2 ，因此，得到 num1 = 1 和 num2 = 4 。然而，如果 num1 = 4且 num2 = 5 ，一步操作后，得到 num1 = 4 和 num2 = 1 。
返回使 num1 = 0 或 num2 = 0 的 操作数 。

 

示例 1：

输入：num1 = 2, num2 = 3
输出：3
解释：
- 操作 1 ：num1 = 2 ，num2 = 3 。由于 num1 < num2 ，num2 减 num1 得到 num1 = 2 ，num2 = 3 - 2 = 1 。
- 操作 2 ：num1 = 2 ，num2 = 1 。由于 num1 > num2 ，num1 减 num2 。
- 操作 3 ：num1 = 1 ，num2 = 1 。由于 num1 == num2 ，num1 减 num2 。
此时 num1 = 0 ，num2 = 1 。由于 num1 == 0 ，不需要再执行任何操作。
所以总操作数是 3 。
示例 2：

输入：num1 = 10, num2 = 10
输出：1
解释：
- 操作 1 ：num1 = 10 ，num2 = 10 。由于 num1 == num2 ，num1 减 num2 得到 num1 = 10 - 10 = 0 。
此时 num1 = 0 ，num2 = 10 。由于 num1 == 0 ，不需要再执行任何操作。
所以总操作数是 1 。
 

提示：

0 <= num1, num2 <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-operations-to-obtain-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int opers = 0;

        while (num2 != 0) {
            opers += (num1 / num2);
            int tmp = num2;
            num2 = num1 % num2;
            num1 = tmp;
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.countOperations(2, 3));
    check.checkInt(1, o.countOperations(10, 10));
    check.checkInt(0, o.countOperations(0, 0));
    check.checkInt(100000, o.countOperations(99999, 100000));
    check.checkInt(145, o.countOperations(99999, 777));
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
