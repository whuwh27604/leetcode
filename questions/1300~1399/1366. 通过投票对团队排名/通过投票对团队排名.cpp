/* 通过投票对团队排名.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现在有一个特殊的排名系统，依据参赛团队在投票人心中的次序进行排名，每个投票者都需要按从高到低的顺序对参与排名的所有团队进行排位。

排名规则如下：

参赛团队的排名次序依照其所获「排位第一」的票的多少决定。如果存在多个团队并列的情况，将继续考虑其「排位第二」的票的数量。以此类推，直到不再存在并列的情况。
如果在考虑完所有投票情况后仍然出现并列现象，则根据团队字母的字母顺序进行排名。
给你一个字符串数组 votes 代表全体投票者给出的排位情况，请你根据上述排名规则对所有参赛团队进行排名。

请你返回能表示按排名系统 排序后 的所有团队排名的字符串。

 

示例 1：

输入：votes = ["ABC","ACB","ABC","ACB","ACB"]
输出："ACB"
解释：A 队获得五票「排位第一」，没有其他队获得「排位第一」，所以 A 队排名第一。
B 队获得两票「排位第二」，三票「排位第三」。
C 队获得三票「排位第二」，两票「排位第三」。
由于 C 队「排位第二」的票数较多，所以 C 队排第二，B 队排第三。
示例 2：

输入：votes = ["WXYZ","XYZW"]
输出："XWYZ"
解释：X 队在并列僵局打破后成为排名第一的团队。X 队和 W 队的「排位第一」票数一样，但是 X 队有一票「排位第二」，而 W 没有获得「排位第二」。
示例 3：

输入：votes = ["ZMNAGUEDSJYLBOPHRQICWFXTVK"]
输出："ZMNAGUEDSJYLBOPHRQICWFXTVK"
解释：只有一个投票者，所以排名完全按照他的意愿。
示例 4：

输入：votes = ["BCA","CAB","CBA","ABC","ACB","BAC"]
输出："ABC"
解释：
A 队获得两票「排位第一」，两票「排位第二」，两票「排位第三」。
B 队获得两票「排位第一」，两票「排位第二」，两票「排位第三」。
C 队获得两票「排位第一」，两票「排位第二」，两票「排位第三」。
完全并列，所以我们需要按照字母升序排名。
示例 5：

输入：votes = ["M","M","M","M"]
输出："M"
解释：只有 M 队参赛，所以它排名第一。
 

提示：

1 <= votes.length <= 1000
1 <= votes[i].length <= 26
votes[i].length == votes[j].length for 0 <= i, j < votes.length
votes[i][j] 是英文 大写 字母
votes[i] 中的所有字母都是唯一的
votes[0] 中出现的所有字母 同样也 出现在 votes[j] 中，其中 1 <= j < votes.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rank-teams-by-votes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

struct vectorCompare {
    bool operator() (const vector<int>& v1, const vector<int>& v2) const {
        for (unsigned int i = 1; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                return v1[i] > v2[i];
            }
        }

        return v1[0] < v2[0];
    }
};

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> ranksCount(26, vector<int>(votes[0].size() + 1, 0));
        init(votes[0], ranksCount);
        countRanks(votes, ranksCount);

        set<vector<int>, vectorCompare> sortedTeams;
        sortTeams(ranksCount, sortedTeams);

        string rankedTeams;
        getRankedTeams(sortedTeams, rankedTeams);

        return rankedTeams;
    }

    void init(string& vote, vector<vector<int>>& ranksCount) {
        for (unsigned int i = 0; i < vote.size(); ++i) {
            ranksCount[vote[i] - 'A'][0] = vote[i];
        }
    }

    void countRanks(vector<string>& votes, vector<vector<int>>& ranksCount) {
        for (string& vote : votes) {
            for (unsigned int i = 0; i < vote.size(); ++i) {
                ++ranksCount[vote[i] - 'A'][i + 1];
            }
        }
    }

    void sortTeams(vector<vector<int>>& ranksCount, set<vector<int>, vectorCompare>& sortedTeams) {
        for (int i = 0; i < 26; ++i) {
            if (ranksCount[i][0] != 0) {
                sortedTeams.insert(ranksCount[i]);
            }
        }
    }

    void getRankedTeams(set<vector<int>, vectorCompare>& sortedTeams, string& rankedTeams) {
        for (auto iter = sortedTeams.begin(); iter != sortedTeams.end(); ++iter) {
            rankedTeams += (char)((*iter)[0]);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> votes = { "ABC","ACB","ABC","ACB","ACB" };
    check.checkString("ACB", o.rankTeams(votes));

    votes = { "WXYZ","XYZW" };
    check.checkString("XWYZ", o.rankTeams(votes));

    votes = { "ZMNAGUEDSJYLBOPHRQICWFXTVK" };
    check.checkString("ZMNAGUEDSJYLBOPHRQICWFXTVK", o.rankTeams(votes));

    votes = { "BCA","CAB","CBA","ABC","ACB","BAC" };
    check.checkString("ABC", o.rankTeams(votes));

    votes = { "M","M","M","M" };
    check.checkString("M", o.rankTeams(votes));
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
