/* 缺失数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // a^a^b=0^b=b
        int miss = nums.size();
        for (int i = 0; i < (int)nums.size(); i++) {
            miss ^= i;
            miss ^= nums[i];
        }

        return miss;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,0,1 };
    check.checkInt(2, o.missingNumber(nums));

    nums = { 9,6,4,2,3,5,7,0,1 };
    check.checkInt(8, o.missingNumber(nums));

    nums = { 1,2 };
    check.checkInt(0, o.missingNumber(nums));

    nums = { 0,1,2 };
    check.checkInt(3, o.missingNumber(nums));
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
