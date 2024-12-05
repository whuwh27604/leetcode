/* 城墙防线.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在探险营地间，小扣意外发现了一片城墙遗迹，在探索期间，却不巧遇到迁徙中的兽群向他迎面冲来。情急之下小扣吹响了他的苍蓝笛，随着笛声响起，遗迹中的城墙逐渐发生了横向膨胀。 已知 rampart[i] = [x,y] 表示第 i 段城墙的初始所在区间。当城墙发生膨胀时，将遵循以下规则：

所有的城墙会同时膨胀相等的长度；
每个城墙可以向左、向右或向两个方向膨胀。
小扣为了确保自身的安全，需要在所有城墙均无重叠的情况下，让城墙尽可能的膨胀。请返回城墙可以膨胀的 最大值 。

注意：

初始情况下，所有城墙均不重叠，且 rampart 中的元素升序排列；
两侧的城墙可以向外无限膨胀。
示例 1：

输入：rampart = [[0,3],[4,5],[7,9]]

输出：3

解释：如下图所示： rampart[0] 向左侧膨胀 3 个单位； rampart[2] 向右侧膨胀 3 个单位； rampart[1] 向左侧膨胀 1 个单位，向右膨胀 2 个单位。 不存在膨胀更多的方案，返回 3。image.png

示例 2：

输入：rampart = [[1,2],[5,8],[11,15],[18,25]]

输出：4

提示：

3 <= rampart.length <= 10^4
rampart[i].length == 2
0 <= rampart[i][0] < rampart[i][1] <= rampart[i+1][0] <= 10^8
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rampartDefensiveLine(vector<vector<int>>& rampart) {
        int size = (int)rampart.size();
        int low = 0, high = INT_MAX, ans = 0;

        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (check(rampart, size, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    bool check(vector<vector<int>>& rampart, int size, int len) {
        int used = 0;

        for (int i = 1; i < size - 1; ++i) {
            int left = rampart[i][0] - rampart[i - 1][1] - used;
            int right = rampart[i + 1][0] - rampart[i][1];

            if (left + right < len) {
                return false;
            }

            used = (left >= len ? 0 : len - left);
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> rampart = { {0,3},{4,5},{7,9} };
    check.checkInt(3, o.rampartDefensiveLine(rampart));

    rampart = { {1,2},{5,8},{11,15},{18,25} };
    check.checkInt(4, o.rampartDefensiveLine(rampart));
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
