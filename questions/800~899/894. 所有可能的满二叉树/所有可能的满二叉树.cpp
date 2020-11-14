/* 所有可能的满二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。

返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。

答案中每个树的每个结点都必须有 node.val=0。

你可以按任何顺序返回树的最终列表。

 

示例：

输入：7
输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
解释：

 

提示：

1 <= N <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-possible-full-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> FBTs;
        if (N % 2 == 0) {
            return FBTs;
        }

        vector<vector<TreeNode*>> allFBTs(N + 1, vector<TreeNode*>{});
        allFBTs[1].push_back(new TreeNode(0));

        return allPossibleFBTs(N, allFBTs);
    }

    vector<TreeNode*> allPossibleFBTs(int n, vector<vector<TreeNode*>>& allFBTs) {
        if (!allFBTs[n].empty()) {
            return allFBTs[n];
        }

        for (int i = n - 2; i > 0; i -= 2) {
            vector<TreeNode*> leftFBTs = allPossibleFBTs(i, allFBTs);
            vector<TreeNode*> rightFBTs = allPossibleFBTs(n - 1 - i, allFBTs);

            for (TreeNode* left : leftFBTs) {
                for (TreeNode* right : rightFBTs) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    allFBTs[n].push_back(root);
                }
            }
        }

        return allFBTs[n];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<TreeNode*> actual = o.allPossibleFBT(1);
    check.checkInt(1, actual.size());

    actual = o.allPossibleFBT(2);
    check.checkInt(0, actual.size());
    
    actual = o.allPossibleFBT(3);
    check.checkInt(1, actual.size());

    actual = o.allPossibleFBT(4);
    check.checkInt(0, actual.size());

    actual = o.allPossibleFBT(5);
    check.checkInt(2, actual.size());

    actual = o.allPossibleFBT(7);
    check.checkInt(5, actual.size());

    actual = o.allPossibleFBT(9);
    check.checkInt(14, actual.size());
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
