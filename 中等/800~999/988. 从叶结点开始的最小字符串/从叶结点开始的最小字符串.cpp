/* 从叶结点开始的最小字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一颗根结点为 root 的二叉树，树中的每一个结点都有一个从 0 到 25 的值，分别代表字母 'a' 到 'z'：值 0 代表 'a'，值 1 代表 'b'，依此类推。

找出按字典序最小的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束。

（小贴士：字符串中任何较短的前缀在字典序上都是较小的：例如，在字典序上 "ab" 比 "aba" 要小。叶结点是指没有子结点的结点。）

 

示例 1：



输入：[0,1,2,3,4,3,4]
输出："dba"
示例 2：



输入：[25,1,3,1,3,0,2]
输出："adz"
示例 3：



输入：[2,2,1,null,1,0,null,0]
输出："abc"
 

提示：

给定树的结点数介于 1 和 8500 之间。
树中的每个结点都有一个介于 0 和 25 之间的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-starting-from-leaf
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string path, smallestPath(1, '{');

        DFS(root, path, smallestPath);
        reverse(smallestPath.begin(), smallestPath.end());

        return smallestPath;
    }

    void DFS(TreeNode* root, string& path, string& smallestPath) {
        path += ('a' + root->val);

        if (root->left != NULL) {
            DFS(root->left, path, smallestPath);
        }

        if (root->right != NULL) {
            DFS(root->right, path, smallestPath);
        }

        if (root->left == NULL && root->right == NULL) {
            comparePath(path, smallestPath);
        }

        path.pop_back();
    }

    void comparePath(string& path, string& smallestPath) {
        int i, sizeP = path.size(), sizeSP = smallestPath.size(), size = min(sizeP, sizeSP);

        for (i = 0; i < size; ++i) {
            if (path[sizeP - 1 - i] > smallestPath[sizeSP - 1 - i]) {
                return;
            }

            if (path[sizeP - 1 - i] < smallestPath[sizeSP - 1 - i]) {
                smallestPath = path;
                return;
            }
        }

        if (sizeP < sizeSP) {
            smallestPath = path;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 0,1,2,3,4,3,4 };
    check.checkString("dba", o.smallestFromLeaf(createTree(values)));

    values = { 25,1,3,1,3,0,2 };
    check.checkString("adz", o.smallestFromLeaf(createTree(values)));

    values = { 2,2,1,INT_MIN,1,0,INT_MIN,0 };
    check.checkString("abc", o.smallestFromLeaf(createTree(values)));

    values = { 1,1,1,1 };
    check.checkString("bb", o.smallestFromLeaf(createTree(values)));

    values = { 1,1,1,2,2,INT_MIN,INT_MIN,2,1 };
    check.checkString("bb", o.smallestFromLeaf(createTree(values)));

    values = { 4,0,1,1 };
    check.checkString("bae", o.smallestFromLeaf(createTree(values)));

    values = { 25 };
    check.checkString("z", o.smallestFromLeaf(createTree(values)));

    values = { 3,9,20,INT_MIN,INT_MIN,15,7 };
    check.checkString("hud", o.smallestFromLeaf(createTree(values)));
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
