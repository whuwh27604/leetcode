/* 统计位数为偶数的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。

 

示例 1：

输入：nums = [12,345,2,6,7896]
输出：2
解释：
12 是 2 位数字（位数为偶数） 
345 是 3 位数字（位数为奇数）  
2 是 1 位数字（位数为奇数） 
6 是 1 位数字 位数为奇数） 
7896 是 4 位数字（位数为偶数）  
因此只有 12 和 7896 是位数为偶数的数字
示例 2：

输入：nums = [555,901,482,1771]
输出：1
解释：
只有 1771 是位数为偶数的数字。
 

提示：

1 <= nums.length <= 500
1 <= nums[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for (int num : nums) {
            if (((num >= 10) && (num <= 99)) || ((num >= 1000) && (num <= 9999)) || (num == 100000)) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 12,345,2,6,7896 };
    check.checkInt(2, o.findNumbers(nums));

    nums = { 555,901,482,1771 };
    check.checkInt(1, o.findNumbers(nums));

    nums = { 1,9,10,99,100,999,1000,9999,10000,99999,100000 };
    check.checkInt(5, o.findNumbers(nums));
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
