/* 环形闯关游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣挑战赛」中有一个由 N 个关卡组成的环形闯关游戏，关卡编号为 0~N-1，编号 0 的关卡和编号 N-1 的关卡相邻。每个关卡均有积分要求，challenge[i] 表示挑战编号 i 的关卡最少需要拥有的积分。图片.png

小扣想要挑战关卡，闯关具体规则如下：

初始小扣可以指定其中一个关卡为「开启」状态，其余关卡将处于「未开启」状态。
小扣可以挑战处于「开启」状态且满足最少积分要求的关卡，若小扣挑战该关卡前积分为 score，挑战结束后，积分将增长为 score|challenge[i]（即位运算中的 "OR" 运算）
在挑战某个关卡后，该关卡两侧相邻的关卡将会开启（若之前未开启）
请帮助小扣进行计算，初始最少需要多少积分，可以挑战 环形闯关游戏 的所有关卡。

示例1：

输入：challenge = [5,4,6,2,7]

输出：4

解释： 初始选择编号 3 的关卡开启，积分为 4 挑战编号 3 的关卡，积分变为
4
∣
2
=
6
4∣2=6，开启 2、4 处的关卡 挑战编号 2 的关卡，积分变为
6
∣
6
=
6
6∣6=6，开启 1 处的关卡 挑战编号 1 的关卡，积分变为
6
∣
4
=
6
6∣4=6，开启 0 处的关卡 挑战编号 0 的关卡，积分变为
6
∣
5
=
7
6∣5=7 挑战编号 4 的关卡，顺利完成全部的关卡

示例2：

输入：challenge = [12,7,11,3,9]

输出：8

解释： 初始选择编号 3 的关卡开启，积分为 8 挑战编号 3 的关卡，积分变为
8
∣
3
=
11
8∣3=11，开启 2、4 处的关卡 挑战编号 2 的关卡，积分变为
11
∣
11
=
11
11∣11=11，开启 1 处的关卡 挑战编号 4 的关卡，积分变为
11
∣
9
=
11
11∣9=11，开启 0 处的关卡 挑战编号 1 的关卡，积分变为
11
∣
7
=
15
11∣7=15 挑战编号 0 的关卡，顺利完成全部的关卡

示例3：

输入：challenge = [1,1,1]

输出：1

提示：

1 <= challenge.length <= 5*10^4
1 <= challenge[i] <= 10^14
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

typedef long long LL;

class Node {
public:
	Node* prev;
	Node* next;
	LL val;

	Node(LL v) : prev(NULL), next(NULL), val(v) {}
};

class DList {
public:
	Node* head;
	Node* tail;
	int size;

	DList() : head(NULL), tail(NULL), size(0) {}
	DList(const DList& o) : size(0) {
		Node* node = o.head;

		do {
			push_back(new Node(node->val));
			node = node->next;
		} while (node != o.head);
	}

	void push_back(Node* node) {
		if (size == 0) {
			head = node;
			tail = node;
			head->next = tail;
			head->prev = tail;
			tail->next = head;
			tail->prev = head;
		}
		else {
			tail->next = node;
			node->next = head;
			node->prev = tail;
			head->prev = node;
			tail = node;
		}

		++size;
	}

	void merge(Node* node, bool rev = false) {
		if (rev) {
			if (node->prev == head) {
				head = node;
			}
			else if (node->prev == tail) {
				tail = tail->prev;
			}
			node->val |= node->prev->val;
			node->prev = node->prev->prev;
			node->prev->next = node;
		}
		else {
			if (node->next == head) {
				head = node->next;
			}
			else if (node->next == tail) {
				tail = node;
			}
			node->val |= node->next->val;
			node->next = node->next->next;
			node->next->prev = node;
		}

		--size;
	}

	Node* getStart(LL score) {
		if (head->val <= score) {
			head->val |= score;
			return head;
		}

		return getNext(head, score);
	}

	Node* getNext(Node* node, LL score) {
		do {
			node = node->next;
		} while (node != head && node->val > score);

		if (node == head) {  // 再次找到头节点时意味着失败
			return NULL;
		}

		node->val |= score;
		return node;
	}
};

class Solution {
public:
	long long ringGame(vector<long long>& challenge) {
		DList ring;
		getRing(challenge, ring);
		LL minScore = *max_element(challenge.begin(), challenge.end());
		LL bit = ((LL)1 << 62);

		while ((bit & minScore) == 0) {
			bit >>= 1;
		}

		for (bit >>= 1; bit != 0; bit >>= 1) {
			if ((bit & minScore) != 0) {
				LL tmpScore = (minScore ^ bit) | (bit - 1);  // 将cc...c1nn...n变为cc...c011..1
				if (check(ring, tmpScore)) {  // 该bit位可以变为0
					minScore = tmpScore;
				}
			}
		}

		return minScore;
	}

	void getRing(vector<LL>& challenge, DList& ring) {
		for (LL val : challenge) {
			ring.push_back(new Node(val));
		}
	}

	bool check(DList ring, LL score) {
		Node* node = ring.getStart(score);

		while (ring.size > 1 && node != NULL) {
			if (node->val >= node->next->val) {
				ring.merge(node);
			}
			else if (node->val >= node->prev->val) {
				ring.merge(node, true);
			}
			else {  // 前后都不能合并了，跳过障碍，找下一个起点
				node = ring.getNext(node, score);
			}
		}

		return ring.size == 1;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<long long> challenge = { 1,180,447 };
	check.checkLongLong(266, o.ringGame(challenge));

	challenge = { 1,32255,15848 };
	check.checkLongLong(16406, o.ringGame(challenge));

	challenge = { 5,4,6,2,7 };
	check.checkLongLong(4, o.ringGame(challenge));

	challenge = { 12,7,11,3,9 };
	check.checkLongLong(8, o.ringGame(challenge));

	challenge = { 1,1,1 };
	check.checkLongLong(1, o.ringGame(challenge));

	challenge = { 7,2 };
	check.checkLongLong(5, o.ringGame(challenge));

	challenge = { 15,10 };
	check.checkLongLong(13, o.ringGame(challenge));

	challenge = { 31,21 };
	check.checkLongLong(26, o.ringGame(challenge));
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
