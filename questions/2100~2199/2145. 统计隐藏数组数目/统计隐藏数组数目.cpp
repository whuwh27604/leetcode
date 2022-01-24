/* 统计隐藏数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始且长度为 n 的整数数组 differences ，它表示一个长度为 n + 1 的 隐藏 数组 相邻 元素之间的 差值 。更正式的表述为：我们将隐藏数组记作 hidden ，那么 differences[i] = hidden[i + 1] - hidden[i] 。

同时给你两个整数 lower 和 upper ，它们表示隐藏数组中所有数字的值都在 闭 区间 [lower, upper] 之间。

比方说，differences = [1, -3, 4] ，lower = 1 ，upper = 6 ，那么隐藏数组是一个长度为 4 且所有值都在 1 和 6 （包含两者）之间的数组。
[3, 4, 1, 5] 和 [4, 5, 2, 6] 都是符合要求的隐藏数组。
[5, 6, 3, 7] 不符合要求，因为它包含大于 6 的元素。
[1, 2, 3, 4] 不符合要求，因为相邻元素的差值不符合给定数据。
请你返回 符合 要求的隐藏数组的数目。如果没有符合要求的隐藏数组，请返回 0 。

 

示例 1：

输入：differences = [1,-3,4], lower = 1, upper = 6
输出：2
解释：符合要求的隐藏数组为：
- [3, 4, 1, 5]
- [4, 5, 2, 6]
所以返回 2 。
示例 2：

输入：differences = [3,-4,5,1,-2], lower = -4, upper = 5
输出：4
解释：符合要求的隐藏数组为：
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
所以返回 4 。
示例 3：

输入：differences = [4,-7,2], lower = 3, upper = 6
输出：0
解释：没有符合要求的隐藏数组，所以返回 0 。
 

提示：

n == differences.length
1 <= n <= 105
-105 <= differences[i] <= 105
-105 <= lower <= upper <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-the-hidden-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minimum = 0, maximum = 0, sum = 0;

        for (int num : differences) {
            sum += num;
            minimum = min(minimum, sum);
            maximum = max(maximum, sum);
        }

        long long low = lower - minimum, high = upper - maximum;

        return low <= high ? (int)(high - low + 1) : 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> differences = { 1,-3,4 };
    check.checkInt(2, o.numberOfArrays(differences, 1, 6));

    differences = { 3,-4,5,1,-2 };
    check.checkInt(4, o.numberOfArrays(differences, -4, 5));

    differences = { 4,-7,2 };
    check.checkInt(0, o.numberOfArrays(differences, 3, 6));

    differences = { -40 };
    check.checkInt(60, o.numberOfArrays(differences, -46, 53));
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
