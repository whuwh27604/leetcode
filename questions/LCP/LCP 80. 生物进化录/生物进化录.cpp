/* 生物进化录.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在永恒之森中，存在着一本生物进化录，以 一个树形结构 记载了所有生物的演化过程。经过观察并整理了各节点间的关系，parents[i] 表示编号 i 节点的父节点编号(根节点的父节点为 -1)。

为了探索和记录其中的演化规律，队伍中的炼金术师提出了一种方法，可以以字符串的形式将其复刻下来，规则如下：

初始只有一个根节点，表示演化的起点，依次记录 01 字符串中的字符，
如果记录 0，则在当前节点下添加一个子节点，并将指针指向新添加的子节点；
如果记录 1，则将指针回退到当前节点的父节点处。
现在需要应用上述的记录方法，复刻下它的演化过程。请返回能够复刻演化过程的字符串中， 字典序最小 的 01 字符串。

注意：

节点指针最终可以停在任何节点上，不一定要回到根节点。
示例 1：

输入：parents = [-1,0,0,2]

输出："00110"

解释：树结构如下图所示，共存在 2 种记录方案： 第 1 种方案为：0(记录编号 1 的节点) -> 1(回退至节点 0) -> 0(记录编号 2 的节点) -> 0((记录编号 3 的节点)) 第 2 种方案为：0(记录编号 2 的节点) -> 0(记录编号 3 的节点) -> 1(回退至节点 2) -> 1(回退至节点 0) -> 0(记录编号 1 的节点) 返回字典序更小的 "00110"image.png进化 (3).gif

示例 2：

输入：parents = [-1,0,0,1,2,2]

输出："00101100"

提示：

1 <= parents.length <= 10^4
-1 <= parents[i] < i (即父节点编号小于子节点)
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string evolutionaryRecord(vector<int>& parents) {
        int size = parents.size();
        vector<vector<int>> children(size);

        for (int i = 1; i < size; ++i) {
            children[parents[i]].push_back(i);
        }

        return DFS(0, children);
    }

    string DFS(int node, vector<vector<int>>& children) {
        if (children[node].empty()) {
            return "";
        }

        string ans;
        vector<string> records;

        for (int next : children[node]) {
            string record = "0";
            record += DFS(next, children);
            record += "1";
            records.push_back(record);
        }

        sort(records.begin(), records.end());

        for (string& record : records) {
            ans += record;
        }

        if (node == 0) {
            while (ans.back() == '1') {
                ans.pop_back();  // 最后不用回到根节点
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> parents = { -1,0,0,2 };
    check.checkString("00110", o.evolutionaryRecord(parents));

    parents = { -1 };
    check.checkString("", o.evolutionaryRecord(parents));

    parents = { -1,0,0,1,1,2,2,3,3,4,4,5,5,6,6 };
    check.checkString("0001011001011100010110010", o.evolutionaryRecord(parents));
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
