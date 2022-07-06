/* 二叉树的序列化与反序列化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例 1：


输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：

输入：root = [1,2]
输出：[1,2]
 

提示：

树中结点数在范围 [0, 104] 内
-1000 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/serialize-and-deserialize-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;

        serialize(root, s);

        return s;
    }

    void serialize(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "n,";
        }
        else {
            s += to_string(root->val);
            s += ',';
            serialize(root->left, s);
            serialize(root->right, s);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;

        return deserialize(data, index);
    }

    TreeNode* deserialize(string& s, int& index) {
        if (s[index] == 'n') {
            index += 2;
            return NULL;
        }

        string value;

        for (; s[index] != ','; ++index) {
            value += s[index];
        }

        ++index;
        TreeNode* root = new TreeNode(stoi(value));
        TreeNode* left = deserialize(s, index);
        TreeNode* right = deserialize(s, index);
        root->left = left;
        root->right = right;

        return root;
    }
};

int main()
{
    CheckResult check;
    Codec o;

    vector<int> values = { 1,2,3,INT_MIN,INT_MIN,INT_MIN,4 };
    TreeNode* root = createTree(values);
    string tree = o.serialize(root);
    TreeNode* actual = o.deserialize(tree);
    check.checkTree(root, actual);

    values = { 1,2,3,INT_MIN,INT_MIN,4,5 };
    root = createTree(values);
    tree = o.serialize(root);
    actual = o.deserialize(tree);
    check.checkTree(root, actual);

    values = {  };
    root = createTree(values);
    tree = o.serialize(root);
    actual = o.deserialize(tree);
    check.checkTree(root, actual);

    values = { 1 };
    root = createTree(values);
    tree = o.serialize(root);
    actual = o.deserialize(tree);
    check.checkTree(root, actual);

    values = { 1,2 };
    root = createTree(values);
    tree = o.serialize(root);
    actual = o.deserialize(tree);
    check.checkTree(root, actual);
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
