/* 个位数字为 K 的整数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 num 和 k ，考虑具有以下属性的正整数多重集：

每个整数个位数字都是 k 。
所有整数之和是 num 。
返回该多重集的最小大小，如果不存在这样的多重集，返回 -1 。

注意：

多重集与集合类似，但多重集可以包含多个同一整数，空多重集的和为 0 。
个位数字 是数字最右边的数位。
 

示例 1：

输入：num = 58, k = 9
输出：2
解释：
多重集 [9,49] 满足题目条件，和为 58 且每个整数的个位数字是 9 。
另一个满足条件的多重集是 [19,39] 。
可以证明 2 是满足题目条件的多重集的最小长度。
示例 2：

输入：num = 37, k = 2
输出：-1
解释：个位数字为 2 的整数无法相加得到 37 。
示例 3：

输入：num = 0, k = 7
输出：0
解释：空多重集的和为 0 。
 

提示：

0 <= num <= 3000
0 <= k <= 9

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }

        for (int i = 1; i <= 10; ++i) {
            int multi = i * k;

            if ((multi % 10) == (num % 10)) {
                if (num >= multi) {
                    return i;
                }
                else {
                    return -1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minimumNumbers(58, 9));
    check.checkInt(-1, o.minimumNumbers(37, 2));
    check.checkInt(0, o.minimumNumbers(0, 7));
    check.checkInt(5, o.minimumNumbers(15, 1));
    check.checkInt(10, o.minimumNumbers(80, 1));
    check.checkInt(2, o.minimumNumbers(20, 5));
    check.checkInt(-1, o.minimumNumbers(31, 9));
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
