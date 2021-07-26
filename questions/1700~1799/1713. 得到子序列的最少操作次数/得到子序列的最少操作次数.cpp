/* 得到子序列的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。

每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr = [1,4,1,2] ，那么你可以在中间添加 3 得到 [1,4,3,1,2] 。你可以在数组最开始或最后面添加整数。

请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。

一个数组的 子序列 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的子序列（加粗元素），但 [2,4,2] 不是子序列。

 

示例 1：

输入：target = [5,1,3], arr = [9,4,2,3,4]
输出：2
解释：你可以添加 5 和 1 ，使得 arr 变为 [5,9,4,1,2,3,4] ，target 为 arr 的子序列。
示例 2：

输入：target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
输出：3
 

提示：

1 <= target.length, arr.length <= 105
1 <= target[i], arr[i] <= 109
target 不包含任何重复元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> position;
        mapTarget(target, position);

        return (int)target.size() - getLIS(arr, position);
    }

    void mapTarget(vector<int>& target, unordered_map<int, int>& position) {
        for (int i = 0; i < (int)target.size(); ++i) {
            position[target[i]] = i;
        }
    }

    int getLIS(vector<int>& arr, unordered_map<int, int>& position) {
        vector<int> LIS;

        for (int num : arr) {
            if (position.count(num) == 0) {
                continue;
            }

            int index = position[num];
            auto iter = lower_bound(LIS.begin(), LIS.end(), index);
            if (iter != LIS.end()) {
                *iter = index;
            }
            else {
                LIS.push_back(index);
            }
        }

        return (int)LIS.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> target = { 5,1,3 };
    vector<int> arr = { 9,4,2,3,4 };
    check.checkInt(2, o.minOperations(target, arr));

    target = { 6,4,8,1,3,2 };
    arr = { 4,7,6,2,3,8,6,1 };
    check.checkInt(3, o.minOperations(target, arr));
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
