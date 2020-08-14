/* 下一个更大元素 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，并且其值大于n。如果不存在这样的32位整数，则返回-1。

示例 1:

输入: 12
输出: 21
示例 2:

输入: 21
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <sstream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int size = s.size(), decreasingI, decreasingJ;

        for (decreasingI = size - 2; decreasingI >= 0; decreasingI--) {
            if (s[decreasingI] < s[decreasingI + 1]) {  // 找到从右到左第一个降序
                break;
            }
        }

        if (decreasingI < 0) {
            return -1;
        }

        decreasingJ = decreasingI + 1;
        for (int i = decreasingI + 2; i < size; i++) {  // 找到比s[decreasingI]大的最小的数
            if (s[i] <= s[decreasingI]) {
                continue;
            }

            if (s[i] < s[decreasingJ]) {
                decreasingJ = i;
            }
        }

        swap(s[decreasingI], s[decreasingJ]);
        sort(s.begin() + decreasingI + 1, s.end());

        stringstream ss;
        ss << s;
        long long greaterNum;
        ss >> greaterNum;

        return (greaterNum > INT_MAX) ? -1 : (int)greaterNum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(-1, o.nextGreaterElement(1));
    check.checkInt(-1, o.nextGreaterElement(9));
    check.checkInt(-1, o.nextGreaterElement(10));
    check.checkInt(-1, o.nextGreaterElement(11));
    check.checkInt(21, o.nextGreaterElement(12));
    check.checkInt(-1, o.nextGreaterElement(21));
    check.checkInt(158513467, o.nextGreaterElement(158476531));
    check.checkInt(-1, o.nextGreaterElement(2147483647));
    check.checkInt(2303124, o.nextGreaterElement(2302431));
    check.checkInt(-1, o.nextGreaterElement(1999999999));
    check.checkInt(230412, o.nextGreaterElement(230241));
    check.checkInt(13222344, o.nextGreaterElement(12443322));
    check.checkInt(2000001, o.nextGreaterElement(1200000));
    check.checkInt(13122, o.nextGreaterElement(12321));
    check.checkInt(125138, o.nextGreaterElement(123851));
    check.checkInt(213456789, o.nextGreaterElement(198765432));
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
