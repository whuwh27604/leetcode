/* 账户合并.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。

 

示例 1：

输入：
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
输出：
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
解释：
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
 

提示：

accounts的长度将在[1，1000]的范围内。
accounts[i]的长度将在[1，10]的范围内。
accounts[i][j]的长度将在[1，30]的范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/accounts-merge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int emailsNum = countEmails(accounts);

        unordered_map<string, int> emailIds;
        unordered_map<string, string> emailAccounts;
        vector<string> allemails(emailsNum);
        DSU dsu(emailsNum);
        mergeAccounts(accounts, emailIds, emailAccounts, allemails, dsu);

        unordered_map<int, set<string>> mergedAccounts;
        output(emailsNum, dsu, allemails, mergedAccounts);

        vector<vector<string>> ans;
        set2Vector(emailAccounts, mergedAccounts, ans);

        return ans;
    }

    int countEmails(vector<vector<string>>& accounts) {
        int count = 0;

        for (auto& account : accounts) {
            count += account.size();
        }

        return count - accounts.size();
    }

    void mergeAccounts(vector<vector<string>>& accounts, unordered_map<string, int>& emailIds, unordered_map<string, string>& emailAccounts, vector<string>& allemails, DSU& dsu) {
        int id = 0;

        for (auto& account : accounts) {
            int i, size = account.size(), group = id;

            for (i = 1; i < size; ++i) {
                emailAccounts[account[i]] = account[0];
                allemails[id] = account[i];
                dsu.merge(id, group);

                if (emailIds.count(account[i]) == 0) {
                    emailIds[account[i]] = id;
                }
                else {
                    dsu.merge(id, emailIds[account[i]]);
                }

                id += 1;
            }
        }
    }

    void output(int emailsNum, DSU& dsu, vector<string>& allemails, unordered_map<int, set<string>>& mergedAccounts) {
        for (int i = 0; i < emailsNum; ++i) {
            mergedAccounts[dsu.find(i)].insert(allemails[i]);
        }
    }

    void set2Vector(unordered_map<string, string>& emailAccounts, unordered_map<int, set<string>>& mergedAccounts, vector<vector<string>>& ans) {
        for (auto it = mergedAccounts.begin(); it != mergedAccounts.end(); ++it) {
            ans.push_back({ emailAccounts[*it->second.begin()] });

            for (auto iter = it->second.begin(); iter != it->second.end(); ++iter) {
                ans.back().push_back(*iter);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> accounts = { {"John","johnsmith@mail.com","john00@mail.com"},{"John","johnnybravo@mail.com"},{"John","johnsmith@mail.com","john_newyork@mail.com"},{"Mary","mary@mail.com"} };
    vector<vector<string>> actual = o.accountsMerge(accounts);
    vector<vector<string>> expected = { {"John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"},{"John","johnnybravo@mail.com"},{"Mary","mary@mail.com"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    accounts = { {"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"} };
    actual = o.accountsMerge(accounts);
    expected = { {"David","David0@m.co","David1@m.co","David2@m.co","David3@m.co","David4@m.co","David5@m.co"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    accounts = { {"David"} };
    actual = o.accountsMerge(accounts);
    expected = {  };
    check.checkStringVectorRandomOrderVector(expected, actual);

    accounts = { {"David","David0@m.co"} };
    actual = o.accountsMerge(accounts);
    expected = { {"David","David0@m.co"} };
    check.checkStringVectorRandomOrderVector(expected, actual);
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
