/* 全部开花的最早一天.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 n 枚花的种子。每枚种子必须先种下，才能开始生长、开花。播种需要时间，种子的生长也是如此。给你两个下标从 0 开始的整数数组 plantTime 和 growTime ，每个数组的长度都是 n ：

plantTime[i] 是 播种 第 i 枚种子所需的 完整天数 。每天，你只能为播种某一枚种子而劳作。无须 连续几天都在种同一枚种子，但是种子播种必须在你工作的天数达到 plantTime[i] 之后才算完成。
growTime[i] 是第 i 枚种子完全种下后生长所需的 完整天数 。在它生长的最后一天 之后 ，将会开花并且永远 绽放 。
从第 0 开始，你可以按 任意 顺序播种种子。

返回所有种子都开花的 最早 一天是第几天。

 

示例 1：


输入：plantTime = [1,4,3], growTime = [2,3,1]
输出：9
解释：灰色的花盆表示播种的日子，彩色的花盆表示生长的日子，花朵表示开花的日子。
一种最优方案是：
第 0 天，播种第 0 枚种子，种子生长 2 整天。并在第 3 天开花。
第 1、2、3、4 天，播种第 1 枚种子。种子生长 3 整天，并在第 8 天开花。
第 5、6、7 天，播种第 2 枚种子。种子生长 1 整天，并在第 9 天开花。
因此，在第 9 天，所有种子都开花。
示例 2：


输入：plantTime = [1,2,3,2], growTime = [2,1,2,1]
输出：9
解释：灰色的花盆表示播种的日子，彩色的花盆表示生长的日子，花朵表示开花的日子。
一种最优方案是：
第 1 天，播种第 0 枚种子，种子生长 2 整天。并在第 4 天开花。
第 0、3 天，播种第 1 枚种子。种子生长 1 整天，并在第 5 天开花。
第 2、4、5 天，播种第 2 枚种子。种子生长 2 整天，并在第 8 天开花。
第 6、7 天，播种第 3 枚种子。种子生长 1 整天，并在第 9 天开花。
因此，在第 9 天，所有种子都开花。
示例 3：

输入：plantTime = [1], growTime = [1]
输出：2
解释：第 0 天，播种第 0 枚种子。种子需要生长 1 整天，然后在第 2 天开花。
因此，在第 2 天，所有种子都开花。
 

提示：

n == plantTime.length == growTime.length
1 <= n <= 105
1 <= plantTime[i], growTime[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/earliest-possible-day-of-full-bloom
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // A、B两个植物按先后顺序种植，最小时间为min(max(pA + gA, pA + pB + gB), max(pB + gB, pB + pA + gA))，这等价于gA > gB则A应该先于B种植
        int i, n = plantTime.size(), time = 0, minTime = 0;
        vector<pair<int, int>> plants(n);

        for (i = 0; i < n; ++i) {
            plants[i] = { growTime[i],plantTime[i] };
        }

        sort(plants.begin(), plants.end());

        for (i = n - 1; i >= 0; --i) {
            time += plants[i].second;
            minTime = max(minTime, time + plants[i].first);
        }

        return minTime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> plantTime = { 1,4,3 };
    vector<int> growTime = { 2,3,1 };
    check.checkInt(9, o.earliestFullBloom(plantTime, growTime));

    plantTime = { 1,2,3,2 };
    growTime = { 2,1,2,1 };
    check.checkInt(9, o.earliestFullBloom(plantTime, growTime));

    plantTime = { 1 };
    growTime = { 1 };
    check.checkInt(2, o.earliestFullBloom(plantTime, growTime));
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
