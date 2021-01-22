/* 增减字符串匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。

返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：

如果 S[i] == "I"，那么 A[i] < A[i+1]
如果 S[i] == "D"，那么 A[i] > A[i+1]
 

示例 1：

输出："IDID"
输出：[0,4,1,3,2]
示例 2：

输出："III"
输出：[0,1,2,3]
示例 3：

输出："DDI"
输出：[3,2,0,1]
 

提示：

1 <= S.length <= 10000
S 只包含字符 "I" 或 "D"。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/di-string-match
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.size();
        vector<int> ans;
        ans.reserve(len + 1);
        int minLeft = 0, maxLeft = len;

        for (int i = 0; i < len; i++) {
            if (S[i] == 'I') {
                ans.push_back(minLeft++);
            }
            else {
                ans.push_back(maxLeft--);
            }
        }

        ans.push_back(maxLeft);
        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string S = "IDID";
    vector<int> actual = o.diStringMatch(S);
    vector<int> expected = { 0,4,1,3,2 };
    check.checkIntVector(expected, actual);

    S = "III";
    actual = o.diStringMatch(S);
    expected = { 0,1,2,3 };
    check.checkIntVector(expected, actual);

    S = "DDI";
    actual = o.diStringMatch(S);
    expected = { 3,2,0,1 };
    check.checkIntVector(expected, actual);

    S = "D";
    actual = o.diStringMatch(S);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);

    S = "I";
    actual = o.diStringMatch(S);
    expected = { 0,1 };
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
