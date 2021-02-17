/* 和为零的N个唯一整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。

 

示例 1：

输入：n = 5
输出：[-7,-1,1,3,4]
解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
示例 2：

输入：n = 3
输出：[-1,0,1]
示例 3：

输入：n = 1
输出：[0]
 

提示：

1 <= n <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        if (n == 1) {
            return ans;
        }

        int index = 0;
        while (n > 1) {
            ans[index++] = n;
            ans[index++] = -n;
            n -= 2;
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.sumZero(1);
    vector<int> expected = { 0 };
    check.checkIntVector(expected, actual);

    actual = o.sumZero(2);
    expected = { 2,-2 };
    check.checkIntVector(expected, actual);

    actual = o.sumZero(3);
    expected = { 3,-3,0 };
    check.checkIntVector(expected, actual);

    actual = o.sumZero(4);
    expected = { 4,-4,2,-2 };
    check.checkIntVector(expected, actual);

    actual = o.sumZero(5);
    expected = { 5,-5,3,-3,0 };
    check.checkIntVector(expected, actual);

    actual = o.sumZero(6);
    expected = { 6,-6,4,-4,2,-2 };
    check.checkIntVector(expected, actual);
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
