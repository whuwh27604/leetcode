/* 字母板上的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。

在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。



我们可以按下面的指令规则行动：

如果方格存在，'U' 意味着将我们的位置上移一行；
如果方格存在，'D' 意味着将我们的位置下移一行；
如果方格存在，'L' 意味着将我们的位置左移一列；
如果方格存在，'R' 意味着将我们的位置右移一列；
'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
（注意，字母板上只存在有字母的位置。）

返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。

 

示例 1：

输入：target = "leet"
输出："DDR!UURRR!!DDD!"
示例 2：

输入：target = "code"
输出："RR!DDRR!UUL!R!"
 

提示：

1 <= target.length <= 100
target 仅含有小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/alphabet-board-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char, pair<int, int>> letterIndex = { {'a', {0,0}},{'b', {0,1}},{'c', {0,2}},{'d', {0,3}},{'e', {0,4}},
        {'f', {1,0}},{'g', {1,1}},{'h', {1,2}},{'i', {1,3}},{'j', {1,4}},{'k', {2,0}},{'l', {2,1}},{'m', {2,2}},{'n', {2,3}},{'o', {2,4}},
        {'p', {3,0}},{'q', {3,1}},{'r', {3,2}},{'s', {3,3}},{'t', {3,4}},{'u', {4,0}},{'v', {4,1}},{'w', {4,2}},{'x', {4,3}},{'y', {4,4}},{'z', {5,0}} };
        vector<string> horizontal = { "LLLL","LLL","LL","L","","R","RR","RRR","RRRR" };
        vector<string> vertical = { "UUUUU","UUUU","UUU","UU","U","","D","DD","DDD","DDDD","DDDDD" };
        string moves;
        char prev = 'a';

        for (char c : target) {
            if (c == 'z') {
                moves += horizontal[letterIndex[c].second - letterIndex[prev].second + 4];
                moves += vertical[letterIndex[c].first - letterIndex[prev].first + 5];
            }
            else {
                moves += vertical[letterIndex[c].first - letterIndex[prev].first + 5];
                moves += horizontal[letterIndex[c].second - letterIndex[prev].second + 4];
            }
            moves += '!';

            prev = c;
        }

        return moves;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("!RRRR!", o.alphabetBoardPath("ae"));
    check.checkString("R!L!", o.alphabetBoardPath("ba"));
    check.checkString("DDDDR!LD!", o.alphabetBoardPath("vz"));
    check.checkString("DDDDD!UR!", o.alphabetBoardPath("zv"));
    check.checkString("DDR!UURRR!!DDD!", o.alphabetBoardPath("leet"));
    check.checkString("RR!DDRR!UUL!R!", o.alphabetBoardPath("code"));
    check.checkString("DDDDD!UUUUUR!", o.alphabetBoardPath("zb"));
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
