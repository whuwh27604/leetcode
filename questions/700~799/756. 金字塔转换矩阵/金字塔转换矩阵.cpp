/* 金字塔转换矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现在，我们用一些方块来堆砌一个金字塔。 每个方块用仅包含一个字母的字符串表示。

使用三元组表示金字塔的堆砌规则如下：

对于三元组(A, B, C) ，“C”为顶层方块，方块“A”、“B”分别作为方块“C”下一层的的左、右子块。当且仅当(A, B, C)是被允许的三元组，我们才可以将其堆砌上。

初始时，给定金字塔的基层 bottom，用一个字符串表示。一个允许的三元组列表 allowed，每个三元组用一个长度为 3 的字符串表示。

如果可以由基层一直堆到塔尖就返回 true ，否则返回 false 。

 

示例 1：

输入：bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
输出：true
解析：
可以堆砌成这样的金字塔:
    A
   / \
  G   E
 / \ / \
B   C   D

因为符合('B', 'C', 'G'), ('C', 'D', 'E') 和 ('G', 'E', 'A') 三种规则。
示例 2：

输入：bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
输出：false
解析：
无法一直堆到塔尖。
注意, 允许存在像 (A, B, C) 和 (A, B, D) 这样的三元组，其中 C != D。
 

提示：

bottom 的长度范围在 [2, 8]。
allowed 的长度范围在[0, 200]。
方块的标记字母范围为{'A', 'B', 'C', 'D', 'E', 'F', 'G'}。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pyramid-transition-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> allowedTable;
        hashAllowed(allowed, allowedTable);

        return canTransit(bottom, allowedTable);
    }

    bool canTransit(string& bottom, unordered_map<string, vector<char>>& allowedTable) {
        int i, j, k, size = bottom.size();
        if (size == 1) {
            return true;
        }

        queue<string> nexts;
        nexts.push("");
        for (i = 0; i < size - 1; i++) {
            string key(bottom, i, 2);
            auto iter = allowedTable.find(key);
            if (iter == allowedTable.end()) {
                return false;
            }

            int sizeNext = nexts.size();
            for (j = 0; j < sizeNext; j++) {
                for (k = 0; k < (int)iter->second.size(); k++) {
                    string next = nexts.front();
                    next += iter->second[k];
                    nexts.push(next);
                }
                nexts.pop();
            }
        }

        while (!nexts.empty()) {
            if (canTransit(nexts.front(), allowedTable)) {
                return true;
            }
            nexts.pop();
        }

        return false;
    }

    void hashAllowed(vector<string>& allowed, unordered_map<string, vector<char>>& allowedTable) {
        for (string& allow : allowed) {
            string key(allow, 0, 2);
            auto iter = allowedTable.find(key);
            if (iter == allowedTable.end()) {
                allowedTable[key] = { allow[2] };
            }
            else {
                iter->second.push_back(allow[2]);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> allowed = { "BCG", "CDE", "GEA", "FFF" };
    check.checkBool(true, o.pyramidTransition("BCD", allowed));

    allowed = { "AAA", "AAB", "ABA", "ABB", "BAC" };
    check.checkBool(false, o.pyramidTransition("AABA", allowed));

    allowed = { "ABD","CAD","EFA","FGB","FGC","GEA","DDC" };
    check.checkBool(false, o.pyramidTransition("EFGE", allowed));

    allowed = { "XXX", "XXY", "XYX", "XYY", "YXZ" };
    check.checkBool(false, o.pyramidTransition("ABC", allowed));

    allowed = { "XXX", "XXY", "XYX", "XYY", "YXZ" };
    check.checkBool(true, o.pyramidTransition("YX", allowed));

    allowed = {  };
    check.checkBool(false, o.pyramidTransition("YX", allowed));

    allowed = { "ABD","DDE" };
    check.checkBool(false, o.pyramidTransition("ABAB", allowed));

    allowed = { "BCG", "CDE", "GEA", "FFF" };
    check.checkBool(true, o.pyramidTransition("BCD", allowed));
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
