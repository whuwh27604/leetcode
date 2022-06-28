/* 不同骰子序列的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 。你需要掷一个 6 面的骰子 n 次。请你在满足以下要求的前提下，求出 不同 骰子序列的数目：

序列中任意 相邻 数字的 最大公约数 为 1 。
序列中 相等 的值之间，至少有 2 个其他值的数字。正式地，如果第 i 次掷骰子的值 等于 第 j 次的值，那么 abs(i - j) > 2 。
请你返回不同序列的 总数目 。由于答案可能很大，请你将答案对 109 + 7 取余 后返回。

如果两个序列中至少有一个元素不同，那么它们被视为不同的序列。

 

示例 1：

输入：n = 4
输出：184
解释：一些可行的序列为 (1, 2, 3, 4) ，(6, 1, 2, 3) ，(1, 2, 3, 1) 等等。
一些不可行的序列为 (1, 2, 1, 3) ，(1, 2, 3, 6) 。
(1, 2, 1, 3) 是不可行的，因为第一个和第三个骰子值相等且 abs(1 - 3) = 2 （下标从 1 开始表示）。
(1, 2, 3, 6) i是不可行的，因为 3 和 6 的最大公约数是 3 。
总共有 184 个不同的可行序列，所以我们返回 184 。
示例 2：

输入：n = 2
输出：22
解释：一些可行的序列为 (1, 2) ，(2, 1) ，(3, 2) 。
一些不可行的序列为 (3, 6) ，(2, 4) ，因为最大公约数不为 1 。
总共有 22 个不同的可行序列，所以我们返回 22 。
 

提示：

1 <= n <= 104

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-distinct-roll-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

vector<vector<vector<int>>> trans(7, vector<vector<int>>(7));
vector<vector<vector<int>>> seqs(10001, vector<vector<int>>(7, vector<int>(7, 0)));
int mod = 1000000007;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

void initTrans() {
    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (i == j || gcd(i, j) != 1) {
                continue;
            }

            for (int k = 1; k < 7; ++k) {
                if (k != i && k != j && gcd(i, k) == 1) {
                    trans[i][j].push_back(k);
                }
            }
        }
    }
}

void calcAll() {
    static bool finished = false;

    if (finished) {
        return;
    }

    initTrans();
    seqs[1][1][1] = 6;

    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (i != j && gcd(i, j) == 1) {
                seqs[2][i][j] = 1;
            }
        }
    }

    for (int n = 3; n < 10001; ++n) {
        for (int i = 1; i < 7; ++i) {
            for (int j = 1; j < 7; ++j) {
                for (int k : trans[i][j]) {
                    seqs[n][i][j] = (seqs[n][i][j] + seqs[n - 1][k][i]) % mod;
                }
            }
        }
    }

    finished = true;
}

class Solution {
public:
    int distinctSequences(int n) {
        int total = 0;

        calcAll();

        for (int i = 1; i < 7; ++i) {
            for (int j = 1; j < 7; ++j) {
                total = (total + seqs[n][i][j]) % mod;
            }
        }

        return total;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.distinctSequences(1));
    check.checkInt(22, o.distinctSequences(2));
    check.checkInt(66, o.distinctSequences(3));
    check.checkInt(184, o.distinctSequences(4));
    check.checkInt(958116668, o.distinctSequences(99));
    check.checkInt(874574246, o.distinctSequences(10000));
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
