/* 递增的三元子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。

数学表达式如下:

如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

示例 1:

输入: [1,2,3,4,5]
输出: true
示例 2:

输入: [5,4,3,2,1]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-triplet-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minimum = INT_MAX, secondMin = INT_MAX;

        for (int number : nums) {
            if (number > secondMin) {
                return true;
            }

            if (number > minimum) {
                secondMin = number;
            }
            else {
                // 这里可以直接更新minimum，因为如果下一个数大于secondMin，就找到了3个递增序列。如果下一个数小于secondMin，会立即更新secondMin，所以不会误判。
                minimum = number;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,5,-1,0 };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = {  };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = { 1 };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = { 1,2 };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = { 3,2,1 };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = { 1,2,3 };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { 5,4,3,2,1 };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = { 1,2,3,4,5 };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { 1,5,2,3 };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { 5,6,2,3,4 };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { 5,6,2,6 };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = { 5,6,2,7 };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { 5,8,2,6,7 };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { 5,8,2,9,6,7 };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { 5,8,2,7 };
    check.checkBool(false, o.increasingTriplet(nums));

    nums = { INT_MAX, 2,1,0,1,INT_MAX };
    check.checkBool(true, o.increasingTriplet(nums));

    nums = { INT_MAX, 2,1,INT_MAX,0,INT_MAX,1,INT_MAX };
    check.checkBool(true, o.increasingTriplet(nums));
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
