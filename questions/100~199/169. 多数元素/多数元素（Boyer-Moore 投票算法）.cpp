/* 多数元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        for (int num : nums) {
            if (num == candidate) {
                ++count;
            }
            else {
                if (count != 0) {
                    --count;
                }
                else {
                    candidate = num;
                    count = 1;
                }
            }
        }

        return candidate;  // 因为题目确定一定存在众数，所以不用再校验candidate是否超过一半
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,2,3 };
    check.checkInt(3, o.majorityElement(nums));

    nums = { 2,2,1,1,1,2,2 };
    check.checkInt(2, o.majorityElement(nums));

    nums = { 2 };
    check.checkInt(2, o.majorityElement(nums));
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
