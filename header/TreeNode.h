#ifndef __TREENODE_H__
#define __TREENODE_H__

#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

extern TreeNode* createTree(std::vector<int>& values);

#endif