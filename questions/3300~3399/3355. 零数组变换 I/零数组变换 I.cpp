/* 零数组变换 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个长度为 n 的整数数组 nums 和一个二维数组 queries，其中 queries[i] = [li, ri]。

对于每个查询 queries[i]：

在 nums 的下标范围 [li, ri] 内选择一个下标子集。
将选中的每个下标对应的元素值减 1。
零数组 是指所有元素都等于 0 的数组。

如果在按顺序处理所有查询后，可以将 nums 转换为 零数组 ，则返回 true，否则返回 false。

数组的 子集 是对数组元素的选择（可能为空）。



示例 1：

输入： nums = [1,0,1], queries = [[0,2]]

输出： true

解释：

对于 i = 0：
选择下标子集 [0, 2] 并将这些下标处的值减 1。
数组将变为 [0, 0, 0]，这是一个零数组。
示例 2：

输入： nums = [4,3,2,1], queries = [[1,3],[0,2]]

输出： false

解释：

对于 i = 0：
选择下标子集 [1, 2, 3] 并将这些下标处的值减 1。
数组将变为 [4, 2, 1, 0]。
对于 i = 1：
选择下标子集 [0, 1, 2] 并将这些下标处的值减 1。
数组将变为 [3, 1, 0, 0]，这不是一个零数组。


提示：

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size = (int)nums.size();
        vector<int> diffs(size + 2, 0);

        for (auto& query : queries) {
            ++diffs[query[0] + 1];
            --diffs[query[1] + 2];
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

    vector<int> nums = { 1,0,1 };
    vector<vector<int>> queries = { {0,2} };
    check.checkBool(true, o.isZeroArray(nums, queries));

    nums = { 4,3,2,1 };
    queries = { {1,3},{0,2} };
    check.checkBool(false, o.isZeroArray(nums, queries));
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
