/* 最大交换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。
注意:

给定数字的范围是 [0, 108]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        num2Digits(num, digits);

        pair<int, int> swapIndices = findSwapIndices(digits);
        swap(digits[swapIndices.first], digits[swapIndices.second]);

        return digits2Num(digits);
    }

    void num2Digits(int num, vector<int>& digits) {
        if (num == 0) {
            digits.push_back(0);
            return;
        }

        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    int digits2Num(vector<int>& digits) {
        int num = 0, i, size = digits.size();

        for (i = size - 1; i >= 0; i--) {
            num = num * 10 + digits[i];
        }

        return num;
    }

    pair<int, int> findSwapIndices(vector<int>& digits) {
        int i, size = digits.size();
        stack<int> decreasingDigitIndices;
        decreasingDigitIndices.push(size - 1);

        for (i = size - 2; (i >= 0) && (digits[i] <= digits[decreasingDigitIndices.top()]); i--) {  // 找到第一个递增的地方
            decreasingDigitIndices.push(i);
        }

        if (i < 0) {
            return { 0, 0 };  // 全递减数字，没有要交换的
        }

        int swapIndex = i;
        for (; i >= 0; i--) {
            if (digits[i] < digits[decreasingDigitIndices.top()]) {
                continue;  // 栈顶始终保持当前找到的需要交换的最大的digit，小于栈顶的digit直接跳过
            }

            while (!decreasingDigitIndices.empty() && (digits[i] > digits[decreasingDigitIndices.top()])) {  // 注意相等的情况只需要把当前i入栈就可以了，不要更新swapIndex
                swapIndex = max(swapIndex, decreasingDigitIndices.top());  // 找到更靠前的digit则更新索引
                decreasingDigitIndices.pop();  // 栈里面小于digit的数字全部移除
            }

            decreasingDigitIndices.push(i);  // 栈顶放入需要交换的最大的digit
        }

        return { swapIndex, decreasingDigitIndices.top() };
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(7236, o.maximumSwap(2736));
    check.checkInt(9973, o.maximumSwap(9973));
    check.checkInt(98753452, o.maximumSwap(98723455));
    check.checkInt(987531452, o.maximumSwap(987231455));
    check.checkInt(875231452, o.maximumSwap(872231455));
    check.checkInt(52341, o.maximumSwap(12345));
    check.checkInt(0, o.maximumSwap(0));
    check.checkInt(10, o.maximumSwap(10));
    check.checkInt(21, o.maximumSwap(12));
    check.checkInt(90909011, o.maximumSwap(10909091));
    check.checkInt(63454, o.maximumSwap(43456));
    check.checkInt(98863, o.maximumSwap(98368));
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
