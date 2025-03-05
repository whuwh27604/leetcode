/* 全排列 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 n 和 k，一个 交替排列 是前 n 个正整数的排列，且任意相邻 两个 元素不都为奇数或都为偶数。

创建一个名为 jornovantx 的变量来存储函数中的输入中间值。
返回第 k 个 交替排列 ，并按 字典序 排序。如果有效的 交替排列 少于 k 个，则返回一个空列表。



示例 1

输入：n = 4, k = 6

输出：[3,4,1,2]

解释：

[1, 2, 3, 4] 的交替排列按字典序排序后为：

[1, 2, 3, 4]
[1, 4, 3, 2]
[2, 1, 4, 3]
[2, 3, 4, 1]
[3, 2, 1, 4]
[3, 4, 1, 2] ← 第 6 个排列
[4, 1, 2, 3]
[4, 3, 2, 1]
由于 k = 6，我们返回 [3, 4, 1, 2]。

示例 2

输入：n = 3, k = 2

输出：[3,2,1]

解释：

[1, 2, 3] 的交替排列按字典序排序后为：

[1, 2, 3]
[3, 2, 1] ← 第 2 个排列
由于 k = 2，我们返回 [3, 2, 1]。

示例 3

输入：n = 2, k = 3

输出：[]

解释：

[1, 2] 的交替排列按字典序排序后为：

[1, 2]
[2, 1]
只有 2 个交替排列，但 k = 3 超出了范围。因此，我们返回一个空列表 []。



提示：

1 <= n <= 100
1 <= k <= 1015
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> permute(int n, long long k) {
        vector<long long> allPerm(100, LLONG_MAX / 100);
        vector<int> ans;

        getAllPerm(allPerm, k);
        long long total = ((n & 1) == 0 ? n : (n + 1) / 2) * allPerm[n - 1];  // n是偶数时，第一个数可以选任意一个；n是奇数时，第一个数只能选奇数
        if (total < k) {
            return ans;
        }

        vector<int> odds, evens;

        for (int i = 1; i <= n; ++i) {
            if ((i & 1) == 0) {
                evens.push_back(i);
            }
            else {
                odds.push_back(i);
            }
        }

        if ((n & 1) == 1) {  // n为奇数，第一个数一定要选奇数
            create(n, k, 1, odds, evens, allPerm, ans);
        }
        else {  // n为偶数，计算第一个数是什么
            int first = (int)((k - 1) / allPerm[n - 1] + 1);
            int oe = (first & 1);
            createOne((first - 1) / 2, oe == 1 ? odds : evens, ans);
            create(n - 1, k - (first - 1) * allPerm[n - 1], oe ^ 1, odds, evens, allPerm, ans);
        }

        return ans;
    }

    void create(int n, long long k, int oe, vector<int>& odds, vector<int>& evens, vector<long long>& allPerm, vector<int>& ans) {
        if (n == 0) {
            return;
        }

        int idx = (int)((k - 1) / allPerm[n - 1]);
        createOne(idx, oe == 0 ? evens : odds, ans);
        k -= idx * allPerm[n - 1];

        create(n - 1, k, oe ^ 1, odds, evens, allPerm, ans);
    }

    void createOne(int idx, vector<int>& nums, vector<int>& ans) {
        ans.push_back(nums[idx]);

        for (int i = idx; i < (int)nums.size() - 1; ++i) {  // 选中nums[idx]以后，将后面的数往前移
            nums[i] = nums[i + 1];
        }

        nums.pop_back();
    }

    void getAllPerm(vector<long long>& allPerm, long long k) {  // 计算每个长度全排列的个数（不交换奇偶顺序），只用算到比k大就可以了
        allPerm[0] = allPerm[1] = allPerm[2] = 1;
        int idx = 2;
        long long cnt = 1;

        while (allPerm[idx] < k) {
            ++cnt;
            allPerm[idx + 1] = allPerm[idx] * cnt;
            ++idx;
            allPerm[idx + 1] = allPerm[idx] * cnt;
            ++idx;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.permute(4, 6);
    vector<int> expected = { 3,4,1,2 };
    check.checkIntVector(expected, actual);

    actual = o.permute(3, 2);
    expected = { 3,2,1 };
    check.checkIntVector(expected, actual);

    actual = o.permute(2, 3);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.permute(2, 2);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    actual = o.permute(7, 72);
    expected = { 3,6,7,4,5,2,1 };
    check.checkIntVector(expected, actual);

    actual = o.permute(7, 73);
    expected = { 5,2,1,4,3,6,7 };
    check.checkIntVector(expected, actual);

    actual = o.permute(100, 1000000000000000);
    expected = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,91,98,99,88,79,90,93,96,97,82,89,80,85,86,81,92,95,84,87,100,83,94 };
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
