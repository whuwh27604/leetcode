/* 分隔数组以得到最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr，请你将该数组分隔为长度最多为 k 的一些（连续）子数组。分隔完成后，每个子数组的中的所有值都会变为该子数组中的最大值。

返回将数组分隔变换后能够得到的元素最大和。

 

注意，原数组和分隔后的数组对应顺序应当一致，也就是说，你只能选择分隔数组的位置而不能调整数组中的顺序。

 

示例 1：

输入：arr = [1,15,7,9,2,5,10], k = 3
输出：84
解释：
因为 k=3 可以分隔成 [1,15,7] [9] [2,5,10]，结果为 [15,15,15,9,10,10,10]，和为 84，是该数组所有分隔变换后元素总和最大的。
若是分隔成 [1] [15,7,9] [2,5,10]，结果就是 [1, 15, 15, 15, 10, 10, 10] 但这种分隔方式的元素总和（76）小于上一种。
示例 2：

输入：arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
输出：83
示例 3：

输入：arr = [1], k = 1
输出：1
 

提示：

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-for-maximum-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int i, j, size = arr.size(), maxNum = 0;
        vector<int> dp(size + 1, 0);  // dp[i]表示arr[i,size-1]能够取得的maxSum

        for (i = size - 1; i >= size - k; --i) {
            maxNum = max(maxNum, arr[i]);
            dp[i] = (size - i) * maxNum;
        }

        for (; i >= 0; --i) {
            maxNum = 0;

            for (j = 0; j < k; ++j) {
                maxNum = max(maxNum, arr[i + j]);
                int sum = (j + 1) * maxNum + dp[i + j + 1];
                dp[i] = max(dp[i], sum);
            }
        }

        return dp[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,15,7,9,2,5,10 };
    check.checkInt(84, o.maxSumAfterPartitioning(arr, 3));

    arr = { 1,4,1,5,7,3,6,1,9,9,3 };
    check.checkInt(83, o.maxSumAfterPartitioning(arr, 4));

    arr = { 1 };
    check.checkInt(1, o.maxSumAfterPartitioning(arr, 1));
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
