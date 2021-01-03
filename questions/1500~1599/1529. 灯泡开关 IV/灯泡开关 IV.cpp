/* 灯泡开关 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
房间中有 n 个灯泡，编号从 0 到 n-1 ，自左向右排成一行。最开始的时候，所有的灯泡都是 关 着的。

请你设法使得灯泡的开关状态和 target 描述的状态一致，其中 target[i] 等于 1 第 i 个灯泡是开着的，等于 0 意味着第 i 个灯是关着的。

有一个开关可以用于翻转灯泡的状态，翻转操作定义如下：

选择当前配置下的任意一个灯泡（下标为 i ）
翻转下标从 i 到 n-1 的每个灯泡
翻转时，如果灯泡的状态为 0 就变为 1，为 1 就变为 0 。

返回达成 target 描述的状态所需的 最少 翻转次数。

 

示例 1：

输入：target = "10111"
输出：3
解释：初始配置 "00000".
从第 3 个灯泡（下标为 2）开始翻转 "00000" -> "00111"
从第 1 个灯泡（下标为 0）开始翻转 "00111" -> "11000"
从第 2 个灯泡（下标为 1）开始翻转 "11000" -> "10111"
至少需要翻转 3 次才能达成 target 描述的状态
示例 2：

输入：target = "101"
输出：3
解释："000" -> "111" -> "100" -> "101".
示例 3：

输入：target = "00000"
输出：0
示例 4：

输入：target = "001011101"
输出：5
 

提示：

1 <= target.length <= 10^5
target[i] == '0' 或者 target[i] == '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bulb-switcher-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        char prev = '0';
        int flips = 0;

        for (char c : target) {
            if (c != prev) {
                ++flips;
            }

            prev = c;
        }

        return flips;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minFlips("10111"));
    check.checkInt(3, o.minFlips("101"));
    check.checkInt(0, o.minFlips("00000"));
    check.checkInt(5, o.minFlips("001011101"));
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
