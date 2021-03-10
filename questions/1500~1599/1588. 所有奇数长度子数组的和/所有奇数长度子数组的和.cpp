/* 所有奇数长度子数组的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。

 

示例 1：

输入：arr = [1,4,2,5,3]
输出：58
解释：所有奇数长度子数组和它们的和为：
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
示例 2：

输入：arr = [1,2]
输出：3
解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
示例 3：

输入：arr = [10,11,12]
输出：66
 

提示：

1 <= arr.length <= 100
1 <= arr[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size(), left = -1, right = size, sum = 0;

        for (int num : arr) {
            ++left, --right;
            int leftOdd = (left + 1) / 2, leftEven = left / 2 + 1;
            int rightOdd = (right + 1) / 2, rightEven = right / 2 + 1;

            // 一个数构成奇数长度子数组的方案有：左边奇数个数，右边奇数个数；或者左边偶数个数，右边偶数个数。
            sum += (leftOdd * rightOdd + leftEven * rightEven) * num;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,4,2,5,3 };
    check.checkInt(58, o.sumOddLengthSubarrays(arr));

    arr = { 1,2 };
    check.checkInt(3, o.sumOddLengthSubarrays(arr));

    arr = { 10,11,12 };
    check.checkInt(66, o.sumOddLengthSubarrays(arr));
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
