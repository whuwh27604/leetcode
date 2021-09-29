/* 魔塔游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣当前位于魔塔游戏第一层，共有 N 个房间，编号为 0 ~ N-1。每个房间的补血道具/怪物对于血量影响记于数组 nums，其中正数表示道具补血数值，即血量增加对应数值；负数表示怪物造成伤害值，即血量减少对应数值；0 表示房间对血量无影响。

小扣初始血量为 1，且无上限。假定小扣原计划按房间编号升序访问所有房间补血/打怪，为保证血量始终为正值，小扣需对房间访问顺序进行调整，每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾。请返回小扣最少需要调整几次，才能顺利访问所有房间。若调整顺序也无法访问完全部房间，请返回 -1。

示例 1：

输入：nums = [100,100,100,-250,-60,-140,-50,-50,100,150]

输出：1

解释：初始血量为 1。至少需要将 nums[3] 调整至访问顺序末尾以满足要求。

示例 2：

输入：nums = [-200,-300,400,0]

输出：-1

解释：调整访问顺序也无法完成全部房间的访问。

提示：

1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/p0NxJO
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int magicTower(vector<int>& nums) {
        int moves = 0;
        long long sum = 1, moved = 0;
        priority_queue<long long> monsters;

        for (int num : nums) {
            sum += num;

            if (num < 0) {
                monsters.push(-num);
            }

            while (sum <= 0) {
                sum += monsters.top();
                moved += monsters.top();
                monsters.pop();
                ++moves;
            }
        }

        return sum > moved ? moves : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 100,100,100,-250,-60,-140,-50,-50,100,150 };
    check.checkInt(1, o.magicTower(nums));

    nums = { -200,-300,400,0 };
    check.checkInt(-1, o.magicTower(nums));

    nums = { -1,1 };
    check.checkInt(1, o.magicTower(nums));

    nums = { -1 };
    check.checkInt(-1, o.magicTower(nums));

    nums = { -1,-1,10 };
    check.checkInt(2, o.magicTower(nums));

    nums = { -1,200,-200,-300,400,0 };
    check.checkInt(2, o.magicTower(nums));
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
