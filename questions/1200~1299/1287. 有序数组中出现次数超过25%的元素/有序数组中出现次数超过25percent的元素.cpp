/* 有序数组中出现次数超过25percent的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

请你找到并返回这个整数

 

示例：

输入：arr = [1,2,2,6,6,6,6,7,10]
输出：6
 

提示：

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i, len = arr.size(), span = len / 4 + 1;

        // 在序列arr[0] arr[span] arr[span*2]...arr[span*n]中一定有一个是答案
        for (i = 0; i < len; i += span) {
            auto l = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto u = upper_bound(arr.begin(), arr.end(), arr[i]);
            if ((u - l) >= span) {
                return arr[i];
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { 1,2,2,6,6,6,6,7,10 };
    check.checkInt(6, o.findSpecialInteger(arr));

    arr = { 1 };
    check.checkInt(1, o.findSpecialInteger(arr));

    arr = { 1,2 };
    check.checkInt(1, o.findSpecialInteger(arr));

    arr = { 1,2,3 };
    check.checkInt(1, o.findSpecialInteger(arr));

    arr = { 1,2,3,4 };
    check.checkInt(-1, o.findSpecialInteger(arr));

    arr = { 1,1,2,3 };
    check.checkInt(1, o.findSpecialInteger(arr));

    arr = { 1,2,2,3 };
    check.checkInt(2, o.findSpecialInteger(arr));

    arr = { 1,2,3,3 };
    check.checkInt(3, o.findSpecialInteger(arr));
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
