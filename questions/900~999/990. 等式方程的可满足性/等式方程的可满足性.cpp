/* 等式方程的可满足性.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

 

示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：

输入：["b==a","a==b"]
输出：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
示例 3：

输入：["a==b","b==c","a==c"]
输出：true
示例 4：

输入：["a==b","b!=c","c==a"]
输出：false
示例 5：

输入：["c==c","b==d","x!=z"]
输出：true
 

提示：

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] 和 equations[i][3] 是小写字母
equations[i][1] 要么是 '='，要么是 '!'
equations[i][2] 是 '='

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/satisfiability-of-equality-equations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents = new int[size];

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    ~DSU() {
        delete[] parents;
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    int* parents;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU variables('z' + 1);

        for (string& equation : equations) {
            if (equation[1] == '=') {
                variables.merge(equation[0], equation[3]);
            }
        }

        for (string& equation : equations) {
            if ((equation[1] == '!') && (variables.find(equation[0]) == variables.find(equation[3]))) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> equations = { "a==b","b!=a" };
    check.checkBool(false, o.equationsPossible(equations));

    equations = { "b==a","a==b" };
    check.checkBool(true, o.equationsPossible(equations));

    equations = { "a==b","b==c","a==c" };
    check.checkBool(true, o.equationsPossible(equations));

    equations = { "a==b","b!=c","c==a" };
    check.checkBool(false, o.equationsPossible(equations));

    equations = { "c==c","b==d","x!=z" };
    check.checkBool(true, o.equationsPossible(equations));

    equations = { "a!=a" };
    check.checkBool(false, o.equationsPossible(equations));
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
