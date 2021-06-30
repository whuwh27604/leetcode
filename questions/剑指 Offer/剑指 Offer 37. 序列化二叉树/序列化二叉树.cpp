/* 序列化二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
 

注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        string data;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();

            data += node == NULL ? "null" : to_string(node->val);
            data += ",";

            if (node != NULL) {
                bfs.push(node->left);
                bfs.push(node->right);
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        char* p = const_cast<char*>(data.c_str());
        char* context;

        p = strtok_s(p, ",", &context);
        TreeNode* root = new TreeNode(stoi(p));
        p = strtok_s(NULL, ",", &context);
        queue<TreeNode*> nodes;
        nodes.push(root);

        TreeNode* current = root;
        TreeNode* node;
        int isLeft = 1;

        while (p != NULL) {
            string value(p);
            if (value == "null") {
                node = NULL;
            }
            else {
                node = new TreeNode(stoi(value));
                nodes.push(node);
            }

            if (isLeft == 1) {
                current = nodes.front();
                nodes.pop();
                current->left = node;
            }
            else {
                current->right = node;
            }

            isLeft ^= 1;
            p = strtok_s(NULL, ",", &context);
        }

        return root;
    }
};

int main()
{
    CheckResult check;
    Codec o;

    vector<int> values = { 1,2,3,INT_MIN,INT_MIN,4,5 };
    TreeNode* root = createTree(values);
    string actual = o.serialize(root);
    check.checkString("1,2,3,null,null,4,5,null,null,null,null,", actual);
    check.checkTree(root, o.deserialize(actual));

    values = {  };
    root = createTree(values);
    actual = o.serialize(root);
    check.checkString("", actual);
    check.checkTree(root, o.deserialize(actual));

    values = { -1 };
    root = createTree(values);
    actual = o.serialize(root);
    check.checkString("-1,null,null,", actual);
    check.checkTree(root, o.deserialize(actual));

    values = { 1,2 };
    root = createTree(values);
    actual = o.serialize(root);
    check.checkString("1,2,null,null,null,", actual);
    check.checkTree(root, o.deserialize(actual));

    values = { 1,INT_MIN,2 };
    root = createTree(values);
    actual = o.serialize(root);
    check.checkString("1,null,2,null,null,", actual);
    check.checkTree(root, o.deserialize(actual));
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
