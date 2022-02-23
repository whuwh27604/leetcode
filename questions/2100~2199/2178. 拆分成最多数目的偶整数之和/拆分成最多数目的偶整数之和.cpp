/* 拆分成最多数目的偶整数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 finalSum 。请你将它拆分成若干个 互不相同 的偶整数之和，且拆分出来的偶整数数目 最多 。

比方说，给你 finalSum = 12 ，那么这些拆分是 符合要求 的（互不相同的偶整数且和为 finalSum）：(2 + 10) ，(2 + 4 + 6) 和 (4 + 8) 。它们中，(2 + 4 + 6) 包含最多数目的整数。注意 finalSum 不能拆分成 (2 + 2 + 4 + 4) ，因为拆分出来的整数必须互不相同。
请你返回一个整数数组，表示将整数拆分成 最多 数目的偶整数数组。如果没有办法将 finalSum 进行拆分，请你返回一个 空 数组。你可以按 任意 顺序返回这些整数。

 

示例 1：

输入：finalSum = 12
输出：[2,4,6]
解释：以下是一些符合要求的拆分：(2 + 10)，(2 + 4 + 6) 和 (4 + 8) 。
(2 + 4 + 6) 为最多数目的整数，数目为 3 ，所以我们返回 [2,4,6] 。
[2,6,4] ，[6,2,4] 等等也都是可行的解。
示例 2：

输入：finalSum = 7
输出：[]
解释：没有办法将 finalSum 进行拆分。
所以返回空数组。
示例 3：

输入：finalSum = 28
输出：[6,8,2,12]
解释：以下是一些符合要求的拆分：(2 + 26)，(6 + 8 + 2 + 12) 和 (4 + 24) 。
(6 + 8 + 2 + 12) 有最多数目的整数，数目为 4 ，所以我们返回 [6,8,2,12] 。
[10,2,4,12] ，[6,2,4,16] 等等也都是可行的解。
 

提示：

1 <= finalSum <= 1010

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-split-of-positive-even-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) {
            return {};
        }

        long long current = 2;
        vector<long long> splits;

        while (finalSum >= current) {
            splits.push_back(current);
            finalSum -= current;
            current += 2;
        }

        if (finalSum != 0) {
            splits.back() += finalSum;
        }

        return splits;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<long long> actual = o.maximumEvenSplit(12);
    vector<long long> expected = { 2,4,6 };
    check.checkLongLongVector(expected, actual);

    actual = o.maximumEvenSplit(1);
    expected = {  };
    check.checkLongLongVector(expected, actual);

    actual = o.maximumEvenSplit(2);
    expected = { 2 };
    check.checkLongLongVector(expected, actual);

    actual = o.maximumEvenSplit(4);
    expected = { 4 };
    check.checkLongLongVector(expected, actual);

    actual = o.maximumEvenSplit(7);
    expected = {  };
    check.checkLongLongVector(expected, actual);

    actual = o.maximumEvenSplit(28);
    expected = { 2,4,6,16, };
    check.checkLongLongVector(expected, actual);
    check.checkLongLongVector(expected, actual);

    actual = o.maximumEvenSplit(10000);
    expected = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,298 };
    check.checkLongLongVector(expected, actual);
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
