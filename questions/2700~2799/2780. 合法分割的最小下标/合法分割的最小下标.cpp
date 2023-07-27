/* 合法分割的最小下标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果元素 x 在长度为 m 的整数数组 arr 中满足 freq(x) * 2 > m ，那么我们称 x 是 支配元素 。其中 freq(x) 是 x 在数组 arr 中出现的次数。注意，根据这个定义，数组 arr 最多 只会有 一个 支配元素。

给你一个下标从 0 开始长度为 n 的整数数组 nums ，数据保证它含有一个支配元素。

你需要在下标 i 处将 nums 分割成两个数组 nums[0, ..., i] 和 nums[i + 1, ..., n - 1] ，如果一个分割满足以下条件，我们称它是 合法 的：

0 <= i < n - 1
nums[0, ..., i] 和 nums[i + 1, ..., n - 1] 的支配元素相同。
这里， nums[i, ..., j] 表示 nums 的一个子数组，它开始于下标 i ，结束于下标 j ，两个端点都包含在子数组内。特别地，如果 j < i ，那么 nums[i, ..., j] 表示一个空数组。

请你返回一个 合法分割 的 最小 下标。如果合法分割不存在，返回 -1 。



示例 1：

输入：nums = [1,2,2,2]
输出：2
解释：我们将数组在下标 2 处分割，得到 [1,2,2] 和 [2] 。
数组 [1,2,2] 中，元素 2 是支配元素，因为它在数组中出现了 2 次，且 2 * 2 > 3 。
数组 [2] 中，元素 2 是支配元素，因为它在数组中出现了 1 次，且 1 * 2 > 1 。
两个数组 [1,2,2] 和 [2] 都有与 nums 一样的支配元素，所以这是一个合法分割。
下标 2 是合法分割中的最小下标。
示例 2：

输入：nums = [2,1,3,1,1,1,7,1,2,1]
输出：4
解释：我们将数组在下标 4 处分割，得到 [2,1,3,1,1] 和 [1,7,1,2,1] 。
数组 [2,1,3,1,1] 中，元素 1 是支配元素，因为它在数组中出现了 3 次，且 3 * 2 > 5 。
数组 [1,7,1,2,1] 中，元素 1 是支配元素，因为它在数组中出现了 3 次，且 3 * 2 > 5 。
两个数组 [2,1,3,1,1] 和 [1,7,1,2,1] 都有与 nums 一样的支配元素，所以这是一个合法分割。
下标 4 是所有合法分割中的最小下标。
示例 3：

输入：nums = [3,3,3,3,7,2,2]
输出：-1
解释：没有合法分割。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
nums 有且只有一个支配元素。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int size = nums.size(), totalFreq = 0, freq1 = 0, freq2 = 0;
        int mode = BoyerMoore(nums);

        for (int num : nums) {
            if (num == mode) {
                ++totalFreq;
            }
        }

        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] == mode) {
                ++freq1;
            }

            freq2 = totalFreq - freq1;

            if ((freq1 * 2 > i + 1) && (freq2 * 2 > size - i - 1)) {
                return i;
            }
        }

        return -1;
    }

    int BoyerMoore(vector<int>& nums) {
        int mode = 0, freq = 0;

        for (int num : nums) {
            if (freq == 0) {
                mode = num;
                freq = 1;
            }
            else {
                if (num == mode) {
                    freq += 1;
                }
                else {
                    freq -= 1;
                }
            }
        }

        return mode;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,2,2 };
    check.checkInt(2, o.minimumIndex(nums));

    nums = { 2,1,3,1,1,1,7,1,2,1 };
    check.checkInt(4, o.minimumIndex(nums));

    nums = { 3,3,3,3,7,2,2 };
    check.checkInt(-1, o.minimumIndex(nums));
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
