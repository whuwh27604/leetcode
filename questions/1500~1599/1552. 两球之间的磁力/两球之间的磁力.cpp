/* 两球之间的磁力.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有 n 个空的篮子，第 i 个篮子的位置在 position[i] ，Morty 想把 m 个球放到这些篮子里，使得任意两球间 最小磁力 最大。

已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为 |x - y| 。

给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。

 

示例 1：



输入：position = [1,2,3,4,7], m = 3
输出：3
解释：将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3 。
示例 2：

输入：position = [5,4,3,2,1,1000000000], m = 2
输出：999999999
解释：我们使用位于 1 和 1000000000 的篮子时最小磁力最大。
 

提示：

n == position.length
2 <= n <= 10^5
1 <= position[i] <= 10^9
所有 position 中的整数 互不相同 。
2 <= m <= position.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magnetic-force-between-two-balls
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lowMagForce = 1, highMagForce = position.back() - position.front(), maxMagForce = 0;

        while (lowMagForce <= highMagForce) {
            int middleMagForce = (lowMagForce + highMagForce) / 2;

            if (canPlaceMBalls(position, middleMagForce, m)) {
                maxMagForce = middleMagForce;
                lowMagForce = middleMagForce + 1;
            }
            else {
                highMagForce = middleMagForce - 1;
            }
        }

        return maxMagForce;
    }

    bool canPlaceMBalls(vector<int>& position, int minMagForce, int m) {
        int prevPosition = -minMagForce, balls = 0;

        for (int pos : position) {
            if (pos - prevPosition >= minMagForce) {
                if (++balls == m) {
                    return true;
                }

                prevPosition = pos;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> position = { 1,2,3,4,7 };
    check.checkInt(3, o.maxDistance(position, 3));

    position = { 5,4,3,2,1,1000000000 };
    check.checkInt(999999999, o.maxDistance(position, 2));
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
