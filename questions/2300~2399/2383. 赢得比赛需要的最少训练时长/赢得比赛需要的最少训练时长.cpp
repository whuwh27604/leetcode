/* 赢得比赛需要的最少训练时长.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在参加一场比赛，给你两个 正 整数 initialEnergy 和 initialExperience 分别表示你的初始精力和初始经验。

另给你两个下标从 0 开始的整数数组 energy 和 experience，长度均为 n 。

你将会 依次 对上 n 个对手。第 i 个对手的精力和经验分别用 energy[i] 和 experience[i] 表示。当你对上对手时，需要在经验和精力上都 严格 超过对手才能击败他们，然后在可能的情况下继续对上下一个对手。

击败第 i 个对手会使你的经验 增加 experience[i]，但会将你的精力 减少  energy[i] 。

在开始比赛前，你可以训练几个小时。每训练一个小时，你可以选择将增加经验增加 1 或者 将精力增加 1 。

返回击败全部 n 个对手需要训练的 最少 小时数目。

 

示例 1：

输入：initialEnergy = 5, initialExperience = 3, energy = [1,4,3,2], experience = [2,6,3,1]
输出：8
解释：在 6 小时训练后，你可以将精力提高到 11 ，并且再训练 2 个小时将经验提高到 5 。
按以下顺序与对手比赛：
- 你的精力与经验都超过第 0 个对手，所以获胜。
  精力变为：11 - 1 = 10 ，经验变为：5 + 2 = 7 。
- 你的精力与经验都超过第 1 个对手，所以获胜。
  精力变为：10 - 4 = 6 ，经验变为：7 + 6 = 13 。
- 你的精力与经验都超过第 2 个对手，所以获胜。
  精力变为：6 - 3 = 3 ，经验变为：13 + 3 = 16 。
- 你的精力与经验都超过第 3 个对手，所以获胜。
  精力变为：3 - 2 = 1 ，经验变为：16 + 1 = 17 。
在比赛前进行了 8 小时训练，所以返回 8 。
可以证明不存在更小的答案。
示例 2：

输入：initialEnergy = 2, initialExperience = 4, energy = [1], experience = [3]
输出：0
解释：你不需要额外的精力和经验就可以赢得比赛，所以返回 0 。
 

提示：

n == energy.length == experience.length
1 <= n <= 100
1 <= initialEnergy, initialExperience, energy[i], experience[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-hours-of-training-to-win-a-competition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size(), hours = 0;

        for (int i = 0; i < n; ++i) {
            if (initialEnergy <= energy[i]) {
                hours += (energy[i] + 1 - initialEnergy);
                initialEnergy = 1;
            }
            else {
                initialEnergy -= energy[i];
            }

            if (initialExperience <= experience[i]) {
                hours += (experience[i] + 1 - initialExperience);
                initialExperience = experience[i] + 1;
            }

            initialExperience += experience[i];
        }

        return hours;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> energy = { 1,4,3,2 };
    vector<int> experience = { 2,6,3,1 };
    check.checkInt(8, o.minNumberOfHours(5, 3, energy, experience));

    energy = { 1 };
    experience = { 3 };
    check.checkInt(0, o.minNumberOfHours(2, 4, energy, experience));

    energy = { 1,1,1,1 };
    experience = { 1,1,1,50 };
    check.checkInt(51, o.minNumberOfHours(1, 1, energy, experience));
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
