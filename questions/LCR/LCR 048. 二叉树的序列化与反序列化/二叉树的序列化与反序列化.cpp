/* 二叉树的序列化与反序列化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。



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

输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，也可以采用其他的方法解决这个问题。
树中结点数在范围 [0, 104] 内
-1000 <= Node.val <= 1000


注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return DFS(root);
    }

    string DFS(TreeNode* root) {
        string ans;

        if (root == NULL) {
            return ans;
        }

        ans = to_string(root->val);
        string left = DFS(root->left);
        ans += 'L';
        ans += to_string(left.size());
        ans += 'L';
        ans += left;
        string right = DFS(root->right);
        ans += 'R';
        ans += to_string(right.size());
        ans += 'R';
        ans += right;

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return DFS(data, 0, data.size());
    }

    TreeNode* DFS(string& data, int start, int size) {
        if (size == 0) {
            return NULL;
        }

        int pos = data.find('L', start);
        TreeNode* node = new TreeNode(stoi(string(data, start, pos - start)));
        int pos1 = data.find('L', pos + 1);
        int len = stoi(string(data, pos + 1, pos1 - pos - 1));
        TreeNode* left = DFS(data, pos1 + 1, len);

        pos = pos1 + len + 1;
        pos1 = data.find('R', pos + 1);
        len = stoi(string(data, pos + 1, pos1 - pos - 1));
        TreeNode* right = DFS(data, pos1 + 1, len);

        node->left = left;
        node->right = right;

        return node;
    }
};

int main()
{
    CheckResult check;
    Codec o;

    vector<int> values = {};
    TreeNode* expected = createTree(values);
    TreeNode* actual = o.deserialize(o.serialize(expected));
    check.checkTree(expected, actual);

    values = { 1 };
    expected = createTree(values);
    actual = o.deserialize(o.serialize(expected));
    check.checkTree(expected, actual);

    values = { 1,2 };
    expected = createTree(values);
    actual = o.deserialize(o.serialize(expected));
    check.checkTree(expected, actual);

    values = { 1,2,3,INT_MIN,INT_MIN,4,5 };
    expected = createTree(values);
    actual = o.deserialize(o.serialize(expected));
    check.checkTree(expected, actual);
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
