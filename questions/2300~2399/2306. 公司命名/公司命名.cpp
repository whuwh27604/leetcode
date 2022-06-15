/* 公司命名.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 ideas 表示在公司命名过程中使用的名字列表。公司命名流程如下：

从 ideas 中选择 2 个 不同 名字，称为 ideaA 和 ideaB 。
交换 ideaA 和 ideaB 的首字母。
如果得到的两个新名字 都 不在 ideas 中，那么 ideaA ideaB（串联 ideaA 和 ideaB ，中间用一个空格分隔）是一个有效的公司名字。
否则，不是一个有效的名字。
返回 不同 且有效的公司名字的数目。

 

示例 1：

输入：ideas = ["coffee","donuts","time","toffee"]
输出：6
解释：下面列出一些有效的选择方案：
- ("coffee", "donuts")：对应的公司名字是 "doffee conuts" 。
- ("donuts", "coffee")：对应的公司名字是 "conuts doffee" 。
- ("donuts", "time")：对应的公司名字是 "tonuts dime" 。
- ("donuts", "toffee")：对应的公司名字是 "tonuts doffee" 。
- ("time", "donuts")：对应的公司名字是 "dime tonuts" 。
- ("toffee", "donuts")：对应的公司名字是 "doffee tonuts" 。
因此，总共有 6 个不同的公司名字。

下面列出一些无效的选择方案：
- ("coffee", "time")：在原数组中存在交换后形成的名字 "toffee" 。
- ("time", "toffee")：在原数组中存在交换后形成的两个名字。
- ("coffee", "toffee")：在原数组中存在交换后形成的两个名字。
示例 2：

输入：ideas = ["lack","back"]
输出：0
解释：不存在有效的选择方案。因此，返回 0 。
 

提示：

2 <= ideas.length <= 5 * 104
1 <= ideas[i].length <= 10
ideas[i] 由小写英文字母组成
ideas 中的所有字符串 互不相同

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/naming-a-company
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> allIdeas;
        vector<vector<int>> valid(26, vector<int>(26, 0));

        hash(ideas, allIdeas);
        getValid(ideas, allIdeas, valid);

        return getAllValid(ideas, allIdeas, valid);
    }

    void hash(vector<string>& ideas, unordered_set<string>& allIdeas) {
        for (string& idea : ideas) {
            allIdeas.insert(idea);
        }
    }

    void getValid(vector<string>& ideas, unordered_set<string>& allIdeas, vector<vector<int>>& valid) {
        for (string& idea : ideas) {
            string newIdea = idea;

            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != idea[0]) {
                    newIdea[0] = c;

                    if (allIdeas.count(newIdea) == 0) {
                        ++valid[idea[0] - 'a'][c - 'a'];
                    }
                }
            }
        }
    }

    long long getAllValid(vector<string>& ideas, unordered_set<string>& allIdeas, vector<vector<int>>& valid) {
        long long count = 0;

        for (string& idea : ideas) {
            string newIdea = idea;

            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != idea[0]) {
                    newIdea[0] = c;

                    if (allIdeas.count(newIdea) == 0) {
                        count += valid[c - 'a'][idea[0] - 'a'];
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> ideas = { "coffee","donuts","time","toffee" };
    check.checkLongLong(6, o.distinctNames(ideas));

    ideas = { "lack","back" };
    check.checkLongLong(0, o.distinctNames(ideas));

    ideas = { "a","b","c","d","e","f","g" };
    check.checkLongLong(0, o.distinctNames(ideas));
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
