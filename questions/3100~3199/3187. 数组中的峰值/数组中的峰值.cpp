/* 数组中的峰值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数组 arr 中 大于 前面和后面相邻元素的元素被称为 峰值 元素。

给你一个整数数组 nums 和一个二维整数数组 queries 。

你需要处理以下两种类型的操作：

queries[i] = [1, li, ri] ，求出子数组 nums[li..ri] 中 峰值 元素的数目。
queries[i] = [2, indexi, vali] ，将 nums[indexi] 变为 vali 。
请你返回一个数组 answer ，它依次包含每一个第一种操作的答案。

注意：

子数组中 第一个 和 最后一个 元素都 不是 峰值元素。


示例 1：

输入：nums = [3,1,4,2,5], queries = [[2,3,4],[1,0,4]]

输出：[0]

解释：

第一个操作：我们将 nums[3] 变为 4 ，nums 变为 [3,1,4,4,5] 。

第二个操作：[3,1,4,4,5] 中峰值元素的数目为 0 。

示例 2：

输入：nums = [4,1,4,2,1,5], queries = [[2,2,4],[1,0,2],[1,0,4]]

输出：[0,1]

解释：

第一个操作：nums[2] 变为 4 ，它已经是 4 了，所以保持不变。

第二个操作：[4,1,4] 中峰值元素的数目为 0 。

第三个操作：第二个 4 是 [4,1,4,2,1] 中的峰值元素。



提示：

3 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i][0] == 1 或者 queries[i][0] == 2
对于所有的 i ，都有：
queries[i][0] == 1 ：0 <= queries[i][1] <= queries[i][2] <= nums.length - 1
queries[i][0] == 2 ：0 <= queries[i][1] <= nums.length - 1, 1 <= queries[i][2] <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);  // caller使用索引[0, n - 1]，bit使用索引[1, n]，不使用索引0
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        ++index;

        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        ++index;
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int size = (int)nums.size();
        BIT bit(size);
        vector<int> ans;

        for (int i = 1; i < size - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                bit.update(i, 1);
            }
        }

        for (auto& query : queries) {
            if (query[0] == 1) {
                ans.push_back(query[2] - query[1] >= 2 ? bit.query(query[2] - 1) - bit.query(query[1]) : 0);
            }
            else {
                int idx = query[1], val = query[2];
                if (idx > 1) {
                    bool oldPeak = nums[idx - 1] > nums[idx - 2] && nums[idx - 1] > nums[idx];
                    bool newPeak = nums[idx - 1] > nums[idx - 2] && nums[idx - 1] > val;
                    if (oldPeak && !newPeak) {
                        bit.update(idx - 1, -1);
                    }
                    else if (!oldPeak && newPeak) {
                        bit.update(idx - 1, 1);
                    }
                }

                if (idx != 0 && idx != size - 1) {
                    bool oldPeak = nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1];
                    bool newPeak = val > nums[idx - 1] && val > nums[idx + 1];
                    if (oldPeak && !newPeak) {
                        bit.update(idx, -1);
                    }
                    else if (!oldPeak && newPeak) {
                        bit.update(idx, 1);
                    }
                }

                if (idx < size - 2) {
                    bool oldPeak = nums[idx + 1] > nums[idx] && nums[idx + 1] > nums[idx + 2];
                    bool newPeak = nums[idx + 1] > val && nums[idx + 1] > nums[idx + 2];
                    if (oldPeak && !newPeak) {
                        bit.update(idx + 1, -1);
                    }
                    else if (!oldPeak && newPeak) {
                        bit.update(idx + 1, 1);
                    }
                }

                nums[idx] = val;
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,1,4,2,5 };
    vector<vector<int>> queries = { {2,3,4},{1,0,4} };
    vector<int> actual = o.countOfPeaks(nums, queries);
    vector<int> expected = { 0 };
    check.checkIntVector(expected, actual);

    nums = { 4,1,4,2,1,5 };
    queries = { {2,2,4},{1,0,2},{1,0,4} };
    actual = o.countOfPeaks(nums, queries);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    nums = { 5,4,8,6 };
    queries = { {1,2,2},{1,1,2},{2,1,6} };
    actual = o.countOfPeaks(nums, queries);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    nums = { 9,5,3,6,4,6 };
    queries = { {2,2,8},{1,0,3},{1,2,2} };
    actual = o.countOfPeaks(nums, queries);
    expected = { 1,0 };
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
