/* 数字默契考验.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
某数学兴趣小组有 N 位同学，编号为 0 ~ N-1，老师提议举行一个数字默契小测试：首先每位同学想出一个数字，按同学编号存于数组 numbers。每位同学可以选择将自己的数字进行放大操作，每次在以下操作中任选一种（放大操作不限次数，可以不操作）：

将自己的数字乘以 2
将自己的数字乘以 3
若最终所有同学可以通过操作得到相等数字，则返回所有同学的最少操作次数总数；否则请返回 -1。



示例 1：

输入：numbers = [50, 75, 100]
输出：5
解释：
numbers[0] * 2 * 3 = 300 操作两次；
numbers[1] * 2 * 2 = 300 操作两次；
numbers[2] * 3 = 300 操作一次。共计操作五次。
示例 2：

输入：numbers = [10, 14]
输出：-1
解释：无法通过操作得到相同数字。
提示：

1 <= numbers.length <= 10^5
1 <= numbers[i] <= 10^9
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& numbers) {
        int n = numbers.size(), opers = 0;
        vector<int> count2(n, 0), count3(n, 0);
        int base = getBase(0, numbers, count2, count3);

        for (int i = 1; i < n; ++i) {
            if (getBase(i, numbers, count2, count3) != base) {
                return -1;
            }
        }

        int oper2 = *max_element(count2.begin(), count2.end()), oper3 = *max_element(count3.begin(), count3.end());

        for (int i = 0; i < n; ++i) {
            opers += ((oper2 - count2[i]) + (oper3 - count3[i]));
        }

        return opers;
    }

    int getBase(int index, vector<int>& numbers, vector<int>& count2, vector<int>& count3) {
        int num = numbers[index];

        while (num % 2 == 0) {
            ++count2[index];
            num /= 2;
        }

        while (num % 3 == 0) {
            ++count3[index];
            num /= 3;
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> numbers = { 50,75,100 };
    check.checkInt(5, o.minOperations(numbers));

    numbers = { 10,14 };
    check.checkInt(-1, o.minOperations(numbers));

    numbers = { 8 };
    check.checkInt(0, o.minOperations(numbers));
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
