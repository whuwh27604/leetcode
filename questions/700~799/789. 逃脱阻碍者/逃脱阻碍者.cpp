/* 逃脱阻碍者.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你在进行一个简化版的吃豆人游戏。你从 (0, 0) 点开始出发，你的目的地是 (target[0], target[1]) 。地图上有一些阻碍者，第 i 个阻碍者从 (ghosts[i][0], ghosts[i][1]) 出发。

每一回合，你和阻碍者们*可以*同时向东，西，南，北四个方向移动，每次可以移动到距离原位置1个单位的新位置。

如果你可以在任何阻碍者抓住你之前到达目的地（阻碍者可以采取任意行动方式），则被视为逃脱成功。如果你和阻碍者同时到达了一个位置（包括目的地）都不算是逃脱成功。

当且仅当你有可能成功逃脱时，输出 True。

示例 1:
输入：
ghosts = [[1, 0], [0, 3]]
target = [0, 1]
输出：true
解释：
你可以直接一步到达目的地(0,1)，在(1, 0)或者(0, 3)位置的阻碍者都不可能抓住你。
示例 2:
输入：
ghosts = [[1, 0]]
target = [2, 0]
输出：false
解释：
你需要走到位于(2, 0)的目的地，但是在(1, 0)的阻碍者位于你和目的地之间。
示例 3:
输入：
ghosts = [[2, 0]]
target = [1, 0]
输出：false
解释：
阻碍者可以和你同时达到目的地。
说明：

所有的点的坐标值的绝对值 <= 10000。
阻碍者的数量不会超过 100。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/escape-the-ghosts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        // 只要比任何一个ghost离target更远就没戏
        int escapeDistance = abs(target[0]) + abs(target[1]);

        for (vector<int>& ghost : ghosts) {
            int distance = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (distance <= escapeDistance) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> ghosts = { {1,0},{0,3} };
    vector<int> target = { 0,1 };
    check.checkBool(true, o.escapeGhosts(ghosts, target));

    ghosts = { {1,0} };
    target = { 2,0 };
    check.checkBool(false, o.escapeGhosts(ghosts, target));

    ghosts = { {2,0} };
    target = { 1,0 };
    check.checkBool(false, o.escapeGhosts(ghosts, target));
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
