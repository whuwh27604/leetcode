/* 火柴拼正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在 0 到 10^9之间。
火柴数组的长度不超过15。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matchsticks-to-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = getSum(matchsticks), len = sum / 4;
        if (len * 4 != sum) {
            return false;
        }

        for (int matchstick : matchsticks) {
            if (matchstick > len) {
                return false;
            }
        }

        int size = matchsticks.size();
        return DFS(matchsticks, size, (1 << size) - 1, 0, len, 0);
    }

    int getSum(vector<int>& matchsticks) {
        int sum = 0;

        for (int len : matchsticks) {
            sum += len;
        }

        return sum;
    }

    bool DFS(vector<int>& matchsticks, int size, int choseable, int start, int len, int current) {
        if (choseable == 0) {
            return true;
        }

        if (current == len) {
            return DFS(matchsticks, size, choseable, 0, len, 0);  // 构成一条边，从0开始找下一条边
        }

        int i, bit = (1 << start);

        for (i = start; i < size; ++i, bit <<= 1) {
            if ((choseable & bit) == 0) {
                continue;
            }

            if (current + matchsticks[i] > len) {
                continue;
            }

            choseable ^= bit;
            current += matchsticks[i];  // 选择这根火柴

            if (DFS(matchsticks, size, choseable, i + 1, len, current)) {
                return true;
            }

            choseable ^= bit;  // 回溯，反选这根火柴
            current -= matchsticks[i];
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> matchsticks = { 1,1,2,2,2 };
    check.checkBool(true, o.makesquare(matchsticks));

    matchsticks = { 3,3,3,3,4 };
    check.checkBool(false, o.makesquare(matchsticks));

    matchsticks = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkBool(true, o.makesquare(matchsticks));

    matchsticks = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,119 };
    check.checkBool(false, o.makesquare(matchsticks));

    matchsticks = { 100000000,1,100000000,100000000,99999999 };
    check.checkBool(true, o.makesquare(matchsticks));

    matchsticks = { 5,5,5,5,16,4,4,4,4,4,3,3,3,3,4 };
    check.checkBool(false, o.makesquare(matchsticks));
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
