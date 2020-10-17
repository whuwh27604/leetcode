
#include <iostream>
#include <queue>
#include <sstream>
#include "../header/TreeNode.h"

using namespace std;

int getNumber(string& value) {
	stringstream ss;
	ss << value;
	int number;
	ss >> number;
	return number;
}

TreeNode* createTree(vector<int>& values) {
	int i, size = values.size();
	TreeNode* root = new TreeNode(values[0]);
	queue<TreeNode*> nodes;
	nodes.push(root);

	TreeNode* current = root;
	TreeNode* node;

	for (i = 1; i < size; ++i) {
		if (values[i] == INT_MIN) {
			node = NULL;
		}
		else {
			node = new TreeNode(values[i]);
			nodes.push(node);
		}

		if (i % 2 == 1) {
			current = nodes.front();
			nodes.pop();
			current->left = node;
		}
		else {
			current->right = node;
		}
	}

	return root;
}

TreeNode* createTree(vector<string>& values) {
	int i, size = values.size();
	TreeNode* root = new TreeNode(getNumber(values[0]));
	queue<TreeNode*> nodes;
	nodes.push(root);

	TreeNode* current = root;
	TreeNode* node;

	for (i = 1; i < size; ++i) {
		if (values[i] == "null") {
			node = NULL;
		}
		else {
			node = new TreeNode(getNumber(values[i]));
			nodes.push(node);
		}

		if (i % 2 == 1) {
			current = nodes.front();
			nodes.pop();
			current->left = node;
		}
		else {
			current->right = node;
		}
	}

	return root;
}
