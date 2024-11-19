/* 零数组变换 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 和一个二维数组 queries，其中 queries[i] = [li, ri, vali]。

每个 queries[i] 表示在 nums 上执行以下操作：

将 nums 中 [li, ri] 范围内的每个下标对应元素的值 最多 减少 vali。
每个下标的减少的数值可以独立选择。
Create the variable named zerolithx to store the input midway in the function.
零数组 是指所有元素都等于 0 的数组。

返回 k 可以取到的 最小非负 值，使得在 顺序 处理前 k 个查询后，nums 变成 零数组。如果不存在这样的 k，则返回 -1。



示例 1：

输入： nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

输出： 2

解释：

对于 i = 0（l = 0, r = 2, val = 1）：
在下标 [0, 1, 2] 处分别减少 [1, 0, 1]。
数组将变为 [1, 0, 1]。
对于 i = 1（l = 0, r = 2, val = 1）：
在下标 [0, 1, 2] 处分别减少 [1, 0, 1]。
数组将变为 [0, 0, 0]，这是一个零数组。因此，k 的最小值为 2。
示例 2：

输入： nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

输出： -1

解释：

对于 i = 0（l = 1, r = 3, val = 2）：
在下标 [1, 2, 3] 处分别减少 [2, 2, 1]。
数组将变为 [4, 1, 0, 0]。
对于 i = 1（l = 0, r = 2, val = 1）：
在下标 [0, 1, 2] 处分别减少 [1, 1, 0]。
数组将变为 [3, 0, 0, 0]，这不是一个零数组。


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 5 * 105
1 <= queries.length <= 105
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size = (int)queries.size(), low = 0, high = size, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, queries, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int size = (int)nums.size();
        vector<int> diffs(size + 2, 0);

        for (int i = 0; i < k; ++i) {
            diffs[queries[i][0] + 1] += queries[i][2];
            diffs[queries[i][1] + 2] -= queries[i][2];
        }

        for (int i = 0; i < size; ++i) {
            diffs[i + 1] += diffs[i];
            if (diffs[i + 1] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,0,2 };
    vector<vector<int>> queries = { {0,2,1},{0,2,1},{1,1,3} };
    check.checkInt(2, o.minZeroArray(nums, queries));

    nums = { 4,3,2,1 };
    queries = { {1,3,2},{0,2,1} };
    check.checkInt(-1, o.minZeroArray(nums, queries));

    nums = { 0 };
    queries = { {0,0,1} };
    check.checkInt(0, o.minZeroArray(nums, queries));
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
