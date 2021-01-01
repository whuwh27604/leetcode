/* 三次操作后最大值与最小值的最小差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums ，每次操作你可以选择 nums 中的任意一个元素并将它改成任意值。

请你返回三次操作后， nums 中最大值与最小值的差的最小值。

 

示例 1：

输入：nums = [5,3,2,4]
输出：0
解释：将数组 [5,3,2,4] 变成 [2,2,2,2].
最大值与最小值的差为 2-2 = 0 。
示例 2：

输入：nums = [1,5,0,10,14]
输出：1
解释：将数组 [1,5,0,10,14] 变成 [1,1,0,1,1] 。
最大值与最小值的差为 1-0 = 1 。
示例 3：

输入：nums = [6,6,0,1,1,4,6]
输出：2
示例 4：

输入：nums = [1,5,6,14,15]
输出：1
 

提示：

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        vector<int> max4(4, INT_MIN), min4(4, INT_MAX);
        getMax4Min4(nums, max4, min4);

        if (max4[3] <= min4[0]) {
            return 0;
        }

        return min({ max4[0] - min4[3], max4[1] - min4[2], max4[2] - min4[1], max4[3] - min4[0] });
    }

    void getMax4Min4(vector<int>& nums, vector<int>& max4, vector<int>& min4) {
        for (int num : nums) {
            if (num > max4[0]) {
                max4[3] = max4[2];
                max4[2] = max4[1];
                max4[1] = max4[0];
                max4[0] = num;
            }
            else if (num > max4[1]) {
                max4[3] = max4[2];
                max4[2] = max4[1];
                max4[1] = num;
            }
            else if (num > max4[2]) {
                max4[3] = max4[2];
                max4[2] = num;
            }
            else if (num > max4[3]) {
                max4[3] = num;
            }

            if (num < min4[0]) {
                min4[3] = min4[2];
                min4[2] = min4[1];
                min4[1] = min4[0];
                min4[0] = num;
            }
            else if (num < min4[1]) {
                min4[3] = min4[2];
                min4[2] = min4[1];
                min4[1] = num;
            }
            else if (num < min4[2]) {
                min4[3] = min4[2];
                min4[2] = num;
            }
            else if (num < min4[3]) {
                min4[3] = num;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,3,2,4 };
    check.checkInt(0, o.minDifference(nums));

    nums = { 1,5,0,10,14 };
    check.checkInt(1, o.minDifference(nums));

    nums = { 6,6,0,1,1,4,6 };
    check.checkInt(2, o.minDifference(nums));

    nums = { 1,5,6,14,15 };
    check.checkInt(1, o.minDifference(nums));
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
