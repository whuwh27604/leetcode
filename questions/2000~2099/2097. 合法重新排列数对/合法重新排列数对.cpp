/* 合法重新排列数对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 pairs ，其中 pairs[i] = [starti, endi] 。如果 pairs 的一个重新排列，满足对每一个下标 i （ 1 <= i < pairs.length ）都有 endi-1 == starti ，那么我们就认为这个重新排列是 pairs 的一个 合法重新排列 。

请你返回 任意一个 pairs 的合法重新排列。

注意：数据保证至少存在一个 pairs 的合法重新排列。

 

示例 1：

输入：pairs = [[5,1],[4,5],[11,9],[9,4]]
输出：[[11,9],[9,4],[4,5],[5,1]]
解释：
输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
end0 = 9 == 9 = start1
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3
示例 2：

输入：pairs = [[1,3],[3,2],[2,1]]
输出：[[1,3],[3,2],[2,1]]
解释：
输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
重新排列后的数组 [[2,1],[1,3],[3,2]] 和 [[3,2],[2,1],[1,3]] 都是合法的。
示例 3：

输入：pairs = [[1,2],[1,3],[2,1]]
输出：[[1,2],[2,1],[1,3]]
解释：
输出的是一个合法重新排列，因为每一个 endi-1 都等于 starti 。
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2
 

提示：

1 <= pairs.length <= 105
pairs[i].length == 2
0 <= starti, endi <= 109
starti != endi
pairs 中不存在一模一样的数对。
至少 存在 一个合法的 pairs 重新排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-arrangement-of-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> startEnds;
        vector<int> path;
        vector<vector<int>> arrangement;

        getStartEnds(pairs, startEnds);
        int start = getStart(pairs);
        hierholzer(start, startEnds, path);
        getArrangement(path, arrangement);

        return arrangement;
    }

    void getStartEnds(vector<vector<int>>& pairs, unordered_map<int, vector<int>>& startEnds) {
        for (auto& p : pairs) {
            startEnds[p[0]].push_back(p[1]);
        }
    }

    int getStart(vector<vector<int>>& pairs) {
        unordered_map<int, int> ingresses, degresses;

        for (auto& p : pairs) {
            ++degresses[p[0]];
            ++ingresses[p[1]];
        }

        // 欧拉图有解必然：1、所有ingress等于degress；2、一个节点ingress - degress = 1，一个节点degress - ingress = 1
        for (auto& degress : degresses) {
            if (degress.second - ingresses[degress.first] == 1) {
                return degress.first;
            }
        }

        return degresses.begin()->first;  // 全部相等时可以从任意节点开始
    }

    void hierholzer(int node, unordered_map<int, vector<int>>& startEnds, vector<int>& path) {
        while (!startEnds[node].empty()) {
            int end = startEnds[node].back();
            startEnds[node].pop_back();  // 先删除该路径，避免重复访问
            hierholzer(end, startEnds, path);
        }

        path.push_back(node);  // 该节点的所有下一跳都已经访问过，放入路径队列
    }

    void getArrangement(vector<int>& path, vector<vector<int>>& arrangement) {
        for (int i = path.size() - 2; i >= 0; --i) {
            arrangement.push_back({ path[i + 1], path[i] });
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> pairs = { {5,1},{4,5},{11,9},{9,4} };
    vector<vector<int>> actual = o.validArrangement(pairs);
    vector<vector<int>> expected = { {11,9},{9,4},{4,5},{5,1} };
    check.checkIntVectorVector(expected, actual);

    pairs = { {1,3},{3,2},{2,1} };
    actual = o.validArrangement(pairs);
    expected = { {1,3},{3,2},{2,1} };
    check.checkIntVectorVector(expected, actual);

    pairs = { {1,2},{1,3},{2,1} };
    actual = o.validArrangement(pairs);
    expected = { {1,2},{2,1},{1,3} };
    check.checkIntVectorVector(expected, actual);

    pairs = { {874,518},{649,247},{621,559},{774,166},{241,168},{835,421},{168,835},{835,399},{741,436},{958,526},{166,578},{734,812},{436,297},{813,774},{166,559},{518,548},{882,719},{559,741},{819,621},{720,168},{964,187},{518,781},{166,781},{781,436},{719,958},{342,241},{659,392},{27,513},{812,468},{513,910},{187,848},{510,741},{835,392},{813,559},{392,848},{964,813},{241,958},{958,436},{854,241},{813,719},{781,421},{421,649},{720,910},{510,297},{725,835},{848,271},{483,578},{848,336},{854,592},{559,720},{436,399},{297,958},{592,483},{526,734},{854,813},{40,720},{719,510},{548,964},{910,882},{342,854},{578,518},{399,514},{514,813},{22,854},{399,342},{336,297},{392,271},{813,835},{27,166},{436,725},{271,854},{468,659},{421,166},{168,548},{297,526},{271,964},{741,725},{548,27},{910,510},{559,27},{73,40},{526,510},{247,819},{725,874},{578,342},{297,22},{510,813} };
    actual = o.validArrangement(pairs);
    expected = { {73,40},{40,720},{720,910},{910,510},{510,813},{813,835},{835,392},{392,271},{271,964},{964,813},{813,719},{719,510},{510,297},{297,22},{22,854},{854,813},{813,559},{559,27},{27,166},{166,781},{781,421},{421,166},{166,559},{559,720},{720,168},{168,548},{548,27},{27,513},{513,910},{910,882},{882,719},{719,958},{958,436},{436,725},{725,874},{874,518},{518,781},{781,436},{436,399},{399,342},{342,854},{854,592},{592,483},{483,578},{578,342},{342,241},{241,958},{958,526},{526,510},{510,741},{741,725},{725,835},{835,399},{399,514},{514,813},{813,774},{774,166},{166,578},{578,518},{518,548},{548,964},{964,187},{187,848},{848,336},{336,297},{297,526},{526,734},{734,812},{812,468},{468,659},{659,392},{392,848},{848,271},{271,854},{854,241},{241,168},{168,835},{835,421},{421,649},{649,247},{247,819},{819,621},{621,559},{559,741},{741,436},{436,297},{297,958} };
    check.checkIntVectorVector(expected, actual);

    pairs = { {1,2} };
    actual = o.validArrangement(pairs);
    expected = { {1,2} };
    check.checkIntVectorVector(expected, actual);
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
