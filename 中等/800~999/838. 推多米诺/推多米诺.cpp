/* 推多米诺.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一行中有 N 张多米诺骨牌，我们将每张多米诺骨牌垂直竖立。

在开始时，我们同时把一些多米诺骨牌向左或向右推。



每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。

同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果同时有多米诺骨牌落在一张垂直竖立的多米诺骨牌的两边，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为正在下降的多米诺骨牌不会对其它正在下降或已经下降的多米诺骨牌施加额外的力。

给定表示初始状态的字符串 "S" 。如果第 i 张多米诺骨牌被推向左边，则 S[i] = 'L'；如果第 i 张多米诺骨牌被推向右边，则 S[i] = 'R'；如果第 i 张多米诺骨牌没有被推动，则 S[i] = '.'。

返回表示最终状态的字符串。

示例 1：

输入：".L.R...LR..L.."
输出："LL.RR.LLRRLL.."
示例 2：

输入："RR.L"
输出："RR.L"
说明：第一张多米诺骨牌没有给第二张施加额外的力。
提示：

0 <= N <= 10^5
表示多米诺骨牌状态的字符串只含有 'L'，'R'; 以及 '.';

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/push-dominoes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes.push_back('R');
        int i, indexL = -1, indexR = -1, size = dominoes.size();
        string pushedDominoes;

        for (i = 0; i < size; i++) {
            if (dominoes[i] == '.') {
                continue;
            }

            if (dominoes[i] == 'L') {
                if (indexR == -1) {
                    pushedDominoes.insert(pushedDominoes.end(), i - indexL, 'L');
                }
                else {
                    int count = i - indexR + 1;
                    pushedDominoes.insert(pushedDominoes.end(), count / 2, 'R');
                    pushedDominoes.insert(pushedDominoes.end(), (count % 2 == 1) ? 1 : 0, '.');
                    pushedDominoes.insert(pushedDominoes.end(), count / 2, 'L');
                }

                indexL = i;
                indexR = -1;
            }
            else {
                if (indexR != -1) {
                    pushedDominoes.insert(pushedDominoes.end(), i - indexR, 'R');
                }
                else {
                    pushedDominoes.insert(pushedDominoes.end(), i - indexL - 1, '.');
                }

                indexR = i;
            }
        }

        return pushedDominoes;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("", o.pushDominoes(""));
    check.checkString(".", o.pushDominoes("."));
    check.checkString("L", o.pushDominoes("L"));
    check.checkString("R", o.pushDominoes("R"));
    check.checkString("LR", o.pushDominoes("LR"));
    check.checkString("RL", o.pushDominoes("RL"));
    check.checkString("R.L", o.pushDominoes("R.L"));
    check.checkString("RRL", o.pushDominoes("RRL"));
    check.checkString("RR.L", o.pushDominoes("RR.L"));
    check.checkString("LLRR", o.pushDominoes(".LR."));
    check.checkString("LL.RR.LLRRLL..", o.pushDominoes(".L.R...LR..L.."));
    check.checkString("LL.RRRRR.LL..RR.LLLLLL..RRR", o.pushDominoes(".L.R..R...L..RR.L...LL..R.."));
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
