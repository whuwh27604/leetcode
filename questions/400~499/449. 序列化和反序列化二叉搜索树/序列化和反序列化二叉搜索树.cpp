/* 序列化和反序列化二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化二叉搜索树。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        string encodedString = encodeValue(root->val);
        encodedString += serialize(root->left);
        encodedString += serialize(root->right);

        return encodedString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        int value = decodeValue(data, 0);
        TreeNode* root = new TreeNode(value);
        int leftEnd = 3, rightEnd = 3;
        root->left = deserialize(data, value, 4, leftEnd, rightEnd);
        root->right = deserialize(data, INT_MAX, leftEnd + 1, leftEnd, rightEnd);

        return root;
    }

    TreeNode* deserialize(string& data, int rootValue, int start, int& leftEnd, int& rightEnd) {
        if (start >= (int)data.size()) {
            return NULL;
        }

        int value = decodeValue(data, start);
        if (value > rootValue) {
            return NULL;
        }

        TreeNode* root = new TreeNode(value);
        leftEnd = start + 3;
        root->left = deserialize(data, value, start + 4, leftEnd, rightEnd);
        rightEnd = leftEnd;
        root->right = deserialize(data, rootValue, leftEnd + 1, leftEnd, rightEnd);
        leftEnd = rightEnd;

        return root;
    }

    string encodeValue(int value) {
        string encodedValue;

        for (int i = 0; i < 4; i++) {
            encodedValue += (char)value;
            value >>= 8;
        }

        return encodedValue;

    }

    int decodeValue(string& encodedValue, int start) {
        int value = 0;

        for (int i = 0; i < 4; i++) {
            value = (value << 8) + ((int)encodedValue[start + 3 - i] & 0xff);
        }

        return value;
    }
};

int main()
{
    Codec o;
    CheckResult check;

    vector<int> values = { 4,2,6,1,3,5,7 };
    TreeNode* actual = o.deserialize(o.serialize(createTree(values)));
    check.checkInt(4, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(6, actual->right->val);
    check.checkInt(1, actual->left->left->val);
    check.checkInt(3, actual->left->right->val);
    check.checkInt(5, actual->right->left->val);
    check.checkInt(7, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left->left);
    check.checkPoint(NULL, actual->left->left->right);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->right->left->left);
    check.checkPoint(NULL, actual->right->left->right);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    actual = o.deserialize(o.serialize(NULL));
    check.checkPoint(NULL, actual);

    values = { 4 };
    actual = o.deserialize(o.serialize(createTree(values)));
    check.checkInt(4, actual->val);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(NULL, actual->right);

    values = { 4,2 };
    actual = o.deserialize(o.serialize(createTree(values)));
    check.checkInt(4, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkPoint(NULL, actual->right);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);

    vector<string> svalues = { "0","-2147483648","2147483647" };
    actual = o.deserialize(o.serialize(createTree(svalues)));
    check.checkInt(0, actual->val);
    check.checkInt(INT_MIN, actual->left->val);
    check.checkInt(INT_MAX, actual->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right);

    values = { 1,0,INT_MIN,-1 };
    actual = o.deserialize(o.serialize(createTree(values)));
    check.checkInt(1, actual->val);
    check.checkInt(0, actual->left->val);
    check.checkPoint(NULL, actual->right);
    check.checkInt(-1, actual->left->left->val);
    check.checkPoint(NULL, actual->left->right);
    check.checkPoint(NULL, actual->left->left->left);
    check.checkPoint(NULL, actual->left->left->right);

    values = { -1,INT_MIN,0,INT_MIN,1 };
    actual = o.deserialize(o.serialize(createTree(values)));
    check.checkInt(-1, actual->val);
    check.checkPoint(NULL, actual->left);
    check.checkInt(0, actual->right->val);
    check.checkPoint(NULL, actual->right->left);
    check.checkInt(1, actual->right->right->val);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    values = { 5,1,INT_MIN,INT_MIN,4,2,INT_MIN,INT_MIN,3 };
    actual = o.deserialize(o.serialize(createTree(values)));
    check.checkInt(5, actual->val);
    check.checkInt(1, actual->left->val);
    check.checkPoint(NULL, actual->right);
    check.checkPoint(NULL, actual->left->left);
    check.checkInt(4, actual->left->right->val);
    check.checkInt(2, actual->left->right->left->val);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->left->right->left->left);
    check.checkInt(3, actual->left->right->left->right->val);
    check.checkPoint(NULL, actual->left->right->left->right->left);
    check.checkPoint(NULL, actual->left->right->left->right->right);

    values = { 6,2,9,1,3,7,10,-5,INT_MIN,INT_MIN,4,INT_MIN,8 };
    actual = o.deserialize(o.serialize(createTree(values)));
    check.checkInt(6, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(9, actual->right->val);
    check.checkInt(1, actual->left->left->val);
    check.checkInt(3, actual->left->right->val);
    check.checkInt(7, actual->right->left->val);
    check.checkInt(10, actual->right->right->val);
    check.checkInt(-5, actual->left->left->left->val);
    check.checkPoint(NULL, actual->left->left->right);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkInt(4, actual->left->right->right->val);
    check.checkPoint(NULL, actual->right->left->left);
    check.checkInt(8, actual->right->left->right->val);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);
    check.checkPoint(NULL, actual->left->left->left->left);
    check.checkPoint(NULL, actual->left->left->left->right);
    check.checkPoint(NULL, actual->left->right->right->left);
    check.checkPoint(NULL, actual->left->right->right->right);
    check.checkPoint(NULL, actual->right->left->right->left);
    check.checkPoint(NULL, actual->right->left->right->right);
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
