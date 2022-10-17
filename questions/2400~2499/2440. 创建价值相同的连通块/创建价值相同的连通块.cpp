/* 创建价值相同的连通块.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一棵 n 个节点的无向树，节点编号为 0 到 n - 1 。

给你一个长度为 n 下标从 0 开始的整数数组 nums ，其中 nums[i] 表示第 i 个节点的值。同时给你一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 与 bi 之间有一条边。

你可以 删除 一些边，将这棵树分成几个连通块。一个连通块的 价值 定义为这个连通块中 所有 节点 i 对应的 nums[i] 之和。

你需要删除一些边，删除后得到的各个连通块的价值都相等。请返回你可以删除的边数 最多 为多少。

 

示例 1：



输入：nums = [6,2,2,2,6], edges = [[0,1],[1,2],[1,3],[3,4]]
输出：2
解释：上图展示了我们可以删除边 [0,1] 和 [3,4] 。得到的连通块为 [0] ，[1,2,3] 和 [4] 。每个连通块的价值都为 6 。可以证明没有别的更好的删除方案存在了，所以答案为 2 。
示例 2：

输入：nums = [2], edges = []
输出：0
解释：没有任何边可以删除。
 

提示：

1 <= n <= 2 * 104
nums.length == n
1 <= nums[i] <= 50
edges.length == n - 1
edges[i].length == 2
0 <= edges[i][0], edges[i][1] <= n - 1
edges 表示一棵合法的树。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/create-components-with-same-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adjs(n);

        getAdjs(edges, adjs);
        int sum = getSum(nums, adjs, 0, -1);

        for (int value = 1; value < sum; ++value) {
            if (sum % value == 0 && cut(nums, adjs, 0, -1, value) == 0) {
                return sum / value - 1;
            }
        }

        return 0;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int getSum(vector<int>& nums, vector<vector<int>>& adjs, int root, int parent) {
        int sum = nums[root];

        for (int node : adjs[root]) {
            if (node != parent) {
                sum += getSum(nums, adjs, node, root);
            }
        }

        return sum;
    }

    int cut(vector<int>& nums, vector<vector<int>>& adjs, int root, int parent, int value) {
        int sum = nums[root];
        if (sum > value) {
            return -1;
        }

        for (int node : adjs[root]) {
            if (node != parent) {
                int subSum = cut(nums, adjs, node, root, value);
                if (subSum == -1) {
                    return -1;
                }

                sum += subSum;
                if (sum > value) {
                    return -1;
                }
            }
        }

        return sum == value ? 0 : sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 6,2,2,2,6 };
    vector<vector<int>> edges = { {0,1},{1,2},{1,3},{3,4} };
    check.checkInt(2, o.componentValue(nums, edges));

    nums = { 2 };
    edges = {};
    check.checkInt(0, o.componentValue(nums, edges));
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
