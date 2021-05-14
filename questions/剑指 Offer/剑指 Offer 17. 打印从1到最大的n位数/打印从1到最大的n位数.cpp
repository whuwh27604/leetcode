/* 打印从1到最大的n位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：

用返回一个整数列表来代替打印
n 为正整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int i, size = (int)pow(10, n) - 1;
        vector<int> nums(size);

        for (i = 0; i < size; ++i) {
            nums[i] = i + 1;
        }

        return nums;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.printNumbers(1);
    vector<int> expected = { 1,2,3,4,5,6,7,8,9 };
    check.checkIntVector(expected, actual);

    actual = o.printNumbers(2);
    for (int i = 10; i < 100; ++i) {
        expected.push_back(i);
    }
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
