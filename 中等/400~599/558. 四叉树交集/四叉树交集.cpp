/* 四叉树交集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
二进制矩阵中的所有元素不是 0 就是 1 。

给你两个四叉树，quadTree1 和 quadTree2。其中 quadTree1 表示一个 n * n 二进制矩阵，而 quadTree2 表示另一个 n * n 二进制矩阵。

请你返回一个表示 n * n 二进制矩阵的四叉树，它是 quadTree1 和 quadTree2 所表示的两个二进制矩阵进行 按位逻辑或运算 的结果。

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



输入：quadTree1 = [[0,1],[1,1],[1,1],[1,0],[1,0]]
, quadTree2 = [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
输出：[[0,0],[1,1],[1,1],[1,1],[1,0]]
解释：quadTree1 和 quadTree2 如上所示。由四叉树所表示的二进制矩阵也已经给出。
如果我们对这两个矩阵进行按位逻辑或运算，则可以得到下面的二进制矩阵，由一个作为结果的四叉树表示。
注意，我们展示的二进制矩阵仅仅是为了更好地说明题意，你无需构造二进制矩阵来获得结果四叉树。

示例 2：

输入：quadTree1 = [[1,0]]
, quadTree2 = [[1,0]]
输出：[[1,0]]
解释：两个数所表示的矩阵大小都为 1*1，值全为 0
结果矩阵大小为 1*1，值全为 0 。
示例 3：

输入：quadTree1 = [[0,0],[1,0],[1,0],[1,1],[1,1]]
, quadTree2 = [[0,0],[1,1],[1,1],[1,0],[1,1]]
输出：[[1,1]]
示例 4：

输入：quadTree1 = [[0,0],[1,1],[1,0],[1,1],[1,1]]
, quadTree2 = [[0,0],[1,1],[0,1],[1,1],[1,1],null,null,null,null,[1,1],[1,0],[1,0],[1,1]]
输出：[[0,0],[1,1],[0,1],[1,1],[1,1],null,null,null,null,[1,1],[1,0],[1,0],[1,1]]
示例 5：

输入：quadTree1 = [[0,1],[1,0],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
, quadTree2 = [[0,1],[0,1],[1,0],[1,1],[1,0],[1,0],[1,0],[1,1],[1,1]]
输出：[[0,0],[0,1],[0,1],[1,1],[1,0],[1,0],[1,0],[1,1],[1,1],[1,0],[1,0],[1,1],[1,1]]
 

提示：

quadTree1 和 quadTree2 都是符合题目要求的四叉树，每个都代表一个 n * n 的矩阵。
n == 2^x ，其中 0 <= x <= 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/logical-or-of-two-binary-grids-represented-as-quad-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/QuadTreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        }
        if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }

        Node* node = new Node();
        Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf
            && (topLeft->val == topRight->val) && (topLeft->val == bottomLeft->val) && (topLeft->val == bottomRight->val)) {
            node->val = topLeft->val;
            node->isLeaf = true;
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

    Node node111(true, true);
    Node node112(true, true);
    Node node113(false, true);
    Node node114(false, true);
    Node node115(false, false, &node111, &node112, &node113, &node114);
    Node node121(false, true);
    Node node122(false, true);
    Node node123(true, true);
    Node node124(true, true);
    Node node125(false, false, &node121, &node122, &node123, &node124);
    Node node126(true, true);
    Node node127(true, true);
    Node node128(false, true);
    Node node129(false, false, &node126, &node125, &node127, &node128);
    Node* actual = o.intersect(&node115, &node129);
    check.checkBool(false, actual->isLeaf);
    check.checkBool(true, actual->topLeft->isLeaf);
    check.checkBool(true, actual->topLeft->val);
    check.checkBool(true, actual->topRight->isLeaf);
    check.checkBool(true, actual->topRight->val);
    check.checkBool(true, actual->bottomLeft->isLeaf);
    check.checkBool(true, actual->bottomLeft->val);
    check.checkBool(true, actual->bottomRight->isLeaf);
    check.checkBool(false, actual->bottomRight->val);

    Node node211(false, true);
    Node node221(false, true);
    actual = o.intersect(&node211, &node221);
    check.checkBool(true, actual->isLeaf);
    check.checkBool(false, actual->val);

    Node node311(false, true);
    Node node312(false, true);
    Node node313(true, true);
    Node node314(true, true);
    Node node315(false, false, &node311, &node312, &node313, &node314);
    Node node321(true, true);
    Node node322(true, true);
    Node node323(false, true);
    Node node324(true, true);
    Node node325(false, false, &node321, &node322, &node323, &node324);
    actual = o.intersect(&node315, &node325);
    check.checkBool(true, actual->isLeaf);
    check.checkBool(true, actual->val);

    Node node411(true, true);
    Node node412(false, true);
    Node node413(true, true);
    Node node414(true, true);
    Node node415(false, false, &node411, &node412, &node413, &node414);
    Node node421(true, true);
    Node node422(false, true);
    Node node423(false, true);
    Node node424(true, true);
    Node node425(false, false, &node421, &node422, &node423, &node424);
    Node node426(true, true);
    Node node427(true, true);
    Node node428(true, true);
    Node node429(false, false, &node426, &node425, &node427, &node428);
    actual = o.intersect(&node415, &node429);
    check.checkBool(false, actual->isLeaf);
    check.checkBool(true, actual->topLeft->isLeaf);
    check.checkBool(true, actual->topLeft->val);
    check.checkBool(false, actual->topRight->isLeaf);
    check.checkBool(true, actual->topRight->topLeft->isLeaf);
    check.checkBool(true, actual->topRight->topLeft->val);
    check.checkBool(true, actual->topRight->topRight->isLeaf);
    check.checkBool(false, actual->topRight->topRight->val);
    check.checkBool(true, actual->topRight->bottomLeft->isLeaf);
    check.checkBool(false, actual->topRight->bottomLeft->val);
    check.checkBool(true, actual->topRight->bottomRight->isLeaf);
    check.checkBool(true, actual->topRight->bottomRight->val);
    check.checkBool(true, actual->bottomLeft->isLeaf);
    check.checkBool(true, actual->bottomLeft->val);
    check.checkBool(true, actual->bottomRight->isLeaf);
    check.checkBool(true, actual->bottomRight->val);

    Node node511(false, true);
    Node node512(false, true);
    Node node513(true, true);
    Node node514(true, true);
    Node node515(false, false, &node511, &node512, &node513, &node514);
    Node node516(false, true);
    Node node517(true, true);
    Node node518(false, true);
    Node node519(false, false, &node516, &node515, &node517, &node518);
    Node node521(false, true);
    Node node522(false, true);
    Node node523(true, true);
    Node node524(true, true);
    Node node525(false, false, &node521, &node522, &node523, &node524);
    Node node526(false, true);
    Node node527(true, true);
    Node node528(false, true);
    Node node529(false, false, &node525, &node526, &node527, &node528);
    actual = o.intersect(&node519, &node529);
    check.checkBool(false, actual->isLeaf);
    check.checkBool(false, actual->topLeft->isLeaf);
    check.checkBool(true, actual->topLeft->topLeft->isLeaf);
    check.checkBool(false, actual->topLeft->topLeft->val);
    check.checkBool(true, actual->topLeft->topRight->isLeaf);
    check.checkBool(false, actual->topLeft->topRight->val);
    check.checkBool(true, actual->topLeft->bottomLeft->isLeaf);
    check.checkBool(true, actual->topLeft->bottomLeft->val);
    check.checkBool(true, actual->topLeft->bottomRight->isLeaf);
    check.checkBool(true, actual->topLeft->bottomRight->val);
    check.checkBool(false, actual->topRight->isLeaf);
    check.checkBool(true, actual->topRight->topLeft->isLeaf);
    check.checkBool(false, actual->topRight->topLeft->val);
    check.checkBool(true, actual->topRight->topRight->isLeaf);
    check.checkBool(false, actual->topRight->topRight->val);
    check.checkBool(true, actual->topRight->bottomLeft->isLeaf);
    check.checkBool(true, actual->topRight->bottomLeft->val);
    check.checkBool(true, actual->topRight->bottomRight->isLeaf);
    check.checkBool(true, actual->topRight->bottomRight->val);
    check.checkBool(true, actual->bottomLeft->isLeaf);
    check.checkBool(true, actual->bottomLeft->val);
    check.checkBool(true, actual->bottomRight->isLeaf);
    check.checkBool(false, actual->bottomRight->val);
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
