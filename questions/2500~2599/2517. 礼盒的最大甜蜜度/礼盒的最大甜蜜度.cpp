/* 礼盒的最大甜蜜度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 price ，其中 price[i] 表示第 i 类糖果的价格，另给你一个正整数 k 。

商店组合 k 类 不同 糖果打包成礼盒出售。礼盒的 甜蜜度 是礼盒中任意两种糖果 价格 绝对差的最小值。

返回礼盒的 最大 甜蜜度。



示例 1：

输入：price = [13,5,1,8,21,2], k = 3
输出：8
解释：选出价格分别为 [13,5,21] 的三类糖果。
礼盒的甜蜜度为 min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8 。
可以证明能够取得的最大甜蜜度就是 8 。
示例 2：

输入：price = [1,3,1], k = 2
输出：2
解释：选出价格分别为 [1,3] 的两类糖果。
礼盒的甜蜜度为 min(|1 - 3|) = min(2) = 2 。
可以证明能够取得的最大甜蜜度就是 2 。
示例 3：

输入：price = [7,7,7,7], k = 2
输出：0
解释：从现有的糖果中任选两类糖果，甜蜜度都会是 0 。


提示：

1 <= price.length <= 105
1 <= price[i] <= 109
2 <= k <= price.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int low = 0, high = price.back() - price[0], maxTastiness = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(price, k, mid)) {
                maxTastiness = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return maxTastiness;
    }

    bool check(vector<int>& price, int k, int tastiness) {
        int count = 1, prev = price[0], size = price.size();

        for (int i = 1; i < size; ++i) {
            if (price[i] - prev >= tastiness) {
                if (++count == k) {
                    return true;
                }
                prev = price[i];
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> price = { 13,5,1,8,21,2 };
    check.checkInt(8, o.maximumTastiness(price, 3));

    price = { 1,3,1 };
    check.checkInt(2, o.maximumTastiness(price, 2));

    price = { 7,7,7,7 };
    check.checkInt(0, o.maximumTastiness(price, 2));
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
