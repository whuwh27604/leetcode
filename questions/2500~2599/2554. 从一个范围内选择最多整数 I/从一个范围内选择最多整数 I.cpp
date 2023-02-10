/* 从一个范围内选择最多整数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 banned 和两个整数 n 和 maxSum 。你需要按照以下规则选择一些整数：

被选择整数的范围是 [1, n] 。
每个整数 至多 选择 一次 。
被选择整数不能在数组 banned 中。
被选择整数的和不超过 maxSum 。
请你返回按照上述规则 最多 可以选择的整数数目。



示例 1：

输入：banned = [1,6,5], n = 5, maxSum = 6
输出：2
解释：你可以选择整数 2 和 4 。
2 和 4 在范围 [1, 5] 内，且它们都不在 banned 中，它们的和是 6 ，没有超过 maxSum 。
示例 2：

输入：banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
输出：0
解释：按照上述规则无法选择任何整数。
示例 3：

输入：banned = [11], n = 7, maxSum = 50
输出：7
解释：你可以选择整数 1, 2, 3, 4, 5, 6 和 7 。
它们都在范围 [1, 7] 中，且都没出现在 banned 中，它们的和是 28 ，没有超过 maxSum 。


提示：

1 <= banned.length <= 104
1 <= banned[i], n <= 104
1 <= maxSum <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int i = 0, size = banned.size(), sum = 0, count = 0;

        sort(banned.begin(), banned.end());

        for (int num = 1; num <= n; ++num) {
            if (i >= size || num != banned[i]) {
                sum += num;
                if (sum > maxSum) {
                    break;
                }
                else {
                    ++count;
                }
            }
            else {
                while (i < size && banned[i] == num) {
                    ++i;
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> banned = { 1,6,5 };
    check.checkInt(2, o.maxCount(banned, 5, 6));

    banned = { 1,6,5,1,6,5 };
    check.checkInt(2, o.maxCount(banned, 5, 6));

    banned = { 1,2,3,4,5,6,7 };
    check.checkInt(0, o.maxCount(banned, 8, 1));

    banned = { 11 };
    check.checkInt(7, o.maxCount(banned, 7, 50));
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
