/* 验证二叉树的前序序列化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 #。

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。

给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。

你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。

示例 1:

输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
输出: true
示例 2:

输入: "1,#"
输出: false
示例 3:

输入: "9,#,#,1"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) {
            return false;
        }

        if (preorder[0] == '#') {
            return preorder.size() == 1;
        }

        preorder.push_back(',');
        int position = preorder.find(',', 0);
        stack<int> nodes;
        nodes.push(0);  // root

        while ((position = preorder.find(',', position + 1)) != preorder.npos) {
            if (nodes.empty()) {
                return false;
            }

            if (preorder[position - 1] != '#') {
                nodes.push(0);
                continue;
            }

            int node = nodes.top();
            nodes.pop();
            if ((++node) == 1) {
                nodes.push(node);
                continue;
            }

            while (!nodes.empty()) {
                int node = nodes.top();
                nodes.pop();
                if (node == 0) {
                    nodes.push(1);
                    break;
                }
            }
        }

        return nodes.empty();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(false, o.isValidSerialization(""));
    check.checkBool(true, o.isValidSerialization("#"));
    check.checkBool(false, o.isValidSerialization("#,#"));
    check.checkBool(false, o.isValidSerialization("1"));
    check.checkBool(false, o.isValidSerialization("123,#"));
    check.checkBool(true, o.isValidSerialization("12,#,#"));
    check.checkBool(false, o.isValidSerialization("12,#,#,1"));
    check.checkBool(false, o.isValidSerialization("12,#,#,#"));
    check.checkBool(true, o.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
    check.checkBool(true, o.isValidSerialization("1,2,4,#,#,5,#,#,3,6,#,#,7,#,#"));
    check.checkBool(false, o.isValidSerialization("1,#,2,4,#,#,5,#,#,3,6,#,#,7,#,#"));
    check.checkBool(false, o.isValidSerialization("1,2,#,4,#,#,5,#,#,3,6,#,#,7,#,#"));
    check.checkBool(false, o.isValidSerialization("1,2,4,#,#,#,5,#,#,3,6,#,#,7,#,#"));
    check.checkBool(false, o.isValidSerialization("1,2,4,#,#,5,#,#,#,3,6,#,#,7,#,#"));
    check.checkBool(false, o.isValidSerialization("1,2,4,#,#,5,#,#,3,#,6,#,#,7,#,#"));
    check.checkBool(false, o.isValidSerialization("1,2,4,#,#,5,#,#,3,6,#,#,#,7,#,#"));
    check.checkBool(false, o.isValidSerialization("1,2,4,#,#,5,#,#,3,6,#,#,7,#,#,#"));
    check.checkBool(true, o.isValidSerialization("12,1,#,#,#"));
    check.checkBool(false, o.isValidSerialization("12,#,1,#,#,#"));
    check.checkBool(false, o.isValidSerialization("12,1,#,#,#,#"));
    check.checkBool(false, o.isValidSerialization("12,1,#,#,#,#,#"));
    check.checkBool(true, o.isValidSerialization("12,#,1,#,#"));
    check.checkBool(false, o.isValidSerialization("12,#,#,1,#,#"));
    check.checkBool(true, o.isValidSerialization("1,1,1,#,#,#,#"));
    check.checkBool(false, o.isValidSerialization("1,#,1,1,#,#,#,#"));
    check.checkBool(false, o.isValidSerialization("1,1,#,1,#,#,#,#"));
    check.checkBool(false, o.isValidSerialization("1,1,1,#,#,#,#,#"));
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
