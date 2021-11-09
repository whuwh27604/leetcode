/* 祖玛游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在参与祖玛游戏的一个变种。

在这个祖玛游戏变体中，桌面上有 一排 彩球，每个球的颜色可能是：红色 'R'、黄色 'Y'、蓝色 'B'、绿色 'G' 或白色 'W' 。你的手中也有一些彩球。

你的目标是 清空 桌面上所有的球。每一回合：

从你手上的彩球中选出 任意一颗 ，然后将其插入桌面上那一排球中：两球之间或这一排球的任一端。
接着，如果有出现 三个或者三个以上 且 颜色相同 的球相连的话，就把它们移除掉。
如果这种移除操作同样导致出现三个或者三个以上且颜色相同的球相连，则可以继续移除这些球，直到不再满足移除条件。
如果桌面上所有球都被移除，则认为你赢得本场游戏。
重复这个过程，直到你赢了游戏或者手中没有更多的球。
给你一个字符串 board ，表示桌面上最开始的那排球。另给你一个字符串 hand ，表示手里的彩球。请你按上述操作步骤移除掉桌上所有球，计算并返回所需的 最少 球数。如果不能移除桌上所有的球，返回 -1 。

 

示例 1：

输入：board = "WRRBBW", hand = "RB"
输出：-1
解释：无法移除桌面上的所有球。可以得到的最好局面是：
- 插入一个 'R' ，使桌面变为 WRRRBBW 。WRRRBBW -> WBBW
- 插入一个 'B' ，使桌面变为 WBBBW 。WBBBW -> WW
桌面上还剩着球，没有其他球可以插入。
示例 2：

输入：board = "WWRRBBWW", hand = "WRBRW"
输出：2
解释：要想清空桌面上的球，可以按下述步骤：
- 插入一个 'R' ，使桌面变为 WWRRRBBWW 。WWRRRBBWW -> WWBBWW
- 插入一个 'B' ，使桌面变为 WWBBBWW 。WWBBBWW -> WWWW -> empty
只需从手中出 2 个球就可以清空桌面。
示例 3：

输入：board = "G", hand = "GGGGG"
输出：2
解释：要想清空桌面上的球，可以按下述步骤：
- 插入一个 'G' ，使桌面变为 GG 。
- 插入一个 'G' ，使桌面变为 GGG 。GGG -> empty
只需从手中出 2 个球就可以清空桌面。
示例 4：

输入：board = "RBYYBBRRB", hand = "YRBGB"
输出：3
解释：要想清空桌面上的球，可以按下述步骤：
- 插入一个 'Y' ，使桌面变为 RBYYYBBRRB 。RBYYYBBRRB -> RBBBRRB -> RRRB -> B
- 插入一个 'B' ，使桌面变为 BB 。
- 插入一个 'B' ，使桌面变为 BBB 。BBB -> empty
只需从手中出 3 个球就可以清空桌面。
 

提示：

1 <= board.length <= 16
1 <= hand.length <= 5
board 和 hand 由字符 'R'、'Y'、'B'、'G' 和 'W' 组成
桌面上一开始的球中，不会有三个及三个以上颜色相同且连着的球

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuma-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        int handSize = hand.size(), steps = -1;
        sort(hand.begin(), hand.end());

        queue<pair<string, string>> bfs;
        bfs.push({ board, hand });

        unordered_set<string> visited;
        visited.insert(board + hand);

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++steps;

            for (i = 0; i < size; ++i) {
                string currentBoard = bfs.front().first, currentHand = bfs.front().second;
                bfs.pop();

                string removed = remove(currentBoard);
                if (removed.empty()) {
                    return steps;
                }

                char prevColor = 0;

                for (char& color : currentHand) {
                    if (color > 'Z' || color == prevColor) {
                        continue;  // 相同颜色的hand只尝试第一个，因为它们的效果是一样的
                    }

                    prevColor = color;
                    color = tolower(color);

                    if (visited.count(prevColor + currentBoard + currentHand) == 0) {
                        visited.insert(prevColor + currentBoard + currentHand);
                        bfs.push({ prevColor + currentBoard, currentHand });
                    }

                    for (int j = 0; j < (int)removed.size(); ++j) {
                        if (prevColor == removed[j]) {
                            continue;  // 相同颜色的球，只插入到开头的位置
                        }

                        string nextBoard(removed, 0, j + 1);
                        nextBoard += prevColor;
                        nextBoard += string(removed, j + 1, (int)removed.size() - j - 1);
                        
                        if (visited.count(nextBoard + currentHand) == 0) {
                            visited.insert(nextBoard + currentHand);
                            bfs.push({ nextBoard, currentHand });
                        }
                    }

                    color = toupper(color);
                }
            }
        }

        return -1;
    }

    string remove(string& board) {
        char prev = 0;
        string removed;
        vector<pair<char, int>> colors;

        for (char color : board) {
            if (color == prev) {
                colors.back().second += 1;
            }
            else {
                while (!colors.empty() && colors.back().first != color && colors.back().second > 2) {
                    removed.erase(removed.size() - colors.back().second);
                    colors.pop_back();
                }

                if (!colors.empty() && colors.back().first == color) {
                    colors.back().second += 1;
                }
                else {
                    colors.push_back({ color, 1 });
                }
            }

            removed += color;
            prev = color;
        }

        if (colors.back().second > 2) {
            removed.erase(removed.size() - colors.back().second);
            colors.pop_back();
        }

        return removed;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.findMinStep("WW", "W"));
    check.checkInt(2, o.findMinStep("WWRRBBWW", "WRBRW"));
    check.checkInt(-1, o.findMinStep("WRRBBW", "RB"));
    check.checkInt(2, o.findMinStep("G", "GGGGG"));
    check.checkInt(3, o.findMinStep("RBYYBBRRB", "YRBGB"));
    check.checkInt(2, o.findMinStep("RRWWRRBBRR", "WB"));
    check.checkInt(5, o.findMinStep("RRYGGYYRRYYGGYRR","GGBBB"));
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
