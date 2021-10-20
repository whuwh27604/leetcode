/* 转换字符串的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，由 n 个字符组成，每个字符不是 'X' 就是 'O' 。

一次 操作 定义为从 s 中选出 三个连续字符 并将选中的每个字符都转换为 'O' 。注意，如果字符已经是 'O' ，只需要保持 不变 。

返回将 s 中所有字符均转换为 'O' 需要执行的 最少 操作次数。

 

示例 1：

输入：s = "XXX"
输出：1
解释：XXX -> OOO
一次操作，选中全部 3 个字符，并将它们转换为 'O' 。
示例 2：

输入：s = "XXOX"
输出：2
解释：XXOX -> OOOX -> OOOO
第一次操作，选择前 3 个字符，并将这些字符转换为 'O' 。
然后，选中后 3 个字符，并执行转换。最终得到的字符串全由字符 'O' 组成。
示例 3：

输入：s = "OOOO"
输出：0
解释：s 中不存在需要转换的 'X' 。
 

提示：

3 <= s.length <= 1000
s[i] 为 'X' 或 'O'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-convert-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int i, size = s.size(), moves = 0;

        for (i = 0; i < size; ++i) {
            if (s[i] == 'X') {
                ++moves;
                i += 2;
            }
        }

        return moves;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minimumMoves("XXX"));
    check.checkInt(2, o.minimumMoves("XXOX"));
    check.checkInt(0, o.minimumMoves("OOOO"));
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
