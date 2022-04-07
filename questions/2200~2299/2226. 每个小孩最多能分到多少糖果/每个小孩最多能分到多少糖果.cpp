/* 每个小孩最多能分到多少糖果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 下标从 0 开始 的整数数组 candies 。数组中的每个元素表示大小为 candies[i] 的一堆糖果。你可以将每堆糖果分成任意数量的 子堆 ，但 无法 再将两堆合并到一起。

另给你一个整数 k 。你需要将这些糖果分配给 k 个小孩，使每个小孩分到 相同 数量的糖果。每个小孩可以拿走 至多一堆 糖果，有些糖果可能会不被分配。

返回每个小孩可以拿走的 最大糖果数目 。

 

示例 1：

输入：candies = [5,8,6], k = 3
输出：5
解释：可以将 candies[1] 分成大小分别为 5 和 3 的两堆，然后把 candies[2] 分成大小分别为 5 和 1 的两堆。现在就有五堆大小分别为 5、5、3、5 和 1 的糖果。可以把 3 堆大小为 5 的糖果分给 3 个小孩。可以证明无法让每个小孩得到超过 5 颗糖果。
示例 2：

输入：candies = [2,5], k = 11
输出：0
解释：总共有 11 个小孩，但只有 7 颗糖果，但如果要分配糖果的话，必须保证每个小孩至少能得到 1 颗糖果。因此，最后每个小孩都没有得到糖果，答案是 0 。
 

提示：

1 <= candies.length <= 105
1 <= candies[i] <= 107
1 <= k <= 1012

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-candies-allocated-to-k-children
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = getSum(candies), ans = 0;

        while (low <= high) {
            long long middle = (low + high) / 2;

            if (check(candies, k, middle)) {
                ans = middle;
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }

        return (int)ans;
    }

    long long getSum(vector<int>& candies) {
        long long sum = 0;

        for (int candy : candies) {
            sum += candy;
        }

        return sum;
    }

    bool check(vector<int>& candies, long long k, long long num) {
        long long count = 0;

        for (int candy : candies) {
            count += (candy / num);
        }

        return count >= k;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> candies = { 5,8,6 };
    check.checkInt(5, o.maximumCandies(candies, 3));

    candies = { 2,5 };
    check.checkInt(0, o.maximumCandies(candies, 11));
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
