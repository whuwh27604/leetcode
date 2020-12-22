/* 是否所有 1 都至少相隔 k 个元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由若干 0 和 1 组成的数组 nums 以及整数 k。如果所有 1 都至少相隔 k 个元素，则返回 True ；否则，返回 False 。

 

示例 1：



输入：nums = [1,0,0,0,1,0,0,1], k = 2
输出：true
解释：每个 1 都至少相隔 2 个元素。
示例 2：



输入：nums = [1,0,0,1,0,1], k = 2
输出：false
解释：第二个 1 和第三个 1 之间只隔了 1 个元素。
示例 3：

输入：nums = [1,1,1,1,1], k = 0
输出：true
示例 4：

输入：nums = [0,1,0,1], k = 1
输出：true
 

提示：

1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] 的值为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-all-1s-are-at-least-length-k-places-away
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int apart = k;

        for (int num : nums) {
            if (num == 0) {
                ++apart;
            }
            else {
                if (apart < k) {
                    return false;
                }

                apart = 0;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,0,0,0,1,0,0,1 };
    check.checkBool(true, o.kLengthApart(nums, 2));

    nums = { 1,0,0,1,0,1 };
    check.checkBool(false, o.kLengthApart(nums, 2));

    nums = { 1,1,1,1,1 };
    check.checkBool(true, o.kLengthApart(nums, 0));

    nums = { 0,1,0,1 };
    check.checkBool(true, o.kLengthApart(nums, 1));
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
