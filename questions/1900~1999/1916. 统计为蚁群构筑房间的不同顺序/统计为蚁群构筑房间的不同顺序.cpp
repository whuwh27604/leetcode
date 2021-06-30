/* 统计为蚁群构筑房间的不同顺序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你是一只蚂蚁，负责为蚁群构筑 n 间编号从 0 到 n-1 的新房间。给你一个 下标从 0 开始 且长度为 n 的整数数组 prevRoom 作为扩建计划。其中，prevRoom[i] 表示在构筑房间 i 之前，你必须先构筑房间 prevRoom[i] ，并且这两个房间必须 直接 相连。房间 0 已经构筑完成，所以 prevRoom[0] = -1 。扩建计划中还有一条硬性要求，在完成所有房间的构筑之后，从房间 0 可以访问到每个房间。

你一次只能构筑 一个 房间。你可以在 已经构筑好的 房间之间自由穿行，只要这些房间是 相连的 。如果房间 prevRoom[i] 已经构筑完成，那么你就可以构筑房间 i。

返回你构筑所有房间的 不同顺序的数目 。由于答案可能很大，请返回对 109 + 7 取余 的结果。

 

示例 1：


输入：prevRoom = [-1,0,1]
输出：1
解释：仅有一种方案可以完成所有房间的构筑：0 → 1 → 2
示例 2：


输入：prevRoom = [-1,0,0,1,2]
输出：6
解释：
有 6 种不同顺序：
0 → 1 → 3 → 2 → 4
0 → 2 → 4 → 1 → 3
0 → 1 → 2 → 3 → 4
0 → 1 → 2 → 4 → 3
0 → 2 → 1 → 3 → 4
0 → 2 → 1 → 4 → 3
 

提示：

n == prevRoom.length
2 <= n <= 105
prevRoom[0] == -1
对于所有的 1 <= i < n ，都有 0 <= prevRoom[i] < n
题目保证所有房间都构筑完成后，从房间 0 可以访问到每个房间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-ways-to-build-rooms-in-an-ant-colony
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<int> factorial(n);
        vector<int> inverse(n);
        vector<int> count(n, 0);  // 对每一个节点，需要统计以它为根的子树有多少个节点
        vector<int> ways(n);  // 对每一个节点，需要统计以它为根的子树构筑的方法数
        vector<vector<int>> edges(n);

        /* 1、n1个x、n2个y、n3个z...的排列方法数是(n1 + n2 + n3 + ...)! / (n1! * n2! * n3! * ...)
           2、对任意节点node，它有子节点c1、c2、c3...，构筑方法记为ways，以节点为根的子树节点个数记为count，
              首先认为子树内的节点是一样的，那么可以根据1计算出排列数；然后每个子树内的节点有ways[c1/c2/c3...]种排列，所以总的排列数就是以上相乘，
              即 (count[c1] + count[c2] + count[c3] + ...)! / (count[c1]! * count[c2]! * count[c3]! * ...) * ways[c1]! * ways[c2]! * ways[c3]! * ...。
           3、除法取模转换为乘法逆元 */

        calcFactorials(n, factorial, inverse);
        buildEdges(n, prevRoom, edges);
        DFS(0, edges, factorial, inverse, count, ways);

        return ways[0];
    }

    void calcFactorials(int n, vector<int>& factorial, vector<int>& inverse) {
        long long num = 1;
        factorial[0] = inverse[0] = 1;

        for (int i = 1; i < n; ++i) {
            num = (num * i) % mod;
            factorial[i] = (int)num;
            inverse[i] = fastPower(factorial[i], mod - 2);
        }
    }

    int fastPower(int x, int n) {
        long long ans = 1;
        int bit = 1;

        while (n != 0) {
            if ((n & bit) != 0) {
                ans = (ans * x) % mod;
            }

            n &= ~bit;
            bit <<= 1;
            x = ((long long)x * x) % mod;
        }

        return (int)ans;
    }

    void buildEdges(int n, vector<int>& prevRoom, vector<vector<int>>& edges) {
        for (int i = 1; i < n; ++i) {
            edges[prevRoom[i]].push_back(i);
        }
    }

    void DFS(int node, vector<vector<int>>& edges, vector<int>& factorial, vector<int>& inverse, vector<int>& count, vector<int>& ways) {
        ways[node] = 1;

        for (int next : edges[node]) {
            DFS(next, edges, factorial, inverse, count, ways);

            count[node] += count[next];
            ways[node] = (long long)ways[node] * ways[next] % mod * inverse[count[next]] % mod;
        }

        ways[node] = (long long)ways[node] * factorial[count[node]] % mod;
        count[node] += 1;
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prevRoom = { -1,0,1 };
    check.checkInt(1, o.waysToBuildRooms(prevRoom));

    prevRoom = { -1,0,0,1,2 };
    check.checkInt(6, o.waysToBuildRooms(prevRoom));

    prevRoom = { -1,0,0,0,1,1,2,2,3,3,4,5,8,8,9,9 };
    check.checkInt(345945600, o.waysToBuildRooms(prevRoom));

    prevRoom = { -1,0,0,0,1,1,2,2,3,3,4,5,8,8,9,9,10,11,12,13,14,15 };
    check.checkInt(229742087, o.waysToBuildRooms(prevRoom));

    prevRoom = { -1,0 };
    check.checkInt(1, o.waysToBuildRooms(prevRoom));
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
