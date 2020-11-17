/* 删除子文件夹.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你是一位系统管理员，手里有一份文件夹列表 folder，你的任务是要删除该列表中的所有 子文件夹，并以 任意顺序 返回剩下的文件夹。

我们这样定义「子文件夹」：

如果文件夹 folder[i] 位于另一个文件夹 folder[j] 下，那么 folder[i] 就是 folder[j] 的子文件夹。
文件夹的「路径」是由一个或多个按以下格式串联形成的字符串：

/ 后跟一个或者多个小写英文字母。
例如，/leetcode 和 /leetcode/problems 都是有效的路径，而空字符串和 / 不是。

 

示例 1：

输入：folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
输出：["/a","/c/d","/c/f"]
解释："/a/b/" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
示例 2：

输入：folder = ["/a","/a/b/c","/a/b/d"]
输出：["/a"]
解释：文件夹 "/a/b/c" 和 "/a/b/d/" 都会被删除，因为它们都是 "/a" 的子文件夹。
示例 3：

输入：folder = ["/a/b/c","/a/b/d","/a/b/ca"]
输出：["/a/b/c","/a/b/ca","/a/b/d"]
 

提示：

1 <= folder.length <= 4 * 10^4
2 <= folder[i].length <= 100
folder[i] 只包含小写字母和 /
folder[i] 总是以字符 / 起始
每个文件夹名都是唯一的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-sub-folders-from-the-filesystem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 27);
        isEnd = false;
    }

    bool isEnd;
    TrieNode* next[27];
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void buildDict(vector<string> folders) {
        for (string& folder : folders) {
            insert(folder);
        }
    }

    void insert(string& folder) {
        TrieNode* current = root;

        for (char c : folder) {
            int index = c == '/' ? 0 : c - 'a' + 1;
            if (current->next[index] == NULL) {
                current->next[index] = new TrieNode;
            }

            current = current->next[index];
        }

        current->isEnd = true;
    }

    void getFolders(vector<string>& folders) {
        string folder;
        bool finished = false;

        DFS(root, folder, folders);
    }

    void DFS(TrieNode* root, string& folder, vector<string>& folders) {
        if (root->isEnd) {
            folders.push_back(folder);
        }

        for (int i = 0; i < 27; ++i) {
            if (root->next[i] == NULL || (i == 0 && root->isEnd)) {
                continue;
            }
            
            folder += (i == 0 ? '/' : 'a' + i - 1);
            DFS(root->next[i], folder, folders);

            folder.pop_back();
        }
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        trie.buildDict(folder);

        vector<string> folders;
        trie.getFolders(folders);

        return folders;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> folder = { "/a","/a/b","/c/d","/c/d/e","/c/f" };
    vector<string> actual = o.removeSubfolders(folder);
    vector<string> expected = { "/a","/c/d","/c/f" };
    check.checkStringVectorRandomOrder(expected, actual);

    folder = { "/a","/a/b/c","/a/b/d" };
    actual = o.removeSubfolders(folder);
    expected = { "/a" };
    check.checkStringVectorRandomOrder(expected, actual);

    folder = { "/a/b/c","/a/b/d","/a/b/ca" };
    actual = o.removeSubfolders(folder);
    expected = { "/a/b/c","/a/b/ca","/a/b/d" };
    check.checkStringVectorRandomOrder(expected, actual);

    folder = { "/a" };
    actual = o.removeSubfolders(folder);
    expected = { "/a" };
    check.checkStringVectorRandomOrder(expected, actual);

    folder = { "/a/b/c","/a/e/f/a/b/c/d" };
    actual = o.removeSubfolders(folder);
    expected = { "/a/b/c","/a/e/f/a/b/c/d" };
    check.checkStringVectorRandomOrder(expected, actual);

    folder = { "/bo/cp/cu/cw","/dc/dd/de/dg","/bo/bp/bu/bw","/bo/cp/cu","/dc/dd/di","/dc/dd/di/dk","/dc/dd/dm/dp","/dc/ed/ee/eh","/dc/ed/ei/ek","/bo/cc/cl/co","/bo/cc/cl","/aa/ao/ax/az","/dc/dd/di/dl","/dc/dq/dr","/aa/ab","/aa/bb/bg/bj","/dc/dq/dr/dt","/dc/dd/dm","/dc/dq/dr/du","/dc/dd/de/dh" };
    actual = o.removeSubfolders(folder);
    expected = { "/aa/ab","/aa/ao/ax/az","/aa/bb/bg/bj","/bo/bp/bu/bw","/bo/cc/cl","/bo/cp/cu","/dc/dd/de/dg","/dc/dd/de/dh","/dc/dd/di","/dc/dd/dm","/dc/dq/dr","/dc/ed/ee/eh","/dc/ed/ei/ek" };
    check.checkStringVectorRandomOrder(expected, actual);
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
