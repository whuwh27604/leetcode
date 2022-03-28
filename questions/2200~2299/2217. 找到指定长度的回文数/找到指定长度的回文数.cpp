/* 找到指定长度的回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 queries 和一个 正 整数 intLength ，请你返回一个数组 answer ，其中 answer[i] 是长度为 intLength 的 正回文数 中第 queries[i] 小的数字，如果不存在这样的回文数，则为 -1 。

回文数 指的是从前往后和从后往前读一模一样的数字。回文数不能有前导 0 。

 

示例 1：

输入：queries = [1,2,3,4,5,90], intLength = 3
输出：[101,111,121,131,141,999]
解释：
长度为 3 的最小回文数依次是：
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 201, ...
第 90 个长度为 3 的回文数是 999 。
示例 2：

输入：queries = [2,4,6], intLength = 4
输出：[1111,1331,1551]
解释：
长度为 4 的前 6 个回文数是：
1001, 1111, 1221, 1331, 1441 和 1551 。
 

提示：

1 <= queries.length <= 5 * 104
1 <= queries[i] <= 109
1 <= intLength <= 15

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-palindrome-with-fixed-length
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        return ((intLength % 2) == 0) ? evenPalindrome(queries, intLength) : oddPalindrome(queries, intLength);
    }

    vector<long long> oddPalindrome(vector<int>& queries, int intLength) {
        int i, size = queries.size(), len = intLength / 2;
        int base = (len == 0 ? 0 : (int)pow(10, len - 1)), maxK = (len == 0 ? 9 : ((int)pow(10, len) - base) * 10);
        vector<long long> ans(size);

        for (i = 0; i < size; ++i) {
            int k = queries[i];

            if (k <= maxK) {
                int half1 = base + (k - 1) / 10, middle = (len == 0 ? k : (k - 1) % 10), half2 = reverseNum(half1);
                ans[i] = half1 * (long long)pow(10, len + 1) + middle * (long long)pow(10, len) + half2;
            }
            else {
                ans[i] = -1;
            }
        }

        return ans;
    }

    vector<long long> evenPalindrome(vector<int>& queries, int intLength) {
        int i, size = queries.size(), len = intLength / 2, base = (int)pow(10, len - 1), maxK = (int)pow(10, len) - base;
        vector<long long> ans(size);

        for (i = 0; i < size; ++i) {
            int k = queries[i];

            if (k <= maxK) {
                int half1 = base + k - 1, half2 = reverseNum(half1);
                ans[i] = half1 * (long long)pow(10, len) + half2;
            }
            else {
                ans[i] = -1;
            }
        }

        return ans;
    }

    int reverseNum(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());

        return stoi(s);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> queries = { 1,2,3,4,5,10,11,90,91 };
    vector<long long> actual = o.kthPalindrome(queries, 3);
    vector<long long> expected = { 101,111,121,131,141,191,202,999,-1 };
    check.checkLongLongVector(expected, actual);

    queries = { 2,4,6,10,11,90,91 };
    actual = o.kthPalindrome(queries, 4);
    expected = { 1111,1331,1551,1991,2002,9999,-1 };
    check.checkLongLongVector(expected, actual);

    queries = { 1,2,9,10 };
    actual = o.kthPalindrome(queries, 1);
    expected = { 1,2,9,-1 };
    check.checkLongLongVector(expected, actual);

    queries = { 1,2,9,10 };
    actual = o.kthPalindrome(queries, 2);
    expected = { 11,22,99,-1 };
    check.checkLongLongVector(expected, actual);
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
