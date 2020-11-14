/* 可能的二分法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一组 N 人（编号为 1, 2, ..., N）， 我们想把每个人分进任意大小的两组。

每个人都可能不喜欢其他人，那么他们不应该属于同一组。

形式上，如果 dislikes[i] = [a, b]，表示不允许将编号为 a 和 b 的人归入同一组。

当可以用这种方法将每个人分进两组时，返回 true；否则返回 false。

 

示例 1：

输入：N = 4, dislikes = [[1,2],[1,3],[2,4]]
输出：true
解释：group1 [1,4], group2 [2,3]
示例 2：

输入：N = 3, dislikes = [[1,2],[1,3],[2,3]]
输出：false
示例 3：

输入：N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
输出：false
 

提示：

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
对于 dislikes[i] == dislikes[j] 不存在 i != j

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/possible-bipartition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> dislikeTable;
        createDislikeTable(dislikes, dislikeTable);

        vector<int> peoples(N + 1, -1);
        for (int i = 1; i <= N; ++i) {
            if (peoples[i] != -1) {
                continue;
            }

            peoples[i] = 0;
            if (!DFS(i, peoples, dislikeTable)) {
                return false;
            }
        }

        return true;
    }

    void createDislikeTable(vector<vector<int>>& dislikes, unordered_map<int, vector<int>>& dislikeTable) {
        for (vector<int>& dislike : dislikes) {
            auto iter = dislikeTable.find(dislike[0]);
            if (iter == dislikeTable.end()) {
                dislikeTable[dislike[0]] = { dislike[1] };
            }
            else {
                iter->second.push_back(dislike[1]);
            }

            iter = dislikeTable.find(dislike[1]);
            if (iter == dislikeTable.end()) {
                dislikeTable[dislike[1]] = { dislike[0] };
            }
            else {
                iter->second.push_back(dislike[0]);
            }
        }
    }

    bool DFS(int people, vector<int>& peoples, unordered_map<int, vector<int>>& dislikeTable) {
        auto iter = dislikeTable.find(people);
        if (iter == dislikeTable.end()) {
            return true;
        }

        vector<int>& dislikes = iter->second;
        for (int dislike : dislikes) {
            if (peoples[dislike] != -1) {  // 这个人已经完成了分组，检查分组情况
                if ((peoples[people] ^ peoples[dislike]) == 1) {
                    continue;  // 两人分在不同组
                }
                else {
                    return false;  // 两人分在同一组，冲突了
                }
            }

            peoples[dislike] = peoples[people] ^ 1;  // 这个人还没有完成分组，把他分到另外一组，继续往下检查
            if (!DFS(dislike, peoples, dislikeTable)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> dislikes = { {1,2},{1,3},{2,4} };
    check.checkBool(true, o.possibleBipartition(4, dislikes));

    dislikes = { {1,2},{1,3},{2,3} };
    check.checkBool(false, o.possibleBipartition(3, dislikes));

    dislikes = { {1,2},{2,3},{3,4},{4,5},{1,5} };
    check.checkBool(false, o.possibleBipartition(5, dislikes));

    dislikes = { {4,7},{4,8},{2,8},{8,9},{1,6},{5,8},{1,2},{6,7},{3,10},{8,10},{1,5},{7,10},{1,10},{3,5},{3,6},{1,4},{3,9},{2,3},{1,9},{7,9},{2,7},{6,8},{5,7},{3,4} };
    check.checkBool(true, o.possibleBipartition(10, dislikes));

    dislikes = { {1,2},{3,4},{5,6},{6,7},{8,9},{7,8} };
    check.checkBool(true, o.possibleBipartition(10, dislikes));

    dislikes = {  };
    check.checkBool(true, o.possibleBipartition(1, dislikes));
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
