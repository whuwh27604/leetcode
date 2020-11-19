/* 交换字符使得字符串相同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有两个长度相同的字符串 s1 和 s2，且它们其中 只含有 字符 "x" 和 "y"，你需要通过「交换字符」的方式使这两个字符串相同。

每次「交换字符」的时候，你都可以在两个字符串中各选一个字符进行交换。

交换只能发生在两个不同的字符串之间，绝对不能发生在同一个字符串内部。也就是说，我们可以交换 s1[i] 和 s2[j]，但不能交换 s1[i] 和 s1[j]。

最后，请你返回使 s1 和 s2 相同的最小交换次数，如果没有方法能够使得这两个字符串相同，则返回 -1 。

 

示例 1：

输入：s1 = "xx", s2 = "yy"
输出：1
解释：
交换 s1[0] 和 s2[1]，得到 s1 = "yx"，s2 = "yx"。
示例 2：

输入：s1 = "xy", s2 = "yx"
输出：2
解释：
交换 s1[0] 和 s2[0]，得到 s1 = "yy"，s2 = "xx" 。
交换 s1[0] 和 s2[1]，得到 s1 = "xy"，s2 = "xy" 。
注意，你不能交换 s1[0] 和 s1[1] 使得 s1 变成 "yx"，因为我们只能交换属于两个不同字符串的字符。
示例 3：

输入：s1 = "xx", s2 = "xy"
输出：-1
示例 4：

输入：s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx"
输出：4
 

提示：

1 <= s1.length, s2.length <= 1000
s1, s2 只包含 'x' 或 'y'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-swaps-to-make-strings-equal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        /* 贪心算法：对于每一个s1[i]/s2[2]：1、如果是xx或者yy，则肯定不需要交换
           2、如果是xy或者yx，那么每两组xy（yx）通过一次交换可以都变为xy
           3、一组xy和一组yx需要两次交换才能都变为xy
           4、综上，优先通过一次交换变换所有的xy或者yx，最后要么都不剩下，要么同时剩一对xy和yx，否则无法使s1s2相同 */
        int i, size = s1.size(), xyCount = 0, yxCount = 0;

        for (i = 0; i < size; ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                ++xyCount;
            }
            else if (s1[i] == 'y' && s2[i] == 'x') {
                ++yxCount;
            }
        }

        return (((xyCount + yxCount) & 1) == 1) ? -1 : (xyCount + 1) / 2 + (yxCount + 1) / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minimumSwap("xx", "yy"));
    check.checkInt(2, o.minimumSwap("xy", "yx"));
    check.checkInt(-1, o.minimumSwap("xx", "xy"));
    check.checkInt(4, o.minimumSwap("xxyyxyxyxx", "xyyxyxxxyx"));
    check.checkInt(4, o.minimumSwap("xxyyxyxyxxxy", "xyyxyxxxyxyx"));
    check.checkInt(-1, o.minimumSwap("x", "y"));
    check.checkInt(0, o.minimumSwap("x", "x"));
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
