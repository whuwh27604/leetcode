/* 自除数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
自除数 是指可以被它包含的每一位数除尽的数。

例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。

还有，自除数不允许包含 0 。

给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。

示例 1：

输入：
上边界left = 1, 下边界right = 22
输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
注意：

每个输入参数的边界满足 1 <= left <= right <= 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/self-dividing-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> numbers;
        for (int i = left; i <= right; i++) {
            if (isSelfDivedingNumber(i)) {
                numbers.push_back(i);
            }
        }

        return numbers;
    }

    bool isSelfDivedingNumber(int num) {
        int dividend = num;
        while (dividend != 0) {
            int remainder = (dividend % 10);
            if ((remainder == 0) || ((num % remainder) != 0)) {
                return false;
            }

            dividend /= 10;
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.selfDividingNumbers(1, 22);
    vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22 };
    check.checkIntVector(expected, actual);

    actual = o.selfDividingNumbers(1, 1);
    expected = { 1 };
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
