/* K 次串联后最大子数组之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个整数 k。

首先，我们要对该数组进行修改，即把原数组 arr 重复 k 次。

举个例子，如果 arr = [1, 2] 且 k = 3，那么修改后的数组就是 [1, 2, 1, 2, 1, 2]。

然后，请你返回修改后的数组中的最大的子数组之和。

注意，子数组长度可以是 0，在这种情况下它的总和也是 0。

由于 结果可能会很大，所以需要 模（mod） 10^9 + 7 后再返回。 

 

示例 1：

输入：arr = [1,2], k = 3
输出：9
示例 2：

输入：arr = [1,-2,1], k = 5
输出：2
示例 3：

输入：arr = [-1,-2], k = 7
输出：0
 

提示：

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-concatenation-maximum-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        /* 对于数组ABCDE，考虑最大和出现的位置，只可能是以下3种情况：
           1、在数组内部，如BCD，那么无论重复多少次，最大和都是BCD
           2、跨域数组尾部和第二段头部，如DEAB，这种情况在B后面D前面一定有负数隔开，继续重复也没有意义，最大和只能是DEAB了
           3、整个数组和是正数，那么最大和出现在ABCDEAB，这种情况重复的次数越多，最终的和就越大 */
        int size = arr.size(), left = 0, right, start = 0, end = 0, sum = 0, totalSum = 0, maxSum = INT_MIN;

        for (right = 0; right < size * 2; ++right) {
            int index = right % size;
            totalSum += arr[index];

            if (sum < 0) {
                sum = arr[index];
                left = right;
            }
            else {
                sum += arr[index];
            }

            if (sum > maxSum) {
                maxSum = sum;
                start = left;
                end = right;
            }
        }

        totalSum /= 2;
        if (totalSum > 0) {
            return (int)(((long long)totalSum * ((long long)k - 1) + maxSum - totalSum) % 1000000007);
        }

        return maxSum < 0 ? 0 : maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2 };
    check.checkInt(9, o.kConcatenationMaxSum(arr, 3));

    arr = { 1,-2,1 };
    check.checkInt(2, o.kConcatenationMaxSum(arr, 5));

    arr = { -1,-2 };
    check.checkInt(0, o.kConcatenationMaxSum(arr, 7));

    arr = { 3,-2 };
    check.checkInt(7, o.kConcatenationMaxSum(arr, 5));

    arr = { -2 };
    check.checkInt(0, o.kConcatenationMaxSum(arr, 1));

    arr = { 3 };
    check.checkInt(3, o.kConcatenationMaxSum(arr, 1));

    arr = { 3 };
    check.checkInt(12, o.kConcatenationMaxSum(arr, 4));

    arr = { -5,-2,0,0,3,9,-2,-5,4 };
    check.checkInt(20, o.kConcatenationMaxSum(arr, 5));
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
