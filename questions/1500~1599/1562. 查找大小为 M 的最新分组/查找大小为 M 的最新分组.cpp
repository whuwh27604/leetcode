/* 查找大小为 M 的最新分组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 arr ，该数组表示一个从 1 到 n 的数字排列。有一个长度为 n 的二进制字符串，该字符串上的所有位最初都设置为 0 。

在从 1 到 n 的每个步骤 i 中（假设二进制字符串和 arr 都是从 1 开始索引的情况下），二进制字符串上位于位置 arr[i] 的位将会设为 1 。

给你一个整数 m ，请你找出二进制字符串上存在长度为 m 的一组 1 的最后步骤。一组 1 是一个连续的、由 1 组成的子串，且左右两边不再有可以延伸的 1 。

返回存在长度 恰好 为 m 的 一组 1  的最后步骤。如果不存在这样的步骤，请返回 -1 。

 

示例 1：

输入：arr = [3,5,1,2,4], m = 1
输出：4
解释：
步骤 1："00100"，由 1 构成的组：["1"]
步骤 2："00101"，由 1 构成的组：["1", "1"]
步骤 3："10101"，由 1 构成的组：["1", "1", "1"]
步骤 4："11101"，由 1 构成的组：["111", "1"]
步骤 5："11111"，由 1 构成的组：["11111"]
存在长度为 1 的一组 1 的最后步骤是步骤 4 。
示例 2：

输入：arr = [3,1,5,4,2], m = 2
输出：-1
解释：
步骤 1："00100"，由 1 构成的组：["1"]
步骤 2："10100"，由 1 构成的组：["1", "1"]
步骤 3："10101"，由 1 构成的组：["1", "1", "1"]
步骤 4："10111"，由 1 构成的组：["1", "111"]
步骤 5："11111"，由 1 构成的组：["11111"]
不管是哪一步骤都无法形成长度为 2 的一组 1 。
示例 3：

输入：arr = [1], m = 1
输出：1
示例 4：

输入：arr = [2,1], m = 2
输出：2
 

提示：

n == arr.length
1 <= n <= 10^5
1 <= arr[i] <= n
arr 中的所有整数 互不相同
1 <= m <= arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-latest-group-of-size-m
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int i, size = arr.size(), lenMIntervals = 0, steps = -1;
        vector<int> leftEndPoints(size + 1, -1), rightEndPoints(size + 1, -1);

        for (i = 0; i < size; ++i) {
            int leftEndPoint = arr[i], rightEndPoint = leftEndPoint;

            if (leftEndPoint != 1 && leftEndPoints[leftEndPoint - 1] != -1) {
                if (leftEndPoint - leftEndPoints[leftEndPoint - 1] == m) {
                    --lenMIntervals;
                }
                leftEndPoint = leftEndPoints[leftEndPoint - 1];
            }

            if (rightEndPoint != size && rightEndPoints[rightEndPoint + 1] != -1) {
                if (rightEndPoints[rightEndPoint + 1] - rightEndPoint == m) {
                    --lenMIntervals;
                }
                rightEndPoint = rightEndPoints[rightEndPoint + 1];
            }

            leftEndPoints[rightEndPoint] = leftEndPoint;
            rightEndPoints[leftEndPoint] = rightEndPoint;

            if (rightEndPoint - leftEndPoint + 1 == m) {
                ++lenMIntervals;
            }

            if (lenMIntervals != 0) {
                steps = i + 1;
            }
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 3,5,1,2,4 };
    check.checkInt(4, o.findLatestStep(arr, 1));

    arr = { 3,1,5,4,2 };
    check.checkInt(-1, o.findLatestStep(arr, 2));

    arr = { 1 };
    check.checkInt(1, o.findLatestStep(arr, 1));

    arr = { 2,1 };
    check.checkInt(2, o.findLatestStep(arr, 2));

    arr = { 3,1,2 };
    check.checkInt(2, o.findLatestStep(arr, 1));

    arr = { 4,3,2,1 };
    check.checkInt(1, o.findLatestStep(arr, 1));
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
