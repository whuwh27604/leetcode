/* 特殊等价字符串组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你将得到一个字符串数组 A。

如果经过任意次数的移动，S == T，那么两个字符串 S 和 T 是特殊等价的。

一次移动包括选择两个索引 i 和 j，且 i ％ 2 == j ％ 2，交换 S[j] 和 S [i]。

现在规定，A 中的特殊等价字符串组是 A 的非空子集 S，这样不在 S 中的任何字符串与 S 中的任何字符串都不是特殊等价的。

返回 A 中特殊等价字符串组的数量。

 

示例 1：

输入：["a","b","c","a","c","c"]
输出：3
解释：3 组 ["a","a"]，["b"]，["c","c","c"]
示例 2：

输入：["aa","bb","ab","ba"]
输出：4
解释：4 组 ["aa"]，["bb"]，["ab"]，["ba"]
示例 3：

输入：["abc","acb","bac","bca","cab","cba"]
输出：3
解释：3 组 ["abc","cba"]，["acb","bca"]，["bac","cab"]
示例 4：

输入：["abcd","cdab","adcb","cbad"]
输出：1
解释：1 组 ["abcd","cdab","adcb","cbad"]
 

提示：

1 <= A.length <= 1000
1 <= A[i].length <= 20
所有 A[i] 都具有相同的长度。
所有 A[i] 都只由小写字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/groups-of-special-equivalent-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> stringValue;

        for (unsigned int i = 0; i < A.size(); i++) {
            string value = hashString(A[i]);
            stringValue.insert(value);
        }

        return stringValue.size();
    }

    string hashString(string s) {
        int i, len = s.size(), charactor[52] = { 0 };

        for (i = 0; i < len; i++) {
            if (i % 2 == 0) {
                charactor[s[i] - 'a']++;
            }
            else {
                charactor[s[i] - 'a' + 26]++;
            }
        }

        string value;
        for (i = 0; i < 52; i++) {
            if (charactor[i] != 0) {
                value += ('a' + i % 26);
                value += to_string(charactor[i]);
            }
        }

        return value;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> A = { "a","b","c","a","c","c" };
    check.checkInt(3, o.numSpecialEquivGroups(A));

    A = { "aa","bb","ab","ba" };
    check.checkInt(4, o.numSpecialEquivGroups(A));

    A = { "abc","acb","bac","bca","cab","cba" };
    check.checkInt(3, o.numSpecialEquivGroups(A));

    A = { "abcd","cdab","adcb","cbad" };
    check.checkInt(1, o.numSpecialEquivGroups(A));

    A = { "abcd" };
    check.checkInt(1, o.numSpecialEquivGroups(A));

    A = { "a" };
    check.checkInt(1, o.numSpecialEquivGroups(A));
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
