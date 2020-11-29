/* 第三大的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

示例 1:

输入: [3, 2, 1]

输出: 1

解释: 第三大的数是 1.
示例 2:

输入: [1, 2]

输出: 2

解释: 第三大的数不存在, 所以返回最大的数 2 .
示例 3:

输入: [2, 2, 3, 1]

输出: 1

解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/third-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = 0;
        int second = 0;
        int third = 0;
        int count = 0;

        for (unsigned int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if ((num > first) || (count == 0)) {
                third = second;
                second = first;
                first = num;
                count++;
                continue;
            }

            if (num == first) {
                continue;
            }

            if ((num > second) || (count == 1)) {
                third = second;
                second = num;
                count++;
            }

            if (num == second) {
                continue;
            }

            if ((num > third) || (count == 2)) {
                third = num;
                count++;
            }
        }

        if (count < 3) {
            return first;
        }
        return third;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,2,1 };
    check.checkInt(1, o.thirdMax(nums));

    nums = { 2,1 };
    check.checkInt(2, o.thirdMax(nums));

    nums = { 2,2,3,1 };
    check.checkInt(1, o.thirdMax(nums));

    nums = { 5 };
    check.checkInt(5, o.thirdMax(nums));

    nums = { 5,5,5 };
    check.checkInt(5, o.thirdMax(nums));

    nums = { 5,4,5,4,5,4,5,4,5,4,5,4 };
    check.checkInt(5, o.thirdMax(nums));

    nums = { 10,9,8,7,6,5,4,3,2,1,0 };
    check.checkInt(8, o.thirdMax(nums));

    nums = { 5,5,5,4,4,4,3,3,3,5,4,3,2,2,1,1 };
    check.checkInt(3, o.thirdMax(nums));

    nums = { -3,-2,-1 };
    check.checkInt(-3, o.thirdMax(nums));

    nums = { -5,0,5 };
    check.checkInt(-5, o.thirdMax(nums));

    nums = { 5,0,-5 };
    check.checkInt(-5, o.thirdMax(nums));

    nums = { 1,2,-2147483648 };
    check.checkInt(-2147483648, o.thirdMax(nums));
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
