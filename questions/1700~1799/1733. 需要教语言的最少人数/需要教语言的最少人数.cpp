/* 需要教语言的最少人数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个由 m 个用户组成的社交网络里，我们获取到一些用户之间的好友关系。两个用户之间可以相互沟通的条件是他们都掌握同一门语言。

给你一个整数 n ，数组 languages 和数组 friendships ，它们的含义如下：

总共有 n 种语言，编号从 1 到 n 。
languages[i] 是第 i 位用户掌握的语言集合。
friendships[i] = [u​​​​​​i​​​, v​​​​​​i] 表示 u​​​​​​​​​​​i​​​​​ 和 vi 为好友关系。
你可以选择 一门 语言并教会一些用户，使得所有好友之间都可以相互沟通。请返回你 最少 需要教会多少名用户。

请注意，好友关系没有传递性，也就是说如果 x 和 y 是好友，且 y 和 z 是好友， x 和 z 不一定是好友。
 

示例 1：

输入：n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
输出：1
解释：你可以选择教用户 1 第二门语言，也可以选择教用户 2 第一门语言。
示例 2：

输入：n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
输出：2
解释：教用户 1 和用户 3 第三门语言，需要教 2 名用户。
 

提示：

2 <= n <= 500
languages.length == m
1 <= m <= 500
1 <= languages[i].length <= n
1 <= languages[i][j] <= n
1 <= u​​​​​​i < v​​​​​​i <= languages.length
1 <= friendships.length <= 500
所有的好友关系 (u​​​​​i, v​​​​​​i) 都是唯一的。
languages[i] 中包含的值互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-people-to-teach
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int users = languages.size();

        vector<unordered_set<int>> languageKnows(users + 1);
        getLanguageKnows(users, languages, languageKnows);

        unordered_set<int> toBeTaughtUsers;
        getUsersNeedToBeTaught(friendships, languageKnows, toBeTaughtUsers);

        return (int)toBeTaughtUsers.size() - getNumMostUserKnowsLanguage(n, languages, toBeTaughtUsers);
    }

    void getLanguageKnows(int users, vector<vector<int>>& languages, vector<unordered_set<int>>& languageKnows) {
        for (int user = 0; user < users; ++user) {
            for (int language : languages[user]) {
                languageKnows[user + 1].insert(language);
            }
        }
    }

    void getUsersNeedToBeTaught(vector<vector<int>>& friendships, vector<unordered_set<int>>& languageKnows, unordered_set<int>& toBeTaughtUsers) {
        for (auto& friendship : friendships) {
            if (needToBeTaught(languageKnows, friendship[0], friendship[1])) {
                toBeTaughtUsers.insert(friendship[0]);
                toBeTaughtUsers.insert(friendship[1]);
            }
        }
    }

    bool needToBeTaught(vector<unordered_set<int>>& languageKnows, int user1, int user2) {
        if (languageKnows[user1].size() < languageKnows[user2].size()) {
            return !checkAnyLanguageBothKnows(languageKnows[user1], languageKnows[user2]);
        }

        return !checkAnyLanguageBothKnows(languageKnows[user2], languageKnows[user1]);
    }

    bool checkAnyLanguageBothKnows(unordered_set<int>& languages1, unordered_set<int>& languages2) {
        for (auto iter = languages1.begin(); iter != languages1.end(); ++iter) {
            if (languages2.count(*iter) != 0) {
                return true;
            }
        }

        return false;
    }

    int getNumMostUserKnowsLanguage(int n, vector<vector<int>>& languages, unordered_set<int>& toBeTaughtUsers) {
        vector<int> nums(n + 1, 0);

        for (int user : toBeTaughtUsers) {
            for (int language : languages[user - 1]) {
                ++nums[language];
            }
        }

        return *max_element(nums.begin(), nums.end());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> languages = { {1},{2},{1,2} };
    vector<vector<int>> friendships = { {1,2},{1,3},{2,3} };
    check.checkInt(1, o.minimumTeachings(2, languages, friendships));

    languages = { {2},{1,3},{1,2},{3} };
    friendships = { {1,4},{1,2},{3,4},{2,3} };
    check.checkInt(2, o.minimumTeachings(3, languages, friendships));
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
