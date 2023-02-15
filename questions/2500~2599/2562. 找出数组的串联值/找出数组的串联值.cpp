/* 找出数组的串联值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

现定义两个数字的 串联 是由这两个数值串联起来形成的新数字。

例如，15 和 49 的串联是 1549 。
nums 的 串联值 最初等于 0 。执行下述操作直到 nums 变为空：

如果 nums 中存在不止一个数字，分别选中 nums 中的第一个元素和最后一个元素，将二者串联得到的值加到 nums 的 串联值 上，然后从 nums 中删除第一个和最后一个元素。
如果仅存在一个元素，则将该元素的值加到 nums 的串联值上，然后删除这个元素。
返回执行完所有操作后 nums 的串联值。



示例 1：

输入：nums = [7,52,2,4]
输出：596
解释：在执行任一步操作前，nums 为 [7,52,2,4] ，串联值为 0 。
 - 在第一步操作中：
我们选中第一个元素 7 和最后一个元素 4 。
二者的串联是 74 ，将其加到串联值上，所以串联值等于 74 。
接着我们从 nums 中移除这两个元素，所以 nums 变为 [52,2] 。
 - 在第二步操作中：
我们选中第一个元素 52 和最后一个元素 2 。
二者的串联是 522 ，将其加到串联值上，所以串联值等于 596 。
接着我们从 nums 中移除这两个元素，所以 nums 变为空。
由于串联值等于 596 ，所以答案就是 596 。
示例 2：

输入：nums = [5,14,13,8,12]
输出：673
解释：在执行任一步操作前，nums 为 [5,14,13,8,12] ，串联值为 0 。
- 在第一步操作中：
我们选中第一个元素 5 和最后一个元素 12 。
二者的串联是 512 ，将其加到串联值上，所以串联值等于 512 。
接着我们从 nums 中移除这两个元素，所以 nums 变为 [14,13,8] 。
- 在第二步操作中：
我们选中第一个元素 14 和最后一个元素 8 。
二者的串联是 148 ，将其加到串联值上，所以串联值等于 660 。
接着我们从 nums 中移除这两个元素，所以 nums 变为 [13] 。
- 在第三步操作中：
nums 只有一个元素，所以我们选中 13 并将其加到串联值上，所以串联值等于 673 。
接着我们从 nums 中移除这个元素，所以 nums 变为空。
由于串联值等于 673 ，所以答案就是 673 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 104
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;
        int i = 0, j = nums.size() - 1;

        for (; i < j; ++i, --j) {
            long long num = nums[j], power = 1;

            while (num != 0) {
                num /= 10;
                power *= 10;
            }

            sum += nums[i] * power + nums[j];
        }

        if (i == j) {
            sum += nums[i];
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 7,52,2,4 };
    check.checkLongLong(596, o.findTheArrayConcVal(nums));

    nums = { 5,14,13,8,12 };
    check.checkLongLong(673, o.findTheArrayConcVal(nums));

    nums = { 1 };
    check.checkLongLong(1, o.findTheArrayConcVal(nums));
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
