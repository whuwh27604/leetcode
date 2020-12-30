/* 检查数组对是否可以被 k 整除.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个整数 k ，其中数组长度是偶数，值为 n 。

现在需要把数组恰好分成 n / 2 对，以使每对数字的和都能够被 k 整除。

如果存在这样的分法，请返回 True ；否则，返回 False 。

 

示例 1：

输入：arr = [1,2,3,4,5,10,6,7,8,9], k = 5
输出：true
解释：划分后的数字对为 (1,9),(2,8),(3,7),(4,6) 以及 (5,10) 。
示例 2：

输入：arr = [1,2,3,4,5,6], k = 7
输出：true
解释：划分后的数字对为 (1,6),(2,5) 以及 (3,4) 。
示例 3：

输入：arr = [1,2,3,4,5,6], k = 10
输出：false
解释：无法在将数组中的数字分为三对的同时满足每对数字和能够被 10 整除的条件。
示例 4：

输入：arr = [-10,10], k = 2
输出：true
示例 5：

输入：arr = [-1,1,-2,2,-3,3,-4,4], k = 3
输出：true
 

提示：

arr.length == n
1 <= n <= 10^5
n 为偶数
-10^9 <= arr[i] <= 10^9
1 <= k <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-array-pairs-are-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainders(k, 0);
        int left = 1, right = k - 1;

        for (int num : arr) {
            num %= k;

            if (num < 0) {
                num += k;
            }

            ++remainders[num];
        }

        while (left < right) {
            if (remainders[left++] != remainders[right--]) {
                return false;
            }
        }

        return left == right ? (remainders[left] & 1) == 0 : true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2,3,4,5,10,6,7,8,9 };
    check.checkBool(true, o.canArrange(arr, 5));

    arr = { 1,2,3,4,5,6 };
    check.checkBool(true, o.canArrange(arr, 7));

    arr = { 1,2,3,4,5,6 };
    check.checkBool(false, o.canArrange(arr, 10));

    arr = { -10,10 };
    check.checkBool(true, o.canArrange(arr, 2));

    arr = { -1,1,-2,2,-3,3,-4,4 };
    check.checkBool(true, o.canArrange(arr, 3));

    arr = { 0,1 };
    check.checkBool(true, o.canArrange(arr, 1));

    arr = { -1,-2 };
    check.checkBool(true, o.canArrange(arr, 1));

    arr = { 0,4,6,7 };
    check.checkBool(true, o.canArrange(arr, 1));

    arr = { 2,4,6,7 };
    check.checkBool(false, o.canArrange(arr, 2));

    arr = { 2,4,5,7 };
    check.checkBool(true, o.canArrange(arr, 2));

    arr = { 8,6,3,3 };
    check.checkBool(false, o.canArrange(arr, 5));
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
