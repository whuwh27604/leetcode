/* K 进制表示下的各位数字总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n（10 进制）和一个基数 k ，请你将 n 从 10 进制表示转换为 k 进制表示，计算并返回转换后各位数字的 总和 。

转换后，各位数字应当视作是 10 进制数字，且它们的总和也应当按 10 进制表示返回。

 

示例 1：

输入：n = 34, k = 6
输出：9
解释：34 (10 进制) 在 6 进制下表示为 54 。5 + 4 = 9 。
示例 2：

输入：n = 10, k = 10
输出：1
解释：n 本身就是 10 进制。 1 + 0 = 1 。
 

提示：

1 <= n <= 100
2 <= k <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-digits-in-base-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;

        while (n != 0) {
            sum += (n % k);
            n /= k;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(9, o.sumBase(34, 6));
    check.checkInt(1, o.sumBase(10, 10));
    check.checkInt(3, o.sumBase(7, 2));
    check.checkInt(1, o.sumBase(1, 9));
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
