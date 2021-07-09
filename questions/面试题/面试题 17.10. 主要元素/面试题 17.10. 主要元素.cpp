/* 面试题 17.10. 主要元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。

 

示例 1：

输入：[1,2,5,9,5,9,5,5,5]
输出：5
示例 2：

输入：[3,2]
输出：-1
示例 3：

输入：[2,2,1,1,1,2,2]
输出：2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-majority-element-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            }
            else {
                count += (num == candidate ? 1 : -1);
            }
        }

        count = 0;

        for (int num : nums) {
            if (num == candidate) {
                ++count;
            }
        }

        return count > (int)nums.size() / 2 ? candidate : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,5,9,5,9,5,5,5 };
    check.checkInt(5, o.majorityElement(nums));

    nums = { 3,2 };
    check.checkInt(-1, o.majorityElement(nums));

    nums = { 3,2,1 };
    check.checkInt(-1, o.majorityElement(nums));

    nums = { 2,2,1,1,1,2,2 };
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
