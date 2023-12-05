/* 找出峰值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 mountain 。你的任务是找出数组 mountain 中的所有 峰值。

以数组形式返回给定数组中 峰值 的下标，顺序不限 。

注意：

峰值 是指一个严格大于其相邻元素的元素。
数组的第一个和最后一个元素 不 是峰值。


示例 1：

输入：mountain = [2,4,4]
输出：[]
解释：mountain[0] 和 mountain[2] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
mountain[1] 也不可能是峰值，因为它不严格大于 mountain[2] 。
因此，答案为 [] 。
示例 2：

输入：mountain = [1,4,3,8,5]
输出：[1,3]
解释：mountain[0] 和 mountain[4] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
mountain[2] 也不可能是峰值，因为它不严格大于 mountain[3] 和 mountain[1] 。
但是 mountain[1] 和 mountain[3] 严格大于它们的相邻元素。
因此，答案是 [1,3] 。


提示：

3 <= mountain.length <= 100
1 <= mountain[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int size = mountain.size();
        vector<int> peaks;

        for (int i = 1; i < size - 1; ++i) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                peaks.push_back(i);
            }
        }

        return peaks;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> mountain = { 2,4,4 };
    vector<int> actual = o.findPeaks(mountain);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    mountain = { 1,4,3,8,5 };
    actual = o.findPeaks(mountain);
    expected = { 1,3 };
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
