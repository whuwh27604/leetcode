/* 三角形的最大周长.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。

如果不能形成任何面积不为零的三角形，返回 0。

 

示例 1：

输入：[2,1,2]
输出：5
示例 2：

输入：[1,2,1]
输出：0
示例 3：

输入：[3,2,3,4]
输出：10
示例 4：

输入：[3,6,2,3]
输出：8
 

提示：

3 <= A.length <= 10000
1 <= A[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-perimeter-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());

        int len = A.size();
        for (int i = 0; i < (len - 2); i++) {
            int c = A[len - 1 - i], b = A[len - 2 - i], a = A[len - 3 - i];
            if (c < (a + b)) {
                return (a + b + c);
            }
        }

        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 2,1,2 };
    check.checkInt(5, o.largestPerimeter(A));

    A = { 1,2,1 };
    check.checkInt(0, o.largestPerimeter(A));

    A = { 3,2,3,4 };
    check.checkInt(10, o.largestPerimeter(A));

    A = { 3,6,2,3 };
    check.checkInt(8, o.largestPerimeter(A));
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
