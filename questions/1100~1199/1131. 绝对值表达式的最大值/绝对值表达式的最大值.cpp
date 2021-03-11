/* 绝对值表达式的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度相等的整数数组，返回下面表达式的最大值：

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

其中下标 i，j 满足 0 <= i, j < arr1.length。

 

示例 1：

输入：arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
输出：13
示例 2：

输入：arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
输出：20
 

提示：

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-of-absolute-value-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int minA = INT_MAX, maxA = INT_MIN, minB = INT_MAX, maxB = INT_MIN, minC = INT_MAX, maxC = INT_MIN, minD = INT_MAX, maxD = INT_MIN;

        for (int i = 0; i < (int)arr1.size(); ++i) {
            minA = min(minA, arr1[i] + arr2[i] + i);
            maxA = max(maxA, arr1[i] + arr2[i] + i);
            minB = min(minB, arr1[i] - arr2[i] + i);
            maxB = max(maxB, arr1[i] - arr2[i] + i);
            minC = min(minC, -arr1[i] + arr2[i] + i);
            maxC = max(maxC, -arr1[i] + arr2[i] + i);
            minD = min(minD, -arr1[i] - arr2[i] + i);
            maxD = max(maxD, -arr1[i] - arr2[i] + i);
        }

        return max({ maxA - minA, maxB - minB, maxC - minC, maxD - minD });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr1 = { 1,2,3,4 };
    vector<int> arr2 = { -1,4,5,6 };
    check.checkInt(13, o.maxAbsValExpr(arr1, arr2));

    arr1 = { 1,-2,-5,0,10 };
    arr2 = { 0,-2,-1,-7,-4 };
    check.checkInt(20, o.maxAbsValExpr(arr1, arr2));

    arr1 = { 2,2,6,1,-7,-1,-7 };
    arr2 = { 6,1,-2,-10,-7,-6,-10 };
    check.checkInt(31, o.maxAbsValExpr(arr1, arr2));

    arr1 = { 1,-2 };
    arr2 = { 8,8 };
    check.checkInt(4, o.maxAbsValExpr(arr1, arr2));

    arr1 = { 10,5,2,-1,5,1 };
    arr2 = { -5,-4,2,9,-8,-5 };
    check.checkInt(28, o.maxAbsValExpr(arr1, arr2));
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
