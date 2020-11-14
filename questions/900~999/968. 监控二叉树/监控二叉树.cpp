/* 监控二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

 

示例 1：



输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
示例 2：



输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。

提示：

给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-cameras
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int minCameras = 0;
        return DFS(root, minCameras) == NO_CAMERA ? minCameras + 1 : minCameras;  // 如果root还没有覆盖到，需要加一个
    }

    int DFS(TreeNode* root, int& minCameras) {
        if (root == NULL) {
            return NO_NEED;
        }

        int left = DFS(root->left, minCameras), right = DFS(root->right, minCameras);
        if (left == NO_CAMERA || right == NO_CAMERA) {  // 左右节点任何一个没有相机覆盖到，都需要在root放一个相机
            minCameras++;
            return HAS_CAMERA;
        }

        return left == HAS_CAMERA || right == HAS_CAMERA ? NO_NEED : NO_CAMERA;  // 左右节点任何一个有相机，root就不再需要；左右都没有相机，那么root还没有覆盖到
    }

private:
    static const int NO_CAMERA = 0;  // 没有相机覆盖，需要父节点覆盖
    static const int HAS_CAMERA = 1;  // 有相机
    static const int NO_NEED = 2;  // 不需要相机，子节点已经覆盖
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(0);
    TreeNode node2(0);
    TreeNode node3(0);
    TreeNode node4(0);
    node1.left = &node2;
    node1.right = NULL;
    node2.left = &node3;
    node2.right = &node4;
    check.checkInt(1, o.minCameraCover(&node1));

    TreeNode node5(0);
    node1.left = &node2;
    node1.right = NULL;
    node2.left = &node3;
    node2.right = NULL;
    node3.left = &node4;
    node3.right = NULL;
    node4.left = NULL;
    node4.right = &node5;
    check.checkInt(2, o.minCameraCover(&node1));

    TreeNode node6(0);
    TreeNode node7(0);
    TreeNode node8(0);
    TreeNode node9(0);
    node1.left = NULL;
    node1.right = &node2;
    node2.left = NULL;
    node2.right = &node3;
    node3.left = NULL;
    node3.right = &node4;
    node4.left = NULL;
    node4.right = &node5;
    node5.left = &node6;
    node5.right = &node7;
    node6.left = node6.right = NULL;
    node7.left = &node8;
    node7.right = &node9;
    node8.left = node8.right = NULL;
    node9.left = node9.right = NULL;
    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node6.val = 6;
    node7.val = 7;
    node8.val = 8;
    node9.val = 9;
    check.checkInt(3, o.minCameraCover(&node1));
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
