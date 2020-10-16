/* 建立四叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n * n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵 grid 。

你需要返回能表示矩阵的 四叉树 的根结点。

注意，当 isLeaf 为 False 时，你可以把 True 或者 False 赋值给节点，两种值都会被判题机制 接受 。

四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：

val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False；
isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
我们可以按以下步骤为二维区域构建四叉树：

如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null 然后停止。
如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
使用适当的子网格递归每个子节点。


如果你想了解更多关于四叉树的内容，可以参考 wiki 。

四叉树格式：

输出为使用层序遍历后四叉树的序列化形式，其中 null 表示路径终止符，其下面不存在节点。

它与二叉树的序列化非常相似。唯一的区别是节点以列表形式表示 [isLeaf, val] 。

如果 isLeaf 或者 val 的值为 True ，则表示它在列表 [isLeaf, val] 中的值为 1 ；如果 isLeaf 或者 val 的值为 False ，则表示值为 0 。

 

示例 1：



输入：grid = [[0,1],[1,0]]
输出：[[0,1],[1,0],[1,1],[1,1],[1,0]]
解释：此示例的解释如下：
请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。

示例 2：



输入：grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
输出：[[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
解释：网格中的所有值都不相同。我们将网格划分为四个子网格。
topLeft，bottomLeft 和 bottomRight 均具有相同的值。
topRight 具有不同的值，因此我们将其再分为 4 个子网格，这样每个子网格都具有相同的值。
解释如下图所示：

示例 3：

输入：grid = [[1,1],[1,1]]
输出：[[1,1]]
示例 4：

输入：grid = [[0]]
输出：[[1,0]]
示例 5：

输入：grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
输出：[[0,1],[1,1],[1,0],[1,0],[1,1]]
 

提示：

n == grid.length == grid[i].length
n == 2^x 其中 0 <= x <= 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-quad-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/QuadTreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int size = grid.size();
        return construct(grid, 1, size + 1, 1, size + 1);
    }

    Node* construct(vector<vector<int>>& grid, int rowStart, int rowEnd, int columnStart, int columnEnd) {
        if ((rowStart + 1) == rowEnd) {
            return new Node(grid[rowStart - 1][columnStart - 1], true);
        }

        Node* node = new Node();
        Node* topLeft = construct(grid, rowStart, (rowEnd + rowStart) / 2, columnStart, (columnEnd + columnStart) / 2);
        Node* topRight = construct(grid, rowStart, (rowEnd + rowStart) / 2, (columnEnd + columnStart) / 2, columnEnd);
        Node* bottomLeft = construct(grid, (rowEnd + rowStart) / 2, rowEnd, columnStart, (columnEnd + columnStart) / 2);
        Node* bottomRight = construct(grid, (rowEnd + rowStart) / 2, rowEnd, (columnEnd + columnStart) / 2, columnEnd);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf
            && (topLeft->val == topRight->val) && (topLeft->val == bottomLeft->val) && (topLeft->val == bottomRight->val)) {
            node->val = topLeft->val;
            node->isLeaf = true;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
        }
        else {
            node->topLeft = topLeft;
            node->topRight = topRight;
            node->bottomLeft = bottomLeft;
            node->bottomRight = bottomRight;
        }

        return node;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {0} };
    Node* actual = o.construct(grid);
    check.checkBool(false, actual->val);
    check.checkBool(true, actual->isLeaf);
    check.checkPoint(NULL, actual->topLeft);
    check.checkPoint(NULL, actual->topRight);
    check.checkPoint(NULL, actual->bottomLeft);
    check.checkPoint(NULL, actual->bottomRight);

    grid = { {1,1},{1,1} };
    actual = o.construct(grid);
    check.checkBool(true, actual->val);
    check.checkBool(true, actual->isLeaf);
    check.checkPoint(NULL, actual->topLeft);
    check.checkPoint(NULL, actual->topRight);
    check.checkPoint(NULL, actual->bottomLeft);
    check.checkPoint(NULL, actual->bottomRight);

    grid = { {0,1},{1,0} };
    actual = o.construct(grid);
    check.checkBool(false, actual->isLeaf);
    check.checkBool(true, actual->topLeft->isLeaf);
    check.checkBool(false, actual->topLeft->val);
    check.checkBool(true, actual->topRight->isLeaf);
    check.checkBool(true, actual->topRight->val);
    check.checkBool(true, actual->bottomLeft->isLeaf);
    check.checkBool(true, actual->bottomLeft->val);
    check.checkBool(true, actual->bottomRight->isLeaf);
    check.checkBool(false, actual->bottomRight->val);
    check.checkPoint(NULL, actual->topLeft->topLeft);
    check.checkPoint(NULL, actual->topRight->topRight);
    check.checkPoint(NULL, actual->bottomLeft->bottomLeft);
    check.checkPoint(NULL, actual->bottomRight->bottomRight);

    grid = { {1,1,0,0},{1,1,0,0},{0,0,1,1},{0,0,1,1} };
    actual = o.construct(grid);
    check.checkBool(false, actual->isLeaf);
    check.checkBool(true, actual->topLeft->isLeaf);
    check.checkBool(true, actual->topLeft->val);
    check.checkBool(true, actual->topRight->isLeaf);
    check.checkBool(false, actual->topRight->val);
    check.checkBool(true, actual->bottomLeft->isLeaf);
    check.checkBool(false, actual->bottomLeft->val);
    check.checkBool(true, actual->bottomRight->isLeaf);
    check.checkBool(true, actual->bottomRight->val);
    check.checkPoint(NULL, actual->topLeft->topLeft);
    check.checkPoint(NULL, actual->topRight->topRight);
    check.checkPoint(NULL, actual->bottomLeft->bottomLeft);
    check.checkPoint(NULL, actual->bottomRight->bottomRight);

    grid = { {1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0},{1,1,1,1,0,0,0,0} };
    actual = o.construct(grid);
    check.checkBool(false, actual->isLeaf);
    check.checkBool(true, actual->topLeft->isLeaf);
    check.checkBool(true, actual->topLeft->val);
    check.checkBool(false, actual->topRight->isLeaf);
    check.checkBool(true, actual->bottomLeft->isLeaf);
    check.checkBool(true, actual->bottomLeft->val);
    check.checkBool(true, actual->bottomRight->isLeaf);
    check.checkBool(false, actual->bottomRight->val);
    check.checkBool(true, actual->topRight->topLeft->isLeaf);
    check.checkBool(false, actual->topRight->topLeft->val);
    check.checkBool(true, actual->topRight->topRight->isLeaf);
    check.checkBool(false, actual->topRight->topRight->val);
    check.checkBool(true, actual->topRight->bottomLeft->isLeaf);
    check.checkBool(true, actual->topRight->bottomLeft->val);
    check.checkBool(true, actual->topRight->bottomRight->isLeaf);
    check.checkBool(true, actual->topRight->bottomRight->val);
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
