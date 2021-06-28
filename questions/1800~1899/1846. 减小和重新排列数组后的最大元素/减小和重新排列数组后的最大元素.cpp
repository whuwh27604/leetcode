/* 减小和重新排列数组后的最大元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 arr 。请你对 arr 执行一些操作（也可以不进行任何操作），使得数组满足以下条件：

arr 中 第一个 元素必须为 1 。
任意相邻两个元素的差的绝对值 小于等于 1 ，也就是说，对于任意的 1 <= i < arr.length （数组下标从 0 开始），都满足 abs(arr[i] - arr[i - 1]) <= 1 。abs(x) 为 x 的绝对值。
你可以执行以下 2 种操作任意次：

减小 arr 中任意元素的值，使其变为一个 更小的正整数 。
重新排列 arr 中的元素，你可以以任意顺序重新排列。
请你返回执行以上操作后，在满足前文所述的条件下，arr 中可能的 最大值 。

 

示例 1：

输入：arr = [2,2,1,2,1]
输出：2
解释：
我们可以重新排列 arr 得到 [1,2,2,2,1] ，该数组满足所有条件。
arr 中最大元素为 2 。
示例 2：

输入：arr = [100,1,1000]
输出：3
解释：
一个可行的方案如下：
1. 重新排列 arr 得到 [1,100,1000] 。
2. 将第二个元素减小为 2 。
3. 将第三个元素减小为 3 。
现在 arr = [1,2,3] ，满足所有条件。
arr 中最大元素为 3 。
示例 3：

输入：arr = [1,2,3,4,5]
输出：5
解释：数组已经满足所有条件，最大元素为 5 。
 

提示：

1 <= arr.length <= 105
1 <= arr[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int wanted = 0;

        sort(arr.begin(), arr.end());

        for (int num : arr) {
            if (num > wanted + 1) {
                wanted += 1;
            }
            else {
                wanted = num;
            }
        }

        return wanted;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 2,2,1,2,1 };
    check.checkInt(2, o.maximumElementAfterDecrementingAndRearranging(arr));

    arr = { 100,1,1000 };
    check.checkInt(3, o.maximumElementAfterDecrementingAndRearranging(arr));

    arr = { 1,2,3,4,5 };
    check.checkInt(5, o.maximumElementAfterDecrementingAndRearranging(arr));
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
