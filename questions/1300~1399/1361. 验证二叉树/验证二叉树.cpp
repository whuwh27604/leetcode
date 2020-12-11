/* 验证二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
二叉树上有 n 个节点，按从 0 到 n - 1 编号，其中节点 i 的两个子节点分别是 leftChild[i] 和 rightChild[i]。

只有 所有 节点能够形成且 只 形成 一颗 有效的二叉树时，返回 true；否则返回 false。

如果节点 i 没有左子节点，那么 leftChild[i] 就等于 -1。右子节点也符合该规则。

注意：节点没有值，本问题中仅仅使用节点编号。

 

示例 1：



输入：n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
输出：true
示例 2：



输入：n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
输出：false
示例 3：



输入：n = 2, leftChild = [1,0], rightChild = [-1,-1]
输出：false
示例 4：



输入：n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
输出：false
 

提示：

1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = n;

        if (countRootEdges(n, leftChild, rightChild, root) == -1) {
            return false;
        }

        vector<bool> visited(n, false);
        int visitedCount = 0;

        if (!DFS(root, leftChild, rightChild, visited, visitedCount)) {
            return false;
        }

        return visitedCount == n;
    }

    int countRootEdges(int n, vector<int>& leftChild, vector<int>& rightChild, int& root) {
        vector<bool> isRoot(n, true);
        int edges = 0;

        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                isRoot[leftChild[i]] = false;
                ++edges;
            }

            if (rightChild[i] != -1) {
                isRoot[rightChild[i]] = false;
                ++edges;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (isRoot[i]) {
                if (root != n) {
                    return -1;  // 只能有一个root
                }

                root = i;
            }
        }

        return edges == n - 1 ? 0 : -1;  // n个节点的树必然有n-1条边
    }

    bool DFS(int root, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited, int& visitedCount) {
        if (visited[root]) {
            return false;
        }

        visited[root] = true;
        ++visitedCount;

        if (leftChild[root] != -1) {
            if (!DFS(leftChild[root], leftChild, rightChild, visited, visitedCount)) {
                return false;
            }
        }

        if (rightChild[root] != -1) {
            if (!DFS(rightChild[root], leftChild, rightChild, visited, visitedCount)) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> leftChild = { 1,-1,3,-1 };
    vector<int> rightChild = { 2,-1,-1,-1 };
    check.checkBool(true, o.validateBinaryTreeNodes(4, leftChild, rightChild));

    leftChild = { 1,-1,3,-1 };
    rightChild = { 2,3,-1,-1 };
    check.checkBool(false, o.validateBinaryTreeNodes(4, leftChild, rightChild));

    leftChild = { 1,0 };
    rightChild = { -1,-1 };
    check.checkBool(false, o.validateBinaryTreeNodes(2, leftChild, rightChild));

    leftChild = { 1,-1,-1,4,-1,-1 };
    rightChild = { 2,-1,-1,5,-1,-1 };
    check.checkBool(false, o.validateBinaryTreeNodes(6, leftChild, rightChild));

    leftChild = { -1,0 };
    rightChild = { -1,-1 };
    check.checkBool(true, o.validateBinaryTreeNodes(2, leftChild, rightChild));

    leftChild = { 1,0,3,-1 };
    rightChild = { -1,-1,-1,-1 };
    check.checkBool(false, o.validateBinaryTreeNodes(4, leftChild, rightChild));

    leftChild = { 1,2,0,-1 };
    rightChild = { -1,-1,-1,-1 };
    check.checkBool(false, o.validateBinaryTreeNodes(4, leftChild, rightChild));
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
