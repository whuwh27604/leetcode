/* 最少移动次数使数组元素相等 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 您可以假设数组的长度最多为10000。

例如:

输入:
[1,2,3]

输出:
2

说明：
只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）：

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        /* 排序后为A0,A1,A2...An-3,An-2,An-1，假设最终都移动到x，不难看出，不论x等于几，(A0,An-1)移动的次数为x-A0+An-1-x=An-1-A0
           所以，当n为奇数时，x应该选中间一个数（注意不是平均值），这样中间一个数不用移动，其它(n-1)/2对数移动的次数是固定的；
           当n为偶数时，x选[An/2-1,An/2]之间任意一个数，最终总的移动次数都是一样的。 */
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1, moves = 0;
        while (i < j) {
            moves += (nums[j--] - nums[i++]);
        }

        return moves;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    check.checkInt(2, o.minMoves2(nums));

    nums = {  };
    check.checkInt(0, o.minMoves2(nums));

    nums = { 1 };
    check.checkInt(0, o.minMoves2(nums));

    nums = { 2,7 };
    check.checkInt(5, o.minMoves2(nums));

    nums = { 3,2,7 };
    check.checkInt(5, o.minMoves2(nums));

    nums = { 2,7,4 };
    check.checkInt(5, o.minMoves2(nums));

    nums = { 8,7,6,5,4,5,6,7,8 };
    check.checkInt(10, o.minMoves2(nums));
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
