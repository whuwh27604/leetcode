/* 使数组中的所有元素都等于零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个正整数 k 。

你可以对数组执行下述操作 任意次 ：

从数组中选出长度为 k 的 任一 子数组，并将子数组中每个元素都 减去 1 。
如果你可以使数组中的所有元素都等于 0 ，返回  true ；否则，返回 false 。

子数组 是数组中的一个非空连续元素序列。



示例 1：

输入：nums = [2,2,3,1,1,0], k = 3
输出：true
解释：可以执行下述操作：
- 选出子数组 [2,2,3] ，执行操作后，数组变为 nums = [1,1,2,1,1,0] 。
- 选出子数组 [2,1,1] ，执行操作后，数组变为 nums = [1,1,1,0,0,0] 。
- 选出子数组 [1,1,1] ，执行操作后，数组变为 nums = [0,0,0,0,0,0] 。
示例 2：

输入：nums = [1,3,1,1], k = 2
输出：false
解释：无法使数组中的所有元素等于 0 。


提示：

1 <= k <= nums.length <= 105
0 <= nums[i] <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int size = nums.size(), sum = 0;
        vector<int> diff(size + 1, 0);

        for (int i = 0; i < size; ++i) {
            sum += diff[i];  // sum是差分数组的前缀和，表示当前位置实际已经操作的次数
            int opers = nums[i] + sum;

            if (opers == 0) {
                continue;
            }

            if (opers < 0 || (opers > 0 && i + k > size)) {  // 操作只能减1，opers小于0时无法完成变大操作。最后一个窗口内的数据必须回到0，否则没有机会再操作它们。
                return false;
            }

            sum -= opers;  // 差分数组在当前位置要减去opers，然后在i + k位置要加回opers。sum执行前缀和操作
            diff[i + k] += opers;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,2,3,1,1,0 };
    check.checkBool(true, o.checkArray(nums, 3));

    nums = { 1,3,1,1 };
    check.checkBool(false, o.checkArray(nums, 2));
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
