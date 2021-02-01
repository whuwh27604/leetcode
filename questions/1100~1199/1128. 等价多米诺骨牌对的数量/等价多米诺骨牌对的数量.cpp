/* 等价多米诺骨牌对的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由一些多米诺骨牌组成的列表 dominoes。

如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。

形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且 b==c。

在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

 

示例：

输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
输出：1
 

提示：

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        short dominoesCount[100] = {0};

        for (unsigned int i = 0; i < dominoes.size(); i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            if (a < b) {
                a = a * 10 + b;
            }
            else {
                a = b * 10 + a;
            }

            dominoesCount[a]++;
        }

        int equivDominoPairs = 0;
        for (int i = 0; i < 100; i++) {
            if (dominoesCount[i] <= 1) {
                continue;
            }

            // 排列组合公式A(n,m)=n(n-1)...(n-m-1)=n!/(n-m)!    C(n,m)=A(n,m)/m!
            equivDominoPairs += dominoesCount[i] * (dominoesCount[i] - 1) / 2;
        }

        return equivDominoPairs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> dominoes = { {1,2},{2,1},{3,4},{5,6} };
    check.checkInt(1, o.numEquivDominoPairs(dominoes));

    dominoes = { {1,2} };
    check.checkInt(0, o.numEquivDominoPairs(dominoes));

    dominoes = { {1,2},{1,2},{2,1},{2,1} };
    check.checkInt(6, o.numEquivDominoPairs(dominoes));

    dominoes = { {1,2},{1,2},{2,1},{2,1},{4,3},{3,4},{4,3},{1,1},{1,1},{5,6} };
    check.checkInt(10, o.numEquivDominoPairs(dominoes));
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
