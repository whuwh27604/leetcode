/* 令牌放置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你的初始能量为 P，初始分数为 0，只有一包令牌。

令牌的值为 token[i]，每个令牌最多只能使用一次，可能的两种使用方法如下：

如果你至少有 token[i] 点能量，可以将令牌置为正面朝上，失去 token[i] 点能量，并得到 1 分。
如果我们至少有 1 分，可以将令牌置为反面朝上，获得 token[i] 点能量，并失去 1 分。
在使用任意数量的令牌后，返回我们可以得到的最大分数。

 

示例 1：

输入：tokens = [100], P = 50
输出：0
示例 2：

输入：tokens = [100,200], P = 150
输出：1
示例 3：

输入：tokens = [100,200,300,400], P = 200
输出：2
 

提示：

tokens.length <= 1000
0 <= tokens[i] < 10000
0 <= P < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bag-of-tokens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int size = tokens.size(), head = 0, tail = size - 1;
        int score = 0, maxScore = 0, power = P;

        sort(tokens.begin(), tokens.end());

        while ((head <= tail) && ((power >= tokens[head]) || (score > 0))) {
            while ((head <= tail) && (power >= tokens[head])) {
                power -= tokens[head++];
                ++score;
            }

            maxScore = max(maxScore, score);

            if ((head <= tail) && (score > 0)) {
                power += tokens[tail--];
                --score;
            }
        }

        return maxScore;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> tokens = { 100 };
    check.checkInt(0, o.bagOfTokensScore(tokens, 50));

    tokens = { 100,200 };
    check.checkInt(1, o.bagOfTokensScore(tokens, 150));

    tokens = { 100,200,300,400 };
    check.checkInt(2, o.bagOfTokensScore(tokens, 200));

    tokens = { 71,55,82 };
    check.checkInt(0, o.bagOfTokensScore(tokens, 54));

    tokens = { 4,24,28,33,96 };
    check.checkInt(3, o.bagOfTokensScore(tokens, 35));

    tokens = {  };
    check.checkInt(0, o.bagOfTokensScore(tokens, 1));

    tokens = { 1,2,3,4,5 };
    check.checkInt(5, o.bagOfTokensScore(tokens, 15));

    tokens = { 33,41,10,91,47,84,98,34,48,70 };
    check.checkInt(4, o.bagOfTokensScore(tokens, 43));

    tokens = { 6,0,39,52,45,49,59,68,42,37 };
    check.checkInt(5, o.bagOfTokensScore(tokens, 99));
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
