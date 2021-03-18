/* 和为奇数的子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 。请你返回和为 奇数 的子数组数目。

由于答案可能会很大，请你将结果对 10^9 + 7 取余后返回。

 

示例 1：

输入：arr = [1,3,5]
输出：4
解释：所有的子数组为 [[1],[1,3],[1,3,5],[3],[3,5],[5]] 。
所有子数组的和为 [1,4,9,3,8,5].
奇数和包括 [1,9,3,5] ，所以答案为 4 。
示例 2 ：

输入：arr = [2,4,6]
输出：0
解释：所有子数组为 [[2],[2,4],[2,4,6],[4],[4,6],[6]] 。
所有子数组和为 [2,6,12,4,10,6] 。
所有子数组和都是偶数，所以答案为 0 。
示例 3：

输入：arr = [1,2,3,4,5,6,7]
输出：16
示例 4：

输入：arr = [100,100,99,99]
输出：4
示例 5：

输入：arr = [7]
输出：1
 

提示：

1 <= arr.length <= 10^5
1 <= arr[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-sub-arrays-with-odd-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int dpEven = 0, dpOdd = 0, totalOdd = 0, tmpEven, tmpOdd;

        for (int num : arr) {
            if ((num & 1) == 0) {
                dpEven += 1;
            }
            else {
                tmpEven = dpOdd;
                tmpOdd = dpEven + 1;
                dpEven = tmpEven;
                dpOdd = tmpOdd;
            }

            totalOdd = (totalOdd + dpOdd) % 1000000007;
        }

        return totalOdd;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,3,5 };
    check.checkInt(4, o.numOfSubarrays(arr));

    arr = { 2,4,6 };
    check.checkInt(0, o.numOfSubarrays(arr));

    arr = { 1,2,3,4,5,6,7 };
    check.checkInt(16, o.numOfSubarrays(arr));

    arr = { 100,100,99,99 };
    check.checkInt(4, o.numOfSubarrays(arr));

    arr = { 7 };
    check.checkInt(1, o.numOfSubarrays(arr));
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
