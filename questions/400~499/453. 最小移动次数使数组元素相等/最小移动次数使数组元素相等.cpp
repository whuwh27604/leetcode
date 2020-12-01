/* 最小移动次数使数组元素相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。

示例:

输入:
[1,2,3]

输出:
3

解释:
只需要3次移动（注意每次移动会增加两个元素的值）：

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        /* A1,A2,...,An，假设minimum最小，最后终结在A1=A2=...=An=X，则移动次数等于(X-minimum)。可得方程：
         (X-minimum)*(n-1)=(X-A1)+(X-A2)+...(X-An)，求解X=(A1+A2+...+An)+minimum-minimum*n */
        int n = nums.size();
        long long minimum = INT_MAX;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
            }
            sum += nums[i];
        }

        return (int)(sum - minimum * n);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    check.checkInt(3, o.minMoves(nums));

    nums = { 1,5,7,10 };
    check.checkInt(19, o.minMoves(nums)); 
    
    nums = { 0,2,3 };
    check.checkInt(5, o.minMoves(nums));

    nums = { -3,0,3 };
    check.checkInt(9, o.minMoves(nums));

    nums = { -3,1,3 };
    check.checkInt(10, o.minMoves(nums));

    nums = { -3,-2,-1 };
    check.checkInt(3, o.minMoves(nums));

    nums = { 2147483635,2147483636,2147483637 };
    check.checkInt(3, o.minMoves(nums));
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
