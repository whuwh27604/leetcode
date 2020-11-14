/* 只出现一次的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        a⊕0=a
        a⊕a=0
        a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
        */
        int num = 0;
        for (unsigned int i = 0; i < nums.size(); i++) {
            num ^= nums[i];
        }
        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,2,1 };
    check.checkInt(1, o.singleNumber(nums));

    nums = { 4,1,2,1,2 };
    check.checkInt(4, o.singleNumber(nums));

    nums = { 0 };
    check.checkInt(0, o.singleNumber(nums));

    nums = { 5 };
    check.checkInt(5, o.singleNumber(nums));
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
