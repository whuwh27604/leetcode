/* 山脉数组中查找目标值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
（这是一个 交互式问题 ）

给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

如果不存在这样的下标 index，就请返回 -1。

 

何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：

首先，A.length >= 3

其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
 

你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
MountainArray.length() - 会返回该数组的长度
 

注意：

对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。

为了帮助大家更好地理解交互式问题，我们准备了一个样例 “答案”：https://leetcode-cn.com/playground/RKhe3ave，请注意这 不是一个正确答案。

 

示例 1：

输入：array = [1,2,3,4,5,3,1], target = 3
输出：2
解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。
示例 2：

输入：array = [0,1,2,4,2,1], target = 3
输出：-1
解释：3 在数组中没有出现，返回 -1。
 

提示：

3 <= mountain_arr.length() <= 10000
0 <= target <= 10^9
0 <= mountain_arr.get(index) <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-in-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/MountainArray.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int peak = findPeak(mountainArr), index = findLeftTarget(peak, target, mountainArr);

        if (index != -1) {
            return index;
        }

        return findRightTarget(peak, target, mountainArr);
    }

    int findPeak(MountainArray& mountainArr) {
        int left = 0, right = mountainArr.length() - 1, middle = 0, A1, A2, A3;

        do {
            middle = (left + right) / 2;
            A1 = mountainArr.get(middle - 1), A2 = mountainArr.get(middle), A3 = mountainArr.get(middle + 1);

            if (A1 < A2 && A2 < A3) {
                left = middle;
            }
            else {
                right = middle;
            }
        } while (A1 > A2 || A3 > A2);

        return middle;
    }

    int findLeftTarget(int peak, int target, MountainArray& mountainArr) {
        int left = 0, right = peak;

        while (left <= right) {
            int middle = (left + right) / 2, A = mountainArr.get(middle);

            if (A == target) {
                return middle;
            }
            else if (A < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        return -1;
    }

    int findRightTarget(int peak, int target, MountainArray& mountainArr) {
        int left = peak, right = mountainArr.length() - 1, index = -1;

        while (left <= right) {
            int middle = (left + right) / 2, A = mountainArr.get(middle);

            if (A == target) {
                return middle;
            }
            else if (A < target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5,3,1 };
    MountainArray mountainArr1(nums);
    check.checkInt(2, o.findInMountainArray(3, mountainArr1));

    nums = { 0,1,2,4,2,1 };
    MountainArray mountainArr2(nums);
    check.checkInt(-1, o.findInMountainArray(3, mountainArr2));

    nums = { 0,4,2 };
    MountainArray mountainArr3(nums);
    check.checkInt(1, o.findInMountainArray(4, mountainArr3));

    nums = { 0,4,2,1 };
    MountainArray mountainArr4(nums);
    check.checkInt(3, o.findInMountainArray(1, mountainArr4));

    nums = { 0,2,4,1 };
    MountainArray mountainArr5(nums);
    check.checkInt(0, o.findInMountainArray(0, mountainArr5));

    nums = { 0,4,2 };
    MountainArray mountainArr6(nums);
    check.checkInt(0, o.findInMountainArray(0, mountainArr6));

    nums = { 0,4,2 };
    MountainArray mountainArr7(nums);
    check.checkInt(2, o.findInMountainArray(2, mountainArr7));
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
