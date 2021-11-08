/* 删除系统中的重复文件夹.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
由于一个漏洞，文件系统中存在许多重复文件夹。给你一个二维数组 paths，其中 paths[i] 是一个表示文件系统中第 i 个文件夹的绝对路径的数组。

例如，["one", "two", "three"] 表示路径 "/one/two/three" 。
如果两个文件夹（不需要在同一层级）包含 非空且相同的 子文件夹 集合 并具有相同的子文件夹结构，则认为这两个文件夹是相同文件夹。相同文件夹的根层级 不 需要相同。如果存在两个（或两个以上）相同 文件夹，则需要将这些文件夹和所有它们的子文件夹 标记 为待删除。

例如，下面文件结构中的文件夹 "/a" 和 "/b" 相同。它们（以及它们的子文件夹）应该被 全部 标记为待删除：
/a
/a/x
/a/x/y
/a/z
/b
/b/x
/b/x/y
/b/z
然而，如果文件结构中还包含路径 "/b/w" ，那么文件夹 "/a" 和 "/b" 就不相同。注意，即便添加了新的文件夹 "/b/w" ，仍然认为 "/a/x" 和 "/b/x" 相同。
一旦所有的相同文件夹和它们的子文件夹都被标记为待删除，文件系统将会 删除 所有上述文件夹。文件系统只会执行一次删除操作。执行完这一次删除操作后，不会删除新出现的相同文件夹。

返回二维数组 ans ，该数组包含删除所有标记文件夹之后剩余文件夹的路径。路径可以按 任意顺序 返回。

 

示例 1：


输入：paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
输出：[["d"],["d","a"]]
解释：文件结构如上所示。
文件夹 "/a" 和 "/c"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含名为 "b" 的空文件夹。
示例 2：


输入：paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
输出：[["c"],["c","b"],["a"],["a","b"]]
解释：文件结构如上所示。
文件夹 "/a/b/x" 和 "/w"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含名为 "y" 的空文件夹。
注意，文件夹 "/a" 和 "/c" 在删除后变为相同文件夹，但这两个文件夹不会被删除，因为删除只会进行一次，且它们没有在删除前被标记。
示例 3：


输入：paths = [["a","b"],["c","d"],["c"],["a"]]
输出：[["c"],["c","d"],["a"],["a","b"]]
解释：文件系统中所有文件夹互不相同。
注意，返回的数组可以按不同顺序返回文件夹路径，因为题目对顺序没有要求。
示例 4：


输入：paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"]]
输出：[]
解释：文件结构如上所示。
文件夹 "/a/x" 和 "/b/x"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含名为 "y" 的空文件夹。
文件夹 "/a" 和 "/b"（以及它们的子文件夹）都会被标记为待删除，因为它们都包含一个名为 "z" 的空文件夹以及上面提到的文件夹 "x" 。
示例 5：


输入：paths = [["a"],["a","x"],["a","x","y"],["a","z"],["b"],["b","x"],["b","x","y"],["b","z"],["b","w"]]
输出：[["b"],["b","w"],["b","z"],["a"],["a","z"]]
解释：本例与上例的结构基本相同，除了新增 "/b/w" 文件夹。
文件夹 "/a/x" 和 "/b/x" 仍然会被标记，但 "/a" 和 "/b" 不再被标记，因为 "/b" 中有名为 "w" 的空文件夹而 "/a" 没有。
注意，"/a/z" 和 "/b/z" 不会被标记，因为相同子文件夹的集合必须是非空集合，但这两个文件夹都是空的。
 

提示：

1 <= paths.length <= 2 * 104
1 <= paths[i].length <= 500
1 <= paths[i][j].length <= 10
1 <= sum(paths[i][j].length) <= 2 * 105
path[i][j] 由小写英文字母组成
不会存在两个路径都指向同一个文件夹的情况
对于不在根层级的任意文件夹，其父文件夹也会包含在输入中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-duplicate-folders-in-system
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class FolderIndices {
public:
    int index;
    unordered_map<string, int> folderIndices;
    unordered_map<int, string> indexFolders;

    FolderIndices() : index(0) {}

    int getIndex(string& folder) {
        auto iter = folderIndices.find(folder);
        if (iter == folderIndices.end()) {
            ++index;
            folderIndices[folder] = index;
            indexFolders[index] = folder;
            return index;
        }
        else {
            return iter->second;
        }
    }

    string getFolder(int index) {
        return indexFolders[index];
    }
};

class Node {
public:
    int index;
    bool needDelete;
    map<int, Node*> children;

    Node() : index(0), needDelete(false){}
    Node(int _index) : index(_index), needDelete(false) {}
};

class Tree {
public:
    Node* root;
    FolderIndices* folderIndices;
    unordered_map<string, Node*> hashTrees;

    Tree(FolderIndices* _folderIndices) {
        folderIndices = _folderIndices;
        root = new Node;
    }

    void buildTree(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            insert(path);
        }
    }

    void insert(vector<string>& path) {
        Node* current = root;

        for (auto& folder : path) {
            int index = folderIndices->getIndex(folder);
            auto iter = current->children.find(index);
            if (iter == current->children.end()) {
                Node* node = new Node(index);
                current->children[index] = node;
                current = node;
            }
            else {
                current = iter->second;
            }
        }
    }

    string DFS4FindSame(Node* node) {
        string hashTree;

        if (!node->children.empty()) {
            for (auto iter = node->children.begin(); iter != node->children.end(); ++iter) {
                hashTree += "C";
                hashTree += DFS4FindSame(iter->second);
            }

            auto iter = hashTrees.find(hashTree);
            if (iter != hashTrees.end()) {
                iter->second->needDelete = true;
                node->needDelete = true;
            }
            else {
                hashTrees[hashTree] = node;
            }
        }

        return hashTree + "S" + to_string(node->index);
    }

    void DFS4DeleteNode(Node* node) {
        auto iter = node->children.begin();

        while (iter != node->children.end()) {
            if (iter->second->needDelete) {
                iter = node->children.erase(iter);
            }
            else {
                DFS4DeleteNode(iter->second);
                ++iter;
            }
        }
    }

    void DFS4GetFolders(Node* node, vector<string>& path, vector<vector<string>>& folderLeft) {
        if (node != root) {
            string folder = folderIndices->getFolder(node->index);
            path.push_back(folder);
            folderLeft.push_back(path);
        }

        for (auto iter = node->children.begin(); iter != node->children.end(); ++iter) {
            DFS4GetFolders(iter->second, path, folderLeft);
        }

        if (node != root) {
            path.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        FolderIndices folderIndices;
        Tree tree(&folderIndices);
        vector<string> path;
        vector<vector<string>> folderLeft;

        tree.buildTree(paths);
        (void)tree.DFS4FindSame(tree.root);
        tree.DFS4DeleteNode(tree.root);
        tree.DFS4GetFolders(tree.root, path, folderLeft);

        return folderLeft;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> paths = { {"a"},{"c"},{"d"},{"a","b"},{"c","b"},{"d","a"} };
    vector<vector<string>> actual = o.deleteDuplicateFolder(paths);
    vector<vector<string>> expected = { {"d"},{"d","a"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    paths = { {"a"},{"c"},{"a","b"},{"c","b"},{"a","b","x"},{"a","b","x","y"},{"w"},{"w","y"} };
    actual = o.deleteDuplicateFolder(paths);
    expected = { {"c"},{"c","b"},{"a"},{"a","b"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    paths = { {"a","b"},{"c","d"},{"c"},{"a"} };
    actual = o.deleteDuplicateFolder(paths);
    expected = { {"c"},{"c","d"},{"a"},{"a","b"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    paths = { {"a"},{"a","x"},{"a","x","y"},{"a","z"},{"b"},{"b","x"},{"b","x","y"},{"b","z"} };
    actual = o.deleteDuplicateFolder(paths);
    expected = {};
    check.checkStringVectorRandomOrderVector(expected, actual);

    paths = { {"a"},{"a","x"},{"a","x","y"},{"a","z"},{"b"},{"b","x"},{"b","x","y"},{"b","z"},{"b","w"} };
    actual = o.deleteDuplicateFolder(paths);
    expected = { {"b"},{"b","w"},{"b","z"},{"a"},{"a","z"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    paths = { {"y"},{"y","b"},{"y","b","a"},{"y","d"},{"y","d","c"},{"z"},{"z","d"},{"z","d","c"},{"z","d","c","b"},{"z","d","c","b","a"} };
    actual = o.deleteDuplicateFolder(paths);
    expected = { {"y"},{"z"},{"y","d"},{"z","d"},{"y","d","c"},{"z","d","c"} };
    check.checkStringVectorRandomOrderVector(expected, actual);

    paths = { {"b"},{"b","d"},{"b","d","d"},{"b","e"},{"c"},{"c","d"},{"c","e"},{"c","e","d"} };
    actual = o.deleteDuplicateFolder(paths);
    expected = { {"b"},{"c"},{"b","e"},{"c","d"} };
    check.checkStringVectorRandomOrderVector(expected, actual);
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
