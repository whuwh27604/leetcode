/* 跳跃游戏 V.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个整数 d 。每一步你可以从下标 i 跳到：

i + x ，其中 i + x < arr.length 且 0 < x <= d 。
i - x ，其中 i - x >= 0 且 0 < x <= d 。
除此以外，你从下标 i 跳到下标 j 需要满足：arr[i] > arr[j] 且 arr[i] > arr[k] ，其中下标 k 是所有 i 到 j 之间的数字（更正式的，min(i, j) < k < max(i, j)）。

你可以选择数组的任意下标开始跳跃。请你返回你 最多 可以访问多少个下标。

请注意，任何时刻你都不能跳到数组的外面。

 

示例 1：



输入：arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
输出：4
解释：你可以从下标 10 出发，然后如上图依次经过 10 --> 8 --> 6 --> 7 。
注意，如果你从下标 6 开始，你只能跳到下标 7 处。你不能跳到下标 5 处因为 13 > 9 。你也不能跳到下标 4 处，因为下标 5 在下标 4 和 6 之间且 13 > 9 。
类似的，你不能从下标 3 处跳到下标 2 或者下标 1 处。
示例 2：

输入：arr = [3,3,3,3,3], d = 3
输出：1
解释：你可以从任意下标处开始且你永远无法跳到任何其他坐标。
示例 3：

输入：arr = [7,6,5,4,3,2,1], d = 1
输出：7
解释：从下标 0 处开始，你可以按照数值从大到小，访问所有的下标。
示例 4：

输入：arr = [7,1,7,1,7,1], d = 2
输出：2
示例 5：

输入：arr = [66], d = 1
输出：1
 

提示：

1 <= arr.length <= 1000
1 <= arr[i] <= 10^5
1 <= d <= arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-v
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int i, size = arr.size(), maximumJumps = 0;
        vector<pair<int, int>> heightsIndices(size);
        vector<int> mostJumps(size);

        for (i = 0; i < size; ++i) {
            heightsIndices[i] = { arr[i],i };
        }

        sort(heightsIndices.begin(), heightsIndices.end());

        for (i = 0; i < size; ++i) {
            maximumJumps = max(maximumJumps, getMaxJumps(arr, d, heightsIndices[i].second, mostJumps));
        }

        return maximumJumps;
    }

    int getMaxJumps(vector<int>& arr, int d, int index, vector<int>& mostJumps) {
        int i, size = arr.size(), mostJump = 1;

        for (i = index - 1; i >= 0 && index - i <= d && arr[i] < arr[index]; --i) {
            mostJump = max(mostJump, mostJumps[i] + 1);
        }

        for (i = index + 1; i < size && i - index <= d && arr[i] < arr[index]; ++i) {
            mostJump = max(mostJump, mostJumps[i] + 1);
        }

        mostJumps[index] = mostJump;
        return mostJump;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 6,4,14,6,8,13,9,7,10,6,12 };
    check.checkInt(4, o.maxJumps(arr, 2));

    arr = { 3,3,3,3,3 };
    check.checkInt(1, o.maxJumps(arr, 3));

    arr = { 7,6,5,4,3,2,1 };
    check.checkInt(7, o.maxJumps(arr, 1));

    arr = { 7,1,7,1,7,1 };
    check.checkInt(2, o.maxJumps(arr, 2));

    arr = { 66 };
    check.checkInt(1, o.maxJumps(arr, 1));
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
