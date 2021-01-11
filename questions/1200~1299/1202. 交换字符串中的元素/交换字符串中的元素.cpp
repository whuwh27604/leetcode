/* 交换字符串中的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。

你可以 任意多次交换 在 pairs 中任意一对索引处的字符。

返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。

 

示例 1:

输入：s = "dcab", pairs = [[0,3],[1,2]]
输出："bacd"
解释：
交换 s[0] 和 s[3], s = "bcad"
交换 s[1] 和 s[2], s = "bacd"
示例 2：

输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
输出："abcd"
解释：
交换 s[0] 和 s[3], s = "bcad"
交换 s[0] 和 s[2], s = "acbd"
交换 s[1] 和 s[2], s = "abcd"
示例 3：

输入：s = "cba", pairs = [[0,1],[1,2]]
输出："abc"
解释：
交换 s[0] 和 s[1], s = "bca"
交换 s[1] 和 s[2], s = "bac"
交换 s[0] 和 s[1], s = "abc"
 

提示：

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-with-swaps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int _size) {
        size = _size;
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
    int size;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size = s.size();
        DSU dsu(size);
        unordered_map<int, vector<int>> sameSetIndices;
        string smallestS(size, 0);

        mergeSet(pairs, dsu, sameSetIndices);
        classifySet(size, dsu, sameSetIndices);

        for (auto iter = sameSetIndices.begin(); iter != sameSetIndices.end(); ++iter) {
            arrangeLetters(s, iter->second, smallestS);
        }

        return smallestS;
    }

    void mergeSet(vector<vector<int>>& pairs, DSU& dsu, unordered_map<int, vector<int>>& sameSetIndices) {
        for (auto& swapPair : pairs) {
            dsu.merge(swapPair[0], swapPair[1]);
        }
    }

    void classifySet(int size, DSU& dsu, unordered_map<int, vector<int>>& sameSetIndices) {
        for (int i = 0; i < size; ++i) {
            sameSetIndices[dsu.find(i)].push_back(i);
        }
    }

    void arrangeLetters(string& s, vector<int>& indices, string& smallestS) {
        string letters;

        for (int index : indices) {
            letters += s[index];
        }

        sort(letters.begin(), letters.end());

        for (int i = 0; i < (int)letters.size(); ++i) {
            smallestS[indices[i]] = letters[i];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> pairs = { {0,3},{1,2} };
    check.checkString("bacd", o.smallestStringWithSwaps("dcab", pairs));

    pairs = { {0,3},{1,2},{0,2} };
    check.checkString("abcd", o.smallestStringWithSwaps("dcab", pairs));

    pairs = { {0,1},{1,2} };
    check.checkString("abc", o.smallestStringWithSwaps("cba", pairs));

    pairs = {  };
    check.checkString("z", o.smallestStringWithSwaps("z", pairs));
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
