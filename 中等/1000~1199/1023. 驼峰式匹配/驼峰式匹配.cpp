/* 驼峰式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果我们可以将小写字母插入模式串 pattern 得到待查询项 query，那么待查询项与给定模式串匹配。（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）

给定待查询列表 queries，和模式串 pattern，返回由布尔值组成的答案列表 answer。只有在待查项 queries[i] 与模式串 pattern 匹配时， answer[i] 才为 true，否则为 false。

 

示例 1：

输入：queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
输出：[true,false,true,true,false]
示例：
"FooBar" 可以这样生成："F" + "oo" + "B" + "ar"。
"FootBall" 可以这样生成："F" + "oot" + "B" + "all".
"FrameBuffer" 可以这样生成："F" + "rame" + "B" + "uffer".
示例 2：

输入：queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
输出：[true,false,true,false,false]
解释：
"FooBar" 可以这样生成："Fo" + "o" + "Ba" + "r".
"FootBall" 可以这样生成："Fo" + "ot" + "Ba" + "ll".
示例 3：

输出：queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
输入：[false,true,false,false,false]
解释：
"FooBarTest" 可以这样生成："Fo" + "o" + "Ba" + "r" + "T" + "est".
 

提示：

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
所有字符串都仅由大写和小写英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/camelcase-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> matchTable;

        for (string& query : queries) {
            matchTable.push_back(isMatch(query, pattern));
        }

        return matchTable;
    }

    bool isMatch(string& query, string& pattern) {
        int i = -1, size = query.size();

        for (char c : pattern) {
            for (i += 1; i < size; ++i) {
                if (query[i] == c) {
                    break;
                }

                if (query[i] >= 'A' && query[i] <= 'Z') {
                    return false;
                }
            }

            if (i >= size) {
                return false;
            }
        }

        for (i += 1; i < size; ++i) {
            if (query[i] >= 'A' && query[i] <= 'Z') {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> queries = { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
    vector<bool> actual = o.camelMatch(queries, "FB");
    vector<bool> expected = { true,false,true,true,false };
    check.checkBoolVector(expected, actual);

    queries = { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
    actual = o.camelMatch(queries, "FoBa");
    expected = { true,false,true,false,false };
    check.checkBoolVector(expected, actual);

    queries = { "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
    actual = o.camelMatch(queries, "FoBaT");
    expected = { false,true,false,false,false };
    check.checkBoolVector(expected, actual);

    queries = { "CompetitiveProgramming", "CounterPick", "Co***olPanel" };
    actual = o.camelMatch(queries, "CooP");
    expected = { false,false,true };
    check.checkBoolVector(expected, actual);

    queries = { "mifeqvzphnrv","mieqxvrvhnrv","mhieqovhnryv","mieqekvhnrpv","miueqrvfhnrv","mieqpvhzntrv","gmimeqvphnrv","mieqvhqyunrv" };
    actual = o.camelMatch(queries, "mieqvhnrv");
    expected = { true,true,true,true,true,true,true,true };
    check.checkBoolVector(expected, actual);

    queries = { "aksvbjLiknuTzqon","ksvjLimflkpnTzqn","mmkasvjLiknTxzqn","ksvjLiurknTzzqbn","ksvsjLctikgnTzqn","knzsvzjLiknTszqn" };
    actual = o.camelMatch(queries, "ksvjLiknTzqn");
    expected = { true,true,true,true,true,true };
    check.checkBoolVector(expected, actual);
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
