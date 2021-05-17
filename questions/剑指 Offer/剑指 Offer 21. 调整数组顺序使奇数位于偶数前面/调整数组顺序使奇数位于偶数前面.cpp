/* 调整数组顺序使奇数位于偶数前面.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。
 

提示：

0 <= nums.length <= 50000
1 <= nums[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i, j = nums.size() - 1;

        for (i = 0; i < j; ++i) {
            if ((nums[i] & 1) == 0) {
                while ((nums[j] & 1) == 0 && j > i) {
                    --j;
                }

                swap(nums[i], nums[j--]);
            }
        }

        return nums;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4 };
    vector<int> actual = o.exchange(nums);
    vector<int> expected = { 1,3,2,4 };
    check.checkIntVector(expected, actual);

    nums = {  };
    actual = o.exchange(nums);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 1,3 };
    actual = o.exchange(nums);
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3,4,5,6,7,8,9,10 };
    actual = o.exchange(nums);
    expected = { 1,9,3,7,5,6,4,8,2,10 };
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
