﻿/* 将一维数组转变成二维数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有 元素创建一个 m 行 n 列的二维数组。

original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都 包含 ）的元素构成二维数组的第二行，依此类推。

请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。

 

示例 1：


输入：original = [1,2,3,4], m = 2, n = 2
输出：[[1,2],[3,4]]
解释：
构造出的二维数组应该包含 2 行 2 列。
original 中第一个 n=2 的部分为 [1,2] ，构成二维数组的第一行。
original 中第二个 n=2 的部分为 [3,4] ，构成二维数组的第二行。
示例 2：

输入：original = [1,2,3], m = 1, n = 3
输出：[[1,2,3]]
解释：
构造出的二维数组应该包含 1 行 3 列。
将 original 中所有三个元素放入第一行中，构成要求的二维数组。
示例 3：

输入：original = [1,2], m = 1, n = 1
输出：[]
解释：
original 中有 2 个元素。
无法将 2 个元素放入到一个 1x1 的二维数组中，所以返回一个空的二维数组。
示例 4：

输入：original = [3], m = 1, n = 2
输出：[]
解释：
original 中只有 1 个元素。
无法将 1 个元素放满一个 1x2 的二维数组，所以返回一个空的二维数组。
 

提示：

1 <= original.length <= 5 * 104
1 <= original[i] <= 105
1 <= m, n <= 4 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-1d-array-into-2d-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int i, size = original.size();
        vector<vector<int>> ans(m, vector<int>(n));

        if (size != m * n) {
            return {};
        }

        for (i = 0; i < size; ++i) {
            ans[i / n][i % n] = original[i];
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> original = { 1,2,3,4 };
    vector<vector<int>> actual = o.construct2DArray(original, 2, 2);
    vector<vector<int>> expected = { {1,2},{3,4} };
    check.checkIntVectorVector(expected, actual);

    original = { 1,2,3 };
    actual = o.construct2DArray(original, 1, 3);
    expected = { {1,2,3} };
    check.checkIntVectorVector(expected, actual);

    original = { 1,2,3,4,5,6 };
    actual = o.construct2DArray(original, 2, 3);
    expected = { {1,2,3},{4,5,6} };
    check.checkIntVectorVector(expected, actual);

    original = { 1,2 };
    actual = o.construct2DArray(original, 1, 1);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    original = { 3 };
    actual = o.construct2DArray(original, 1, 2);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    original = { 3 };
    actual = o.construct2DArray(original, 1, 1);
    expected = { {3} };
    check.checkIntVectorVector(expected, actual);
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
