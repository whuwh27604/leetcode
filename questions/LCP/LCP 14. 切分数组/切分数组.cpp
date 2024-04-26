/* 切分数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 nums ，小李想将 nums 切割成若干个非空子数组，使得每个子数组最左边的数和最右边的数的最大公约数大于 1 。为了减少他的工作量，请求出最少可以切成多少个子数组。

示例 1：

输入：nums = [2,3,3,2,3,3]

输出：2

解释：最优切割为 [2,3,3,2] 和 [3,3] 。第一个子数组头尾数字的最大公约数为 2 ，第二个子数组头尾数字的最大公约数为 3 。

示例 2：

输入：nums = [2,3,5,7]

输出：4

解释：只有一种可行的切割：[2], [3], [5], [7]

限制：

1 <= nums.length <= 10^5
2 <= nums[i] <= 10^6
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

const int maxNum = 1000000;
const int maxSize = 7;  // 数据范围内最多7个质因子
int factors[maxNum + 1][maxSize + 1] = { 0 };

void EratosthenesSieve() {
    vector<bool> isPrime(maxNum + 1, true);

    for (int i = 2; i <= maxNum; ++i) {
        if (isPrime[i]) {
            factors[i][0] = i;
            factors[i][maxSize] = 1;

            for (int j = 2 * i; j <= maxNum; j += i) {
                isPrime[j] = false;
                factors[j][factors[j][maxSize]++] = i;
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        EratosthenesSieve();
    }
}

class Solution {
public:
	int splitArray(vector<int>& nums) {
        init();
        int size = (int)nums.size();
        vector<int> dp(size, size);  // dp[i]表示nums[0, i]可以划分的最小数组个数
        vector<int> minDp(maxNum, size);  // minDp[i][p]表示对nums[0, i]，假设最后一组的左端点在位置j，不要求最后一组是合法分组，nums[j]包含质因子p，对所有这样的j，dp[j - 1]的最小值

        dp[0] = 1;
        for (int p : factors[nums[0]]) {
            minDp[p] = 0;
        }

        for (int i = 1; i < size; ++i) {
            dp[i] = dp[i - 1] + 1;  // nums[i]单独一组

            for (int k = 0; k < factors[nums[i]][maxSize]; ++k) {
                int p = factors[nums[i]][k];
                dp[i] = min(dp[i], minDp[p] + 1);  // 对nums[j, i]，nums[j]和nums[i]都包含质因子p，可以形成一个合法分组；然后对所有这样的j，dp[j - 1]的最小值保存在minDp[p]中
                minDp[p] = min(minDp[p], dp[i - 1]);
            }
        }

        return dp[size - 1];
	}
};

int main()
{
	Solution o;
	CheckResult check;

    vector<int> nums = { 2,2,2,3,2,5,3 };
    check.checkInt(2, o.splitArray(nums));

    nums = { 2,3,3,2,3,3 };
    check.checkInt(2, o.splitArray(nums));

    nums = { 2,3,5,7 };
    check.checkInt(4, o.splitArray(nums));

    nums = { 197597,26083,231529,216133,22483,74411,89087,218681,863,228421,214463,224863,5737,32941,216103,132689,159737,151241,164309,73643,45121,59981,68821,11197,54679,85213,138727,89657,102769,112121,136573,27059,77351,109891,94229,173617,224443,149531,84979,31013,219409,156749,108233,80107,90173,138899,151057,66683,66683,153911,69959,79451,75407,159319,7411,78571,128717,52057,55799,128201,125353,214763,12071,152657,81199,190391,96779,62659,27997,318559,299113,258691,258031,296713,297533,341477,273271,270659,296479,262693,270287,247769,246781,308509,289031,298559,246439,318713,317773,260879,322237,245851,276623,319237,352589,283463,235111,393203,917327,495371 };
    check.checkInt(99, o.splitArray(nums));
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
