/* 相邻字符不同的最长路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 树（即一个连通、无向、无环图），根节点是节点 0 ，这棵树由编号从 0 到 n - 1 的 n 个节点组成。用下标从 0 开始、长度为 n 的数组 parent 来表示这棵树，其中 parent[i] 是节点 i 的父节点，由于节点 0 是根节点，所以 parent[0] == -1 。

另给你一个字符串 s ，长度也是 n ，其中 s[i] 表示分配给节点 i 的字符。

请你找出路径上任意一对相邻节点都没有分配到相同字符的 最长路径 ，并返回该路径的长度。

 

示例 1：



输入：parent = [-1,0,0,1,1,2], s = "abacbe"
输出：3
解释：任意一对相邻节点字符都不同的最长路径是：0 -> 1 -> 3 。该路径的长度是 3 ，所以返回 3 。
可以证明不存在满足上述条件且比 3 更长的路径。
示例 2：



输入：parent = [-1,0,0,0], s = "aabc"
输出：3
解释：任意一对相邻节点字符都不同的最长路径是：2 -> 0 -> 3 。该路径的长度为 3 ，所以返回 3 。
 

提示：

n == parent.length == s.length
1 <= n <= 105
对所有 i >= 1 ，0 <= parent[i] <= n - 1 均成立
parent[0] == -1
parent 表示一棵有效的树
s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-path-with-different-adjacent-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size(), maxPath = 0;
        vector<vector<int>> children(n);

        int root = getChildren(n, parent, children);
        (void)DFS(root, children, s, maxPath);

        return maxPath;
    }

    int getChildren(int n, vector<int>& parent, vector<vector<int>>& children) {
        int root = 0;

        for (int node = 0; node < n; ++node) {
            if (parent[node] == -1) {
                root = node;
            }
            else {
                children[parent[node]].push_back(node);
            }
        }

        return root;
    }

    int DFS(int root, vector<vector<int>>& children, string& s, int& maxPath) {
        int first = 0, second = 0;

        for (int child : children[root]) {
            int longest = DFS(child, children, s, maxPath);

            if (s[root] != s[child]) {
                if (longest >= first) {
                    second = first;
                    first = longest;
                }
                else if (longest > second) {
                    second = longest;
                }
            }
        }

        maxPath = max(maxPath, first + second + 1);

        return first + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> parent = { -1,0,0,1,1,2 };
    check.checkInt(3, o.longestPath(parent, "abacbe"));

    parent = { -1,0,0,0 };
    check.checkInt(3, o.longestPath(parent, "aabc"));

    parent = { -1 };
    check.checkInt(1, o.longestPath(parent, "z"));

    parent = { -1,137,65,60,73,138,81,17,45,163,145,99,29,162,19,20,132,132,13,60,21,18,155,65,13,163,125,102,96,60,50,101,100,86,162,42,162,94,21,56,45,56,13,23,101,76,57,89,4,161,16,139,29,60,44,127,19,68,71,55,13,36,148,129,75,41,107,91,52,42,93,85,125,89,132,13,141,21,152,21,79,160,130,103,46,65,71,33,129,0,19,148,65,125,41,38,104,115,130,164,138,108,65,31,13,60,29,116,26,58,118,10,138,14,28,91,60,47,2,149,99,28,154,71,96,60,106,79,129,83,42,102,34,41,55,31,154,26,34,127,42,133,113,125,113,13,54,132,13,56,13,42,102,135,130,75,25,80,159,39,29,41,89,85,19 };
    check.checkInt(17, o.longestPath(parent, "ajunvefrdrpgxltugqqrwisyfwwtldxjgaxsbbkhvuqeoigqssefoyngykgtthpzvsxgxrqedntvsjcpdnupvqtroxmbpsdwoswxfarnixkvcimzgvrevxnxtkkovwxcjmtgqrrsqyshxbfxptuvqrytctujnzzydhpal"));
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
