/* 分式化简.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？



连分数是形如上图的分式。在本题中，所有系数都是大于等于0的整数。

 

输入的cont代表连分数的系数（cont[0]代表上图的a0，以此类推）。返回一个长度为2的数组[n, m]，使得连分数的值等于n / m，且n, m最大公约数为1。

 

示例 1：

输入：cont = [3, 2, 0, 2]
输出：[13, 4]
解释：原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。
示例 2：

输入：cont = [0, 0, 3]
输出：[3, 1]
解释：如果答案是整数，令分母为1即可。
限制：

cont[i] >= 0
1 <= cont的长度 <= 10
cont最后一个元素不等于0
答案的n, m的取值都能被32位int整型存下（即不超过2 ^ 31 - 1）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/deep-dark-fraction
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int len = cont.size(), i = len - 1;
        long long a, dividend = 1, divisor = cont[i];
        
        while (i != 0) {
            i--;
            a = cont[i];
            dividend = a * divisor + dividend;
            swap(dividend, divisor);
        }

        long long maxFactor = gcd(dividend, divisor);
        return { (int)(divisor / maxFactor), (int)(dividend / maxFactor) };
    }

    long long gcd(long long a, long long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> cont = { 3,2,0,2 };
    vector<int> actual = o.fraction(cont);
    vector<int> expected = { 13,4 };
    check.checkIntVector(expected, actual);

    cont = { 0,0,3 };
    actual = o.fraction(cont);
    expected = { 3,1 };
    check.checkIntVector(expected, actual);

    cont = { 3 };
    actual = o.fraction(cont);
    expected = { 3,1 };
    check.checkIntVector(expected, actual);

    cont = { 3,5 };
    actual = o.fraction(cont);
    expected = { 16,5 };
    check.checkIntVector(expected, actual);

    cont = { 3,5,7,9,13 };
    actual = o.fraction(cont);
    expected = { 13778,4313 };
    check.checkIntVector(expected, actual);

    cont = { 1,0,0,1};
    actual = o.fraction(cont);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    cont = { 2147483647 };
    actual = o.fraction(cont);
    expected = { 2147483647,1 };
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
