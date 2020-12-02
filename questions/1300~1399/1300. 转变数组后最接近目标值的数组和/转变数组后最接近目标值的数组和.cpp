/* 转变数组后最接近目标值的数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。

如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

请注意，答案不一定是 arr 中的数字。

 

示例 1：

输入：arr = [4,9,3], target = 10
输出：3
解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
示例 2：

输入：arr = [2,3,5], target = 10
输出：5
示例 3：

输入：arr = [60864,25176,27249,21296,20204], target = 56803
输出：11361
 

提示：

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        int i, size = arr.size(), preSum = 0;

        for (i = 0; i < size; ++i) {
            if (preSum + arr[i] * (size - i) >= target) {
                break;
            }

            preSum += arr[i];
        }

        if (i == size) {
            return arr.back();
        }

        int bestValue = (target - preSum) / (size - i);
        return abs(bestValue * (size - i) + preSum - target) <= abs((bestValue + 1) * (size - i) + preSum - target) ? bestValue : bestValue + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 4,9,3 };
    check.checkInt(3, o.findBestValue(arr, 10));

    arr = { 2,3,5 };
    check.checkInt(5, o.findBestValue(arr, 10));

    arr = { 60864,25176,27249,21296,20204 };
    check.checkInt(11361, o.findBestValue(arr, 56803));

    arr = { 60864,25176,27249,21296,20204 };
    check.checkInt(0, o.findBestValue(arr, 0));

    arr = { 1,2,2 };
    check.checkInt(2, o.findBestValue(arr, 10));

    arr = { 1,1,1 };
    check.checkInt(0, o.findBestValue(arr, 1));

    arr = { 1547,83230,57084,93444,70879 };
    check.checkInt(17422, o.findBestValue(arr, 71237));

    arr = { 40091,2502,74024,53101,60555,33732,23467,40560,32693,13013 };
    check.checkInt(8463, o.findBestValue(arr, 78666));

    arr = { 48772,52931,14253,32289,75263 };
    check.checkInt(8175, o.findBestValue(arr, 40876));
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
