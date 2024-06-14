/* 无限棋局.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小力正在通过残局练习来备战「力扣挑战赛」中的「五子棋」项目，他想请你能帮他预测当前残局的输赢情况。棋盘中的棋子分布信息记录于二维数组 pieces 中，其中 pieces[i] = [x,y,color] 表示第 i 枚棋子的横坐标为 x，纵坐标为 y，棋子颜色为 color(0 表示黑棋，1 表示白棋)。假如黑棋先行，并且黑棋和白棋都按最优策略落子，请你求出当前棋局在三步（按 黑、白、黑 的落子顺序）之内的输赢情况（三步之内先构成同行、列或对角线连续同颜色的至少 5 颗即为获胜）：

黑棋胜, 请返回 "Black"
白棋胜, 请返回 "White"
仍无胜者, 请返回 "None"
注意：

和传统的五子棋项目不同，「力扣挑战赛」中的「五子棋」项目 不存在边界限制，即可在 任意位置 落子；
黑棋和白棋均按 3 步内的输赢情况进行最优策略的选择
测试数据保证所给棋局目前无胜者；
测试数据保证不会存在坐标一样的棋子。
示例 1：

输入： pieces = [[0,0,1],[1,1,1],[2,2,0]]

输出："None"

解释：无论黑、白棋以何种方式落子，三步以内都不会产生胜者。

示例 2：

输入： pieces = [[1,2,1],[1,4,1],[1,5,1],[2,1,0],[2,3,0],[2,4,0],[3,2,1],[3,4,0],[4,2,1],[5,2,1]]

输出："Black"

解释：三步之内黑棋必胜，以下是一种可能的落子情况：902b87df29998b1c181146c8fdb3a4b6.gif

提示：

0 <= pieces.length <= 1000
pieces[i].length = 3
-10^9 <= pieces[i][0], pieces[i][1] <=10^9
0 <= pieces[i][2] <=1
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

typedef unsigned long long ULL;

const int BLACK = 0;
const int WHITE = 1;
const int ROW = 0;
const int COLUMN = 1;
const int DIAGONAL = 2;
const int BACKDIAGONAL = 3;

class Piece {
public:
	int x;
	int y;
	int color;

	Piece() : x(0), y(0), color(BLACK) {}
	Piece(int a, int b, int c = BLACK) : x(a), y(b), color(c) {}
	Piece(ULL k) : x((int)(k >> 32)), y((int)k), color(BLACK) {}

	ULL key() {
		return ((ULL)x << 32) | (unsigned int)y;  // 有负数，要用无符号数作为key
	}

	Piece prev(int type) {
		return type == ROW ? Piece(x, y - 1) : (type == COLUMN ? Piece(x - 1, y) : (type == DIAGONAL ? Piece(x - 1, y - 1) : Piece(x - 1, y + 1)));
	}

	Piece next(int type) {
		return type == ROW ? Piece(x, y + 1) : (type == COLUMN ? Piece(x + 1, y) : (type == DIAGONAL ? Piece(x + 1, y + 1) : Piece(x + 1, y - 1)));
	}
};

class Solution {
public:
	unordered_map<int, vector<pair<int, int>>> rows, columns, diags, bdiags;  // 记录每一行的pieces
	unordered_set<ULL> allPieces, winPieces;  // 记录所有pieces、可以win的pieces的key

	string gobang(vector<vector<int>>& pieces) {
		init(pieces);

		getOneStepWinPieces(BLACK);
		if (!winPieces.empty()) {  // 黑棋一步可赢
			return "Black";
		}

		winPieces.clear();
		getOneStepWinPieces(WHITE);
		if (winPieces.size() > 1) {  // 白棋有多个一步致胜点
			return "White";
		}
		else if (winPieces.size() == 1) {  // 白棋只有一个致胜点，黑棋必须先堵上它
			Piece piece(*winPieces.begin());
			winPieces.clear();
			getTwoStepWinPieces(piece);  // 堵上之后检查黑棋是否有多个致胜点
			return winPieces.size() > 1 ? "Black" : "None";
		}

		return canTwoStepWin() ? "Black" : "None";  // 都无法一步制胜，检查黑棋是否可以两步获胜
	}

	void init(vector<vector<int>>& pieces) {
		rows.clear(), columns.clear(), diags.clear(), bdiags.clear(), allPieces.clear(), winPieces.clear();

		for (auto& piece : pieces) {
			int x = piece[0], y = piece[1], color = piece[2];
			rows[x].push_back({ y,color });
			columns[y].push_back({ x,color });
			diags[x - y].push_back({ x,color });
			bdiags[x + y].push_back({ x,color });
			allPieces.insert(Piece(x, y).key());
		}

		sortPiece(rows);
		sortPiece(columns);
		sortPiece(diags);
		sortPiece(bdiags);
	}

	void sortPiece(unordered_map<int, vector<pair<int, int>>>& pieces) {
		for (auto& kv : pieces) {
			sort(kv.second.begin(), kv.second.end());
		}
	}

	void getOneStepWinPieces(int color) {
		getOneStepWinPieces(rows, ROW, color);
		getOneStepWinPieces(columns, COLUMN, color);
		getOneStepWinPieces(diags, DIAGONAL, color);
		getOneStepWinPieces(bdiags, BACKDIAGONAL, color);
	}

	void getOneStepWinPieces(unordered_map<int, vector<pair<int, int>>>& lines, int type, int color) {
		for (auto& line : lines) {
			getOneStepWinPieces(line.first, line.second, type, color);
		}
	}

	void getOneStepWinPieces(int key, vector<pair<int, int>>& line, int type, int color) {
		int size = (int)line.size();

		for (int i = 0; i + 3 < size; ++i) {
			if (line[i].second == color && line[i + 1].second == color && line[i + 2].second == color && line[i + 3].second == color) {  // 连续4个同色棋子
				if (line[i + 3].first - line[i].first == 3) {  // 紧邻的4个棋子，检查前后是否有空位
					if (i == 0 || line[i].first - line[i - 1].first != 1) {
						winPieces.insert(getPiece(key, line[i].first, type).prev(type).key());
					}
					if (i + 3 == size - 1 || line[i + 4].first - line[i + 3].first != 1) {
						winPieces.insert(getPiece(key, line[i + 3].first, type).next(type).key());
					}
				}

				if (line[i + 3].first - line[i].first == 4) {  // 首尾相差4，中间有一个空位
					for (int j = i + 1; j <= i + 3; ++j) {
						if (line[j].first - line[j - 1].first == 2) {
							winPieces.insert(getPiece(key, line[j].first, type).prev(type).key());
							break;
						}
					}
				}
			}
		}
	}

	bool canTwoStepWin() {
		return canTwoStepWin(rows, ROW) || canTwoStepWin(columns, COLUMN) || canTwoStepWin(diags, DIAGONAL) || canTwoStepWin(bdiags, BACKDIAGONAL);
	}

	bool canTwoStepWin(unordered_map<int, vector<pair<int, int>>>& lines, int type) {
		for (auto& line : lines) {
			if (canTwoStepWin(line.first, line.second, type)) {
				return true;
			}
		}

		return false;
	}

	bool canTwoStepWin(int key, vector<pair<int, int>>& line, int type) {
		int size = (int)line.size();

		for (int i = 0; i + 2 < size; ++i) {
			if (line[i].second == BLACK && line[i + 1].second == BLACK && line[i + 2].second == BLACK 
				&& line[i + 2].first - line[i].first < 5) {  // 连续3个黑棋并且距离小于5才有可能2步获胜
				for (int val = line[i + 2].first - 4; val <= line[i].first + 4; ++val) {  // 遍历5格以内的范围
					Piece piece = getPiece(key, val, type);
					if (allPieces.count(piece.key()) == 0) {  // 该位置没有棋子，选择作为第一步的位置
						winPieces.clear();
						getTwoStepWinPieces(piece);  // 检查第一步下在这里后，是否有多个获胜点
						if (winPieces.size() > 1) {
							return true;
						}
					}
				}
			}
		}

		return false;
	}

	void getTwoStepWinPieces(Piece& one) {  // 只需要检查棋子one相关的行
		int key = one.x;
		getTwoStepWinPieces(one, key, rows[key], ROW);
		key = one.y;
		getTwoStepWinPieces(one, key, columns[key], COLUMN);
		key = one.x - one.y;
		getTwoStepWinPieces(one, key, diags[key], DIAGONAL);
		key = one.x + one.y;
		getTwoStepWinPieces(one, key, bdiags[key], BACKDIAGONAL);
	}

	void getTwoStepWinPieces(Piece& one, int key, vector<pair<int, int>>& line, int type) {
		int size = (int)line.size(), value = type == ROW ? one.y : one.x;

		for (int i = 0; i + 2 < size; ++i) {  // 遍历每3个棋子，也可以快速定位到one附近，实现有点繁琐
			int minVal = min({ value, line[i].first, line[i + 1].first, line[i + 2].first });
			int maxVal = max({ value, line[i].first, line[i + 1].first, line[i + 2].first });
			if (line[i].second == BLACK && line[i + 1].second == BLACK && line[i + 2].second == BLACK && maxVal - minVal < 5) {  // 包括one棋子在内，4个棋子间隔5以内才可能获胜
				for (int val = maxVal - 4; val <= minVal + 4; ++val) {  // 查找获胜点
					if (val != value) {
						ULL piece = getPiece(key, val, type).key();
						if (allPieces.count(piece) == 0) {
							winPieces.insert(piece);
						}
					}
				}
			}
		}
	}

	Piece getPiece(int key, int value, int type) {
		return type == ROW ? Piece(key, value) : (type == COLUMN ? Piece(value, key) : (type == DIAGONAL ? Piece(value, value - key) : Piece(value, key - value)));
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> pieces = { {0,0,1},{1,1,1},{2,2,0} };
	check.checkString("None", o.gobang(pieces));

	pieces = { {1,2,1},{1,4,1},{1,5,1},{2,1,0},{2,3,0},{2,4,0},{3,2,1},{3,4,0},{4,2,1},{5,2,1} };
	check.checkString("Black", o.gobang(pieces));

	pieces = { {0,0,0},{0,2,0},{0,3,0},{0,4,0},{0,5,0} };
	check.checkString("Black", o.gobang(pieces));

	pieces = { {0,0,1},{0,1,0},{0,3,0},{0,4,0},{0,7,0},{0,8,1} };
	check.checkString("Black", o.gobang(pieces));

	pieces = { {0,0,1},{0,1,0},{0,2,0},{0,3,0},{0,7,0},{0,8,0},{0,9,0},{0,10,1} };
	check.checkString("Black", o.gobang(pieces));

	pieces = { {1,0,1},{1,1,0},{1,2,0},{1,3,0},{1,6,1},{0,5,1},{3,5,0},{4,5,0},{5,5,0},{6,5,1} };
	check.checkString("Black", o.gobang(pieces));

	pieces = { { -1000000000,-1000000000,0},{-999999999,-1000000000,0},{-999999998,-1000000000,0} };
	check.checkString("Black", o.gobang(pieces));

	pieces = { {5,1,0},{5,9,1},{1,8,0},{9,7,1},{4,4,1},{4,3,0},{9,2,0},{2,4,1},{0,6,0},{2,5,0},{4,5,1},{5,3,0},{7,6,0},{8,2,0},{4,8,0},{1,5,0},{4,1,1},{7,0,1},{8,1,1},{4,2,0},{9,5,1},{7,5,1},{3,8,0},{7,9,1},{3,3,1},{4,0,1},{5,5,0},{2,2,1},{7,2,0},{8,8,0},{9,6,0},{1,3,1},{9,0,0},{2,3,1},{7,4,0},{7,7,1},{6,7,0},{6,4,0},{8,6,0},{8,3,0},{6,1,1},{6,9,1},{7,8,0},{1,9,0},{3,4,1},{0,3,0},{0,5,0},{3,6,1},{7,1,1},{8,4,1},{5,7,1},{1,0,1},{9,3,1} };
	check.checkString("Black", o.gobang(pieces));
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
