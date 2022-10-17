/* 反转之后不同整数的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 正 整数组成的数组 nums 。

你必须取出数组中的每个整数，反转其中每个数位，并将反转后得到的数字添加到数组的末尾。这一操作只针对 nums 中原有的整数执行。

返回结果数组中 不同 整数的数目。

 

示例 1：

输入：nums = [1,13,10,12,31]
输出：6
解释：反转每个数字后，结果数组是 [1,13,10,12,31,1,31,1,21,13] 。
反转后得到的数字添加到数组的末尾并按斜体加粗表示。注意对于整数 10 ，反转之后会变成 01 ，即 1 。
数组中不同整数的数目为 6（数字 1、10、12、13、21 和 31）。
示例 2：

输入：nums = [2,2,2]
输出：1
解释：反转每个数字后，结果数组是 [2,2,2,2,2,2] 。
数组中不同整数的数目为 1（数字 2）。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-number-of-distinct-integers-after-reverse-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int num : nums) {
            numbers.insert(num);
            int reverse = 0;

            while (num != 0) {
                reverse = reverse * 10 + num % 10;
                num /= 10;
            }

            numbers.insert(reverse);
        }

        return numbers.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,13,10,12,31 };
    check.checkInt(6, o.countDistinctIntegers(nums));

    nums = { 2,2,2 };
    check.checkInt(1, o.countDistinctIntegers(nums));
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
