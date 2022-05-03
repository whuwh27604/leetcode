/* 重新排列日志文件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个日志数组 logs。每条日志都是以空格分隔的字串。

对于每条日志，其第一个字为字母数字标识符。然后，要么：

标识符后面的每个字将仅由小写字母组成，或；
标识符后面的每个字将仅由数字组成。
我们将这两种日志分别称为字母日志和数字日志。保证每个日志在其标识符后面至少有一个字。

将日志重新排序，使得所有字母日志都排在数字日志之前。字母日志按内容字母顺序排序，忽略标识符；在内容相同时，按标识符排序。数字日志应该按原来的顺序排列。

返回日志的最终顺序。

 

示例 ：

输入：["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

提示：

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] 保证有一个标识符，并且标识符后面有一个字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-data-in-log-files
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool pairCompare(const pair<string, string>& p1, const pair<string, string>& p2) {
    return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letterLogs;
        vector<string> digitLogs;
        vector<string> ans;
        string identifier, words;

        for (string& log : logs) {
            if (lettersOrDigits(log, identifier, words) == LETTERS) {
                letterLogs.push_back({ identifier, words });
            }
            else {
                digitLogs.push_back(log);
            }
        }

        sort(letterLogs.begin(), letterLogs.end(), pairCompare);

        for (auto& log : letterLogs) {
            ans.push_back(log.first + " " + log.second);
        }

        ans.insert(ans.end(), digitLogs.begin(), digitLogs.end());

        return ans;
    }

    int lettersOrDigits(string& log, string& identifier, string& words) {
        int index = log.find(' ');

        if (log[index + 1] <= '9') {
            return DIGITS;
        }

        identifier = log.substr(0, index);
        words = log.substr(index + 1, log.size() - index - 1);

        return LETTERS;
    }

    const int LETTERS = 1;
    const int DIGITS = 0;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> logs = { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo" };
    vector<string> actual = o.reorderLogFiles(logs);
    vector<string> expected = { "g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7" };
    check.checkStringVector(expected, actual);

    logs = { "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };
    actual = o.reorderLogFiles(logs);
    expected = { "let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6" };
    check.checkStringVector(expected, actual);

    logs = {  };
    actual = o.reorderLogFiles(logs);
    expected = {  };
    check.checkStringVector(expected, actual);

    logs = { "b act","a act" };
    actual = o.reorderLogFiles(logs);
    expected = { "a act","b act" };
    check.checkStringVector(expected, actual);

    logs = { "   b act","a act" };
    actual = o.reorderLogFiles(logs);
    expected = { "a act","   b act" };
    check.checkStringVector(expected, actual);

    logs = { "a act","a act" };
    actual = o.reorderLogFiles(logs);
    expected = { "a act","a act" };
    check.checkStringVector(expected, actual);

    logs = { "dig1 8 1 5 1","let1 art zero can","dig2 3 6","let2 own kit dig","let3 art zero" };
    actual = o.reorderLogFiles(logs);
    expected = { "let3 art zero","let1 art zero can","let2 own kit dig","dig1 8 1 5 1","dig2 3 6" };
    check.checkStringVector(expected, actual);
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
