/* 字符的最短距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

示例 1:

输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
说明:

字符串 S 的长度范围为 [1, 10000]。
C 是一个单字符，且保证是字符串 S 里的字符。
S 和 C 中的所有字母均为小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-distance-to-a-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int i, j, size = S.size(), prev, distance;
        vector<int> minDistances(size);

        for (i = 0; i < size && S[i] != C; ++i) {}

        prev = i;
        distance = i;

        for (j = 0; j <= i; ++j) {
            minDistances[j] = distance--;
        }

        for (i += 1; i < size; ++i) {
            if (S[i] == C) {
                distance = 1;
                for (j = prev + 1; j <= (i + prev) / 2; ++j) {
                    minDistances[j] = distance++;
                }

                distance = 0;
                for (j = i; j > (i + prev) / 2; --j) {
                    minDistances[j] = distance++;
                }

                prev = i;
            }
        }

        distance = 1;
        for (j = prev + 1; j < size; ++j) {
            minDistances[j] = distance++;
        }

        return minDistances;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string S = "loveleetcode";
    vector<int> actual = o.shortestToChar(S, 'e');
    vector<int> expected = { 3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0 };
    check.checkIntVector(expected, actual);

    S = "a";
    actual = o.shortestToChar(S, 'a');
    expected = { 0 };
    check.checkIntVector(expected, actual);

    S = "abbaccca";
    actual = o.shortestToChar(S, 'a');
    expected = { 0,1,1,0,1,2,1,0 };
    check.checkIntVector(expected, actual);

    S = "bbbbaccccc";
    actual = o.shortestToChar(S, 'a');
    expected = { 4,3,2,1,0,1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    S = "bbbbaccccc";
    actual = o.shortestToChar(S, 'b');
    expected = { 0,0,0,0,1,2,3,4,5,6 };
    check.checkIntVector(expected, actual);

    S = "bbbbaccccc";
    actual = o.shortestToChar(S, 'c');
    expected = { 5,4,3,2,1,0,0,0,0,0 };
    check.checkIntVector(expected, actual);

    S = "abc";
    actual = o.shortestToChar(S, 'c');
    expected = { 2,1,0 };
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
