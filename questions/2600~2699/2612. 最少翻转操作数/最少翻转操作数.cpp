/* 最少翻转操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个在范围 [0, n - 1] 以内的整数 p ，它们表示一个长度为 n 且下标从 0 开始的数组 arr ，数组中除了下标为 p 处是 1 以外，其他所有数都是 0 。

同时给你一个整数数组 banned ，它包含数组中的一些位置。banned 中第 i 个位置表示 arr[banned[i]] = 0 ，题目保证 banned[i] != p 。

你可以对 arr 进行 若干次 操作。一次操作中，你选择大小为 k 的一个 子数组 ，并将它 翻转 。在任何一次翻转操作后，你都需要确保 arr 中唯一的 1 不会到达任何 banned 中的位置。换句话说，arr[banned[i]] 始终 保持 0 。

请你返回一个数组 ans ，对于 [0, n - 1] 之间的任意下标 i ，ans[i] 是将 1 放到位置 i 处的 最少 翻转操作次数，如果无法放到位置 i 处，此数为 -1 。

子数组 指的是一个数组里一段连续 非空 的元素序列。
对于所有的 i ，ans[i] 相互之间独立计算。
将一个数组中的元素 翻转 指的是将数组中的值变成 相反顺序 。


示例 1：

输入：n = 4, p = 0, banned = [1,2], k = 4
输出：[0,-1,-1,1]
解释：k = 4，所以只有一种可行的翻转操作，就是将整个数组翻转。一开始 1 在位置 0 处，所以将它翻转到位置 0 处需要的操作数为 0 。
我们不能将 1 翻转到 banned 中的位置，所以位置 1 和 2 处的答案都是 -1 。
通过一次翻转操作，可以将 1 放到位置 3 处，所以位置 3 的答案是 1 。
示例 2：

输入：n = 5, p = 0, banned = [2,4], k = 3
输出：[0,-1,-1,-1,-1]
解释：这个例子中 1 一开始在位置 0 处，所以此下标的答案为 0 。
翻转的子数组长度为 k = 3 ，1 此时在位置 0 处，所以我们可以翻转子数组 [0, 2]，但翻转后的下标 2 在 banned 中，所以不能执行此操作。
由于 1 没法离开位置 0 ，所以其他位置的答案都是 -1 。
示例 3：

输入：n = 4, p = 2, banned = [0,1,3], k = 1
输出：[-1,-1,0,-1]
解释：这个例子中，我们只能对长度为 1 的子数组执行翻转操作，所以 1 无法离开初始位置。


提示：

1 <= n <= 105
0 <= p <= n - 1
0 <= banned.length <= n - 1
0 <= banned[i] <= n - 1
1 <= k <= n
banned[i] != p
banned 中的值 互不相同 。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        ans[p] = 0;
        if (k == 1) {
            return ans;
        }

        vector<bool> isBanned(n, false);
        for (int ban : banned) {
            isBanned[ban] = true;
            ans[ban] = -1;
        }

        set<int> choseables[2];
        for (int i = 0; i < n; ++i) {
            if (i != p && !isBanned[i]) {
                choseables[i & 1].insert(i);
            }
        }

        int opers = 0;
        queue<int> indices;
        indices.push(p);

        while (!indices.empty()) {
            int size = indices.size();
            ++opers;

            for (int i = 0; i < size; ++i) {
                int index = indices.front();
                indices.pop();

                int left = index + max(-(k - 1), k - 1 - 2 * index);
                int right = index + min(k - 1, -(k - 1) + 2 * (n - index - 1));
                set<int>& choseable = choseables[(index + k - 1) & 1];
                auto iter = choseable.lower_bound(left);

                while (iter != choseable.end() && *iter <= right) {
                    ans[*iter] = opers;
                    indices.push(*iter);
                    iter = choseable.erase(iter);
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> banned = { 1,2 };
    vector<int> actual = o.minReverseOperations(4, 0, banned, 4);
    vector<int> expected = { 0,-1,-1,1 };
    check.checkIntVector(expected, actual);

    banned = { 2,4 };
    actual = o.minReverseOperations(5, 0, banned, 3);
    expected = { 0,-1,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    banned = { 0,1,3 };
    actual = o.minReverseOperations(4, 2, banned, 1);
    expected = { -1,-1,0,-1 };
    check.checkIntVector(expected, actual);

    banned = {  };
    actual = o.minReverseOperations(6, 2, banned, 4);
    expected = { 2,1,0,1,2,1 };
    check.checkIntVector(expected, actual);

    banned = {  };
    actual = o.minReverseOperations(4, 0, banned, 3);
    expected = { 0,-1,1,-1 };
    check.checkIntVector(expected, actual);

    banned = {  };
    actual = o.minReverseOperations(4, 0, banned, 4);
    expected = { 0,-1,-1,1 };
    check.checkIntVector(expected, actual);

    banned = {  };
    actual = o.minReverseOperations(4, 2, banned, 4);
    expected = { -1,1,0,-1 };
    check.checkIntVector(expected, actual);

    banned = {  };
    actual = o.minReverseOperations(4, 3, banned, 4);
    expected = { 1,-1,-1,0 };
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
