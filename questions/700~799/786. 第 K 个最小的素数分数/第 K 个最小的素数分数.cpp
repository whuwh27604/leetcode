/* 第 K 个最小的素数分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数  组成，且其中所有整数互不相同。

对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。

那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。

 
示例 1：

输入：arr = [1,2,3,5], k = 3
输出：[2,5]
解释：已构造好的分数,排序后如下所示:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3
很明显第三个最小的分数是 2/5
示例 2：

输入：arr = [1,7], k = 1
输出：[1,7]
 

提示：

2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 104
arr[0] == 1
arr[i] 是一个 素数 ，i > 0
arr 中的所有数字 互不相同 ，且按 严格递增 排序
1 <= k <= arr.length * (arr.length - 1) / 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-th-smallest-prime-fraction
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Score {
public:
    int numerator;
    int denominator;
    int numeratorIndex;

    Score(int _numerator, int _denominator, int _numeratorIndex) : numerator(_numerator), denominator(_denominator), numeratorIndex(_numeratorIndex) {}

    bool operator< (const Score& s) const {
        return numerator * s.denominator > s.numerator * denominator;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> kthSmallest(2);
        priority_queue<Score> scores;

        for (int i = 1; i < (int)arr.size(); ++i) {
            scores.push(Score(1, arr[i], 0));
        }

        do {
            int numerator = scores.top().numerator, denominator = scores.top().denominator, numeratorIndex = scores.top().numeratorIndex;
            scores.pop();

            if (arr[numeratorIndex + 1] < denominator) {
                scores.push(Score(arr[numeratorIndex + 1], denominator, numeratorIndex + 1));
            }
            
            if (--k == 0) {
                kthSmallest = { numerator, denominator };
            }
        } while (k != 0);

        return kthSmallest;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2,3,5 };
    vector<int> actual = o.kthSmallestPrimeFraction(arr, 3);
    vector<int> expected = { 2,5 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,5 };
    actual = o.kthSmallestPrimeFraction(arr, 1);
    expected = { 1,5 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,5 };
    actual = o.kthSmallestPrimeFraction(arr, 6);
    expected = { 2,3 };
    check.checkIntVector(expected, actual);

    arr = { 1,7 };
    actual = o.kthSmallestPrimeFraction(arr, 1);
    expected = { 1,7 };
    check.checkIntVector(expected, actual);

    arr = { 1,7,23,29,47 };
    actual = o.kthSmallestPrimeFraction(arr, 3);
    expected = { 1,23 };
    check.checkIntVector(expected, actual);

    arr = { 1,7,23,29,47 };
    actual = o.kthSmallestPrimeFraction(arr, 8);
    expected = { 23,47 };
    check.checkIntVector(expected, actual);

    arr = { 1,7,23,29,47 };
    actual = o.kthSmallestPrimeFraction(arr, 10);
    expected = { 23,29 };
    check.checkIntVector(expected, actual);
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
