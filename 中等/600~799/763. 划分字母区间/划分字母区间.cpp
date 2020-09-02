/* 划分字母区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 

提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int end = -1, size = S.size(), lastIndex['z' + 1];
        getLastIndex(S, lastIndex);

        vector<int> partLens;
        while (end != size - 1) {
            end = partition(S, end + 1, lastIndex, partLens);
        }

        return partLens;
    }

    void getLastIndex(string& s, int* lastIndex) {
        for (int i = 0; i < (int)s.size(); i++) {
            lastIndex[s[i]] = i;
        }
    }

    // 贪心算法，最后一个s[start]一定要和s[start]划分在一组，然后扫描这一组内，其它字符的最后位置，从而决定这一组的区间是否要扩大
    int partition(string& s, int start, int* lastIndex, vector<int>& partLens) {
        int i, end = lastIndex[s[start]];

        for (i = start; i < end; i++) {
            if (lastIndex[s[i]] > end) {
                end = lastIndex[s[i]];
            }
        }

        partLens.push_back(end - start + 1);

        return end;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.partitionLabels("ababcbacadefegdehijhklij");
    vector<int> expected = { 9,7,8 };
    check.checkIntVector(expected, actual);

    actual = o.partitionLabels("a");
    expected = { 1 };
    check.checkIntVector(expected, actual);

    actual = o.partitionLabels("aa");
    expected = { 2 };
    check.checkIntVector(expected, actual);

    actual = o.partitionLabels("ab");
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    actual = o.partitionLabels("eccbbbbdec");
    expected = { 10 };
    check.checkIntVector(expected, actual);

    actual = o.partitionLabels("abcdacfg");
    expected = { 6,1,1 };
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
