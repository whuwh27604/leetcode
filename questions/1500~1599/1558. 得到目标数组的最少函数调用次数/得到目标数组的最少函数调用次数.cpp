/* 得到目标数组的最少函数调用次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个与 nums 大小相同且初始值全为 0 的数组 arr ，请你调用以上函数得到整数数组 nums 。

请你返回将 arr 变成 nums 的最少函数调用次数。

答案保证在 32 位有符号整数以内。

 

示例 1：

输入：nums = [1,5]
输出：5
解释：给第二个数加 1 ：[0, 0] 变成 [0, 1] （1 次操作）。
将所有数字乘以 2 ：[0, 1] -> [0, 2] -> [0, 4] （2 次操作）。
给两个数字都加 1 ：[0, 4] -> [1, 4] -> [1, 5] （2 次操作）。
总操作次数为：1 + 2 + 2 = 5 。
示例 2：

输入：nums = [2,2]
输出：3
解释：给两个数字都加 1 ：[0, 0] -> [0, 1] -> [1, 1] （2 次操作）。
将所有数字乘以 2 ： [1, 1] -> [2, 2] （1 次操作）。
总操作次数为： 2 + 1 = 3 。
示例 3：

输入：nums = [4,2,5]
输出：6
解释：（初始）[0,0,0] -> [1,0,0] -> [1,0,1] -> [2,0,2] -> [2,1,2] -> [4,2,4] -> [4,2,5] （nums 数组）。
示例 4：

输入：nums = [3,2,2,4]
输出：7
示例 5：

输入：nums = [2,4,8,16]
输出：8
 

提示：

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-numbers-of-function-calls-to-make-target-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        /* 1、从0到x的步骤为：x为奇数，则x-1；x为偶数，则x/2。将以上过程反过来执行，就是x+1、x*2
           2、+1操作是每个数独立完成的，互相不影响；
           3、*2操作是所有数都要执行，所以需要先执行最多的。比如a需要3次，b需要5次*2操作，则b先执行2次（此时a保持0），然后ab一起执行3次。
           4、综上，结论就是找到最多的*2操作次数，加上所有的+1操作次数 */
        int add1 = 0, multi2, maxMulti2 = 0;

        for (int num : nums) {
            multi2 = 0;

            while (num != 0) {
                if ((num & 1) == 1) {
                    ++add1;
                    num &= ~1;
                }
                
                if (num > 1) {
                    ++multi2;
                    num >>= 1;
                }
            }

            maxMulti2 = max(maxMulti2, multi2);
        }

        return maxMulti2 + add1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,5 };
    check.checkInt(5, o.minOperations(nums));

    nums = { 2,2 };
    check.checkInt(3, o.minOperations(nums));

    nums = { 4,2,5 };
    check.checkInt(6, o.minOperations(nums));

    nums = { 3,2,2,4 };
    check.checkInt(7, o.minOperations(nums));

    nums = { 2,4,8,16 };
    check.checkInt(8, o.minOperations(nums));

    nums = { 0 };
    check.checkInt(0, o.minOperations(nums));

    nums = { 1 };
    check.checkInt(1, o.minOperations(nums));
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
