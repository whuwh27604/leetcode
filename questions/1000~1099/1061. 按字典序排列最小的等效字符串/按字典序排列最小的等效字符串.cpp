/* 按字典序排列最小的等效字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出长度相同的两个字符串s1 和 s2 ，还有一个字符串 baseStr 。

其中  s1[i] 和 s2[i]  是一组等价字符。

举个例子，如果 s1 = "abc" 且 s2 = "cde"，那么就有 'a' == 'c', 'b' == 'd', 'c' == 'e'。
等价字符遵循任何等价关系的一般规则：

 自反性 ：'a' == 'a'
 对称性 ：'a' == 'b' 则必定有 'b' == 'a'
 传递性 ：'a' == 'b' 且 'b' == 'c' 就表明 'a' == 'c'
例如， s1 = "abc" 和 s2 = "cde" 的等价信息和之前的例子一样，那么 baseStr = "eed" , "acd" 或 "aab"，这三个字符串都是等价的，而 "aab" 是 baseStr 的按字典序最小的等价字符串

利用 s1 和 s2 的等价信息，找出并返回 baseStr 的按字典序排列最小的等价字符串。



示例 1：

输入：s1 = "parker", s2 = "morris", baseStr = "parser"
输出："makkek"
解释：根据 A 和 B 中的等价信息，我们可以将这些字符分为 [m,p], [a,o], [k,r,s], [e,i] 共 4 组。每组中的字符都是等价的，并按字典序排列。所以答案是 "makkek"。
示例 2：

输入：s1 = "hello", s2 = "world", baseStr = "hold"
输出："hdld"
解释：根据 A 和 B 中的等价信息，我们可以将这些字符分为 [h,w], [d,e,o], [l,r] 共 3 组。所以只有 S 中的第二个字符 'o' 变成 'd'，最后答案为 "hdld"。
示例 3：

输入：s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
输出："aauaaaaada"
解释：我们可以把 A 和 B 中的等价字符分为 [a,o,e,r,s,c], [l,p], [g,t] 和 [d,m] 共 4 组，因此 S 中除了 'u' 和 'd' 之外的所有字母都转化成了 'a'，最后答案为 "aauaaaaada"。


提示：

1 <= s1.length, s2.length, baseStr <= 1000
s1.length == s2.length
字符串s1, s2, and baseStr 仅由从 'a' 到 'z' 的小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);

        if (px < py) {
            parents[py] = px;
        }
        else {
            parents[px] = py;
        }
    }

private:
    vector<int> parents;
};

class Solution {
public:
	string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu(26);
		int size = s1.size(), len = baseStr.size();
		string ans(len, 0);

		for (int i = 0; i < size; ++i) {
            dsu.merge(s1[i] - 'a', s2[i] - 'a');
		}

        for (int i = 0; i < len; ++i) {
            ans[i] = 'a' + dsu.find(baseStr[i] - 'a');
        }

        return ans;
	}
};

int main()
{
	Solution o;
	CheckResult check;

    check.checkString("makkek", o.smallestEquivalentString("parker", "morris", "parser"));
    check.checkString("hdld", o.smallestEquivalentString("hello", "world", "hold"));
    check.checkString("aauaaaaada", o.smallestEquivalentString("leetcode", "programs", "sourcecode"));
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
