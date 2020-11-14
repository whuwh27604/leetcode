/* 删除一次得到子数组最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。

换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。

请看示例：

示例 1：

输入：arr = [1,-2,0,3]
输出：4
解释：我们可以选出 [1, -2, 0, 3]，然后删掉 -2，这样得到 [1, 0, 3]，和最大。
示例 2：

输入：arr = [1,-2,-2,3]
输出：3
解释：我们直接选出 [3]，这就是最大和。
示例 3：

输入：arr = [-1,-1,-1,-1]
输出：-1
解释：最后得到的子数组不能为空，所以我们不能选择 [-1] 并从中删去 -1 来得到 0。
     我们应该直接选择 [-1]，或者选择 [-1, -1] 再从中删去一个 -1。
 

提示：

1 <= arr.length <= 10^5
-10^4 <= arr[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray-sum-with-one-deletion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int i, size = arr.size();
        if (size == 1) {
            return arr[0];
        }

        int deleteMaxSum = max(arr[0], arr[1]);  // 如果删除一个数，maxSum就是arr[0]和arr[1]之间大的一个
        int noDeleteMaxSum = (arr[0] < 0) ? arr[1] : arr[0] + arr[1];  // 如果不删除数，maxSum就是arr[1]+arr[0]和arr[1]之间大的一个
        int maxSum = max(deleteMaxSum, noDeleteMaxSum);

        for (i = 2; i < size; ++i) {
            // 如果前面没有删除过数，可以选择把arr[i]删掉，maxSum=noDeleteMaxSum；如果已经删过，就只能把arr[i]加上。取两者大的作为删除过数的结果
            deleteMaxSum = max(deleteMaxSum + arr[i], noDeleteMaxSum);
            // 不删除数的最大和，就只能把arr[i]加上。如果前面已经是一个负数了，那么从arr[i]开始重新计算最大和。
            noDeleteMaxSum = max(noDeleteMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, max(deleteMaxSum, noDeleteMaxSum));
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,-3,5,-7,2,-4,6 };
    check.checkInt(9, o.maximumSum(arr));

    arr = { 5 };
    check.checkInt(5, o.maximumSum(arr));

    arr = { -5 };
    check.checkInt(-5, o.maximumSum(arr));

    arr = { -5,3 };
    check.checkInt(3, o.maximumSum(arr));

    arr = { 8,-1,6,-7,-4,5,-4,7,-6 };
    check.checkInt(17, o.maximumSum(arr));

    arr = { 1,-2,0,3 };
    check.checkInt(4, o.maximumSum(arr));

    arr = { 1,-2,-2,3 };
    check.checkInt(3, o.maximumSum(arr));

    arr = { -1,-1,-1,-1 };
    check.checkInt(-1, o.maximumSum(arr));
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
