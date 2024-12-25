/* 使数组元素互不相同所需的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，你需要确保数组中的元素 互不相同 。为此，你可以执行以下操作任意次：

从数组的开头移除 3 个元素。如果数组中元素少于 3 个，则移除所有剩余元素。
注意：空数组也视作为数组元素互不相同。返回使数组元素互不相同所需的 最少操作次数 。





示例 1：

输入： nums = [1,2,3,4,2,3,3,5,7]

输出： 2

解释：

第一次操作：移除前 3 个元素，数组变为 [4, 2, 3, 3, 5, 7]。
第二次操作：再次移除前 3 个元素，数组变为 [3, 5, 7]，此时数组中的元素互不相同。
因此，答案是 2。

示例 2：

输入： nums = [4,5,6,4,4]

输出： 2

解释：

第一次操作：移除前 3 个元素，数组变为 [4, 4]。
第二次操作：移除所有剩余元素，数组变为空。
因此，答案是 2。

示例 3：

输入： nums = [6,7,8,9]

输出： 0

解释：

数组中的元素已经互不相同，因此不需要进行任何操作，答案是 0。



提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> exist(101, false);

        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            if (exist[nums[i]]) {
                return (i + 3) / 3;
            }

            exist[nums[i]] = true;
        }

        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4,2,3,3,5,7 };
    check.checkInt(2, o.minimumOperations(nums));

    nums = { 4,5,6,4,4 };
    check.checkInt(2, o.minimumOperations(nums));

    nums = { 6,7,8,9 };
    check.checkInt(0, o.minimumOperations(nums));
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
