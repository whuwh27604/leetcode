/* 子域名访问计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个网站域名，如"discuss.leetcode.com"，包含了多个子域名。作为顶级域名，常用的有"com"，下一级则有"leetcode.com"，最低的一级为"discuss.leetcode.com"。当我们访问域名"discuss.leetcode.com"时，也同时访问了其父域名"leetcode.com"以及顶级域名 "com"。

给定一个带访问次数和域名的组合，要求分别计算每个域名被访问的次数。其格式为访问次数+空格+地址，例如："9001 discuss.leetcode.com"。

接下来会给出一组访问次数和域名组合的列表cpdomains 。要求解析出所有域名的访问次数，输出格式和输入格式相同，不限定先后顺序。

示例 1:
输入:
["9001 discuss.leetcode.com"]
输出:
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
说明:
例子中仅包含一个网站域名："discuss.leetcode.com"。按照前文假设，子域名"leetcode.com"和"com"都会被访问，所以它们都被访问了9001次。
示例 2
输入:
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
输出:
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
说明:
按照假设，会访问"google.mail.com" 900次，"yahoo.com" 50次，"intel.mail.com" 1次，"wiki.org" 5次。
而对于父域名，会访问"mail.com" 900+1 = 901次，"com" 900 + 50 + 1 = 951次，和 "org" 5 次。
注意事项：

 cpdomains 的长度小于 100。
每个域名的长度小于100。
每个域名地址包含一个或两个"."符号。
输入中任意一个域名的访问次数都小于10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subdomain-visit-count
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <sstream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainNums;
        for (unsigned int i = 0; i < cpdomains.size(); i++) {
            processDomainRecord(cpdomains[i], domainNums);
        }

        vector<string> allDomainNums;
        for (auto iter = domainNums.begin(); iter != domainNums.end(); iter++) {
            string oneDomainNums = to_string(iter->second);
            oneDomainNums += " ";
            oneDomainNums += iter->first;
            allDomainNums.push_back(oneDomainNums);
        }

        return allDomainNums;
    }

    void processDomainRecord(string& domainRecord, unordered_map<string, int>& domainNums) {
        int len = domainRecord.size();
        int spaceIndex = domainRecord.find(" ");
        string number(domainRecord, 0, spaceIndex);
        stringstream ss;
        ss << number;
        int nums;
        ss >> nums;

        string domain(domainRecord, (spaceIndex + 1), (len - spaceIndex));
        processOneDomain(domain, nums, domainNums);

        int dotIndex = 0;
        while ((dotIndex = domainRecord.find(".", dotIndex)) != string::npos) {
            string subdomain(domainRecord, (dotIndex + 1), (len - dotIndex));
            processOneDomain(subdomain, nums, domainNums);

            dotIndex++;
        }
    }

    void processOneDomain(string& domain, int nums, unordered_map<string, int>& domainNums) {
        auto iter = domainNums.find(domain);
        if (iter == domainNums.end()) {
            domainNums[domain] = nums;
        }
        else {
            iter->second += nums;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> cpdomains = { "9001 discuss.leetcode.com" };
    vector<string> actual = o.subdomainVisits(cpdomains);
    vector<string> expected = { "9001 leetcode.com", "9001 discuss.leetcode.com", "9001 com" };
    check.checkStringVector(expected, actual);

    cpdomains = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
    actual = o.subdomainVisits(cpdomains);
    expected = { "900 google.mail.com","901 mail.com","951 com","50 yahoo.com","1 intel.mail.com","5 org","5 wiki.org" };
    check.checkStringVector(expected, actual);

    cpdomains = { "900 google" };
    actual = o.subdomainVisits(cpdomains);
    expected = { "900 google" };
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
