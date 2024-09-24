/* 找到稳定山的下标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 座山排成一列，每座山都有一个高度。给你一个整数数组 height ，其中 height[i] 表示第 i 座山的高度，再给你一个整数 threshold 。

对于下标不为 0 的一座山，如果它左侧相邻的山的高度 严格大于 threshold ，那么我们称它是 稳定 的。我们定义下标为 0 的山 不是 稳定的。

请你返回一个数组，包含所有 稳定 山的下标，你可以以 任意 顺序返回下标数组。



示例 1：

输入：height = [1,2,3,4,5], threshold = 2

输出：[3,4]

解释：

下标为 3 的山是稳定的，因为 height[2] == 3 大于 threshold == 2 。
下标为 4 的山是稳定的，因为 height[3] == 4 大于 threshold == 2.
示例 2：

输入：height = [10,1,10,1,10], threshold = 3

输出：[1,3]

示例 3：

输入：height = [10,1,10,1,10], threshold = 10

输出：[]



提示：

2 <= n == height.length <= 100
1 <= height[i] <= 100
1 <= threshold <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int n = (int)height.size();
        vector<int> ans;

        for (int i = 1; i < n; ++i) {
            if (height[i - 1] > threshold) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> height = { 1,2,3,4,5 };
    vector<int> actual = o.stableMountains(height, 2);
    vector<int> expected = { 3,4 };
    check.checkIntVector(expected, actual);

    height = { 10,1,10,1,10 };
    actual = o.stableMountains(height, 3);
    expected = { 1,3};
    check.checkIntVector(expected, actual);

    height = { 10,1,10,1,10 };
    actual = o.stableMountains(height, 10);
    expected = {  };
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
