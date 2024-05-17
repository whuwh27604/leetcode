/* 积木拼接.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位勇者来到力扣城，本次试炼主题为「积木拼接」。 勇者面前有 6 片积木（厚度均为 1），每片积木的形状记录于二维字符串数组 shapes 中，shapes[i] 表示第 i 片积木，其中 1 表示积木对应位置无空缺，0 表示积木对应位置有空缺。 例如 ["010","111","010"] 对应积木形状为image.png

拼接积木的规则如下：

积木片可以旋转、翻面
积木片边缘必须完全吻合才能拼接在一起
每片积木片 shapes[i] 的中心点在拼接时必须处于正方体对应面的中心点
例如 3*3、4*4 的积木片的中心点如图所示（红色点）：middle_img_v2_c2d91eb5-9beb-4c06-9726-f7dae149d86g.png

请返回这 6 片积木能否拼接成一个严丝合缝的正方体且每片积木正好对应正方体的一个面。

注意：

输入确保每片积木均无空心情况（即输入数据保证对于大小 N*N 的 shapes[i]，内部的 (N-2)*(N-2) 的区域必然均为 1）
输入确保每片积木的所有 1 位置均连通
示例 1：

输入：shapes = [["000","110","000"],["110","011","000"],["110","011","110"],["000","010","111"],["011","111","011"],["011","010","000"]]

输出：true

解释：cube.gif

示例 2：

输入：shapes = [["101","111","000"],["000","010","111"],["010","011","000"],["010","111","010"],["101","111","010"],["000","010","011"]]

输出：false

解释： 由于每片积木片的中心点在拼接时必须处于正方体对应面的中心点，积木片 ["010","011","000"] 不能作为 ["100","110","000"] 使用，因此无法构成正方体

提示：

shapes.length == 6
shapes[i].length == shapes[j].length
shapes[i].length == shapes[i][j].length
3 <= shapes[i].length <= 10
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Side {
public:
	vector<int> points;
};

class Square {
public:
	Side up;
	Side right;
	Side down;
	Side left;

	void rotate() {
		Side tmp = up;
		up = right;
		right = down;
		down = left;
		left = tmp;
	}

	void flip() {
		reverse(up.points.begin(), up.points.end());
		reverse(right.points.begin(), right.points.end());
		reverse(down.points.begin(), down.points.end());
		reverse(left.points.begin(), left.points.end());
		swap(left, right);
	}
};

class Solution {
public:
	bool composeCube(vector<vector<string>>& shapes) {
		init(shapes);
		indices[bottom] = { 0,0 };  // bottom固定第0个square第0个变形即可

		return DFS(left, 1);
	}

	void init(vector<vector<string>>& shapes) {
		indices.resize(allDir, { -1,-1 });
		squares.clear();
		n = (int)shapes[0].size();

		for (auto& shape : shapes) {
			squares.push_back({});
			Square square;

			for (int i = 0; i < n; ++i) {
				square.up.points.push_back(shape[0][i] - '0');
				square.right.points.push_back(shape[i][n - 1] - '0');
			}

			for (int i = n - 1; i >= 0; --i) {
				square.down.points.push_back(shape[n - 1][i] - '0');
				square.left.points.push_back(shape[i][0] - '0');
			}

			for (int i = 0; i < 4; ++i) {
				squares.back().push_back(square);
				square.rotate();
			}
			square.flip();
			for (int i = 0; i < 4; ++i) {
				squares.back().push_back(square);
				square.rotate();
			}
		}
	}

	bool DFS(int direction, int mask) {
		if (direction == up) {
			return checkUp(mask);
		}

		for (int i = 0, bit = 1; i < allDir; ++i, bit <<= 1) {  // 选一个还没有使用的square
			if ((mask & bit) != 0) {
				continue;
			}

			for (int j = 0; j < allIdx; ++j) {  // 遍历该square的所有变形
				if (placeable(direction, i, j)) {  // 校验是否可以放置
					indices[direction] = { i,j };
					if (DFS(direction + 1, mask | bit)) {  // 如果可放置则进入下一状态的搜索
						return true;
					}
					indices[direction] = { -1,-1 };
				}
			}
		}

		return false;
	}

	bool placeable(int direction, int sqr, int index) {
		if (direction == left) {
			return checkLeft(sqr, index);
		}
		else if (direction == right) {
			return checkRight(sqr, index);
		}
		else if (direction == front) {
			return checkFront(sqr, index);
		}
		else {
			return checkBack(sqr, index);
		}
	}

	bool checkLeft(int sqr, int index) {
		return checkSide(squares[sqr][index].right, squares[0][0].left, true);
	}

	bool checkRight(int sqr, int index) {
		return checkSide(squares[sqr][index].left, squares[0][0].right, true);
	}

	bool checkFront(int sqr, int index) {
		if (!checkSide(squares[sqr][index].up, squares[0][0].down, true)) {
			return false;
		}

		int leftSqr = indices[left].first, leftIdx = indices[left].second;
		if (!checkSide(squares[sqr][index].left, squares[leftSqr][leftIdx].down, true)) {
			return false;
		}

		int rightSqr = indices[right].first, rightIdx = indices[right].second;
		if (!checkSide(squares[sqr][index].right, squares[rightSqr][rightIdx].down, true)) {
			return false;
		}

		if (squares[sqr][index].up.points[0] + squares[0][0].left.points[0] + squares[leftSqr][leftIdx].down.points[0] != 1) {
			return false;
		}

		return squares[sqr][index].right.points[0] + squares[0][0].down.points[0] + squares[rightSqr][rightIdx].left.points[0] == 1;
	}

	bool checkBack(int sqr, int index) {
		if (!checkSide(squares[sqr][index].down, squares[0][0].up, true)) {
			return false;
		}

		int leftSqr = indices[left].first, leftIdx = indices[left].second;
		if (!checkSide(squares[sqr][index].left, squares[leftSqr][leftIdx].up, true)) {
			return false;
		}

		int rightSqr = indices[right].first, rightIdx = indices[right].second;
		if (!checkSide(squares[sqr][index].right, squares[rightSqr][rightIdx].up, true)) {
			return false;
		}

		if (squares[sqr][index].left.points[0] + squares[0][0].up.points[0] + squares[leftSqr][leftIdx].right.points[0] != 1) {
			return false;
		}

		return squares[sqr][index].down.points[0] + squares[0][0].right.points[0] + squares[rightSqr][rightIdx].up.points[0] == 1;
	}

	bool checkUp(int mask) {
		int sqr = -1;

		for (int i = 0, bit = 1; i < allDir; ++i, bit <<= 1) {
			if ((mask & bit) == 0) {
				sqr = i;
				break;
			}
		}

		for (int i = 0; i < allIdx; ++i) {
			if (checkUp(sqr, i)) {
				return true;
			}
		}

		return false;
	}

	bool checkUp(int sqr, int index) {
		int leftSqr = indices[left].first, leftIdx = indices[left].second;
		if (!checkSide(squares[sqr][index].left, squares[leftSqr][leftIdx].left, false)) {
			return false;
		}

		int rightSqr = indices[right].first, rightIdx = indices[right].second;
		if (!checkSide(squares[sqr][index].right, squares[rightSqr][rightIdx].right, false)) {
			return false;
		}

		int frontSqr = indices[front].first, frontIdx = indices[front].second;
		if (!checkSide(squares[sqr][index].down, squares[frontSqr][frontIdx].down, false)) {
			return false;
		}

		int backSqr = indices[back].first, backIdx = indices[back].second;
		if (!checkSide(squares[sqr][index].up, squares[backSqr][backIdx].up, false)) {
			return false;
		}

		if (squares[sqr][index].up.points[0] + squares[backSqr][backIdx].up.points[0] + squares[leftSqr][leftIdx].up.points[0] != 1) {
			return false;
		}

		if (squares[sqr][index].right.points[0] + squares[backSqr][backIdx].right.points[0] + squares[rightSqr][rightIdx].right.points[0] != 1) {
			return false;
		}

		if (squares[sqr][index].down.points[0] + squares[frontSqr][frontIdx].down.points[0] + squares[rightSqr][rightIdx].down.points[0] != 1) {
			return false;
		}

		return squares[sqr][index].left.points[0] + squares[frontSqr][frontIdx].left.points[0] + squares[leftSqr][leftIdx].left.points[0] == 1;
	}

	bool checkSide(Side& s1, Side& s2, bool rev) {
		if (rev) {  // 注意重合边的方向，分相同方向和相反方向重合
			for (int i = 1; i < n - 1; ++i) {
				if ((s1.points[i] ^ s2.points[n - 1 - i]) == 0) {
					return false;
				}
			}
		}
		else {
			for (int i = 1; i < n - 1; ++i) {
				if ((s1.points[i] ^ s2.points[i]) == 0) {
					return false;
				}
			}
		}

		return true;
	}

	vector<vector<Square>> squares;
	vector<pair<int, int>> indices;
	int n = 0;
	int allDir = 6;
	int allIdx = 8;

	enum Direction {
		bottom = 0,
		left,
		right,
		front,
		back,
		up
	};
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<string>> shapes = { {"000","110","000"},{"110","011","110"},{"110","011","000"},{"000","010","111"},{"011","111","011"},{"011","010","000"} };
	check.checkBool(true, o.composeCube(shapes));

	shapes = { {"101","111","000"},{"000","010","111"},{"010","011","000"},{"010","111","010"},{"101","111","010"},{"000","010","011"} };
	check.checkBool(false, o.composeCube(shapes));
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
