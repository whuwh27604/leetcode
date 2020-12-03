/* 获取你好友已观看的视频.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个人，每个人都有一个  0 到 n-1 的唯一 id 。

给你数组 watchedVideos  和 friends ，其中 watchedVideos[i]  和 friends[i] 分别表示 id = i 的人观看过的视频列表和他的好友列表。

Level 1 的视频包含所有你好友观看过的视频，level 2 的视频包含所有你好友的好友观看过的视频，以此类推。一般的，Level 为 k 的视频包含所有从你出发，最短距离为 k 的好友观看过的视频。

给定你的 id  和一个 level 值，请你找出所有指定 level 的视频，并将它们按观看频率升序返回。如果有频率相同的视频，请将它们按字母顺序从小到大排列。

 

示例 1：



输入：watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
输出：["B","C"]
解释：
你的 id 为 0（绿色），你的朋友包括（黄色）：
id 为 1 -> watchedVideos = ["C"] 
id 为 2 -> watchedVideos = ["B","C"] 
你朋友观看过视频的频率为：
B -> 1 
C -> 2
示例 2：



输入：watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
输出：["D"]
解释：
你的 id 为 0（绿色），你朋友的朋友只有一个人，他的 id 为 3（黄色）。
 

提示：

n == watchedVideos.length == friends.length
2 <= n <= 100
1 <= watchedVideos[i].length <= 100
1 <= watchedVideos[i][j].length <= 8
0 <= friends[i].length < n
0 <= friends[i][j] < n
0 <= id < n
1 <= level < n
如果 friends[i] 包含 j ，那么 friends[j] 包含 i

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-watched-videos-by-your-friends
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> levelFriends;
        getLevelFriends(friends, id, level, levelFriends);

        unordered_map<string, int> videosCount;
        getWatchedVideosByFriends(watchedVideos, levelFriends, videosCount);

        map<int, set<string>> sortedVideos;
        sortVideos(videosCount, sortedVideos);

        vector<string> friendsWatchedVideos;
        getWatchedVideos(sortedVideos, friendsWatchedVideos);

        return friendsWatchedVideos;
    }

    void getLevelFriends(vector<vector<int>>& friends, int id, int level, vector<int>& levelFriends) {
        int n = friends.size();
        vector<bool> visited(n, false);
        visited[id] = true;

        queue<int> bfs;
        bfs.push(id);

        while (!bfs.empty() && level != 0) {
            int i, size = bfs.size();
            --level;

            for (i = 0; i < size; ++i) {
                int person = bfs.front();
                bfs.pop();

                for (int hisFriends : friends[person]) {
                    if (!visited[hisFriends]) {
                        visited[hisFriends] = true;
                        bfs.push(hisFriends);
                    }
                }
            }
        }

        while (!bfs.empty()) {
            levelFriends.push_back(bfs.front());
            bfs.pop();
        }
    }

    void getWatchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<int>& ids, unordered_map<string, int>& videosCount) {
        for (int id : ids) {
            for (string& video : watchedVideos[id]) {
                ++videosCount[video];
            }
        }
    }

    void sortVideos(unordered_map<string, int>& videos, map<int, set<string>>& sortedVideos) {
        for (auto iter = videos.begin(); iter != videos.end(); ++iter) {
            sortedVideos[iter->second].insert(iter->first);
        }
    }

    void getWatchedVideos(map<int, set<string>>& sortedVideos, vector<string>& watchedVideos) {
        for (auto iter = sortedVideos.begin(); iter != sortedVideos.end(); ++iter) {
            for (auto it = iter->second.begin(); it != iter->second.end(); ++it) {
                watchedVideos.push_back(*it);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> watchedVideos = { {"A"},{"B"},{"C"} };
    vector<vector<int>> friends = { {1,2},{0,2},{0,1} };
    vector<string> actual = o.watchedVideosByFriends(watchedVideos, friends, 0, 2);
    vector<string> expected = {};
    check.checkStringVector(expected, actual);

    watchedVideos = { {"A","B"},{"C"},{"B","C"},{"D"} };
    friends = { {1,2},{0,3},{0,3},{1,2} };
    actual = o.watchedVideosByFriends(watchedVideos, friends, 0, 1);
    expected = { "B","C" };
    check.checkStringVector(expected, actual);

    watchedVideos = { {"A","B"},{"C"},{"B","C"},{"D"} };
    friends = { {1,2},{0,3},{0,3},{1,2} };
    actual = o.watchedVideosByFriends(watchedVideos, friends, 0, 2);
    expected = { "D" };
    check.checkStringVector(expected, actual);

    watchedVideos = { {"A","B"},{"D","C"},{"B","D","C","E"},{"D","B","A","C"},{"D","A","C"} };
    friends = { {1},{0,2,3,4},{1},{1},{1} };
    actual = o.watchedVideosByFriends(watchedVideos, friends, 0, 2);
    expected = { "E","A","B","C","D" };
    check.checkStringVector(expected, actual);

    watchedVideos = { {"A","B"},{"C"} };
    friends = { {},{} };
    actual = o.watchedVideosByFriends(watchedVideos, friends, 0, 1);
    expected = {  };
    check.checkStringVector(expected, actual);

    watchedVideos = { {"A","B"},{"C"} };
    friends = { {1},{0} };
    actual = o.watchedVideosByFriends(watchedVideos, friends, 0, 1);
    expected = { "C" };
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
