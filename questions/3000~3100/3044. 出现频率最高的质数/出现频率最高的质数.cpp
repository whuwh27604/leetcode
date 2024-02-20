/* 出现频率最高的质数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 、下标从 0 开始的二维矩阵 mat 。在每个单元格，你可以按以下方式生成数字：

最多有 8 条路径可以选择：东，东南，南，西南，西，西北，北，东北。
选择其中一条路径，沿着这个方向移动，并且将路径上的数字添加到正在形成的数字后面。
注意，每一步都会生成数字，例如，如果路径上的数字是 1, 9, 1，那么在这个方向上会生成三个数字：1, 19, 191 。
返回在遍历矩阵所创建的所有数字中，出现频率最高的、大于 10的
质数
；如果不存在这样的质数，则返回 -1 。如果存在多个出现频率最高的质数，那么返回其中最大的那个。

注意：移动过程中不允许改变方向。



示例 1：



输入：mat = [[1,1],[9,9],[1,1]]
输出：19
解释：
从单元格 (0,0) 出发，有 3 个可能的方向，这些方向上可以生成的大于 10 的数字有：
东方向: [11], 东南方向: [19], 南方向: [19,191] 。
从单元格 (0,1) 出发，所有可能方向上生成的大于 10 的数字有：[19,191,19,11] 。
从单元格 (1,0) 出发，所有可能方向上生成的大于 10 的数字有：[99,91,91,91,91] 。
从单元格 (1,1) 出发，所有可能方向上生成的大于 10 的数字有：[91,91,99,91,91] 。
从单元格 (2,0) 出发，所有可能方向上生成的大于 10 的数字有：[11,19,191,19] 。
从单元格 (2,1) 出发，所有可能方向上生成的大于 10 的数字有：[11,19,19,191] 。
在所有生成的数字中，出现频率最高的质数是 19 。
示例 2：

输入：mat = [[7]]
输出：-1
解释：唯一可以生成的数字是 7 。它是一个质数，但不大于 10 ，所以返回 -1 。
示例 3：

输入：mat = [[9,7,8],[4,6,5],[2,8,6]]
输出：97
解释：
从单元格 (0,0) 出发，所有可能方向上生成的大于 10 的数字有: [97,978,96,966,94,942] 。
从单元格 (0,1) 出发，所有可能方向上生成的大于 10 的数字有: [78,75,76,768,74,79] 。
从单元格 (0,2) 出发，所有可能方向上生成的大于 10 的数字有: [85,856,86,862,87,879] 。
从单元格 (1,0) 出发，所有可能方向上生成的大于 10 的数字有: [46,465,48,42,49,47] 。
从单元格 (1,1) 出发，所有可能方向上生成的大于 10 的数字有: [65,66,68,62,64,69,67,68] 。
从单元格 (1,2) 出发，所有可能方向上生成的大于 10 的数字有: [56,58,56,564,57,58] 。
从单元格 (2,0) 出发，所有可能方向上生成的大于 10 的数字有: [28,286,24,249,26,268] 。
从单元格 (2,1) 出发，所有可能方向上生成的大于 10 的数字有: [86,82,84,86,867,85] 。
从单元格 (2,2) 出发，所有可能方向上生成的大于 10 的数字有: [68,682,66,669,65,658] 。
在所有生成的数字中，出现频率最高的质数是 97 。


提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 6
1 <= mat[i][j] <= 9
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

const int maxN = 1000000;
vector<int> primes;
vector<bool> isPrimes(maxN + 1, true);

void EulerFilter() {
    isPrimes[0] = isPrimes[1] = false;

    for (int num = 2; num <= maxN; ++num) {
        if (isPrimes[num]) {
            primes.push_back(num);
        }

        for (int prime : primes) {
            int composite = num * prime;
            if (composite > maxN) {
                break;
            }

            isPrimes[composite] = false;

            if (num % prime == 0) {
                break;
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        EulerFilter();
    }
}

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        init();

        int m = mat.size(), n = mat[0].size();
        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };
        int maxFreq = 0, maxPrime = -1;
        unordered_map<int, int> freqs;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int i = 0; i < 8; ++i) {
                    int num = mat[r][c];

                    for (int d = 1; d < 6; ++d) {
                        int nr = r + dr[i] * d, nc = c + dc[i] * d;
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            break;
                        }

                        num = num * 10 + mat[nr][nc];
                        if (isPrimes[num]) {
                            ++freqs[num];
                        }
                    }
                }
            }
        }

        for (auto& kv : freqs) {
            if (kv.second > maxFreq) {
                maxFreq = kv.second;
                maxPrime = kv.first;
            }
            else if (kv.second == maxFreq) {
                maxPrime = max(maxPrime, kv.first);
            }
        }

        return maxPrime;
    }
};

int main()
{
	Solution o;
	CheckResult check;

    vector<vector<int>> mat = { {1,1},{9,9},{1,1} };
    check.checkInt(19, o.mostFrequentPrime(mat));

    mat = { {7} };
    check.checkInt(-1, o.mostFrequentPrime(mat));

    mat = { {9,7,8},{4,6,5},{2,8,6} };
    check.checkInt(97, o.mostFrequentPrime(mat));
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
