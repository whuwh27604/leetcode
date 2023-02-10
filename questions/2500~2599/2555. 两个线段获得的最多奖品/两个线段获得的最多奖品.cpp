/* 两个线段获得的最多奖品.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在 X轴 上有一些奖品。给你一个整数数组 prizePositions ，它按照 非递减 顺序排列，其中 prizePositions[i] 是第 i 件奖品的位置。数轴上一个位置可能会有多件奖品。再给你一个整数 k 。

你可以选择两个端点为整数的线段。每个线段的长度都必须是 k 。你可以获得位置在任一线段上的所有奖品（包括线段的两个端点）。注意，两个线段可能会有相交。

比方说 k = 2 ，你可以选择线段 [1, 3] 和 [2, 4] ，你可以获得满足 1 <= prizePositions[i] <= 3 或者 2 <= prizePositions[i] <= 4 的所有奖品 i 。
请你返回在选择两个最优线段的前提下，可以获得的 最多 奖品数目。



示例 1：

输入：prizePositions = [1,1,2,2,3,3,5], k = 2
输出：7
解释：这个例子中，你可以选择线段 [1, 3] 和 [3, 5] ，获得 7 个奖品。
示例 2：

输入：prizePositions = [1,2,3,4], k = 0
输出：2
解释：这个例子中，一个选择是选择线段 [3, 3] 和 [4, 4] ，获得 2 个奖品。


提示：

1 <= prizePositions.length <= 105
1 <= prizePositions[i] <= 109
0 <= k <= 109
prizePositions 有序非递减。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int size = prizePositions.size();
        vector<int> leftMax(size), rightMax(size);

        getLeftMax(prizePositions, k, leftMax);
        getRightMax(prizePositions, k, rightMax);

        return getMaxPrize(leftMax, rightMax);
    }

    void getLeftMax(vector<int>& prizePositions, int k, vector<int>& leftMax) {
        int size = prizePositions.size(), left = 0, prize = 0, maxPrize = 0;

        for (int right = 0; right < size; ++right) {
            ++prize;

            while (prizePositions[right] - prizePositions[left] > k) {
                --prize;
                ++left;
            }

            maxPrize = max(maxPrize, prize);
            leftMax[right] = maxPrize;
        }
    }

    void getRightMax(vector<int>& prizePositions, int k, vector<int>& rightMax) {
        int size = prizePositions.size(), right = size - 1, prize = 0, maxPrize = 0;

        for (int left = size - 1; left >= 0; --left) {
            ++prize;

            while (prizePositions[right] - prizePositions[left] > k) {
                --prize;
                --right;
            }

            maxPrize = max(maxPrize, prize);
            rightMax[left] = maxPrize;
        }
    }

    int getMaxPrize(vector<int>& leftMax, vector<int>& rightMax) {
        int size = leftMax.size(), maxPrize = rightMax[0];

        for (int i = 1; i < size; ++i) {
            maxPrize = max(maxPrize, leftMax[i - 1] + rightMax[i]);
        }

        return maxPrize;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prizePositions = { 1,1,2,2,3,3,5 };
    check.checkInt(7, o.maximizeWin(prizePositions, 2));

    prizePositions = { 1,2,3,4 };
    check.checkInt(2, o.maximizeWin(prizePositions, 0));

    prizePositions = { 4 };
    check.checkInt(1, o.maximizeWin(prizePositions, 0));

    prizePositions = { 2616,2618,2620,2621,2626,2635,2657,2662,2662,2669,2671,2693,2702,2713,2714,2718,2730,2731,2750,2756,2772,2773,2775,2785,2795,2805,2811,2813,2816,2823,2824,2824,2826,2830,2833,2857,2885,2898,2910,2919,2928,2941,2942,2944,2965,2967,2970,2973,2974,2975,2977,3002,3007,3012,3042,3049,3078,3084,3089,3090,3094,3097,3114,3124,3125,3125,3144,3147,3148,3174,3197,3255,3262,3288,3291,3316,3320,3322,3331,3342,3378,3412,3412,3416,3420,3427,3428,3446,3452,3472,3479,3483,3488,3500,3516,3522,3531,3532,3540,3540,3544,3557,3570,3580,3592,3597,3597,3601,3615,3631,3640,3645,3673,3677,3681,3683,3685,3718,3738,3746,3758,3769,3797,3802,3815,3832,3839,3851,3864,3888,3889,3901,3902,3910,3913,3933,3940,3961,3974,3988,4003,4013,4019,4023,4026,4047,4060,4065,4072,4073,4082,4084,4109,4132,4139,4143,4145,4146,4155 };
    check.checkInt(159, o.maximizeWin(prizePositions, 6641));
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
