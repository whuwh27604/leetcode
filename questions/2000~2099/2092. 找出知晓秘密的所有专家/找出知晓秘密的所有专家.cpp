/* 找出知晓秘密的所有专家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，表示有 n 个专家从 0 到 n - 1 编号。另外给你一个下标从 0 开始的二维整数数组 meetings ，其中 meetings[i] = [xi, yi, timei] 表示专家 xi 和专家 yi 在时间 timei 要开一场会。一个专家可以同时参加 多场会议 。最后，给你一个整数 firstPerson 。

专家 0 有一个 秘密 ，最初，他在时间 0 将这个秘密分享给了专家 firstPerson 。接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播。更正式的表达是，每次会议，如果专家 xi 在时间 timei 时知晓这个秘密，那么他将会与专家 yi 分享这个秘密，反之亦然。

秘密共享是 瞬时发生 的。也就是说，在同一时间，一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享。

在所有会议都结束之后，返回所有知晓这个秘密的专家列表。你可以按 任何顺序 返回答案。

 

示例 1：

输入：n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
输出：[0,1,2,3,5]
解释：
时间 0 ，专家 0 将秘密与专家 1 共享。
时间 5 ，专家 1 将秘密与专家 2 共享。
时间 8 ，专家 2 将秘密与专家 3 共享。
时间 10 ，专家 1 将秘密与专家 5 共享。
因此，在所有会议结束后，专家 0、1、2、3 和 5 都将知晓这个秘密。
示例 2：

输入：n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
输出：[0,1,3]
解释：
时间 0 ，专家 0 将秘密与专家 3 共享。
时间 2 ，专家 1 与专家 2 都不知晓这个秘密。
时间 3 ，专家 3 将秘密与专家 0 和专家 1 共享。
因此，在所有会议结束后，专家 0、1 和 3 都将知晓这个秘密。
示例 3：

输入：n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
输出：[0,1,2,3,4]
解释：
时间 0 ，专家 0 将秘密与专家 1 共享。
时间 1 ，专家 1 将秘密与专家 2 共享，专家 2 将秘密与专家 3 共享。
注意，专家 2 可以在收到秘密的同一时间分享此秘密。
时间 2 ，专家 3 将秘密与专家 4 共享。
因此，在所有会议结束后，专家 0、1、2、3 和 4 都将知晓这个秘密。
示例 4：

输入：n = 6, meetings = [[0,2,1],[1,3,1],[4,5,1]], firstPerson = 1
输出：[0,1,2,3]
解释：
时间 0 ，专家 0 将秘密与专家 1 共享。
时间 1 ，专家 0 将秘密与专家 2 共享，专家 1 将秘密与专家 3 共享。
因此，在所有会议结束后，专家 0、1、2 和 3 都将知晓这个秘密。
 

提示：

2 <= n <= 105
1 <= meetings.length <= 105
meetings[i].length == 3
0 <= xi, yi <= n - 1
xi != yi
1 <= timei <= 105
1 <= firstPerson <= n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-people-with-secret
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[2] < v2[2];  // 按照time排序
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int i = 0, j = 0, size = meetings.size();
        vector<int> ans;
        vector<bool> knows(n, false);
        knows[0] = knows[firstPerson] = true;

        sort(meetings.begin(), meetings.end(), vectorCompare);

        for (i = 0; i < size; i = j) {
            unordered_map<int, vector<int>> adjs;
            unordered_set<int> persons;
            queue<int> bfs;

            for (j = i; j < size && meetings[i][2] == meetings[j][2]; ++j) {
                int person1 = meetings[j][0], person2 = meetings[j][1];
                adjs[person1].push_back(person2);
                adjs[person2].push_back(person1);
                persons.insert(person1);
                persons.insert(person2);
            }

            for (int person : persons) {
                if (knows[person]) {
                    bfs.push(person);
                }
            }

            while (!bfs.empty()) {
                int current = bfs.front();
                bfs.pop();

                for (int next : adjs[current]) {
                    if (!knows[next]) {
                        knows[next] = true;
                        bfs.push(next);
                    }
                }
            }
        }

        for (i = 0; i < n; ++i) {
            if (knows[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> meetings = { {1,2,5},{2,3,8},{1,5,10} };
    vector<int> actual = o.findAllPeople(6, meetings, 1);
    vector<int> expected = { 0,1,2,3,5 };
    check.checkIntVector(expected, actual);

    meetings = { {3,1,3},{1,2,2},{0,3,3} };
    actual = o.findAllPeople(4, meetings, 3);
    expected = { 0,1,3 };
    check.checkIntVector(expected, actual);

    meetings = { {3,4,2},{1,2,1},{2,3,1} };
    actual = o.findAllPeople(5, meetings, 1);
    expected = { 0,1,2,3,4 };
    check.checkIntVector(expected, actual);

    meetings = { {0,2,1},{1,3,1},{4,5,1} };
    actual = o.findAllPeople(6, meetings, 1);
    expected = { 0,1,2,3 };
    check.checkIntVector(expected, actual);

    meetings = { {10,8,6},{9,5,11},{0,5,18},{4,5,13},{11,6,17},{0,11,10},{10,11,7},{5,8,3},{7,6,16},{3,6,10},{3,11,1},{8,3,2},{5,0,7},{3,8,20},{11,0,20},{8,3,4},{1,9,4},{10,7,11},{8,10,18} };
    actual = o.findAllPeople(12, meetings, 9);
    expected = { 0,1,4,5,6,9,11 };
    check.checkIntVector(expected, actual);

    meetings = getIntVectorVector("./testcase1.txt");
    actual = o.findAllPeople(100000, meetings, 1);
    expected = { 0,1,2,3 };
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
