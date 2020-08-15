/* 有效三角形的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。

示例 1:

输入: [2,2,3,4]
输出: 3
解释:
有效的组合是:
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
注意:

数组长度不超过1000。
数组里整数的范围为 [0, 1000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-triangle-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j, k, size = nums.size(), count = 0;
        while ((i < size) && (nums[i] == 0)) {
            i++;
        }

        for (; i < size; i++) {
            k = i + 2;

            for (j = i + 1; j < size - 1; j++) {
                while ((k < size) && (nums[i] + nums[j] > nums[k])) {
                    k++;
                }

                count += (k - j - 1);
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,2,3,4 };
    check.checkInt(3, o.triangleNumber(nums));

    nums = {  };
    check.checkInt(0, o.triangleNumber(nums));

    nums = { 1 };
    check.checkInt(0, o.triangleNumber(nums));

    nums = { 1,2 };
    check.checkInt(0, o.triangleNumber(nums));

    nums = { 1,2,3 };
    check.checkInt(0, o.triangleNumber(nums));

    nums = { 2,2,3 };
    check.checkInt(1, o.triangleNumber(nums));

    nums = { 0,0,0 };
    check.checkInt(0, o.triangleNumber(nums));

    nums = { 0,1,2 };
    check.checkInt(0, o.triangleNumber(nums));

    nums = { 3,4,5,6,7 };
    check.checkInt(9, o.triangleNumber(nums));

    nums = { 1,2,3,4,5,6 };
    check.checkInt(7, o.triangleNumber(nums));
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
