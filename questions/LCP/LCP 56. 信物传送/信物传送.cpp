/* 信物传送.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣城，本次试炼主题为「信物传送」。

本次试炼场地设有若干传送带，matrix[i][j] 表示第 i 行 j 列的传送带运作方向，"^","v","<",">" 这四种符号分别表示 上、下、左、右 四个方向。信物会随传送带的方向移动。勇者每一次施法操作，可临时变更一处传送带的方向，在物品经过后传送带恢复原方向。lcp (2).gif

通关信物初始位于坐标 start处，勇者需要将其移动到坐标 end 处，请返回勇者施法操作的最少次数。

注意：

start 和 end 的格式均为 [i,j]
示例 1:

输入：matrix = [">>v","v^<","<><"], start = [0,1], end = [2,0]

输出：1

解释： 如上图所示 当信物移动到 [1,1] 时，勇者施法一次将 [1,1] 的传送方向 ^ 从变更为 < 从而信物移动到 [1,0]，后续到达 end 位置 因此勇者最少需要施法操作 1 次

示例 2:

输入：matrix = [">>v",">>v","^<<"], start = [0,0], end = [1,1]

输出：0

解释：勇者无需施法，信物将自动传送至 end 位置

示例 3:

输入：matrix = [">^^>","<^v>","^v^<"], start = [0,0], end = [1,3]

输出：3

提示：

matrix 中仅包含 '^'、'v'、'<'、'>'
0 < matrix.length <= 100
0 < matrix[i].length <= 100
0 <= start[0],end[0] < matrix.length
0 <= start[1],end[1] < matrix[i].length
*/

#include <iostream>
#include <deque>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int magic;

    Node() : r(0), c(0), magic(0) {}
    Node(int x, int y, int m) : r(x), c(y), magic(m) {}

    int hash() {
        return (magic << 16) | (r << 8) | c;
    }
};

class Solution {
public:
    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        int row = (int)matrix.size(), column = (int)matrix[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        char dir[4] = { '>','v','<','^' };
        deque<Node> nodes;
        Node node(start[0], start[1], 0);
        nodes.push_back(node);
        unordered_set<int> visited;
        visited.insert(node.hash());

        while (!nodes.empty()) {
            int r = nodes.front().r, c = nodes.front().c, magic = nodes.front().magic;
            nodes.pop_front();

            if (r == end[0] && c == end[1]) {
                return magic;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= row || nc < 0 || nc >= column) {
                    continue;
                }

                if (dir[i] == matrix[r][c]) {
                    Node node(nr, nc, magic);
                    int key = node.hash();
                    if (visited.count(key) == 0) {
                        visited.insert(key);
                        nodes.push_front(node);
                    }
                }
                else {
                    Node node(nr, nc, magic + 1);
                    int key = node.hash();
                    if (visited.count(key) == 0) {
                        visited.insert(key);
                        nodes.push_back(node);
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> matrix = { ">>v","v^<","<><" };
    vector<int> start = { 0,1 };
    vector<int> end = { 2,0 };
    check.checkInt(1, o.conveyorBelt(matrix, start, end));

    matrix = { ">>v",">>v","^<<" };
    start = { 0,0 };
    end = { 1,1 };
    check.checkInt(0, o.conveyorBelt(matrix, start, end));

    matrix = { ">^^>","<^v>","^v^<" };
    start = { 0,0 };
    end = { 1,3 };
    check.checkInt(3, o.conveyorBelt(matrix, start, end));
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
