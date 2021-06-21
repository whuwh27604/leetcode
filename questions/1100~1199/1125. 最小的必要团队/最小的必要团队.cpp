/* 最小的必要团队.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
作为项目经理，你规划了一份需求的技能清单 req_skills，并打算从备选人员名单 people 中选出些人组成一个「必要团队」（ 编号为 i 的备选人员 people[i] 含有一份该备选人员掌握的技能列表）。

所谓「必要团队」，就是在这个团队中，对于所需求的技能列表 req_skills 中列出的每项技能，团队中至少有一名成员已经掌握。可以用每个人的编号来表示团队中的成员：

例如，团队 team = [0, 1, 3] 表示掌握技能分别为 people[0]，people[1]，和 people[3] 的备选人员。
请你返回 任一 规模最小的必要团队，团队成员用人员编号表示。你可以按 任意顺序 返回答案，题目数据保证答案存在。

 

示例 1：

输入：req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
输出：[0,2]
示例 2：

输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
输出：[1,2]
 

提示：

1 <= req_skills.length <= 16
1 <= req_skills[i].length <= 16
req_skills[i] 由小写英文字母组成
req_skills 中的所有字符串 互不相同
1 <= people.length <= 60
0 <= people[i].length <= 16
1 <= people[i][j].length <= 16
people[i][j] 由小写英文字母组成
people[i] 中的所有字符串 互不相同
people[i] 中的每个技能是 req_skills 中的技能
题目数据保证「必要团队」一定存在

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-sufficient-team
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int sizeS = req_skills.size(), sizeP = people.size(), maxSkills = (1 << sizeS) - 1, inf = 10000;

        vector<int> skills(sizeP);
        getSkills(req_skills, people, skills);

        vector<vector<int>> trans(sizeP + 1, vector<int>(maxSkills + 1));
        vector<vector<int>> dp(sizeP + 1, vector<int>(maxSkills + 1, inf));
        dp[0][0] = 0;

        for (int peo = 1; peo <= sizeP; ++peo) {
            dp[peo][0] = 0;

            for (int req = 1; req <= maxSkills; ++req) {
                int reqLeft = req & ~skills[peo - 1];
                int num1 = dp[peo - 1][req], num2 = dp[peo - 1][reqLeft] + 1;

                if (num1 < num2) {
                    dp[peo][req] = num1;
                    trans[peo][req] = req;
                }
                else {
                    dp[peo][req] = num2;
                    trans[peo][req] = reqLeft;
                }
            }
        }

        return getTeam(trans, maxSkills);
    }

    void getSkills(vector<string>& req_skills, vector<vector<string>>& people, vector<int>& skills) {
        unordered_map<string, int> skillIndices;

        for (int i = 0; i < (int)req_skills.size(); ++i) {
            skillIndices[req_skills[i]] = i;
        }

        for (int i = 0; i < (int)people.size(); ++i) {
            for (auto& skill : people[i]) {
                skills[i] |= (1 << skillIndices[skill]);
            }
        }
    }

    vector<int> getTeam(vector<vector<int>>& trans, int maxSkills) {
        vector<int> smallestTeam;

        for (int peo = trans.size() - 1, req = maxSkills; peo > 0; --peo) {
            if (trans[peo][req] != req) {
                smallestTeam.push_back(peo - 1);
            }

            req = trans[peo][req];
        }

        return smallestTeam;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> req_skills = { "java","nodejs","reactjs" };
    vector<vector<string>> people = { {"java"},{"nodejs"},{"nodejs","reactjs"} };
    vector<int> actual = o.smallestSufficientTeam(req_skills, people);
    vector<int> expected = { 2,0 };
    check.checkIntVector(expected, actual);

    req_skills = { "algorithms","math","java","reactjs","csharp","aws" };
    people = { {"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"} };
    actual = o.smallestSufficientTeam(req_skills, people);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    req_skills = { "ldq","lpah","i","ypowcknvrcuouhe","jftllvrfghmvt","svscjulmksgo","xt","mnfgnpsqhcobst" };
    people = { {"lpah","xt"},{"ldq","i"},{"ypowcknvrcuouhe"},{"lpah","jftllvrfghmvt","mnfgnpsqhcobst"},{"xt"},{"i","xt"},{"svscjulmksgo"},{"i"},{"i","ypowcknvrcuouhe"},{"i"},{},{"svscjulmksgo","mnfgnpsqhcobst"},{},{"xt","mnfgnpsqhcobst"},{},{"ypowcknvrcuouhe","mnfgnpsqhcobst"},{"i"},{},{"jftllvrfghmvt","svscjulmksgo"},{"i","mnfgnpsqhcobst"},{"jftllvrfghmvt"},{"jftllvrfghmvt"},{},{"i"},{"ypowcknvrcuouhe"},{"ypowcknvrcuouhe"},{},{},{},{"ldq","i"} };
    actual = o.smallestSufficientTeam(req_skills, people);
    expected = { 29,18,15,0 };
    check.checkIntVector(expected, actual);

    req_skills = { "z" };
    people = { {},{},{"z"} };
    actual = o.smallestSufficientTeam(req_skills, people);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    req_skills = { "mwobudvo","goczubcwnfze","yspbsez","pf","ey","hkq" };
    people = { {} ,{"mwobudvo"},{"hkq"},{"pf"},{"pf"},{"mwobudvo","pf"},{},{"yspbsez"},{},{"hkq"},{},{},{"goczubcwnfze","pf","hkq"},{"goczubcwnfze"},{"hkq"},{"mwobudvo"},{},{"mwobudvo","pf"},{"pf","ey"},{"mwobudvo"},{"hkq"},{},{"pf"},{"mwobudvo","yspbsez"},{"mwobudvo","goczubcwnfze"},{"goczubcwnfze","pf"},{"goczubcwnfze"},{"goczubcwnfze"},{"mwobudvo"},{"mwobudvo","goczubcwnfze"},{},{"goczubcwnfze"},{},{"goczubcwnfze"},{"mwobudvo"},{},{"hkq"},{"yspbsez"},{"mwobudvo"},{"goczubcwnfze","ey"} };
    actual = o.smallestSufficientTeam(req_skills, people);
    expected = { 39,23,12 };
    check.checkIntVector(expected, actual);

    req_skills = { "wmycibrjxh","wicacrldwneag","ndutqtjuzu","pgo","gxsskiz","rbrymc","erpevpmu","jboexi","vpfdcjwngzuf","w" };
    people = { {} ,{"ndutqtjuzu","pgo"},{"ndutqtjuzu"},{"pgo","rbrymc"},{"wicacrldwneag","ndutqtjuzu"},{},{"wicacrldwneag","rbrymc","erpevpmu"},{"w"},{"wmycibrjxh","wicacrldwneag","pgo","w"},{},{"w"},{"gxsskiz","erpevpmu","vpfdcjwngzuf"},{"wicacrldwneag"},{"vpfdcjwngzuf"},{"wmycibrjxh","erpevpmu"},{"ndutqtjuzu","pgo"},{"ndutqtjuzu","pgo"},{"wmycibrjxh","erpevpmu","jboexi"},{"wmycibrjxh","wicacrldwneag","jboexi"},{"wmycibrjxh","wicacrldwneag","rbrymc"},{"wicacrldwneag"},{"erpevpmu","vpfdcjwngzuf"},{"wmycibrjxh"},{"jboexi","w"},{"erpevpmu","jboexi","w"},{"w"},{"erpevpmu","jboexi"},{"jboexi"},{"wicacrldwneag"},{},{"jboexi","vpfdcjwngzuf"},{"wmycibrjxh","jboexi"},{"wicacrldwneag"},{},{"pgo"},{"wicacrldwneag"},{},{"wmycibrjxh","vpfdcjwngzuf"},{"wmycibrjxh"},{"pgo","vpfdcjwngzuf","w"},{"wicacrldwneag","jboexi"},{"wicacrldwneag","erpevpmu","vpfdcjwngzuf"},{"wicacrldwneag"},{"wmycibrjxh","pgo","erpevpmu","vpfdcjwngzuf"},{"w"},{"vpfdcjwngzuf","w"},{"wmycibrjxh","erpevpmu"},{"wicacrldwneag","pgo","jboexi"},{"wmycibrjxh","erpevpmu","vpfdcjwngzuf"},{"w"},{},{},{},{"pgo","jboexi"},{"wicacrldwneag"},{"wicacrldwneag","erpevpmu","jboexi"},{"wmycibrjxh","pgo"},{"wmycibrjxh","wicacrldwneag","gxsskiz"},{"erpevpmu"},{"pgo","rbrymc","erpevpmu","w"} };
    actual = o.smallestSufficientTeam(req_skills, people);
    expected = { 59,57,30,16 };
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
