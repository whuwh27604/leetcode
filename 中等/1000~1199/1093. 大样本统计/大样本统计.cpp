/* 大样本统计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们对 0 到 255 之间的整数进行采样，并将结果存储在数组 count 中：count[k] 就是整数 k 的采样个数。

我们以 浮点数 数组的形式，分别返回样本的最小值、最大值、平均值、中位数和众数。其中，众数是保证唯一的。

我们先来回顾一下中位数的知识：

如果样本中的元素有序，并且元素数量为奇数时，中位数为最中间的那个元素；
如果样本中的元素有序，并且元素数量为偶数时，中位数为中间的两个元素的平均值。
 

示例 1：

输入：count = [0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
输出：[1.00000,3.00000,2.37500,2.50000,3.00000]
示例 2：

输入：count = [0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
输出：[1.00000,4.00000,2.18182,2.00000,1.00000]
 

提示：

count.length == 256
1 <= sum(count) <= 10^9
计数表示的众数是唯一的
答案与真实值误差在 10^-5 以内就会被视为正确答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/statistics-from-a-large-sample
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int size = count.size(), i, fi, bi;

        for (fi = 0; count[fi] == 0; ++fi) {}
        for (bi = size - 1; count[bi] == 0; --bi) {}

        int fiLast = fi, biLast = bi;
        int fCount = count[fi], bCount = count[bi];
        int minimum = fi, maximum = bi;
        int mode = (fCount > bCount) ? fi : bi;
        int maxCount = (fCount > bCount) ? fCount : bCount;
        long long sum = (fi == bi) ? ((long long)count[fi] * fi) : ((long long)count[fi] * fi) + ((long long)count[bi] * bi);

        while (true) {
            if (fCount <= bCount) {
                for (fi += 1; fi < bi && count[fi] == 0; ++fi) {}
                if (fi >= bi) {
                    break;
                }
                fiLast = i = fi;
                fCount += count[i];
            }
            else {
                for (bi -= 1; fi < bi && count[bi] == 0; --bi) {}
                if (fi >= bi) {
                    break;
                }
                biLast = i = bi;
                bCount += count[i];
            }

            maxCount = (maxCount > count[i]) ? maxCount : count[i];
            mode = (maxCount > count[i]) ? mode : i;
            sum += ((long long)count[i] * i);
        }

        int totalCount = (fiLast == biLast) ? fCount : (fCount + bCount);
        double mean = (double)sum / totalCount;
        double median = (fCount > bCount) ? fi : ((fCount < bCount) ? bi : ((double)fiLast + biLast) / 2);

        return { (double)minimum, (double)maximum, mean, median, (double)mode };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> count = { 0,1,3,4 };
    vector<double> actual = o.sampleStats(count);
    vector<double> expected = { 1.0,3.0,2.375,2.5,3.0 };
    check.checkDoubleVector(expected, actual);

    count = { 0,4,3,2,2,0 };
    actual = o.sampleStats(count);
    expected = { 1.00000,4.00000,2.181818,2.00000,1.00000 };
    check.checkDoubleVector(expected, actual);

    count = { 1 };
    actual = o.sampleStats(count);
    expected = { 0.00000,0.00000,0.00000,0.00000,0.00000 };
    check.checkDoubleVector(expected, actual);

    count = { 0,0,0,1 };
    actual = o.sampleStats(count);
    expected = { 3.00000,3.00000,3.00000,3.00000,3.00000 };
    check.checkDoubleVector(expected, actual);
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
