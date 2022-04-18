/* 花园的最大总美丽值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
Alice 是 n 个花园的园丁，她想通过种花，最大化她所有花园的总美丽值。

给你一个下标从 0 开始大小为 n 的整数数组 flowers ，其中 flowers[i] 是第 i 个花园里已经种的花的数目。已经种了的花 不能 移走。同时给你 newFlowers ，表示 Alice 额外可以种花的 最大数目 。同时给你的还有整数 target ，full 和 partial 。

如果一个花园有 至少 target 朵花，那么这个花园称为 完善的 ，花园的 总美丽值 为以下分数之 和 ：

完善 花园数目乘以 full.
剩余 不完善 花园里，花的 最少数目 乘以 partial 。如果没有不完善花园，那么这一部分的值为 0 。
请你返回 Alice 种最多 newFlowers 朵花以后，能得到的 最大 总美丽值。

 

示例 1：

输入：flowers = [1,3,1,1], newFlowers = 7, target = 6, full = 12, partial = 1
输出：14
解释：Alice 可以按以下方案种花
- 在第 0 个花园种 2 朵花
- 在第 1 个花园种 3 朵花
- 在第 2 个花园种 1 朵花
- 在第 3 个花园种 1 朵花
花园里花的数目为 [3,6,2,2] 。总共种了 2 + 3 + 1 + 1 = 7 朵花。
只有 1 个花园是完善的。
不完善花园里花的最少数目是 2 。
所以总美丽值为 1 * 12 + 2 * 1 = 12 + 2 = 14 。
没有其他方案可以让花园总美丽值超过 14 。
示例 2：

输入：flowers = [2,4,5,3], newFlowers = 10, target = 5, full = 2, partial = 6
输出：30
解释：Alice 可以按以下方案种花
- 在第 0 个花园种 3 朵花
- 在第 1 个花园种 0 朵花
- 在第 2 个花园种 0 朵花
- 在第 3 个花园种 2 朵花
花园里花的数目为 [5,4,5,5] 。总共种了 3 + 0 + 0 + 2 = 5 朵花。
有 3 个花园是完善的。
不完善花园里花的最少数目为 4 。
所以总美丽值为 3 * 2 + 4 * 6 = 6 + 24 = 30 。
没有其他方案可以让花园总美丽值超过 30 。
注意，Alice可以让所有花园都变成完善的，但这样她的总美丽值反而更小。
 

提示：

1 <= flowers.length <= 105
1 <= flowers[i], target <= 105
1 <= newFlowers <= 1010
1 <= full, partial <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-total-beauty-of-the-gardens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        int size = flowers.size(), complete = getComplete(flowers, target), incomplete = size - complete, i, j = incomplete - 2;

        if (incomplete == 0) {
            return (long long)full * size;
        }

        int maxMinIncomplete = getMaxMinIncomplete(flowers, newFlowers, target, incomplete);
        long long maxBeauty = (long long)maxMinIncomplete * partial + (long long)full * complete;

        for (i = incomplete - 1; i >= 0 && j >= 0; --i) {  // 从大往小依次将incomplete增加到complete，遍历所有可能的complete
            int increase = target - max(flowers[i], maxMinIncomplete);  // 将flowers[0, i - 1]的newFlowers移动increase个到flowers[i]

            if (newFlowers >= increase) {  // 已经够了，直接移动
                newFlowers -= increase;
            }
            else {
                for (j = min(j, i - 1); j >= 0; --j) {
                    if (flowers[j] >= maxMinIncomplete) {  // 该花园没有新增newFlowers
                        continue;
                    }

                    long long moved = ((long long)maxMinIncomplete - flowers[j]) * ((long long)j + 1);  // 削减到flowers[j]高度，总共可以移动的数量
                    
                    if (newFlowers + moved < increase) {  // 还不够，需要继续往前找
                        newFlowers += moved;
                        maxMinIncomplete = flowers[j];
                    }
                    else {  // 够了，计算实际降低的高度。有余数的情况下要多减一行
                        int decrease = (increase - (int)newFlowers) / (j + 1) + ((increase - (int)newFlowers) % (j + 1) == 0 ? 0 : 1);
                        maxMinIncomplete -= decrease;
                        newFlowers += (decrease * ((long long)j + 1) - increase);
                        break;
                    }
                }
            }

            if (j >= 0) {  // 成功将flowers[i]增加到target，计算beauty值
                maxBeauty = max(maxBeauty, (i == 0 ? 0 : (long long)maxMinIncomplete * partial) + full * ((long long)size - i));
            }
        }

        return maxBeauty;
    }

    int getComplete(vector<int>& flowers, int target) {
        int i, size = flowers.size();

        for (i = size - 1; i >= 0 && flowers[i] >= target; --i) {}

        return size - 1 - i;
    }

    // 先把所有的newFlowers种下，得到最大的不完善花园
    int getMaxMinIncomplete(vector<int>& flowers, long long& newFlowers, int target, int incomplete) {
        int i = 0, j, increase = 0;

        while (i < incomplete && newFlowers != 0) {
            for (j = i + 1; j < incomplete && flowers[j] == flowers[i]; ++j) {}  // 相同数量的花园需要同时增加

            int inc = (int)min(newFlowers / j, (long long)(j == incomplete ? target - 1 : flowers[j]) - flowers[i]);  // 将flowers[0,j-1]增加到flowers[j]，注意不能达到target
            increase += inc;
            newFlowers -= (long long)inc * j;

            if (newFlowers < j) {  // 剩下的newFlowers已经不足以再增加minIncomplete，退出
                break;
            }

            i = j;
        }

        return flowers[0] + increase;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> flowers = { 1,3,1,1 };
    check.checkLongLong(14, o.maximumBeauty(flowers, 7, 6, 12, 1));

    flowers = { 2,4,5,3 };
    check.checkLongLong(30, o.maximumBeauty(flowers, 10, 5, 2, 6));

    flowers = { 1,2,4,5,3 };
    check.checkLongLong(402, o.maximumBeauty(flowers, 7, 5, 100, 1));

    flowers = { 10,9,16,14,6,5,11,12,17,2,11,15,1 };
    check.checkLongLong(195, o.maximumBeauty(flowers, 80, 14, 15, 1));

    flowers = { 1056,73246,24730,45592,2076,47062,51329,30904,77941,93853,99362,35655,37069,29547,75748,19177,15083,62416,38012,63192,22196,66038,70061,61813,17744,75195,91086,16455,62569,376,99843,75705,63131,64017,90656,79076,69391,39275,70667,87360,86690,42416,99339,7827,5112,93538,31350,75264,72815,97536,76295,8700,35630,99048,9193,71976,66667,41722,9016,83118,22486,93533,11894,22471,69541,34613,2290,50824,77760,89037,71688,91386,41314,63112,74778,97032,64333,11903,42272,46057,48163,72195,44974,14659,94983,29406,75337,83095,87638,13317,53059,87590,3989,80643,9239,94515,22388,87053,33189 };
    check.checkLongLong(1696054247, o.maximumBeauty(flowers, 4141897, 100000, 62283, 17678));

    flowers = { 64753,70721,35179,14240,85904,41870,19694,36688,99646,49085,85619,26435,18771,55583,60427,72027,44868,95581,98990,81882,51628,82625,43425,74385,63862,53800,76884,13139,63703,68373,81076,18220,91633,52737,65764,89790,42570,19317,43152,65395,28911,46582,25554,76178,9173,25436,5842,54867,52028,58952,63094,29583,11598,69236,68720,19564,2757,57855,60757,23659,67839,32038,65734,15290,42556,48913,13312,96397,27608,42084,98068,68397,29079,4376,97930,52427,11075,13088,81742,29956,21925,49807,67952,16287,68255,57174,59840,77891,40221,3156,5128,3497,65228,93320,68648,33111,9676,97523,39295,52427,74753,7798,89393,60840,55642,9150,5029,12613,85348,84827,25601,95020,86573,73326,63948,49911,62048,42886,80491,83517,85604,37006,56101,21357,71697,73275,82457,91209,59471,92914,70091,36917,63223,12256,60120,20354,61169,49300,40539,97203,84401,54030,506,83883,75217,63499,46032,7437,96915,32796,98461,14572,11146,5326,17821,86744,44579,44213,66468,20471,38854,44697,99750,63414,24457,66770,62214,60029,18358,87031,11454,96612,31108,8877,27205,40854,90185,52276,59947,67499,16375,33772,5300,591,89451,197,73076,74487,40029,77991,71909,19864,27554,64674,27391,88798,92353,54954,39830,57000,65183,79551,47415,70699,53812,79880,96880,55432,85877,67140,16297,90637,581,22493,20043,92338,7151,48283,42379,69667,34839,65754,942,7666,30914,47012,27900,19866,98873,86437,38098,57219,24538,34548,6735,86260,98999,42451,34032,18392,26693,92306,18429,86527,19493,56794,27966,79551,22829,99628,5979,37492,83251,40886,23767,72893,79000,29487,74422,39852 };
    check.checkLongLong(9945865, o.maximumBeauty(flowers, 3463894, 65243, 40780, 47));
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
