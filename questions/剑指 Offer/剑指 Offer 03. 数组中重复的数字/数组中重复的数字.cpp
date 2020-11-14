/* 数组中重复的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
 

限制：

2 <= n <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == i) {
                continue;
            }

            int num = nums[i];
            nums[i] = -1;

            while (num != -1) {
                if (nums[num] == num) {
                    return num;
                }

                int tmp = nums[num];
                nums[num] = num;
                num = tmp;
            }
        }

        return 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,1,0,2,5,3 };
    check.checkInt(2, o.findRepeatNumber(nums));

    nums = { 0,3,2,1,2 };
    check.checkInt(2, o.findRepeatNumber(nums));

    nums = { 2,0,1,3,3 };
    check.checkInt(3, o.findRepeatNumber(nums));

    nums = { 0,0 };
    check.checkInt(0, o.findRepeatNumber(nums));
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
