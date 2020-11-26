/* 最大间距.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-gap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maximum = 0, minimum = INT_MAX;
        int size = preprocess(nums, maximum, minimum);
        if (size < 2) {
            return 0;
        }

        int minMaxGap = (maximum - minimum) / (size - 1);  // 一共size-1个gap，如果最大的gap比minMaxGap还小的话，将导致maximum和minimum之间的距离不够
        int bucketSize = (maximum - minimum) / minMaxGap + 1;  // 注意bucketSize>=size
        vector<pair<int, int>> buckets(bucketSize, pair<int, int>{ -1, -1 });  // 准备bucketSize个bucket，每个bucket的长度是minMaxGap，维护每个bucket里面的max和min
        placeNumsInBucket(nums, buckets, minimum, minMaxGap);
        
        return getMaxGap(buckets);
    }

    int preprocess(vector<int>& nums, int& maximum, int& minimum) {
        unordered_set<int> unduplicatedNums;

        for (int num : nums) {
            maximum = max(maximum, num);
            minimum = min(minimum, num);
            unduplicatedNums.insert(num);
        }

        return unduplicatedNums.size();
    }

    void placeNumsInBucket(vector<int>& nums, vector<pair<int, int>>& buckets, int minimum, int minMaxGap) {
        for (int num : nums) {
            int index = (num - minimum) / minMaxGap;
            if (buckets[index].first == -1) {
                buckets[index].first = buckets[index].second = num;
            }
            else {
                buckets[index].first = min(buckets[index].first, num);
                buckets[index].second = max(buckets[index].second, num);
            }
        }
    }

    int getMaxGap(vector<pair<int, int>>& buckets) {
        int i, size = buckets.size(), prevMax = buckets[0].second, maxGap = 0;

        for (i = 1; i < size; ++i) {
            if (buckets[i].first != -1) {
                maxGap = max(maxGap, buckets[i].first - prevMax);  // maxGap只能出现在两个bucket之间，如果在一个bucket内部，那么maxGap比minMaxGap还小，出现矛盾
                prevMax = buckets[i].second;
            }
        }

        return maxGap;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,6,9,1 };
    check.checkInt(3, o.maximumGap(nums));

    nums = {  };
    check.checkInt(0, o.maximumGap(nums));

    nums = { 10 };
    check.checkInt(0, o.maximumGap(nums));

    nums = { 1,1,1,1 };
    check.checkInt(0, o.maximumGap(nums));

    nums = { 1,1,1,1,5,5,5,5 };
    check.checkInt(4, o.maximumGap(nums));

    nums = { 12115,10639,2351,29639,31300,11245,16323,24899,8043,4076,17583,15872,19443,12887,5286,6836,31052,25648,17584,24599,13787,24727,12414,5098,26096,23020,25338,28472,4345,25144,27939,10716,3830,13001,7960,8003,10797,5917,22386,12403,2335,32514,23767,1868,29882,31738,30157,7950,20176,11748,13003,13852,19656,25305,7830,3328,19092,28245,18635,5806,18915,31639,24247,32269,29079,24394,18031,9395,8569,11364,28701,32496,28203,4175,20889,28943,6495,14919,16441,4568,23111,20995,7401,30298,2636,16791,1662,27367,2563,22169,1607,15711,29277,32386,27365,31922,26142,8792 };
    check.checkInt(1244, o.maximumGap(nums));

    nums = { 15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740 };
    check.checkInt(2901, o.maximumGap(nums));
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
