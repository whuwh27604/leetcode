/* 执行交换操作后的最小汉明距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 source 和 target ，长度都是 n 。还有一个数组 allowedSwaps ，其中每个 allowedSwaps[i] = [ai, bi] 表示你可以交换数组 source 中下标为 ai 和 bi（下标从 0 开始）的两个元素。注意，你可以按 任意 顺序 多次 交换一对特定下标指向的元素。

相同长度的两个数组 source 和 target 间的 汉明距离 是元素不同的下标数量。形式上，其值等于满足 source[i] != target[i] （下标从 0 开始）的下标 i（0 <= i <= n-1）的数量。

在对数组 source 执行 任意 数量的交换操作后，返回 source 和 target 间的 最小汉明距离 。

 

示例 1：

输入：source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
输出：1
解释：source 可以按下述方式转换：
- 交换下标 0 和 1 指向的元素：source = [2,1,3,4]
- 交换下标 2 和 3 指向的元素：source = [2,1,4,3]
source 和 target 间的汉明距离是 1 ，二者有 1 处元素不同，在下标 3 。
示例 2：

输入：source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
输出：2
解释：不能对 source 执行交换操作。
source 和 target 间的汉明距离是 2 ，二者有 2 处元素不同，在下标 1 和下标 2 。
示例 3：

输入：source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
输出：0
 

提示：

n == source.length == target.length
1 <= n <= 105
1 <= source[i], target[i] <= 105
0 <= allowedSwaps.length <= 105
allowedSwaps[i].length == 2
0 <= ai, bi <= n - 1
ai != bi

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        DSU dsu(source.size());
        mergeIndices(allowedSwaps, dsu);

        unordered_map<int, vector<vector<int>>> sameSetNums;
        classifyNums(source, target, dsu, sameSetNums);

        return getDistance(sameSetNums);
    }

    void mergeIndices(vector<vector<int>>& allowedSwaps, DSU& dsu) {
        for (auto& allowedSwap : allowedSwaps) {
            dsu.merge(allowedSwap[0], allowedSwap[1]);
        }
    }

    void classifyNums(vector<int>& source, vector<int>& target, DSU& dsu, unordered_map<int, vector<vector<int>>>& sameSetNums) {
        for (int i = 0; i < (int)source.size(); ++i) {
            int setId = dsu.find(i);

            if (sameSetNums.count(setId) == 0) {
                sameSetNums[setId] = { {source[i]},{target[i]} };
            }
            else {
                sameSetNums[setId][0].push_back(source[i]);
                sameSetNums[setId][1].push_back(target[i]);
            }
        }
    }

    int getDistance(unordered_map<int, vector<vector<int>>>& sameSetNums) {
        int distance = 0;

        for (auto iter = sameSetNums.begin(); iter != sameSetNums.end(); ++iter) {
            sort(iter->second[0].begin(), iter->second[0].end());
            sort(iter->second[1].begin(), iter->second[1].end());

            distance += getDifference(iter->second[0], iter->second[1]);
        }

        return distance;
    }

    int getDifference(vector<int>& source, vector<int>& target) {
        int i, j = 0, size = source.size(), diff = 0;

        for (i = 0; i < size; ++i) {
            while (target[j] < source[i]) {
                ++diff;
                if (++j == size) {
                    return diff;
                }
            }

            if (target[j] == source[i]) {
                if (++j == size) {
                    return diff;
                }
            }
        }

        return diff + size - j;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> source = { 1,2,5 };
    vector<int> target = { 2,4,6 };
    check.checkInt(2, o.getDifference(source, target));

    source = { 2,4,6 };
    target = { 1,4,5 };
    check.checkInt(2, o.getDifference(source, target));

    source = { 2,4,6 };
    target = { 2,4,6 };
    check.checkInt(0, o.getDifference(source, target));

    source = { 1,2,3,4 };
    target = { 2,1,4,5 };
    vector<vector<int>> allowedSwaps = { {0,1},{2,3} };
    check.checkInt(1, o.minimumHammingDistance(source, target, allowedSwaps));

    source = { 1,2,3,4 };
    target = { 1,3,2,4 };
    allowedSwaps = {  };
    check.checkInt(2, o.minimumHammingDistance(source, target, allowedSwaps));

    source = { 5,1,2,4,3 };
    target = { 1,5,4,2,3 };
    allowedSwaps = { {0,4},{4,2},{1,3},{1,4} };
    check.checkInt(0, o.minimumHammingDistance(source, target, allowedSwaps));

    source = { 1,2 };
    target = { 2,1 };
    allowedSwaps = { {0,1},{1,0} };
    check.checkInt(0, o.minimumHammingDistance(source, target, allowedSwaps));

    source = { 2 };
    target = { 2 };
    allowedSwaps = {  };
    check.checkInt(0, o.minimumHammingDistance(source, target, allowedSwaps));

    source = { 2 };
    target = { 1 };
    allowedSwaps = {  };
    check.checkInt(1, o.minimumHammingDistance(source, target, allowedSwaps));
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
