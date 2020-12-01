/* 顺次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 1 的整数。

请你返回由 [low, high] 范围内所有顺次数组成的 有序 列表（从小到大排序）。

 

示例 1：

输出：low = 100, high = 300
输出：[123,234]
示例 2：

输出：low = 1000, high = 13000
输出：[1234,2345,3456,4567,5678,6789,12345]
 

提示：

10 <= low <= high <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sequential-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> sequentialNums;
        vector<int> allSequentialNums = { 12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,
            12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789 };

        for (int num : allSequentialNums) {
            if (num >= low && num <= high) {
                sequentialNums.push_back(num);
            }
        }

        return sequentialNums;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.sequentialDigits(100, 300);
    vector<int> expected = { 123,234 };
    check.checkIntVector(expected, actual);

    actual = o.sequentialDigits(1000, 13000);
    expected = { 1234,2345,3456,4567,5678,6789,12345 };
    check.checkIntVector(expected, actual);

    actual = o.sequentialDigits(123, 789);
    expected = { 123,234,345,456,567,678,789 };
    check.checkIntVector(expected, actual);

    actual = o.sequentialDigits(10, 10);
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.sequentialDigits(23, 23);
    expected = { 23 };
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
