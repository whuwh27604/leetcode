/* 第 k 个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。

示例 1:

输入: k = 5

输出: 9

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/get-kth-magic-number-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        set<long long> nums = { 1 };

        for (int i = 1; i < k; ++i) {
            long long num = *nums.begin();
            nums.erase(nums.begin());
            nums.insert(num * 3);
            nums.insert(num * 5);
            nums.insert(num * 7);
        }

        return (int)(*nums.begin());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.getKthMagicNumber(1));
    check.checkInt(3, o.getKthMagicNumber(2));
    check.checkInt(5, o.getKthMagicNumber(3));
    check.checkInt(7, o.getKthMagicNumber(4));
    check.checkInt(9, o.getKthMagicNumber(5));
    check.checkInt(15, o.getKthMagicNumber(6));
    check.checkInt(21, o.getKthMagicNumber(7));
    check.checkInt(33075, o.getKthMagicNumber(100));
    check.checkInt(2144153025, o.getKthMagicNumber(652));
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
