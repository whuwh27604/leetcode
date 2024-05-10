/* 魔法棋盘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
* 在大小为 n * m 的棋盘中，有两种不同的棋子：黑色，红色。当两颗颜色不同的棋子同时满足以下两种情况时，将会产生魔法共鸣：

两颗异色棋子在同一行或者同一列
两颗异色棋子之间恰好只有一颗棋子
注：异色棋子之间可以有空位

由于棋盘上被施加了魔法禁制，棋盘上的部分格子变成问号。chessboard[i][j] 表示棋盘第 i 行 j 列的状态：

若为 . ，表示当前格子确定为空
若为 B ，表示当前格子确定为 黑棋
若为 R ，表示当前格子确定为 红棋
若为 ? ，表示当前格子待定
现在，探险家小扣的任务是确定所有问号位置的状态（留空/放黑棋/放红棋），使最终的棋盘上，任意两颗棋子间都 无法 产生共鸣。请返回可以满足上述条件的放置方案数量。

示例1：

输入：n = 3, m = 3, chessboard = ["..R","..B","?R?"]

输出：5

解释：给定的棋盘如图：image.png所有符合题意的最终局面如图：image.png

示例2：

输入：n = 3, m = 3, chessboard = ["?R?","B?B","?R?"]

输出：105

提示：

n == chessboard.length
m == chessboard[i].length
1 <= n*m <= 30
chessboard 中仅包含 "."、"B"、"R"、"?"
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	long long getSchemeCount(int n, int m, vector<string>& chessboard) {
		if (n < m) {
			rotate(n, m, chessboard);
		}

		row = n;
		column = m;
		board = chessboard;
		memo.clear();
		memo.resize(n * ((size_t)1 << (3 * m)), -1);

		return DFSRow(0, 0);
	}

	long long DFSRow(int r, int colStates) {
		if (r == row) {
			return 1;
		}

		int state = r * (1 << (3 * column)) + colStates;
		long long& ans = memo[state];
		if (ans != -1) {
			return ans;
		}

		return ans = DFSCell(r, 0, 0, colStates);
	}

	long long DFSCell(int r, int c, int rowState, int colStates) {
		if (c == column) {
			return DFSRow(r + 1, colStates);
		}

		if (board[r][c] == '.') {
			return DFSDot(r, c, rowState, colStates);
		}

		if (board[r][c] == 'B') {
			return DFSBlack(r, c, rowState, colStates);
		}

		if (board[r][c] == 'R') {
			return DFSRed(r, c, rowState, colStates);
		}

		return DFSQuestion(r, c, rowState, colStates);
	}

	long long DFSDot(int r, int c, int rowState, int colStates) {
		return DFSCell(r, c + 1, rowState, colStates);  // 添加blank后状态不会变化
	}

	long long DFSBlack(int r, int c, int rowState, int colStates) {
		int nextRowState = trans[rowState][black];
		if (nextRowState == invalid) {
			return 0;
		}

		int nextColStates = getNextStates(c, colStates, black);
		if (nextColStates == invalid) {
			return 0;
		}

		return DFSCell(r, c + 1, nextRowState, nextColStates);
	}

	long long DFSRed(int r, int c, int rowState, int colStates) {
		int nextRowState = trans[rowState][red];
		if (nextRowState == invalid) {
			return 0;
		}

		int nextColStates = getNextStates(c, colStates, red);
		if (nextColStates == invalid) {
			return 0;
		}

		return DFSCell(r, c + 1, nextRowState, nextColStates);
	}

	long long DFSQuestion(int r, int c, int rowState, int colStates) {
		long long sum = DFSDot(r, c, rowState, colStates);
		sum += DFSBlack(r, c, rowState, colStates);
		sum += DFSRed(r, c, rowState, colStates);

		return sum;
	}

	int getNextStates(int c, int states, int cell) {
		int bits = (0b111 << (3 * c));
		int state = ((states & bits) >> (3 * c));
		int nextState = trans[state][cell];

		if (nextState == invalid) {
			return invalid;
		}

		int nextStates = (states & bits);
		nextStates ^= states;
		nextStates |= (nextState << (3 * c));

		return nextStates;
	}

	void rotate(int& n, int& m, vector<string>& chessboard) {
		vector<string> board;

		for (int c = 0; c < m; ++c) {
			string row;

			for (int r = 0; r < n; ++r) {
				row += chessboard[r][c];
			}

			board.push_back(row);
		}

		swap(n, m);
		chessboard = board;
	}

	Solution() {
		row = 0;
		column = 0;
		trans = { {blank,b,r},{b,bb,br},{r,rb,rr},{bb,bb,invalid},{rr,invalid,rr},{rb,invalid,br},{br,rb,invalid} };
	}

	int row;
	int column;
	vector<string> board;
	vector<vector<int>> trans;
	vector<long long> memo;

	enum CELL {
		dot = 0,
		black = 1,
		red = 2
	};

	enum STATE {
		blank = 0,
		b,  // 一个b
		r,  // 一个r
		bb,  // 连续多个b
		rr,  // 连续多个r
		rb,  // br交替以b结尾
		br,  // br交替以r结尾
		maxState,
		invalid = -1
	};
};

int main()
{
	Solution o;
	CheckResult check;

	vector<string> chessboard = { "..R","..B","?R?" };
	check.checkLongLong(5, o.getSchemeCount(3, 3, chessboard));

	chessboard = { "?R?","B?B","?R?" };
	check.checkLongLong(105, o.getSchemeCount(3, 3, chessboard));

	chessboard = { "?B?",".?R" };
	check.checkLongLong(21, o.getSchemeCount(2, 3, chessboard));

	chessboard = { "??????","??????","??????","??????","??????" };
	check.checkLongLong(69933892903, o.getSchemeCount(5, 6, chessboard));
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
