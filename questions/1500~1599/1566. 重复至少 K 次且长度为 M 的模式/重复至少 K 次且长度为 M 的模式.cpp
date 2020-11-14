/* 重复至少 K 次且长度为 M 的模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 arr，请你找出一个长度为 m 且在数组中至少重复 k 次的模式。

模式 是由一个或多个值组成的子数组（连续的子序列），连续 重复多次但 不重叠 。 模式由其长度和重复次数定义。

如果数组中存在至少重复 k 次且长度为 m 的模式，则返回 true ，否则返回  false 。

 

示例 1：

输入：arr = [1,2,4,4,4,4], m = 1, k = 3
输出：true
解释：模式 (4) 的长度为 1 ，且连续重复 4 次。注意，模式可以重复 k 次或更多次，但不能少于 k 次。
示例 2：

输入：arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
输出：true
解释：模式 (1,2) 长度为 2 ，且连续重复 2 次。另一个符合题意的模式是 (2,1) ，同样重复 2 次。
示例 3：

输入：arr = [1,2,1,2,1,3], m = 2, k = 3
输出：false
解释：模式 (1,2) 长度为 2 ，但是只连续重复 2 次。不存在长度为 2 且至少重复 3 次的模式。
示例 4：

输入：arr = [1,2,3,1,2], m = 2, k = 2
输出：false
解释：模式 (1,2) 出现 2 次但并不连续，所以不能算作连续重复 2 次。
示例 5：

输入：arr = [2,2,2,2], m = 2, k = 3
输出：false
解释：长度为 2 的模式只有 (2,2) ，但是只连续重复 2 次。注意，不能计算重叠的重复次数。
 

提示：

2 <= arr.length <= 100
1 <= arr[i] <= 100
1 <= m <= 100
2 <= k <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int i, j, size = arr.size(), last = size - m * k, checkLen = m * (k - 1);

        for (i = 0; i <= last; ++i) {
            for (j = i + m; j < i + m + checkLen; ++j) {
                if (arr[j] != arr[j - m]) {
                    break;
                }
            }

            if (j == i + m + checkLen) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2,4,4,4,4 };
    check.checkBool(true, o.containsPattern(arr, 1, 3));

    arr = { 1,2,1,2,1,1,1,3 };
    check.checkBool(true, o.containsPattern(arr, 2, 2));

    arr = { 1,2,1,2,1,3 };
    check.checkBool(false, o.containsPattern(arr, 2, 3));

    arr = { 1,2,3,1,2 };
    check.checkBool(false, o.containsPattern(arr, 2, 2));

    arr = { 2,2,2,2 };
    check.checkBool(false, o.containsPattern(arr, 2, 3));

    arr = { 1,2,3,2,3,2,3 };
    check.checkBool(true, o.containsPattern(arr, 2, 3));

    arr = { 2,3,2,3,2,3 };
    check.checkBool(true, o.containsPattern(arr, 2, 3));

    arr = { 1,5,2,4,2,5,1,4,1,4,5,1,4,1,5,5,3,4,3,2,2 };
    check.checkBool(false, o.containsPattern(arr, 3, 3));

    arr = { 2,2,2,2,2,2 };
    check.checkBool(false, o.containsPattern(arr, 1, 7));
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
