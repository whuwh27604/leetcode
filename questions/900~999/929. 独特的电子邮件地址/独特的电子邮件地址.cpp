/* 独特的电子邮件地址.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
每封电子邮件都由一个本地名称和一个域名组成，以 @ 符号分隔。

例如，在 alice@leetcode.com中， alice 是本地名称，而 leetcode.com 是域名。

除了小写字母，这些电子邮件还可能包含 '.' 或 '+'。

如果在电子邮件地址的本地名称部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名称中没有点的同一地址。例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。 （请注意，此规则不适用于域名。）

如果在本地名称中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件，例如 m.y+name@email.com 将转发到 my@email.com。 （同样，此规则不适用于域名。）

可以同时使用这两个规则。

给定电子邮件列表 emails，我们会向列表中的每个地址发送一封电子邮件。实际收到邮件的不同地址有多少？

 

示例：

输入：["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
输出：2
解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
 

提示：

1 <= emails[i].length <= 100
1 <= emails.length <= 100
每封 emails[i] 都包含有且仅有一个 '@' 字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-email-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> realAddress;

        for (unsigned int i = 0; i < emails.size(); i++) {
            string oneAddress = emails[i];
            processAddress(oneAddress);
            realAddress.insert(oneAddress);
        }

        return realAddress.size();
    }

    void processAddress(string& address) {
        auto iter = address.begin();
        while ((*iter != '@') && (*iter != '+')) {
            if (*iter == '.') {
                iter = address.erase(iter);
            }
            else {
                iter++;
            }
        }

        if (*iter == '@') {
            return;
        }

        auto iterPlus = iter;
        while (*iterPlus != '@') {
            iterPlus++;
        }

        address.erase(iter, iterPlus);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    check.checkInt(2, o.numUniqueEmails(emails));

    emails = { "@",".@","+@","...@","+++@","...+++@","+++...@" };
    check.checkInt(1, o.numUniqueEmails(emails));

    emails = { "aaa@","aaa.@","aaa+@","abc...@","abc+++@",".abc..+++@","abc+++...@" };
    check.checkInt(2, o.numUniqueEmails(emails));
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
